/*
	Consider a warehouse that needs a way to keep track of Inventory Items
	Every item of Inventory has a 
		Item Identifier
		Item Quantity
		Item Name
		Cost
	An item can be created and displayed.
	An item’s inventory can be increased
	A quantity of items can be shipped, decreasing inventory
		Design a class that can be used to encapsulate the Inventory Item’s state and behavior
		Use string class for the name & itemID
		Use a static member variable to generate the unique item identifier
		Provide a default constructor to initialize the object
		A capture inventory method – to request & read in the item information from the user
		An Add Quantity method and a Ship Quantity method;
		An overloaded friend function extraction operator << to display the item to the user
*/

#include <iostream>
#include <string>
using namespace std;




//Class Declaration for Inventory
class Inventory
{
private:
	int id;
	static int idGenerator;
	int qty;
	string itemName;
	double cost;
public:
	Inventory();
	void getInventory();
	int addQty(int q);
	friend ostream& operator<< (ostream&o, Inventory& i); //friend class to print out the object using the insertion operator

};

//Initializing idGenerator
int Inventory::idGenerator = 1; //always unique


//Creating a class for inventory list (Class Declaration)
class InventoryList
{
private:
	int numItems;
	Inventory iList[1000];
public: 
	InventoryList();
	void addItem();
	void showList();
	//int removeFromList(int id);
	//int sellItem(int id, int qtyToSell);

};


//Creating Constructor and initialize id, itemName, qty, and cost
Inventory::Inventory()
{
	id = idGenerator;
	itemName = "";
	qty = 0;
	cost = 0;
}


//Function 
ostream& operator<< (ostream&o, Inventory& i)
{
	o << "\n\t\t\t Your item name: " << i.itemName;
	o << "\n\t\t\t ID: " << i.id;
	o << "\n\t\t\t Qty: " << i.qty;
	o << "\n\t\t\t Cost: " << i.cost;
	cout << endl;
	cout << endl;

	return o;
}

void Inventory::getInventory()
{
	cout << "\n Enter name: ";
	getline(cin, itemName);
	cout << "\n Enter qty: ";
	cin >> qty;
	cout << "\n Enter cost: ";
	cin >> cost;
	cin.ignore();
	cin.clear();
}

//
int Inventory::addQty(int q)
{
	qty += q;
	return qty;
}


//Constructor for inventory list
InventoryList::InventoryList()
{
	numItems = 0;
}


void InventoryList::addItem()
{
	iList[numItems].getInventory(); //get the inventory method of the inventory item 
	numItems++;
}


//defind the method for showlist
void InventoryList::showList()
{
	int i;
	for (i = 0; i < numItems; i++)
	{
		cout << iList[i] << endl;
	}
}


int main()
{
	//First way:
	//Inventory item1, item2, item3; //automatically calling the constructor above 
	//item1.getInventory();
	//item2.getInventory();
	//item3.getInventory();
	//item3.addQty(300); //adding 300 to whatever number of qty that user inputs for item3
	//cout << endl;
	//cout << "\t\t ********************************** " << endl;
	//cout << item1;
	//cout << "\t\t ********************************** " << endl;
	//cout << item2;
	//cout << "\t\t ********************************** " << endl;
	//cout << item3;
	//cout << "\t\t ********************************** " << endl;


	//Second way:
	InventoryList myList;
	for (int i = 0; i < 3; i++)
	{
		myList.addItem();
	}

	myList.showList();


	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}
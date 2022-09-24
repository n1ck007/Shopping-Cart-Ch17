#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
	cout << "MENU\n"
		<< "a - Add item to cart\n"
		<< "d - Remove item from cart\n"
		<< "c - Change item quantity\n"
		<< "i - Output items' descriptions\n"
		<< "o - Output shopping cart\n"
		<< "q - Quit\n\n";
	//<< "Choose an option:";
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
	switch (option)
	{
	case 'a':
	{
		string itemName;
		string itemDescription;
		int itemPrice;
		int itemQuantity;

		cout << "ADD ITEM TO CART" << endl;
		getline(cin, itemName);
		cout << "Enter the item name:";
		getline(cin, itemName);
		cout << endl;


		cout << "Enter the item description:";
		getline(cin, itemDescription);
		cout << endl;

		cout << "Enter the item price:";
		cin >> itemPrice;
		cout << endl;


		cout << "Enter the item quantity:";
		cin >> itemQuantity;
		cout << endl << endl;

		ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);

		theCart.AddItem(newItem);

	}
	break;

	case 'd':
	{
		string item;
		cout << "REMOVE ITEM FROM CART" << endl;
		getline(cin, item);
		cout << "Enter name of item to remove:";
		getline(cin, item);
		cout << endl;

		theCart.RemoveItem(item);
		cout << endl;

	}
	break;

	case 'c':
	{
		cout << "CHANGE ITEM QUANTITY" << endl;
	}
	break;

	case 'i':
	{
		cout << "OUTPUT ITEMS' DESCRIPTIONS\n";
		theCart.PrintDescriptions();
	}
	break;

	case 'o':
	{
		cout << "OUTPUT SHOPPING CART\n";
		theCart.PrintTotal();
	}
	break;

	case 'q':
	{

	}
	break;

	default:
		break;
	}

}

int main() {
	char option;
	string name;
	string date;

	cout << "Enter customer's name:";
	getline(cin, name);
	cout << endl;
	cout << "Enter today's date:";
	getline(cin, date);
	cout << endl << endl;

	ShoppingCart cart(name, date);
	cout << "Customer name: " << cart.GetCustomerName() << endl;
	cout << "Today's date: " << cart.GetDate() << endl;
	cout << endl;

	// a d c i o q

	do {
		PrintMenu();
		do {
			cout << "Choose an option:";
			cin >> option;
			cout << endl;
		} while ((option != 'a') && (option != 'd') && (option != 'c') && (option != 'i') && (option != 'o') && (option != 'q'));


		ExecuteMenu(option, cart);
	} while (option != 'q');


	return 0;
}
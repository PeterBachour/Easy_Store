//Created by Axel Coutisson on 29 / 01 /2020
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Client.h"
#include "Order.h"
#include "Store.h"
using namespace std;

//
// Fonctions d'affichage
//

void afficheMenu()
{
	cout << endl << "**************" <<  endl << "* Easy Store *" <<  endl << "**************" <<  endl << "Enter the right number corresponding to your choose" << endl << "1. Manage Store" << endl << "2. Manage Users" << endl << "3. Manage Orders" << endl << "4. Exit" << endl;
}

void afficheMenuStore()
{
	cout << endl << "****************" <<  endl << "* Manage Store *" <<  endl << "****************" << endl <<  "Enter the right number corresponding to your choose" << endl << "1. Add product to the Store" << endl << "2. Display all products" << endl << "3. Search product by name" << endl << "4. Update product quantity" << endl << "5. return" << endl;
}

void afficheMenuUsers()
{
	cout << endl << "*****************" <<  endl << "* Manage Client *" <<  endl << "*****************" <<  endl << "Enter the right number corresponding to your choose" << endl << "1. Add client" << endl << "2. Display all clients" << endl << "3. Search client" << endl << "4. Search client by id" << endl << "5. Add product to basket" << endl << "6. Add product to basket by id" << endl << "7. remove product from basket" << endl << "8. Remove product from basket by id" << endl << "9. Modify product quantity in the basket" << endl << "10. Modify product quantity in the basket by id" << endl << "11. return" << endl;
}

void afficheMenuOrder()
{
	cout << endl << "*****************" <<  endl << "* Manage Orders *" <<  endl << "*****************" <<  endl << "Enter the right number corresponding to your choose" << endl << "1. Valideat client order" << endl << "2. Update order status" << endl << "3. Display all orders" << endl << "4. Display client orders" << endl << "5. Display client orders by id" << endl << "6. return" << endl;
}

//
// Main
//

int main()
{
	Store EasyStore;
	int choose, subchoose;
	bool stay = true, substay = true;
	while(stay)
	{
		substay = true;
		afficheMenu();
		cin >> choose;
		switch(choose)
		{
			case 1:
				while(substay)
				{
					afficheMenuStore();
					cin >>subchoose;
					
					if(subchoose == 1)
					{
						string title, description;
						int quantity;
						float price;
						cout << endl << "title :" << endl;
						cin >> title;
						cout << endl << "description :" << endl;
						cin >> description;
						cout << endl << "quantity :" << endl;
						cin >> quantity;
						cout << endl << "price :" << endl;
						cin >> price;
						EasyStore.add_product_to_store(title,description,quantity,price);
					}
					if (subchoose == 2)
					{
						EasyStore.display_products();
					}
					if(subchoose == 3)
					{
						string product;
						cout << endl << "Product name :" << endl;
						cin >> product;
						EasyStore.display_product(product);
					}
					if(subchoose == 4)
					{
						string product;
						int quantity;
						cout << endl << "Product name :" << endl;
						cin >> product;
						cout << endl << "Quantity :" << endl;
						cin >> quantity;
						EasyStore.update_product_quantity(product, quantity);
					}
					if(subchoose == 5)
					{
						substay = false;
					}
				}
				break;
			case 2:
				while(substay)
				{
					afficheMenuUsers();
					cin >>subchoose;
					if(subchoose == 1)
					{
						string name, firstname;
						cout << endl <<" Name :" << endl;
						cin >> name;
						cout << endl <<" Firstname :" << endl;
						cin >> firstname;
						EasyStore.add_client(name, firstname);
					}
					if(subchoose == 2)
					{
						EasyStore.display_clients();
					}
					if(subchoose == 3)
					{
						string name, firstname;
						cout << endl <<" Name :" << endl;
						cin >> name;
						cout << endl <<" Firstname :" << endl;
						cin >> firstname;
						EasyStore.display_client(name, firstname);
					}
					if(subchoose == 4)
					{
						int id;
						cout << endl <<" Client Id :" << endl;
						cin >> id;
						EasyStore.display_client(id);
					}
					if(subchoose == 5)
					{
						string producttitle, name, firstname;
						cout << endl <<" Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<" Name :" << endl;
						cin >> name;
						cout << endl <<" Firstname :" << endl;
						cin >> firstname;
						EasyStore.add_product_to_shopping_cart(producttitle,name,firstname);
					}
					if(subchoose == 6)
					{
						string producttitle;
						int id;
						cout << endl <<" Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<" Client Id :" << endl;
						cin >> id;
						EasyStore.add_product_to_shopping_cart(producttitle,id);
					}
					if(subchoose == 7)
					{
						string producttitle, name, firstname;
						cout << endl <<" Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<" Name :" << endl;
						cin >> name;
						cout << endl <<" Firstname :" << endl;
						cin >> firstname;
						EasyStore.remove_product_from_shopping_cart(producttitle,name,firstname);
					}
					if(subchoose == 8)
					{
						string producttitle;
						int id;
						cout << endl <<" Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<" Client Id :" << endl;
						cin >> id;
						EasyStore.remove_product_from_shopping_cart(producttitle,id);
					}
					if(subchoose == 9)
					{
						string producttitle, name, firstname;
						int quantity;
						cout << endl <<" Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<" Name :" << endl;
						cin >> name;
						cout << endl <<" Firstname :" << endl;
						cin >> firstname;
						cout << endl <<" Quantity :" << endl;
						cin >> quantity;
						EasyStore.modify_quantity_in_shopping_cart(producttitle, name, firstname, quantity);
					}
					if(subchoose == 10)
					{
						string producttitle;
						int id, quantity;
						cout << endl <<" Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<" Client Id:" << endl;
						cin >> id;
						cout << endl <<" quantity :" << endl;
						cin >> quantity;
						EasyStore.modify_quantity_in_shopping_cart(producttitle,id,quantity);
					}
					if(subchoose == 11)
					{
						substay = false;
					}
				}
				break;
			case 3:
			while(substay)
			{
				afficheMenuOrder();
				cin >>subchoose;
				if(subchoose == 1)
				{
					string name, firstname;
					cout << endl <<" Client Name :" << endl;
					cin >> name;
					cout << endl <<" Client Firstname :" << endl;
					cin >> firstname;
					EasyStore.validate_client_order(name,firstname);
				}
				if(subchoose == 2)
				{
					int order;
					cout << endl <<" Order Id :" << endl;
					cin >> order;
					EasyStore.update_status_order(order);
				}
				if(subchoose == 3)
				{
					EasyStore.display_orders();
				}
				if(subchoose == 4)
				{
					string name, firstname;
					cout << endl <<" Client name :" << endl;
					cin >> name;
					cout << endl <<" Client firstname :" << endl;
					cin >> firstname;
					EasyStore.display_orders_client(name, firstname);
				}
				if(subchoose == 5)
				{
					int id;
					cout << endl <<" Client Id :" << endl;
					cin >> id;
					EasyStore.display_orders_client(id);
				}
				if(subchoose == 6)
				{
					substay = false;
				}
			}	
				break;
			case 4:
				stay = false;
				break;
		}
	}
	return 0;
}

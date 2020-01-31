//Created by Axel Coutisson on 29 / 01 /2020
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "Product.h"
#include "Client.h"
#include "Order.h"
#include "Store.h"
#include <iomanip>
#include <algorithm>

using namespace std;

//
// Fonctions d'affichage
//

void afficheMenu()
{
	cout << endl << "**************" <<  endl << "* Easy Store *" <<  endl << "**************" <<  endl 
	<< "Enter the right number corresponding to your choice" << endl 
	<< "1. Manage Store" << endl 
	<< "2. Manage CLients" << endl 
	<< "3. Manage Orders" << endl 
	<< "4. Exit" << endl;
}

void afficheMenuStore()
{
	cout << endl << "****************" <<  endl << "* Manage Store *" <<  endl << "****************" << endl 
	<<  "Enter the right number corresponding to your choice" << endl 
	<< "1. Add product to the Store" << endl 
	<< "2. Display all products" << endl 
	<< "3. Search product by Title" << endl 
	<< "4. Update product quantity" << endl 
	<< "5. Return" << endl;
}

void afficheMenuUsers()
{
	cout << endl << "*****************" <<  endl << "* Manage Client *" <<  endl << "*****************" <<  endl 
	<< "Enter the right number corresponding to your choice" << endl 
	<< "1. Add client" << endl 
	<< "2. Display all clients" << endl 
	<< "3. Search client" << endl 
	<< "4. Search client by id" << endl 
	<< "5. Add product to basket" << endl 
	<< "6. Add product to basket by client id" << endl 
	<< "7. Remove product from basket" << endl 
	<< "8. Remove product from basket by client id" << endl 
	<< "9. Modify product quantity in the basket" << endl 
	<< "10. Modify product quantity in the basket by client id" << endl 
	<< "11. Return" << endl;
}

void afficheMenuOrder()
{
	cout << endl << "*****************" <<  endl << "* Manage Orders *" <<  endl << "*****************" <<  endl 
	<< "Enter the right number corresponding to your choice" << endl 
	<< "1. Validate client order" << endl 
	<< "2. Update order status" << endl 
	<< "3. Display all orders" << endl 
	<< "4. Display client orders" << endl 
	<< "5. Display client orders by id" << endl 
	<< "6. Return" << endl;
}

//
// Main
//

int main()
{
	Store EasyStore;

	string const fileproducts("Products.txt");
	string const fileclients("Clients.txt");
	string const fileorders("Orders.txt");


	ifstream fichierp("Products.txt");
	ifstream fichierc("Clients.txt");
	ifstream fichiero("Orders.txt");
	
	//
	// Load
	//

   	if(fichierp)
   	{
      	string ligne; //Une variable pour stocker les lignes lues

      	while(getline(fichierp, ligne)) //Tant qu'on n'est pas à la fin, on lit
      	{
        	if(ligne != "" && ligne.find("Title               |Description                             |Quantity       |Price") == string::npos &&
        		ligne.find("------------") == string::npos)
			{
				string titre;
				string desc;
				string rest;
				string rest1;
				int quantite;
				float price;


				auto first = ligne.find("|");
				titre = ligne.substr(0,first-1);
				rest = ligne.substr(first+1);
				desc = rest.substr(0, rest.find("|")-1);
				rest1 = rest.substr(rest.find("|")+1);

				quantite = stoi(rest1);
				price = stof(rest1.substr(rest1.find("|")+1));

				titre.erase(remove(titre.begin(), titre.end(), ' '), titre.end());
				// desc.erase(remove(desc.begin(), desc.end(), ' '), desc.end());

				EasyStore.add_product_to_store(titre, desc, quantite, price);
			}
      	}
   	}
    else
   	{
      cout << "ERROR: Failed to load Products." << endl;
   	}

	if(fichierc)
   	{
      	string ligne; //Une variable pour stocker les lignes lues
		string name;
      	string firstname;
      	
      	while(getline(fichierc, ligne)) //Tant qu'on n'est pas à la fin, on lit
      	{
      		if(ligne != "" && ligne.find("------------") == string::npos){
      			if(ligne.find("Client") != string::npos) {
      				string fullname = ligne.substr(ligne.find(" ")+1);
        			firstname = fullname.substr(0, fullname.find(" "));
        			string rest = fullname.substr(firstname.length()+1);
        			name = rest.substr(0, rest.find(" "));

 					EasyStore.add_client(name,firstname);
				}else{
					string titre =  ligne.substr(0,ligne.find(" "));
					titre.erase(remove(titre.begin(), titre.end(), ' '), titre.end());
					EasyStore.add_product_to_shopping_cart(titre, name, firstname);					
				}
			}
      	}
   	}
   	else
   	{
      cout << "ERROR: Failed to load Clients " << endl;
   	}

	if(fichiero)
   	{
      	string ligne; //Une variable pour stocker les lignes lues
		string name;
      	string firstname;
      	int cmp = 0;

      	while(getline(fichiero, ligne)) //Tant qu'on n'est pas à la fin, on lit
      	{
      		if(ligne != "" && ligne.find("------------") == string::npos){

      			if(ligne.find("Client") != string::npos) {
      				string fullname = ligne.substr(ligne.find(" ")+1);
        			firstname = fullname.substr(0, fullname.find(" "));
        			string rest = fullname.substr(firstname.length()+1);
        			name = rest.substr(0, rest.find(" "));
					EasyStore.validate_client_order(name, firstname);
					cmp++;
				}
				if(ligne.find("The order was delivered successfully.") != string::npos ){
					EasyStore.update_status_order(cmp);

				}
			}
      	}
   	}
    else
   	{
      cout << "ERROR: Failed to load Orders " << endl;
   	}
    
	//
	// MENU
	//

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
						string title;
						string description;
						int quantity;
						float price;
						cout << endl << "Title :" << endl;
						getline(cin >> ws, title);
						cout << endl << "Description :" << endl;
						getline(cin >> ws, description);
						cout << endl << "Quantity :" << endl;
						cin >> quantity;
						cout << endl << "Price :" << endl;
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
						cout << endl << "Product Title :" << endl;
						getline(cin >> ws, product);
						EasyStore.display_product(product);
					}
					if(subchoose == 4)
					{
						string product;
						int quantity;
						cout << endl << "Product name :" << endl;
						getline(cin >> ws, product);
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
						cout << endl <<"Name :" << endl;
						cin >> name;
						cout << endl <<"Firstname :" << endl;
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
						cout << endl <<"Name :" << endl;
						cin >> name;
						cout << endl <<"Firstname :" << endl;
						cin >> firstname;
						cout << "The client you are searching for is: " << endl;
						EasyStore.display_client(name, firstname);
					}
					if(subchoose == 4)
					{
						int id;
						cout << endl <<"Client Id :" << endl;
						cin >> id;
						cout << "The client you are searching for is: " << endl;
						EasyStore.display_client(id);
					}
					if(subchoose == 5)
					{
						string producttitle, name, firstname;
						cout << endl <<"Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<"Name :" << endl;
						cin >> name;
						cout << endl <<"Firstname :" << endl;
						cin >> firstname;
						EasyStore.add_product_to_shopping_cart(producttitle,name,firstname);
						cout << "The product has been sucessfully added to your client. " << endl;

					}
					if(subchoose == 6)
					{
						string producttitle;
						int id;
						cout << endl <<"Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<"Client Id :" << endl;
						cin >> id;
						EasyStore.add_product_to_shopping_cart(producttitle,id);
						cout << "The product has been sucessfully added to your client. " << endl;
					}
					if(subchoose == 7)
					{
						string producttitle, name, firstname;
						cout << endl <<"Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<"Name :" << endl;
						cin >> name;
						cout << endl <<"Firstname :" << endl;
						cin >> firstname;
						EasyStore.remove_product_from_shopping_cart(producttitle,name,firstname);
					}
					if(subchoose == 8)
					{
						string producttitle;
						int id;
						cout << endl <<"Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<"Client Id :" << endl;
						cin >> id;
						EasyStore.remove_product_from_shopping_cart(producttitle,id);
					}
					if(subchoose == 9)
					{
						string producttitle, name, firstname;
						int quantity;
						cout << endl <<"Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<"Name :" << endl;
						cin >> name;
						cout << endl <<"Firstname :" << endl;
						cin >> firstname;
						cout << endl <<"Quantity :" << endl;
						cin >> quantity;
						EasyStore.modify_quantity_in_shopping_cart(producttitle, name, firstname, quantity);
					}
					if(subchoose == 10)
					{
						string producttitle;
						int id, quantity;
						cout << endl <<"Product Name :" << endl;
						cin >> producttitle;
						cout << endl <<"Client Id:" << endl;
						cin >> id;
						cout << endl <<"Quantity :" << endl;
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
					cout << endl <<"Client Name :" << endl;
					cin >> name;
					cout << endl <<"Client Firstname :" << endl;
					cin >> firstname;
					EasyStore.validate_client_order(name,firstname);
				}
				if(subchoose == 2)
				{
					int order;
					cout << endl <<"Order Id :" << endl;
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
					cout << endl <<"Client Name :" << endl;
					cin >> name;
					cout << endl <<"Client Firstname :" << endl;
					cin >> firstname;
					EasyStore.display_orders_client(name, firstname);
				}
				if(subchoose == 5)
				{
					int id;
					cout << endl <<"Client Id :" << endl;
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

	vector<Product*> sprod = EasyStore.getProducts();
	vector<Client*> scli = EasyStore.getClients();
	vector<Order*> sord = EasyStore.getOrders();

	ofstream fluxp(fileproducts.c_str());
    if(fluxp)    
    {	
    	fluxp << "Title               |Description                             |Quantity       |Price" << endl;
    	fluxp << "------------------------------------------------------------------------------------------" << endl;
        for(Product *prod : sprod )
		{
			fluxp << *prod << endl;
		}
		 fluxp << "------------------------------------------------------------------------------------------" << endl;

    }
    else
    {
        cout << "ERROR: Failed to save Products." << endl;
    }

	ofstream fluxc(fileclients.c_str());
    if(fluxc)    
    {
        for(Client *cli : scli )
		{
			fluxc << *cli << endl;		
			fluxc << "------------------------------------------------------------------------------------------" << endl;

		}
    }
    else
    {
        cout << "ERROR: Failed to save Clients." << endl;
    }

	ofstream fluxo(fileorders.c_str());
    if(fluxo)    
    {
        for(Order *ord : sord)
		{
			fluxo << *ord << endl;
		}
    }
    else
    {
        cout << "ERROR: Failed to save Orders." << endl;
    }
	return 0;
}

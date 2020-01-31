#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Client.h"
#include "Order.h"
#include "Store.h"

#include <fstream>
#include <stdio.h>
#include "Display.h"

using namespace std;


string readString(string s){
	string p;
	cout << endl << s << " : " << endl;
	getline(cin >> ws, p);
	return p;
}
int readInt(string s){
	int p;
	cout << endl << s << " : " << endl;
	cin >> p;
	return p;
}
float readFloat(string s){
	float p;
	cout << endl << s << " : " << endl;
	cin >> p;
	return p;
}

int main()
{
	Store EasyStore;
	Display d;
	// 
	// LOAD
	//
    ifstream IP("Products.txt");
    if(IP)
    {
        string ligne; //Une variable pour stocker les lignes lues

        while(getline(IP, ligne)) //Tant qu'on n'est pas à la fin, on lit
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

                EasyStore.add_product_to_store(titre, desc, quantite, price);
            }
        }
    }
    else
    {
      cout << "ERROR: Failed to load Products." << endl;
    }

    ifstream IC("Clients.txt"); 
    if(IC)
    {
        string ligne; //Une variable pour stocker les lignes lues
        string name;
        string firstname;
        
        while(getline(IC, ligne)) //Tant qu'on n'est pas à la fin, on lit
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

    ifstream IO("Orders.txt");
    if(IO)
    {
        string ligne; //Une variable pour stocker les lignes lues
        string name;
        string firstname;
        int cmp = 0;

        while(getline(IO, ligne)) //Tant qu'on n'est pas à la fin, on lit
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
		d.afficheMenu();
		cin >> choose;
		switch(choose)
		{
			case 1:
				while(substay)
				{
					d.afficheMenuStore();
					cin >>subchoose;
					
					if(subchoose == 1)
					{
						string title = readString("Product Title");
						string description = readString("Description");
						int quantity = readInt("Quantity");
						float price =readFloat("Price");
						EasyStore.add_product_to_store(title,description,quantity,price);
					}
					if (subchoose == 2)
					{
						EasyStore.display_products();
					}
					if(subchoose == 3)
					{
						string product = readString("Product Title");
						EasyStore.display_product(product);
					}
					if(subchoose == 4)
					{
						string product = readString("Product Title");
						int quantity = readInt("Quantity");
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
					d.afficheMenuUsers();
					cin >>subchoose;
					if(subchoose == 1)
					{
						string name = readString("Name");
						string firstname = readString("Firstname");
						EasyStore.add_client(name, firstname);
					}
					if(subchoose == 2)
					{
						EasyStore.display_clients();
					}
					if(subchoose == 3)
					{
						string name = readString("Name");
						string firstname = readString("Firstname");
						cout << "The client you are searching for is: " << endl;
						EasyStore.display_client(name, firstname);
					}
					if(subchoose == 4)
					{
						int id = readInt("Client Id");
						cout << "The client you are searching for is: " << endl;
						EasyStore.display_client(id);
					}
					if(subchoose == 5)
					{
						string producttitle = readString("Product Title");
						string name = readString("Name");
						string firstname = readString("Firstname");
						EasyStore.add_product_to_shopping_cart(producttitle,name,firstname);
						cout << "The product has been sucessfully added to your client. " << endl;

					}
					if(subchoose == 6)
					{
						string producttitle = readString("Product Title");
						int id = readInt("Client Id");
						EasyStore.add_product_to_shopping_cart(producttitle,id);
						cout << "The product has been sucessfully added to your client. " << endl;
					}
					if(subchoose == 7)
					{
						string producttitle = readString("Product Title");
						string name = readString("Name");
						string firstname = readString("Firstname");
						EasyStore.remove_product_from_shopping_cart(producttitle,name,firstname);
					}
					if(subchoose == 8)
					{
						string producttitle = readString("Product Title");
						int id = readInt("Client Id");
						EasyStore.remove_product_from_shopping_cart(producttitle,id);
					}
					if(subchoose == 9)
					{
						string producttitle = readString("Product Title");
						string name = readString("Name");
						string firstname = readString("Firstname");
						int quantity = readInt("Quantity");
						EasyStore.modify_quantity_in_shopping_cart(producttitle, name, firstname, quantity);
					}
					if(subchoose == 10)
					{
						string producttitle = readString("Product Title");
						int id = readInt("Client Id");
						int quantity = readInt("Quantity");
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
				d.afficheMenuOrder();
				cin >>subchoose;
				if(subchoose == 1)
				{
					string name = readString("Client Name");
					string firstname = readString("Client Firstname");
					EasyStore.validate_client_order(name,firstname);
				}
				if(subchoose == 2)
				{
					int order = readInt("Order ID");
					EasyStore.update_status_order(order);
				}
				if(subchoose == 3)
				{
					EasyStore.display_orders();
				}
				if(subchoose == 4)
				{
					string name = readString("Client Name");
					string firstname = readString("Client Firstname");
					EasyStore.display_orders_client(name, firstname);
				}
				if(subchoose == 5)
				{
					int id = readInt("Order ID");
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
	//
	// SAVE
	//
    string const fileproducts("Products.txt");
    ofstream PP(fileproducts.c_str());
    vector<Product*> sprod = EasyStore.getProducts();
    if(PP)    
    {   
        PP << "Title               |Description                             |Quantity       |Price" << endl;
        PP << "------------------------------------------------------------------------------------------" << endl;
        for(Product *prod : sprod )
        {
            PP << *prod << endl;
        }
        PP << "------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "ERROR: Failed to save Products." << endl;
    }

    string const fileclients("Clients.txt");
    ofstream CC(fileclients.c_str());
    vector<Client*> scli = EasyStore.getClients();
    if(CC)    
    {
        for(Client *cli : scli )
        {
            CC << *cli << endl;     
            CC << "------------------------------------------------------------------------------------------" << endl;

        }
    }
    else
    {
        cout << "ERROR: Failed to save Clients." << endl;
    }

    string const fileorders("Orders.txt");
    ofstream OO(fileorders.c_str());
    vector<Order*> sord = EasyStore.getOrders();
    if(OO)    
    {
        for(Order *ord : sord)
        {
            OO << *ord << endl;
        }
    }
    else
    {
        cout << "ERROR: Failed to save Orders." << endl;
    }

	return 0;
}

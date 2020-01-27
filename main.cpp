#include <iostream>
#include <vector>
#include "Product.h"
#include "Client.h"
#include "Order.h"
#include "Store.h"
using namespace std;

int main()
{
	
	// Test special peter
	// Store EasyStore;

	// EasyStore.add_client("Bachour", "Peter");
	// EasyStore.add_client("Coutisson", "Axel");

	// EasyStore.add_product_to_store("PS4", "Console de jeu marque Sony", 10, 249.99);
	// EasyStore.add_product_to_store("Switch", "Console de jeu Nintendo", 30,299.99);
	// EasyStore.add_product_to_store("Xbox One", "Console de jeu Microsoft", 15,179.99);

	// EasyStore.add_product_to_shopping_cart("PS4", 1);
	// EasyStore.add_product_to_shopping_cart("PS4", 1);
	// cout << "clients" << endl;
	// EasyStore.display_clients();

	// cout << endl << endl << "product" << endl;
	// EasyStore.display_products();

	/*
  	//Question 1.
  	cout << "Question 1 : Création de la classe Magasin." << endl;
  	Store EasyStore;
  	//Fin Question 1.   
	*/
	
	/*
  	//Question 2.
  	cout << "Question 2 : Création de la classe Product." << endl;
  	Product product("PS4", "Console de jeu marque Sony", 10, 249.99);
  	cout << product << endl; 
  	//Fin Question 2.
	*/


	/*
	//Question 3.
	cout << "Question 3 : Ajout de fonctionnalités à Magasin." << endl;
	Store EasyStore;

	// Add products to the store with Title, Description, Quantity and Price
  	EasyStore.add_product_to_store("PS4", "Console de jeu Sony", 10,249.99);
  	EasyStore.add_product_to_store("Switch", "Console de jeu Nintendo", 30,299.99);
  	EasyStore.add_product_to_store("Xbox One", "Console de jeu Microsoft", 15,179.99);

  	// Display all the products
  	EasyStore.display_products();

  	// Update quantity of a product
  	EasyStore.update_product_quantity("Switch", 10);

  	// Display the updated product
 	EasyStore.display_product("Switch");
 	*/

	/*
	//Question 4.
	cout << "Question 4 : Création de la classe Client" << endl;
	Client peter(0, "Bachour", "Peter");
	Client axel(1, "Coutisson", "Axel");
  	Product PS4("PS4", "Console de jeu marque Sony", 10, 249.99);
	Product Switsh("Switch", "Console de jeu Nintendo", 30,299.99);
	Product Xbox("Xbox One", "Console de jeu Microsoft", 15,179.99);

	peter.add_product(&PS4);
	peter.add_product(&Xbox);

	axel.add_product(&Switsh);
	axel.add_product(&PS4);

  	cout <<  peter << endl;
  	peter.modify_quantity("PS4", 3);
  	cout <<  peter << endl;
  	peter.delete_product("Xbox One");
  	cout <<  peter << endl;
  	peter.empty_basket();
  	cout <<  peter << endl;
  	cout << endl;
  	cout << axel << endl;
  	cout <<  PS4 << endl;
  	cout << Switsh << endl;
  	cout <<  Xbox << endl;
  	*/

	/*
  	//Question 5.
  	cout << "Question 5 : Ajout de fonctionnalités à Magasin." << endl;
  	// Add new clients
	EasyStore.add_client("Dom", "Ginhac");
	EasyStore.add_client("Bill", "Gates");
	EasyStore.add_client("Richard", "Stallman");
	EasyStore.add_client("Alan", "Turing");
	EasyStore.add_client("Steve", "Jobs");

	// Display all the clients
	EasyStore.display_clients();

	// Display clients "Richard Stalman" and 4
	EasyStore.display_client("Richard", "Stallman");
	EasyStore.display_client(4);

	// Add a product with its title and add to a client identified by his name
	EasyStore.add_product_to_shopping_cart("PS4", "Richard", "Stallman");

	// Add a product with its title and add to a client identified by his uid
	EasyStore.add_product_to_shopping_cart("Xbox", 4);
	*/

	/*
	//Question 6.
	cout << "Question 6 : Création de la classe Commande." << endl;
	Client peter(0, "Bachour", "Peter");
  	Product PS4("PS4", "Console de jeu marque Sony", 10, 249.99);
	Product Switsh("Switch", "Console de jeu Nintendo", 30,299.99);
	Product Xbox("Xbox One", "Console de jeu Microsoft", 15,179.99);
	peter.add_product(&PS4);
	peter.add_product(&Switsh);
	peter.add_product(&Xbox);
    Order order(&peter, peter.get_productList());
    cout << order << endl;
    order.set_status(true);
    cout << order << endl;
   	*/
	/*
   	//Question 7.
   	cout << "Question 7 : Ajout de fonctionnalités à Magasin." << endl;
   	Store EasyStore;
   	EasyStore.add_product_to_store("PS4", "Console de jeu Sony", 10,249.99);
  	EasyStore.add_product_to_store("Switch", "Console de jeu Nintendo", 30,299.99);
  	EasyStore.add_product_to_store("Xbox One", "Console de jeu Microsoft", 15,179.99);

	EasyStore.add_client("Dom", "Ginhac");
	EasyStore.add_client("Bill", "Gates");

	EasyStore.add_product_to_shopping_cart("PS4", "Ginhac", "Dom");
	EasyStore.add_product_to_shopping_cart("Xbox", "Ginhac", "Dom");

	EasyStore.modify_quantity_in_shopping_cart("Xbox", "Ginhac", "Dom", 2);

	EasyStore.validate_client_order("Ginhac", "Dom");
	EasyStore.display_orders();

	EasyStore.add_product_to_shopping_cart("Switch", "Gates", "Bill");
	EasyStore.validate_client_order("Gates", "Bill");

	EasyStore.display_orders_client("Gates","Bill");
	EasyStore.display_products();
	*/







	return 0;
}
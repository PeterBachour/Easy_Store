#include <iostream>
#include <vector>
#include "Product.h"
#include "Client.h"
#include "Order.h"
#include "Store.h"
using namespace std;

int main()
{
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

	//Question 3.
	cout << "Question 3 : Ajout de fonctionnalités à Magasin." << endl;
	Store EasyStore;

	// Add products to the store with Title, Description, Quantity and Price
  	EasyStore.add_product("PS4", "Console de jeu Sony", 10,249.99);
  	EasyStore.add_product("Switch", "Console de jeu Nintendo", 30,299.99);
  	EasyStore.add_product("Xbox One", "Console de jeu Microsoft", 15,179.99);

  	// Display all the products
  	EasyStore.display_products();

  	// Update quantity of a product
  	EasyStore.update_product_quantity("Switch", 10);

  	// Display the updated product
 	EasyStore.display_product("Switch");

	return 0;
}
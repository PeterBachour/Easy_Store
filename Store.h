#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include "Client.h"
#include "Order.h"

#include <vector>
#include <iostream>

using namespace std;

class Store
{
public:

    //constructors
    Store();
    ~Store();

    Store(vector<Product*> products, vector<Client*> clients, vector<Order*> order);

    //getters
    vector<Product*> getProducts();
    vector<Client*> getClients();
    vector<Order*> getOrders();

    //methods
    void add_product_to_store(string title, string description, int quantity, float price);
    void display_products();        
    void display_product(string productName);    
    void update_product_quantity(string productName, int quantity);

    void add_client(string name, string firstname);
    void display_clients();
    void display_client(string name, string firstname);
    void display_client(int id_client);

    void add_product_to_shopping_cart(string productTitle, string name, string firstname);
    void add_product_to_shopping_cart(string productTitle, int id_client);
	void remove_product_from_shopping_cart(string productTitle, string name, string firstname);
    void remove_product_from_shopping_cart(string productTitle, int id_client);
    void modify_quantity_in_shopping_cart(string productTitle, string name, string firstname, int quantity);
    void modify_quantity_in_shopping_cart(string productTitle, int id_client, int quantity);




private:
    vector<Product*> m_products;
    vector<Client*> m_clients;
    vector<Order*> m_orders;
    int cmpt_clients;
};


#endif

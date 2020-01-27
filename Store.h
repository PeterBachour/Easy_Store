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
    void display_client(int client_id);

    void add_product_to_shopping_cart(string productTitle, string name, string firstname);
    void add_product_to_shopping_cart(string productTitle, int client_id);
	void remove_product_from_shopping_cart(string productTitle, string name, string firstname);
    void remove_product_from_shopping_cart(string productTitle, int client_id);
    void modify_quantity_in_shopping_cart(string productTitle, string name, string firstname, int quantity);
    void modify_quantity_in_shopping_cart(string productTitle, int client_id, int quantity);

    void validate_client_order(string clientName, string clientFirstname);
    void update_status_order(int order_id);
    void display_orders();
    void display_orders_client(string clientName, string clientFirstname);
    void display_orders_client(int client_id);


private:
    vector<Product*> m_products;
    vector<Client*> m_clients;
    vector<Order*> m_orders;
    int cmpt_clients;
    int cmpt_orders;

};


#endif

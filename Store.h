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
    void add_product(string title, string description, int quantity, float price);
    void display_products();        
    void display_product(string productName);    
    void update_product_quantity(string productName, int quantity);


private:
    vector<Product*> m_products;
    vector<Client*> m_clients;
    vector<Order*> m_orders;
};


#endif

#ifndef STORE_H
#define STORE_H

// #include "Product.h"
// #include "Order.h"
// #include "Client.h"


#include "Product.h"
#include "Client.h"
#include "Order.h"

#include <vector>

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

private:
    vector<Product*> m_products;
    vector<Client*> m_clients;
    vector<Order*> m_orders;
};


#endif

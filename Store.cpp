#include "Store.h"

using namespace std;
Store::Store() : m_products(vector<Product *>()) , m_clients(vector<Client *>()) ,m_orders(vector<Order *>())
{

}

Store::~Store(){

    for (Product *product : m_products) {
        delete product;
    }
    for (Client *client : m_clients) {
        delete client;
    }
    for (Order *order : m_orders) {
        delete order;
    }

}

vector<Product*> Store::getProducts(){
	return m_products;
}

vector<Client*> Store::getClients(){
	return m_clients;
}

vector<Order*> Store::getOrders(){
	return m_orders;
}
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

void Store::add_product(string title, string description, int quantity, float price){
	m_products.push_back(new Product(title, description, quantity, price));
}

void Store::display_products(){
	cout << "You have " << m_products.size() << " products in your store." << endl; 
	for (Product *product : m_products) {
        cout << *product << endl;
    }
} 

void Store::display_product(string productName){
	cout << "The product " << productName << " is :" << endl;
    for (Product *p : m_products) {
        if (p->getTitle() == productName) {
            cout << *p << endl;
        }
    }
} 

void Store::update_product_quantity(string productName, int quantity){
	for(Product* prod : m_products)
    {
        if (prod->getTitle() == productName)
            prod->modifyQuantity(quantity);
    }

}

#include "Store.h"

using namespace std;

Store::Store() : m_products(vector<Product *>()) , m_clients(vector<Client *>()) ,m_orders(vector<Order *>())
{
	cmpt_clients = 0;
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

void Store::add_product_to_store(string title, string description, int quantity, float price){
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

void Store::add_client(string name, string firstname){
	cmpt_clients++;
	m_clients.push_back(new Client(cmpt_clients, name, firstname));
}
void Store::display_clients(){
	cout << "You have " << m_clients.size() << " clients in your store." << endl; 
	for (Client *client : m_clients) {
        cout << *client << endl;
    }
}
void Store::display_client(string name, string firstname){
	for(Client* client : m_clients)
    {
        if (client->get_firstname() == firstname && client->get_name() == name)
        	cout << *client << endl;
    }
}
void Store::display_client(int id_client){
	for(Client* client : m_clients)
    {
        if (client->get_clientID() == id_client)
          	cout << *client << endl;
	}
}
    
void Store::add_product_to_shopping_cart(string productTitle, string name, string firstname){
	for(Client* client : m_clients)
    {
        if (client->get_firstname() == firstname && client->get_name() == name)
        	for(Product* prod : m_products)
    		{
        		if (prod->getTitle() == productTitle)
            		client->add_product(prod);
            }
    }
}

void Store::add_product_to_shopping_cart(string productTitle, int id_client){
	for(Client* client : m_clients)
    {
        if (client->get_clientID() == id_client)
        	for(Product* prod : m_products)
    		{
        		if (prod->getTitle() == productTitle)
            		client->add_product(prod);
            }
    }
}
void Store::remove_product_from_shopping_cart(string productTitle, string name, string firstname){
	for(Client* client : m_clients)
    {
        if (client->get_firstname() == firstname && client->get_name() == name)
           	client->delete_product(productTitle);
    }
}
void Store::remove_product_from_shopping_cart(string productTitle, int id_client){
	for(Client* client : m_clients)
    {
        if (client->get_clientID() == id_client)
            client->delete_product(productTitle);
    }
}
void Store::modify_quantity_in_shopping_cart(string productTitle, string name, string firstname, int quantity){
	for(Client* client : m_clients)
    {
        if (client->get_firstname() == firstname && client->get_name() == name)
           	client->modify_quantity(productTitle, quantity);
    }
}
void Store::modify_quantity_in_shopping_cart(string productTitle, int id_client, int quantity){
	for(Client* client : m_clients)
    {
        if (client->get_clientID() == id_client)
            client->modify_quantity(productTitle, quantity);
    }
}



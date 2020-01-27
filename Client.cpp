#include "Client.h"

using namespace std;
Client::Client()
{

}

Client::~Client(){

}

Client::Client(int id, string name, string firstname) : m_id(id), m_firstname(firstname), m_name(name), m_products(vector<Product*>()){

}

//getters
int Client::get_clientID(){
	return m_id;
}

string Client::get_firstname(){
	return m_firstname;
}

string Client::get_name(){
	return m_name;
}

vector<Product*> Client::get_productList(){
	return m_products;
}

//setters
void Client::set_name(string name){
	m_name = name;
}

void Client::set_firstname(string firstname){
	m_firstname=firstname;
}

//methods
void Client::add_product(Product* product){
	m_products.push_back(product);
}

void Client::empty_basket(){
	m_products.clear();
}

void Client::modify_quantity(string product_title, int quantity){
	for(Product* prod : m_products)
    {
        if (prod->getTitle() == product_title)
            prod->modifyQuantity(quantity);
    }
}
void Client::delete_product(string product_title){
    for (unsigned j = 0; j < m_products.size(); j++)
    {
        if (m_products[j]->getTitle() == product_title)
        	m_products.erase(m_products.begin()+j);
    }
}

ostream& operator<<(ostream& stream,  Client client){
    stream << client.get_firstname() << " " << client.get_name() << endl;
    for (unsigned j = 0; j < client.get_productList().size(); j++)
    {
        cout << *client.get_productList()[j] << endl;   
    }
    return stream;
}


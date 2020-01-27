#include "Client.h"

using namespace std;
Client::Client()
{

}

Client::~Client(){

}

Client::Client(int id, string name, string firstname) : 
    m_id(id), m_firstname(firstname), m_name(name), m_products(vector<Product*>()){
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

vector<Product*> Client::get_products(){
	return m_products;
}

vector<int> Client::get_products_quantity(){
	return m_products_quantity;
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
    m_products_quantity.push_back(1);
    product->modifyQuantity(product->getQuantity() -1);
}

void Client::empty_basket(){
    for (unsigned i = 0; i <m_products.size(); i++) {
        m_products.at(i)->modifyQuantity(m_products.at(i)->getQuantity() + m_products_quantity.at(i));
    }
    m_products_quantity.clear();
	m_products.clear();
}

void Client::modify_quantity(string product_title, int quantity){
    if (quantity > 0) {
        for (unsigned i = 0; i < m_products.size(); i++) {
            if (m_products.at(i)->getTitle() == product_title) {
                if (m_products.at(i)->getQuantity() != 0) {
                    if ((m_products.at(i)->getQuantity() < quantity - m_products_quantity.at(i))) {
                        m_products_quantity.at(i) = m_products.at(i)->getQuantity() + m_products_quantity.at(i);
                    }
                    else {
                        m_products.at(i)->modifyQuantity(m_products.at(i)->getQuantity() - quantity + m_products_quantity.at(i));
                        m_products_quantity.at(i) = quantity;
                    }
                }
            }
        }
    }
}
void Client::delete_product(string product_title){
    for (unsigned i = 0; i < m_products.size(); i++) {
        if (m_products.at(i)->getTitle() == product_title) {
            m_products.at(i)->modifyQuantity(m_products.at(i)->getQuantity() + m_products_quantity.at(i));
            m_products.erase(m_products.begin() + i);
            m_products_quantity.erase(m_products_quantity.begin() + i);
        }
    }
}


ostream& operator<<(ostream& stream,  Client client){
    stream << client.get_firstname() << " " << client.get_name() << endl;
    for (unsigned j = 0; j < client.get_products().size(); j++)
    {
        cout << *client.get_products()[j] << endl;   
    }
    return stream;
}


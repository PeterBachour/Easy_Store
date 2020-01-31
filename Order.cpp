#include "Order.h"

using namespace std;
Order::Order()
{

}
Order::Order(int order_id, Client* client, vector<Product*> orderedProducts, vector<int> orderedProducts_quantity) :
	m_order_id(order_id), m_client(client), m_status(false), m_orderedProducts(orderedProducts), m_orderedProducts_quantity(orderedProducts_quantity) {

}
Order::~Order(){

}

int Order::get_order_id(){
	return m_order_id;
}

Client* Order::get_client(){
	return m_client;
}

vector<Product*> Order::get_orderedProducts(){
	return m_orderedProducts;
}

vector<int> Order::get_orderedProducts_quantity(){
	return m_orderedProducts_quantity;
}


bool Order::get_status(){
	return m_status;
}

void Order::set_client(Client *client){
	m_client=client;
}

void Order::set_orderedProducts(vector<Product*> orderedProducts){
	m_orderedProducts=orderedProducts;
}

void Order::set_status(bool status){
	m_status=status;
}

ostream& operator<<(ostream& stream,  Order order){
    stream << *order.get_client() << endl;
    if(order.get_status()){
    	stream << "The order was delivered successfully." << endl;
    }else{
    	stream << "The order is not delivered yet." << endl;
    }
    return stream;
}

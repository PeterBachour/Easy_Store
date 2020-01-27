#include "Order.h"

using namespace std;
Order::Order()
{

}
Order::Order(Client* client, vector<Product*> orderedProducts) :m_client(client), m_status(false), m_orderedProducts(orderedProducts) {

}
Order::~Order(){

}


Client* Order::get_client(){
	return m_client;
}

vector<Product*> Order::get_orderedProducts(){
	return m_orderedProducts;
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
    stream << "The client is : " << *order.get_client() << endl;
    stream << "The products ordered are : " << endl;
    for (unsigned i = 0; i < order.get_orderedProducts().size(); i++) {
		stream << *order.get_orderedProducts().at(i) << endl;
    }
    if(order.get_status()){
    	stream << "The order was delivered successfully." << endl;
    }else{
    	stream << "The order is not delivered yet." << endl;
    }
    return stream;
}

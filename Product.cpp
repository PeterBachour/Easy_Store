#include "Product.h"

using namespace std;

//constructors
Product::Product()
{

}

Product::Product(string title, string description, int quantity, float price) : 
	m_title(title), m_description(description), m_availableQuantity(quantity), m_unitPrice(price){

	}

//getters	
string Product::getTitle(){
	return m_title;
}

string Product::getDescription(){
	return m_description;
}

int Product::getQuantity(){
	return m_availableQuantity;
}

float Product::getPrice(){
	return m_unitPrice;
}

//method
void Product::modifyQuantity(int quantity){
	m_availableQuantity = quantity;
}

string Product::toString() {
	string out = m_title;
	for (unsigned int i = m_title.length(); i < 20; i++) 
		out += " ";
	out += "|" + m_description;
	for (unsigned int i = m_description.length(); i < 40; i++) 
		out += " ";
	out += "|" +to_string(m_availableQuantity);
	for (unsigned int i = to_string(m_availableQuantity).length(); i < 15; i++) 
		out += " ";	
	out += "|" + to_string(m_unitPrice) + "€" ;
    return  out;
}


ostream& operator<<(ostream &stream, Product product)
{
	stream << product.toString();
    return stream;
}
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
    return  m_title + "\t\t" + m_description + "\t\t[" + to_string(m_availableQuantity) +"]\t\t" + to_string(m_unitPrice) + " €";
}


ostream& operator<<(ostream &stream, Product product)
{
    stream << product.toString() << endl;
    return stream;
}
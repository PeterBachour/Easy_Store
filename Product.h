#ifndef PRODUCT_H
#define PRODUCT_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Product
{
public:

    //constructors
    Product();
    Product(string title, string description, int quantity, float price);

    //getters
    string getTitle();
    string getDescription();
    int getQuantity();
    float getPrice();

    //method
    void modifyQuantity(int quantity);
    string toString();
        
private:
    string m_title;
    string m_description;
    int m_availableQuantity;
    float m_unitPrice;
};

ostream& operator<<(ostream& stream, Product product);

#endif

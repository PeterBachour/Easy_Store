#ifndef PRODUCT_H
#define PRODUCT_H

#include <vector>
#include <string>

using namespace std;

class Product
{
public:

    //constructors
    Product();
        
private:
    string m_title;
    string m_description;
    int m_availableQuantity;
    float m_unitPrice;
};


#endif

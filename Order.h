#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "Product.h"

using namespace std;

class Order
{
public:

    //constructors
    Order();
        
private:
    string m_clientName;
    bool m_status;
    vector<Product*> m_orderedProducts;
};


#endif

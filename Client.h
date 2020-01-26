#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <string>
#include "Product.h"

using namespace std;

class Client
{
public:

    //constructors
    Client();
        
private:
    int m_id;
    string m_firstname;
    string m_name;
    vector<Product*> m_products;
};

#endif

#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "Product.h"
#include "Client.h"

using namespace std;

class Order
{
public:

    //constructors
    Order();
    Order(Client* client, vector<Product*> orderedProducts);
    ~Order();

    //getters
    Client* get_client();
    vector<Product*> get_orderedProducts();
    bool get_status();

    //setters
    void set_client(Client *client);
    void set_orderedProducts(vector<Product*> orderedProducts);
    void set_status(bool status);

    friend ostream& operator<<(ostream& stream, Order order);    
        
private:
    Client* m_client;
    bool m_status;
    vector<Product*> m_orderedProducts;
};


#endif

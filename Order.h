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
    Order(int order_id, Client* client, vector<Product*> orderedProducts, vector<int> orderedProducts_quantity);
    ~Order();

    //getters
    int get_order_id();
    Client* get_client();
    vector<Product*> get_orderedProducts();
    vector<int> get_orderedProducts_quantity();
    bool get_status();

    //setters
    void set_client(Client *client);
    void set_orderedProducts(vector<Product*> orderedProducts);
    void set_status(bool status);

    friend ostream& operator<<(ostream& stream, Order order);    
        
private:
    int m_order_id;
    Client* m_client;
    bool m_status;
    vector<Product*> m_orderedProducts;
    vector<int> m_orderedProducts_quantity;
};


#endif

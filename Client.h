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
    ~Client();
    Client(int id, string name, string firstname);

    //getters
    int get_clientID();
    string get_firstname();
    string get_name();
    vector<Product*> get_productList();

    //setters
    void set_name(string name);
    void set_firstname(string firstname);

    //methods
    void add_product(Product* product);
    void empty_basket();
    void modify_quantity(string product_title, int quantity);
    void delete_product(string product_title);
    

    friend ostream& operator<<(ostream& stream, Client client);    
private:
    int m_id;
    string m_firstname;
    string m_name;
    vector<Product*> m_products;
};

#endif



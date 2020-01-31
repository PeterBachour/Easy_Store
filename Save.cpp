#include "Save.h"


using namespace std;

void Save::save_Products(Store EasyStore){
    string const fileproducts("Products.txt");
    ofstream stream(fileproducts.c_str());
    vector<Product*> sprod = EasyStore.getProducts();
    if(stream)    
    {   
        stream << "Title               |Description                             |Quantity       |Price" << endl;
        stream << "------------------------------------------------------------------------------------------" << endl;
        for(Product *prod : sprod )
        {
            stream << *prod << endl;
        }
        stream << "------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "ERROR: Failed to save Products." << endl;
    }
}

void Save::save_Clients(Store *EasyStore){
    string const fileclients("Clients.txt");
    ofstream stream(fileclients.c_str());
    vector<Client*> scli = EasyStore.getClients();
    if(stream)    
    {
        for(Client *cli : scli )
        {
            stream << *cli << endl;     
            stream << "------------------------------------------------------------------------------------------" << endl;

        }
    }
    else
    {
        cout << "ERROR: Failed to save Clients." << endl;
    }
}

void Save::save_Orders(Store *EasyStore){
    string const fileorders("Orders.txt");
    ofstream stream(fileorders.c_str());
    vector<Order*> sord = EasyStore.getOrders();
    if(stream)    
    {
        for(Order *ord : sord)
        {
            stream << *ord << endl;
        }
    }
    else
    {
        cout << "ERROR: Failed to save Orders." << endl;
    }
}
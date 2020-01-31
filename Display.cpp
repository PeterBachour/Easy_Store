#include "Display.h"

using namespace std;

void Display::afficheMenu()
{
    cout << endl << "**************" <<  endl << "* Easy Store *" <<  endl << "**************" <<  endl 
    << "Enter the right number corresponding to your choice" << endl 
    << "1. Manage Store" << endl 
    << "2. Manage Clients" << endl 
    << "3. Manage Orders" << endl 
    << "4. Exit" << endl;
}

void Display::afficheMenuStore()
{
    cout << endl << "****************" <<  endl << "* Manage Store *" <<  endl << "****************" << endl 
    <<  "Enter the right number corresponding to your choice" << endl 
    << "1. Add product to the Store" << endl 
    << "2. Display all products" << endl 
    << "3. Search product by Title" << endl 
    << "4. Update product quantity" << endl 
    << "5. Return" << endl;
}

void Display::afficheMenuUsers()
{
    cout << endl << "*****************" <<  endl << "* Manage Client *" <<  endl << "*****************" <<  endl 
    << "Enter the right number corresponding to your choice" << endl 
    << "1. Add a client" << endl 
    << "2. Display all clients" << endl 
    << "3. Search client" << endl 
    << "4. Search client by id" << endl 
    << "5. Add product to basket" << endl 
    << "6. Add product to basket by client id" << endl 
    << "7. Remove product from basket" << endl 
    << "8. Remove product from basket by client id" << endl 
    << "9. Modify product quantity in the basket" << endl 
    << "10. Modify product quantity in the basket by client id" << endl 
    << "11. Return" << endl;
}

void Display::afficheMenuOrder()
{
    cout << endl << "*****************" <<  endl << "* Manage Orders *" <<  endl << "*****************" <<  endl 
    << "Enter the right number corresponding to your choice" << endl 
    << "1. Validate client order" << endl 
    << "2. Update order status" << endl 
    << "3. Display all orders" << endl 
    << "4. Display client orders" << endl 
    << "5. Display client orders by id" << endl 
    << "6. Return" << endl;
}

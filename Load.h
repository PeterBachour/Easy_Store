#ifndef LOAD_H
#define LOAD_H

#include <fstream>
#include <stdio.h>
#include <iostream>
#include "Product.h"
#include "Client.h"
#include "Order.h"
#include "Store.h"


class Load{
public:
    void load_Products(Store EasyStore);
    void load_Clients(Store EasyStore);
    void load_Orders(Store EasyStore);
};



#endif
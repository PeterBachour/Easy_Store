#ifndef SAVE_H
#define SAVE_H

#include <fstream>
#include <stdio.h>
#include <iostream>
#include "Product.h"
#include "Client.h"
#include "Order.h"
#include "Store.h"


class Save{
public:
    void save_Products(Store EasyStore);
    void save_Clients(Store EasyStore);
    void save_Orders(Store EasyStore);
};



#endif
#include "Load.h"
 
using namespace std;

void Load::load_Products(Store EasyStore){
    ifstream stream("Products.txt");
    if(stream)
    {
        string ligne; //Une variable pour stocker les lignes lues

        while(getline(stream, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            if(ligne != "" && ligne.find("Title               |Description                             |Quantity       |Price") == string::npos &&
                ligne.find("------------") == string::npos)
            {
                string titre;
                string desc;
                string rest;
                string rest1;
                int quantite;
                float price;


                auto first = ligne.find("|");
                titre = ligne.substr(0,first-1);
                rest = ligne.substr(first+1);
                desc = rest.substr(0, rest.find("|")-1);
                rest1 = rest.substr(rest.find("|")+1);

                quantite = stoi(rest1);
                price = stof(rest1.substr(rest1.find("|")+1));

                titre.erase(remove(titre.begin(), titre.end(), ' '), titre.end());

                EasyStore.add_product_to_store(titre, desc, quantite, price);
            }
        }
    }
    else
    {
      cout << "ERROR: Failed to load Products." << endl;
    }
}

void Load::load_Clients(Store EasyStore){
    ifstream stream("Clients.txt"); 
    if(stream)
    {
        string ligne; //Une variable pour stocker les lignes lues
        string name;
        string firstname;
        
        while(getline(stream, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            if(ligne != "" && ligne.find("------------") == string::npos){
                if(ligne.find("Client") != string::npos) {
                    string fullname = ligne.substr(ligne.find(" ")+1);
                    firstname = fullname.substr(0, fullname.find(" "));
                    string rest = fullname.substr(firstname.length()+1);
                    name = rest.substr(0, rest.find(" "));

                    EasyStore.add_client(name,firstname);
                }else{
                    string titre =  ligne.substr(0,ligne.find(" "));
                    titre.erase(remove(titre.begin(), titre.end(), ' '), titre.end());
                    EasyStore.add_product_to_shopping_cart(titre, name, firstname);                 
                }
            }
        }
    }
    else
    {
      cout << "ERROR: Failed to load Clients " << endl;
    }
}

void Load::load_Orders(Store EasyStore){
    ifstream stream("Orders.txt");
    if(stream)
    {
        string ligne; //Une variable pour stocker les lignes lues
        string name;
        string firstname;
        int cmp = 0;

        while(getline(stream, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            if(ligne != "" && ligne.find("------------") == string::npos){

                if(ligne.find("Client") != string::npos) {
                    string fullname = ligne.substr(ligne.find(" ")+1);
                    firstname = fullname.substr(0, fullname.find(" "));
                    string rest = fullname.substr(firstname.length()+1);
                    name = rest.substr(0, rest.find(" "));
                    EasyStore.validate_client_order(name, firstname);
                    cmp++;
                }
                if(ligne.find("The order was delivered successfully.") != string::npos ){
                    EasyStore.update_status_order(cmp);

                }
            }
        }
    }
    else
    {
      cout << "ERROR: Failed to load Orders " << endl;
    }
}
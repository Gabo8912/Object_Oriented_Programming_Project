//
// Created by gavo0 on 22/11/2022.
//

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Product {
private:

    string name;
    double price;
    string brand;
    string description;

public:

    Product(string nameP = "none",string brandP="none",string des="none",double priceP=0);
    string getName();
    double getPrice();
    string getBrand();
    string getDescription();
    void setName(string);
    void setPrice(double);
    void setBrand(string);
    void setDescription(string);
    void showProduct();




};


#endif

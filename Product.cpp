//
// Created by gavo0 on 22/11/2022.
//

#include "Product.h"
#include <string>
#include <iostream>

Product::Product(string nameP,string brandP, string desP,double priceP):name{nameP},price{priceP},brand{brandP},description{desP} {
}

string Product::getName(){
    return name;
}
double Product::getPrice(){
    return price;
}
string Product::getBrand(){
    return brand;
}
string Product::getDescription(){
    return description;
}
void Product::setName(string nameP){
    name=nameP;
}
void Product::setPrice(double priceP){
    price=priceP;
}
void Product::setBrand(string brandP){
    brand=brandP;
}
void Product::setDescription(string desP){
    description=desP;
}
void Product::showProduct(){
    cout<<"/////////////////////////////////"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Brand: "<<brand<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"Price per piece: "<<price<<endl;
    cout<<"/////////////////////////////////"<<endl;
}
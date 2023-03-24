//
// Created by gavo0 on 29/11/2022.
//

#ifndef MAINSYSTEM_H
#define MAINSYSTEM_H
#include "user.h"
#include "Sales.h"
#include "Product.h"
#include "cart.h"
#include "Category.h"

class MainSystem {
private:
    vector<User> users;
    Category categories[10];
    Sales sales;
    Cart cart;
public:
    MainSystem();
    int login(string,string);
    void logOut();
    void addProductToCart(string);
    void addItemsToStock(string,int);
    void serchProductByName(string);
    void serchProductByCategory(string);
    void ShowAllProducts();
    void BuyCart();
    void CreateUser(string,string,string);
    void CreateNewProduct(string,string , string, string,double );
    void DeleteProduct(string);
    void RemoveProductFromCart(string,int);
    void ShowSales();
    void ShowCart();
};


#endif
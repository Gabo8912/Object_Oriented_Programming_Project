//
// Created by gavo0 on 26/11/2022.
//

#ifndef SYSTEM_H
#define SYSTEM_H
#include "user.h"
#include "cart.h"
#include "Product.h"
#include "Category.h"
#include "Sales.h"
#include <vector>

class System {
private:
    vector<User> users;
    Category categories[10];
    vector<Sales> sales;
    Cart cart;
public:
    System();
    void ShowMainMenu();//Listo
    void ShowUserMenu(vector<Product>,Cart&,Category []);//Casi listo
    void ShowAdminMenu(vector<Product> &p, Category *C, Sales sale);
    void login(vector<Product>,vector<User> ,Cart&,Category[],Sales sale);//**
    void logOut();//**
    void addProductToCart(Cart&,vector<Product>&);//**
    void addItemsToStock(vector<Product>&,Category[]);
    void serchProductByName(vector<Product> Products, Category[]);//**
    void serchProductByCategory(Category[]);//**
    void ShowAllProducts(vector<Product>);//**
    void BuyCart(Cart);//**
    void CreateUser(vector<User>&); //**
    void CreateNewProduct(vector<Product>&,Category[]); //**
    void DeleteProduct(vector <Product>&);
};


#endif //USERS_CPP_SYSTEM_H

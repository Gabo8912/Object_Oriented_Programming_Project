//
// Created by gavo0 on 25/11/2022.
//

#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
#include "Product.h"
#include <vector>
class Category {
private:
    string name;
    vector <Product> products;
    vector <int> inventory;
public:
    Category(string n = "", string filename = "");
    string getName();
    int getInventory(string);
    void addProduct(Product);
    int removeProducts(string,int);
    void showProducts();
    Product searchProduct(string);
    bool getProductName(string NameP);
    void AddStock(string,int);
    void EliminateProduct(string NameP);
    int ReduceStock(string,int );
};


#endif //USERS_CPP_CATEGORY_H

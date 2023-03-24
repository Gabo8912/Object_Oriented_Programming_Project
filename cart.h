//
// Created by gavo0 on 25/11/2022.
//

#ifndef CART_H
#define CART_H
#include "Product.h"
#include <vector>
#include <string>

class Cart {
private:
    vector <Product> products;
    vector <int> num_products;
    int TotalProducts;
    double total;
public:
    Cart(vector<Product> p={},vector<int>np={},double to=0,int TP=0);
    void emptyCart(); //elimina productos del carrito
    void addProduct(Product ,int);//Añade un producto nuevo
    void removeProduct(string);//Remueve un solo producto
    void ShowCart();
    double getTotal();
    int getNumProducts();
    void emptyTotal();
};


#endif //USERS_CPP_CART_H

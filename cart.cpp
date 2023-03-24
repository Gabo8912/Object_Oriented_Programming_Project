//
// Created by gavo0 on 25/11/2022.
//

#include "cart.h"
#include <iomanip>
#include <iostream>
#include <string>

Cart::Cart(vector<Product>p,vector<int>np,double to,int TotalP):products{p},num_products{np},total{to},TotalProducts{TotalP}{

}

void Cart::ShowCart() {
    cout<<"***************************"<<endl;
    cout<<setw(20)<<"Your cart"<<endl;
    for (int j = 0; j <products.size() ; ++j) {
        products.at(j).showProduct();
        cout<<"Number of products: "<<num_products.at(j)<<endl;
    }
    cout<<"Total: "<<total<<endl;
    cout<<"***************************"<<endl;
}

void Cart::addProduct(Product newP,int n){
    for(int i=0;i<products.size();i++){
        if(products.at(i).getName()==newP.getName()){
            num_products.at(i)+ n;
            total=total+(newP.getPrice()*num_products.at(i));
            cout<<"Product added successfully"<<endl;
            return;
        }
    }
    products.push_back(newP);
    num_products.push_back(n);
    total+=newP.getPrice()*n;
    cout<<"Product added successfully"<<endl;
}

void Cart::emptyCart() {
    for (int i = 0; i < products.size(); ++i) {
        products.erase(products.begin()+i);
        cout<<"The cart has been emptied"<<endl;
        return;
    }
    cout<<"Product not found";
}

void Cart::removeProduct(string NameP) {
    for (int i = 0; i < products.size(); ++i) {
        if(products.at(i).getName()==NameP) {
            total=total-(num_products.at(i)*products.at(i).getPrice());

            products.erase(products.begin() + i);
            cout<<"Product '"<<NameP<<"' Successfully removed"<<endl;
            return;
        }

    }
    cout<<"The product is not in the cart"<<endl;
}
double Cart::getTotal() {
    return total;
}

int Cart::getNumProducts() {
    return TotalProducts;
}

void Cart::emptyTotal(){
    total=0;
}
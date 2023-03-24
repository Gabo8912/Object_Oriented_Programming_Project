//
// Created by gavo0 on 25/11/2022.
//

#include "Category.h"
#include "Product.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Category::Category(string n, string productos): name{n} {
    ifstream inputFile;
    inputFile.open(productos); // The file should be in the same location as Category.cpp
    if (inputFile.fail()) {
        cout << "Sorry, the file couldn't be opened!\n";
        return;
    }
    string product{};
    vector<string> product_attributes;
    while(getline(inputFile, product)) {
        stringstream s_stream{product};
        while (s_stream.good()) {
            string substr;
            getline(s_stream, substr, ',');
            product_attributes.push_back(substr);
        }
        Product newProduct{product_attributes.at(0), product_attributes.at(1), product_attributes.at(2), stod(product_attributes.at(3))};
        products.push_back(newProduct);
        inventory.push_back(stoi(product_attributes.at(4)));
        product_attributes.clear();
    }
    inputFile.close();
}

string Category::getName() {
    return name;
}

bool Category::getProductName(string NameP){
    for (int i = 0; i < products.size(); ++i) {
        if (products.at(i).getName()==NameP){
            return true;
        }
    }
    return false;
}
void Category::addProduct(Product p){
    for(int i=0;i<products.size();i++){
        if(products.at(i).getName()==p.getName()){
            inventory.at(i)+ 1;
            return;
        }
    }
    products.push_back(p);
    inventory.push_back(1);
    cout<<"New product successfully added"<<endl;
}

int Category::removeProducts(string name,int quantity){//Esta es para cuando el usuario quiere comprar productos
    for(int i=0;i<products.size();i++){
        if(products.at(i).getName()==name){
            if(inventory.at(i) <= quantity){
                int removed=inventory.at(i);
                inventory.at(i)=0;
                return removed;//regresa la cantidad de productos que removimos, osea la cantidad que tenemos en dado caso que sean mas los que el ususario quiere comprar
            }
            inventory.at(i)-=quantity;
            return quantity;//si no son mas lo que quiere de los que tenemos regresa la cantidad que quito
        }
    }
    return 0; //si no encuentra el producto regresa el 0
};
void Category::showProducts(){
    for(int i=0;i<products.size();i++){
        products.at(i).showProduct();
        cout<<"Stock: "<<inventory.at(i)<<endl;
        cout<<"========================";
    }
}
Product Category::searchProduct(string name){
    for(auto product:products){
        if(product.getName()==name){
            return product;
        }
    }
    Product empty;
    return empty;
}
int Category::getInventory(string produ) {
    for(int i=0;i<10;i++){
        if (produ==products.at(i).getName())
            return inventory.at(i);
    }
}

void Category::AddStock(string nameP,int n){
    for(int i=0;i<products.size();i++) {
        if (products.at(i).getName() == nameP) {
            inventory.at(i)=inventory.at(i)+n;
        }
    }
}
void Category::EliminateProduct(string NameP){
    for (int i = 0; i < products.size(); ++i) {
        if(products.at(i).getName()==NameP){
            products.erase(begin(products)+i);
            cout<<"Product "<<NameP<<" Successfully eliminated";
            return;
        }
    }
    cout<<"Product does not exist"<<endl;
}

int Category::ReduceStock(string nameP,int n){
    int op;
    for(int i=0;i<products.size();i++) {
        if (products.at(i).getName() == nameP) {
            if (inventory.at(i)>n){
                inventory.at(i)=inventory.at(i)-n;
                return n;
        }else if (inventory.at(i)>0){
                if(inventory.at(i)<n ){
                    cout<<"There is "<<inventory.at(i)<<" in the stock,Do you want to remove "<<inventory.at(i)<<"?(1.-Yes,2.-No): ";
                    cin>>op;
                    if (op==1){
                        n=inventory.at(i);
                        inventory.at(i)=0;
                        return n;
                    }
                }
            } else if (inventory.at(i)==0){
                cout<<"There is "<<inventory.at(i)<<" in the inventory, you cant remove more"<<endl;
            }
    }
}

}
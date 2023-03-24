//
// Created by gavo0 on 29/11/2022.
//

#include "MainSystem.h"
#include <iostream>

MainSystem::MainSystem() {
    //Productos
    Category drinks{"Drinks","..\\drinks.txt"};
    Category snacks{"Snacks","..\\snacks.txt"};
    Category food{"Food","..\\food.txt"};
    categories[0]=drinks;
    categories[1]=snacks;
    categories[2]=food;
    //Usuarios
    User admin{"admin","1234","-","admin"};
    User client{"Gabo89","1234","pp"};
    users.push_back(admin);
    users.push_back(client);
}

void MainSystem::addItemsToStock(string nameP,int nump) {
    for(int i=0;i<10;i++){
        if (categories[i].getProductName(nameP)){
            categories[i].AddStock(nameP,nump);
            return;
        }
    }
    cout<<"The product does noy exist";
}
void MainSystem::DeleteProduct(string nameP) {
    for (int i = 0; i <10; ++i) {
        if (categories[i].getProductName(nameP)){
            categories[i].EliminateProduct(nameP);
        }
    }
}

int MainSystem::login(string UserName,string Password) {//regresara un valor 1-admin,2-cliente,0-Si fallo el inicio de sesion
    for (int i=0;i<users.size();i++){
        if(UserName==users.at(i).getUserName()){
            if (Password==users.at(i).getPassword()){
                if(users.at(i).getType()=="admin"){
                    return 1;
                }
                else if (users.at(i).getType()=="client"){
                    return 2;
                }
            }
        }
    }
    return 0;
}

void MainSystem::logOut() {
    cout<<"Logging out of the system"<<endl;
}

void MainSystem::addProductToCart(string nameP) {//recibe el nombre del producto que se deasea añadir
    int numP;
    for(int i=0;i<10;i++){
        if (categories[i].getProductName(nameP)){//verifica que exista el producto
            cout<<"How many products do you want to add to the cart: ";
            cin>>numP;
            numP=categories[i].ReduceStock(nameP,numP);
            cart.addProduct(categories[i].searchProduct(nameP),numP);
            return;
        }
    }
    cout<<"Product does not exist"<<endl;
}

void MainSystem::serchProductByName(string NameP) {
    Product SerchP;
    for (int i = 0; i <10; ++i) {
        if(categories[i].getProductName(NameP)){
            SerchP=categories[i].searchProduct(NameP);
            SerchP.showProduct();
            return;
        }
    }
    cout<<"Product does not exist"<<endl;
}

void MainSystem::serchProductByCategory(string NameC) {
    for (int i = 0; i < 10; ++i) {
        if (NameC==categories[i].getName()){
            categories[i].showProducts();
            return;
        }
    }
    cout<<"Category does not exist"<<endl;
}

void MainSystem::ShowAllProducts() {
    for (int i = 0; i < 10;++i) {
        categories[i].showProducts();
    }
}

void MainSystem::BuyCart() {
    float shipping=50,tax,total;
    total=cart.getTotal();
    tax=total*0.16;
    cart.ShowCart();
    cout<<"The shipping cost: "<<shipping<<endl;
    cout<<"Tax: "<<tax<<endl;
    cout<<"Your total is: "<<cart.getTotal()+shipping+tax<<endl;
    sales.AddSale(cart);
    cart.emptyCart();
    cart.emptyTotal();

}

void MainSystem::CreateUser(string NewUsername,string NewPassword,string Addres) {
    User NewUser{NewUsername, NewPassword, Addres};
    users.push_back(NewUser);
}

void MainSystem::CreateNewProduct(string NameP,string brand,string description,string category,double price) {
    Product NewProduct{NameP,brand,description,price};
    for(int i=0;i<10;i++){
        if(categories[i].getName()==category){
            categories[i].addProduct(NewProduct);
            return;
        }
    }
    cout<<"The category does not exist"<<endl;
}

void MainSystem::RemoveProductFromCart(string NameP,int n) {
    for (int i = 0; i <10; ++i) {
        if (categories[i].getProductName(NameP)){
            cart.removeProduct(NameP);
            categories[i].AddStock(NameP,n);
        }

    }
}
void MainSystem::ShowSales() {
    sales.ShowSales();
}

void MainSystem::ShowCart(){
    cart.ShowCart();
}
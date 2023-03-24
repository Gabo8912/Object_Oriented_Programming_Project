//
// Created by gavo0 on 25/11/2022.
//
#include "MainSystem.h"
#include <iostream>
MainSystem GlobalSystem;
void ShowMainMenu();
void ShowUserMenu();
void ShowAdminMenu();

int main(){
    ShowMainMenu();
};

void ShowMainMenu() {
    int opi=0,checker=0;
    string UserName,Password,Address;
    do {
        cout << "\nMain menu:\n1.-Login\n2.-Create New User\n3.-Exit\nGive me the desired option: ";
        cin >> opi;
        if (opi==1){
            cout<<"Enter the username: ";
            cin>>UserName;
            cout<<"Enter the password: ";
            cin>>Password;
            checker=GlobalSystem.login(UserName,Password);
            if(checker==1){
                ShowAdminMenu();
            }
            if (checker==2){
                ShowUserMenu();
            }
            if (checker==0){
                cout<<"Wrong username or password"<<endl;
            }
        }
        if (opi==2){
            cout<<"Enter the new Username: ";
            cin>>UserName;
            cout<<"Enter the new Password: ";
            cin>>Password;
            cout<<"Enter the address: ";
            cin>>Address;
            GlobalSystem.CreateUser(UserName,Password,Address);
        }
        if (opi==3){
            GlobalSystem.logOut();
        }
    }
    while(opi!=3);
}
void ShowUserMenu(){
    int opu=0,nump=0;
    string NameP,NameC;
    do{
        cout<<"\nOptions menu:\n1.-Show All Products\n2.-Serch by Name\n3.-Search by Category""\n4.-Add Product to cart";
        cout<<"\n5.-Remove Product from cart\n6.-Show Cart\n7.-Buy Cart\n8.-Log out\nGive me the desired option: ";
        cin>>opu;
        if(opu==1){
            GlobalSystem.ShowAllProducts();
        }
        if(opu==2){
            cout<<"Enter the product name: ";
            cin>>NameP;
            GlobalSystem.serchProductByName(NameP);
        }if(opu==3){
            cout<<"Enter the category name:";
            cin>>NameC;
            GlobalSystem.serchProductByCategory(NameC);
        }if(opu==4){
            cout<<"Enter the product name: ";
            cin>>NameP;
            GlobalSystem.addProductToCart(NameP);
        }if(opu==5) {
            cout << "Enter the product name: ";
            cin >> NameP;
            GlobalSystem.RemoveProductFromCart(NameP,nump);
            GlobalSystem.ShowCart();
        }if(opu==6){
            GlobalSystem.ShowCart();
        }if(opu==7){
            GlobalSystem.BuyCart();
        }if(opu==8){
            cout<<"Returning to the main menu"<<endl;
        }
    }while(opu!=8);

}
void ShowAdminMenu(){
    int op=0,nump=0;
    string NameP,Description,Category,Brand;
    double Price = 0;
    do {
        cout<<"\nAdmin Menu:\n1.-Create New Product\n2.-Delete a product\n3.-Add items to stock\n4.-Show Sales\n5.-Log out\nGive me the desired option: ";
        cin>>op;
        if (op==1){
            cout<<"Enter the category of the product";
            cin>>Category;
            cout<<"Enter the product name: ";
            cin>>NameP;
            cout<<"Enter the price of the product: ";
            cin>>Price;
            cout<<"Enter the brand: ";
            cin>>Brand;
            cout<<"Enter the description of the product";
            cin>>Description;
            GlobalSystem.CreateNewProduct(NameP,Brand,Description,Category,Price);
        }
        if (op==2){
            cout<<"Enter the product name: ";
            cin>>NameP;
            GlobalSystem.DeleteProduct(NameP);
        }
        if (op==3){
            cout<<"Enter the product name: ";
            cin>>NameP;
            cout<<"How many items do you want to add: ";
            cin>>nump;
            GlobalSystem.addItemsToStock(NameP,nump);
        }
        if(op==4){
            GlobalSystem.ShowSales();
        }
        if (op==5){
            cout<<"Returning to the main menu"<<endl;
        }
    } while (op!=5);
}


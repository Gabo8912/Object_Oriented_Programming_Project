//
// Created by gavo0 on 26/11/2022.
//

#include "System.h"
#include "Product.h"
#include "Category.h"
#include "user.h"
#include "cart.h"
#include "Sales.h"
#include <iostream>

System::System() {}

void System::ShowMainMenu(){
    int opi;
    do {
        cout<< "\nMain menu:\n1.-Login\n2.-Create New User\n3.-Exit\nGive me the desired option: ";
        cin >> opi;
        switch (opi) {
            case 1: login(P,Users,carrito,cat,s);
                break;
            case 2: CreateUser(Users);
                break;
            case 3: cout<<"Exiting the system...";
                break;
            default:cout<<"Invalid option"<<endl;
                break;
        }
    }while(opi!=3);
}

void System::ShowUserMenu(vector<Product> P,Cart &carrito,Category cat[]){
    int opu=0;
    do{
        cout<<"\nOptions menu:\n1.-Show All Products\n2.-Serch by Name\n3.-Search by Category""\n4.-Add Product to cart";
        cout<<"\n5.-Remove Product from cart\n6.-BuyCart\n7.-Log out\nGive me the desired option: ";
        cin>>opu;
        if (opu==1){ShowAllProducts(P);}//Method that show all products of the store
        if (opu==2){serchProductByName(P,cat);}//Method that serch the product by the name
        if (opu==3) {serchProductByCategory(cat);}//Method that show the products y one category
        if (opu==4){ addProductToCart(carrito,P);}
        if (opu==5){carrito.removeProduct();}
        if (opu==6){ BuyCart(carrito);}
        if(opu==7){carrito.ShowCart();}
        if(opu==8){logOut();}//Method that logs out of the user menu and go to the main menu
        if(opu>8 or opu<8){cout<<"Invalid Option"<<endl;}
    }while(opu!=8);
}
void System::ShowAdminMenu(vector <Product>&p,Category C[],Sales sale) {
    int op=0;
    Product NewProduct;
    do {
        cout<<"\nAdmin Menu:\n1.-Create New Product\n2.-Delete a product\n3.-Add items to stock\n4.-Show Sales\n5.-Log out\nGive me the desired option: ";
        cin>>op;
        if (op==1){CreateNewProduct(p,C);}
        if (op==2){DeleteProduct(p);}
        if (op==3){ addItemsToStock(p,C);}
        if(op==4){sale.ShowSales(p);}
        if(op==5){logOut();}
        else{ cout<<"Invalid option"<<endl;}
    }while(op!=5);
}
void System::login(vector<Product> P,vector<User> U,Cart &carrito,Category cat[],Sales s){
    string userName,password;
    int j=0;
    cout<<"UserName: ";
    cin>>userName;
    cout<<"Password: ";
    cin>>password;
    for (int i = 0; i <U.size(); ++i) {
        if(userName==U.at(i).getUserName()){
            if(password==U.at(i).getPassword()){
                if (U.at(i).getType()=="admin"){
                        ShowAdminMenu(P,cat,s);
                        j=1;
            }else{
                    ShowUserMenu(P,carrito,cat);
                    j=1;
                }
            }
        }

    }
    if(j==0){
        cout<<"Wrong username or password"<<endl;
    }
}

void System::logOut(){
    cout<<"Logging out..."<<endl;
}

void System::addItemsToStock(vector<Product>&p,Category c[]){
    string name;
    Product pro;
    cout<<"Product name: ";
    cin>>name;
    for (int i=0;i<10;i++){
        if (p.at(i).getName()==name){
            pro=p.at(i);
            c->addProduct(pro);
        }
    }
}

void System::serchProductByName(vector<Product>Products,Category category[]){
    string name;
    cout<<"Enter product name: ";
    cin>>name;
    int k=0;
    for (int i=0;i<Products.size();i++) {
        if (name == Products.at(i).getName()) {
            Products.at(i).showProduct();
            for(int j=0;j<10;j++){
                cout<<"Stock: "<<category[j].getInventory(name);
            }
            k++;
        }
    }if(k==0) {
        cout << "Product not found misspelled" <<endl;
    }
}
void System::CreateUser(vector<User>&Users) {
    User NewUser;
    string name,password,address;
    cout<<"Username: ";
    cin>>name;
    cout<<"Password: ";
    cin>>password;
    cout<<"Address: ";
    cin>>address;
    NewUser={name,password,"client",address};
    Users.push_back(NewUser);
}

void System::CreateNewProduct(vector<Product> &products,Category categories[]) {
    Product NewProduct;
    string name,brand,description,category;
    double price;
    cout<<"Name: ";
    cin>>name;
    cout<<"Price: ";
    cin>>price;
    cout<<"Brand: ";
    cin>>brand;
    cout<<"Description: ";
    cin>>description;
    cout<<"Category: ";
    cin>>category;
    NewProduct={name,price,brand,description};
    for(int i=0;i<=10;i++){
        if(category==categories[i].getName()){
            categories[i].addProduct(NewProduct);
        }
    }
    products.push_back(NewProduct);
}
void System::serchProductByCategory(Category cat[]){
    string name;
    cout<<"Category name: ";
    cin>>name;
    for(int i=0;i<=10;i++){
        if(name==cat[i].getName()){
            cat[i].showProducts();
        }
    }

}
void System::ShowAllProducts(vector<Product> Products){
    for(auto p:Products){
        p.showProduct();
    }
}
void System::DeleteProduct(vector <Product>&products){
    string nameP;
    int j=0;
    cout<<"Enter the name of the product you want to remove";
    cin>>nameP;
    for(int i=0;i<=products.size();i++){
        if(nameP==products.at(i).getName()){
            //products.erase();
            cout<<"Product successfully removed"<<endl;
            j++;
        }
    }
    if (j==0){cout<<"Product not found"<<endl;}
}
void System::BuyCart(Cart carrito){
    carrito.ShowCart();
    cout<<"Your total is: "<<carrito.getTotal();
    carrito.emptyCart();


}

void System::addProductToCart(Cart &carrito,vector<Product>&P){
    string Pname;
    Product PCart;
    cout<<"Enter the product name: ";
    cin>>Pname;
    for(auto products:P){
        if (products.getName()==Pname){
            PCart=products;
            carrito.addProduct(PCart,P);
        }
    }



}

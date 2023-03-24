//
// Created by gavo0 on 22/11/2022.
//

#include "user.h"
#include <string>



User::User(string Name,string Pass,string UserAddress , string type):userName{Name},password{Pass},Type{type},address{UserAddress} {

}

string User::getType() {
    return Type;
}

string User::getUserName() {
    return userName;
}

string User::getPassword(){
    return password;
}

string User::getAddress() {
    return address;
}

void User::setPassword(string pass){
    password=pass;
}
void User::setUsername(string name){
    userName=name;
}
void User::setAddress(string NewAddress) {
    address=NewAddress;
}
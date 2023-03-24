//
// Created by gavo0 on 22/11/2022.
//

#ifndef CLIENT_H
#define CLIENT_H
#include "Product.h"
#include <string>
#include <vector>
using namespace std;

class User {
private:
    string userName;
    string password;
    string Type;
    string address;
public:
    User(string Name="none",string Pass="none",string addres="none",string type="client");
    string getUserName();
    string getType();
    string getPassword();
    string getAddress();
    void setUsername(string);
    void setPassword(string);
    void setAddress(string);

};


#endif

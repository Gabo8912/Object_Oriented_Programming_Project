//
// Created by gavo0 on 28/11/2022.
//

#ifndef CATEGORY_H_SALES_H
#define CATEGORY_H_SALES_H
#include "user.h"
#include "cart.h"
#include <vector>

class Sales {
private:
    vector<Cart> AllSales;
    double Total;
public:
    Sales();
    void ShowSales();
    void AddSale(Cart);

};


#endif //CATEGORY_H_SALES_H

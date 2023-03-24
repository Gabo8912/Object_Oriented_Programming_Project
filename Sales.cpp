//
// Created by gavo0 on 28/11/2022.
//

#include "Sales.h"
#include <iostream>

Sales::Sales() {}

void Sales::ShowSales() {
    for(int i=0;i<AllSales.size();i++){
        AllSales.at(i).ShowCart();
    }
    cout<<"The total of the sales are: "<<Total<<endl;
}
void Sales::AddSale(Cart NewSale) {
    Total=Total+NewSale.getTotal();
    AllSales.push_back(NewSale);


}

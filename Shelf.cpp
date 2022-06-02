#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Shelf.h"

using namespace std;

Shelf::Shelf() {}

int convertDate(const string& date){
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
    int convertDate = day + month * 100 + year * 10000;
    return convertDate;
}

void Shelf::printProductFood() {
    for(auto i : vecAmountProduct){
        cout << i->Info() << endl;
    }
}

void Shelf::addProductFood(const ProductFood* product, int count) {
    while (count > 0){
        if(vecAmountProduct.size() >= getCapacity()){
            throw invalid_argument("dis");
        }
        else{
            vecAmountProduct.push_back(product); count--;
        }
    }
}

const ProductFood* Shelf::takeProduct(const string &name) {
    for(auto product = vecAmountProduct.begin(); product != vecAmountProduct.end(); product++){
        const ProductFood * productFood = *product;
        if(productFood->getName() == name){
            vecAmountProduct.erase(product);
            sumPrice(productFood->getPrice());
            return productFood;
        }
    }
}

void Shelf::loseShelfLifeProductFood(const string& date) {
    int todayDate = convertDate(date);
    for(auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();){
        const ProductFood * productFood = *product;
        int shelfDate = convertDate(productFood->getShelfLife());
        if (todayDate > shelfDate){
            product = vecAmountProduct.erase(product);
        }
        else {
            product++;
        }
    }
}

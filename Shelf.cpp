#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Shelf.h"

using namespace std;

Shelf::Shelf() {}

int Shelf::convertDate(const string& date){
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
    int convertDate = day + month * 100 + year * 10000;
    return convertDate;
}

void Shelf::dateComparison(const string &ProduceDate, const string &ShelfLife) {
    int produceDate = convertDate(ProduceDate);
    int shelfLife = convertDate(ShelfLife);
    if(produceDate > shelfLife){
        throw invalid_argument("You entered a production date less than the shelf life. This can't be");
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

const ProductFood* Shelf::buyProduct(const string &name) {
    for(auto product = vecAmountProduct.begin(); product != vecAmountProduct.end(); product++){
        const ProductFood * productFood = *product;
        if(productFood->getName() == name){
            vecAmountProduct.erase(product);
            sumPrice(productFood->getPrice());
            return productFood;
        }
    }
    return nullptr;
}

void Shelf::addProductFood(const ProductFood* product, int count) {
    if(count < 0) {
        throw invalid_argument("You have entered a amount of products less than 0. This cannot be.");
    } else {
        while (count > 0) {
            if(vecAmountProduct.size() >= getCapacity()) {
                throw invalid_argument("dis");
            }
            else {
                vecAmountProduct.push_back(product); count--;
            }
        }
    }
}

void Shelf::printProductFood() {
    for(auto i : vecAmountProduct){
        cout << i->Info() << endl;
    }
}





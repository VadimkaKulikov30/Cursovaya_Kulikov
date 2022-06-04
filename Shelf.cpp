#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Shelf.h"

using namespace std;

Shelf::Shelf() : capacity(5) {}

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
            product = vecAmountProduct.erase(product); capacity++;
        }
        else {
            product++;
        }
    }
}

const ProductFood* Shelf::checkIntegrity(const string &name) {
    random_device rd;
    default_random_engine generator(rd());
    for(auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();){
        const ProductFood * productFood = *product;

            if(productFood->getName() == name){
                bernoulli_distribution distribution(0.5);
                if(distribution(generator)){
                    product++;
                }
                else {
                    vecAmountProduct.erase(product); capacity++;
                }
            }
            else{product++;}
        }
    return nullptr;
}

const ProductFood* Shelf::buyProduct(const string &name) {
    for(auto product = vecAmountProduct.begin(); product != vecAmountProduct.end(); product++){
        const ProductFood * productFood = *product;
        if(productFood->getName() == name){
            vecAmountProduct.erase(product);
            sumPrice(productFood->getPrice());
            capacity++;
            return productFood;
        }
    }
    return nullptr;
}

void Shelf::addProductFood(const ProductFood* product, int count) {
    if(count < 0) {
        throw invalid_argument("You have entered a amount of products less than 0. This cannot be.");
    } else if (count > getCapacity()){
        throw invalid_argument("Initially, there is less space on the shelf than you wanted to add.");
    } else {
        while (count > 0) {
            vecAmountProduct.push_back(product); count--; capacity--;
        }
    }
}

void Shelf::printProductFood() {
    for(auto i : vecAmountProduct){
        cout << i->Info() << endl;
    }
}





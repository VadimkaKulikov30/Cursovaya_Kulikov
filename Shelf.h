#ifndef CURSOVAYA_SHELF_H
#define CURSOVAYA_SHELF_H

#include "Product.h"
#include "ProductFood.h"

#include <vector>
#include <random>

class Shelf {
private:
    int capacity;
    int amountMoney = 0;
    vector<const ProductFood*> vecAmountProduct;
public:

    Shelf();

    int convertDate(const string& date);
    int getCapacity() const {return capacity;}
    int getAmountMoney() const {return amountMoney;}

    //Revenue of products sold.
    void sumPrice(int gain) {amountMoney += gain;}

    void setCapacityIncrease(int gain) {capacity += gain;}
    void setCapacityReduce(int gain) {capacity -= gain;}

    void loseShelfLifeProductFood(const string& date);
    void printProductFood();
    void sortProductFood();
    void addProductFood(const ProductFood* product, int quantity);
    void dateComparison(const string& ProduceDate, const string& ShelfLife);

    const ProductFood* buyProduct(const string& name);
    const ProductFood* checkIntegrity(const string& name);
};


#endif //CURSOVAYA_SHELF_H

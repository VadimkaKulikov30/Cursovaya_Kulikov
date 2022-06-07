#ifndef CURSOVAYA_SHELF_H
#define CURSOVAYA_SHELF_H

#include "ProductFood.h"

class Shelf {
private:
    int capacity;
    int damage = 0;
    int amountMoney = 0;
    vector<const ProductFood*> vecAmountProduct;
public:

    Shelf();

    int convertDate(const string& date);

    int getCapacity() const {return capacity;}
    int getAmountMoney() const {return amountMoney;}
    int getDamageProduct() const {return damage;}

    //Revenue of products sold.
    void sumPrice(int gain) {amountMoney += gain;}

    void setCapacityIncrease(int gain) {capacity += gain;}
    void setCapacityReduce(int gain) {capacity -= gain;}

    void dateComparison(const string& ProduceDate, const string& ShelfLife);
    void addProductFood(const ProductFood* product, int quantity);
    void loseShelfLifeProductFood(const string& date);
    void sortProductPriceAscending();
    void sortProductPriceDescending();
    void buyProduct(const string& name);
    void buyAllProduct();
    void checkIntegrity(const string& name);
    void checkAllIntegrity();
    void printProductFood();

};


#endif //CURSOVAYA_SHELF_H

#ifndef CURSOVAYA_SHELF_H
#define CURSOVAYA_SHELF_H

#include "Product.h"
#include "ProductFood.h"
#include <vector>

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

    void sumPrice(int gain) {amountMoney += gain;}
    void printProductFood();
    void sortProductFood();
    void addProductFood(const ProductFood* i, int quantity);
    void loseShelfLifeProductFood(const string& date);

    void dateComparison(const string& ProduceDate, const string& ShelfLife);

    const ProductFood* buyProduct(const string& name);

};


#endif //CURSOVAYA_SHELF_H

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
    int exam_bool = 5;
    vector<const ProductFood*> vecAmountProduct;
public:

    Shelf();

    int convertDate(const string& date);
    int getCapacity() const {return capacity;}
    int getAmountMoney() const {return amountMoney;}
    int getOneLessCapacity() const{return getCapacity();}

    void setCapacity(int gain) {capacity += gain;}
    void sumPrice(int gain) {amountMoney += gain;}
    void printProductFood();
    void sortProductFood();
    void addProductFood(const ProductFood* product, int quantity);
    void loseShelfLifeProductFood(const string& date);
    void dateComparison(const string& ProduceDate, const string& ShelfLife);

    const ProductFood* buyProduct(const string& name);
    const ProductFood* checkIntegrity(const string& name);
};


#endif //CURSOVAYA_SHELF_H

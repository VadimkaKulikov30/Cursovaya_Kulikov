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

    int getCapacity() const {return capacity;}
    int getAmountMoney() {return amountMoney;}

    //void setCapacity(int gain) {capacity = gain;}
    void sumPrice(int gain) {amountMoney += gain;}
    void printProductFood();
    void sortProductFood();
    void addProductFood(const ProductFood* i, int quantity);
    void loseShelfLifeProductFood(const string& date);


    const vector<const ProductFood*> getAmountProduct() const {return vecAmountProduct;}
    const ProductFood* takeProduct(const string& name);



};

int convertDate(const string& date);

#endif //CURSOVAYA_SHELF_H

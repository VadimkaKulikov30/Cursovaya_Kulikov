#ifndef CURSOVAYA_SHELF_H
#define CURSOVAYA_SHELF_H


class Shelf {
private:
    int capacity;
    int amountProduct;
    int amountMoney = 0;
public:
    Shelf();

    int getCapacity() const {return capacity;}
    //void setCapacity(int gain) {capacity = gain;}
    int getAmountMoney() {return amountMoney;}
    void Sum(int gain) {amountMoney += gain;}

    int getAmountProduct() const {return amountProduct;}


};


#endif //CURSOVAYA_SHELF_H

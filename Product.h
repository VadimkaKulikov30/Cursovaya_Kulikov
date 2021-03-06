#ifndef CURSOVAYA_PRODUCT_H
#define CURSOVAYA_PRODUCT_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

class Product {
private:
    string name, produceDate;
    int weight, price;
public:
    Product();
    Product(string name,
            string produceDate,
            int weight,
            int price);
    virtual ~Product() {}

    string getName() const {return name;}
    string getProduceDate() const {return produceDate;}
    int getWeight() const {return weight;}
    int getPrice() const {return price;}

    virtual string Info() const;
};


#endif //CURSOVAYA_PRODUCT_H

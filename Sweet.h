#ifndef CURSOVAYA_SWEET_H
#define CURSOVAYA_SWEET_H

#include "Product.h"
#include "ProductFood.h"
#include <string>

using namespace std;

class Sweet : public ProductFood {
private:
    string sweetType;
    string packageType;
public:
    Sweet();
    Sweet(
           const string& nameSweet,
           const string& produceDate,
           int weight,
           int price,
           const string& shelfLife,
           int amountCalories,
           const string& sweetType,
           const string& packageType
           );

    string getSweetType() const {return sweetType;}
    string getPackageType() const {return packageType;}

    string Info() const override;
    string Type() const override{return "Sweet";}
};


#endif //CURSOVAYA_SWEET_H

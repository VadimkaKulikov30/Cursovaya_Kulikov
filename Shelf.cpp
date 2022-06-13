#include "Shelf.h"

Shelf::Shelf() : capacity(5) {}

void Shelf::addProductFood(const ProductFood* product, int count) {
    if(count < 0) {
        throw invalid_argument(" You have entered a amount of products less than 0. This cannot be.");
    } else if (count > getCapacity()){
        throw invalid_argument(" Initially, there is less space on the shelf than you wanted to add.");
    } else {
        while (count > 0) {
            vecAmountProduct.push_back(product); count--; capacity--; 
        }
    }
}

//Checking the product for shelf life.
void Shelf::loseShelfLifeProductFood(const string& date) {
    if(vecAmountProduct.empty()){
        cout << " There are no products on the shelf." << endl;
    } else {
        int todayDate = ProductFood::convertDate(date);
        for (auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();) {
            const ProductFood *productFood = *product;
            int shelfDate = ProductFood::convertDate(productFood->getShelfLife());
            if (todayDate > shelfDate) {
                delete * product;
                product = vecAmountProduct.erase(product);
                capacity++; damage++;
            } else {
                product++;
            }
        }
        if(damage != 0){
            cout << " Expired products - " << getDamageProduct() << "\n These products were disposed of off the shelf.\n";
            damage = 0;
        } else {
            cout << " No expired products.\n";
        }
    }
}

//Sorting products by price.
bool sortComparatorPriceAscending(const ProductFood * productFirst, const ProductFood * productSecond){return (productFirst->getPrice() < productSecond->getPrice());}
bool sortComparatorPriceDescending(const ProductFood * productFirst, const ProductFood * productSecond) {return (productFirst->getPrice() > productSecond->getPrice());}

void Shelf::sortProductPriceAscending() {
    if(vecAmountProduct.empty()){
        cout << "There are no products on the shelf.\n"
                "You can't sort the product." << "\n";
    } else {
        sort(vecAmountProduct.begin(), vecAmountProduct.end(), sortComparatorPriceAscending);
        cout << "Products sorted.\n";
    }
}

void Shelf::sortProductPriceDescending() {
    if(vecAmountProduct.empty()){
        cout << "There are no products on the shelf.\n"
                "You can't sort the product." << "\n";
    } else {
        sort(vecAmountProduct.begin(), vecAmountProduct.end(), sortComparatorPriceDescending);
        cout << "Products sorted.\n";
    }
}

//Buying a product by name.
void Shelf::buyProduct(const string &name) {
    if(vecAmountProduct.empty()){
        cout << "There are no products on the shelf." << "\n";
    } else {
        for (auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();) {
            const ProductFood * productFood = *product;
            if (productFood->getName() == name) {
                delete * product;
                vecAmountProduct.erase(product);
                sumPrice(productFood->getPrice());
                capacity++;
                break;
            } else {
                product++;
            }
        }
        cout << "You bought " << name << ".\n";
    }
}

//Buying of all products.
void Shelf::buyAllProduct() {
    if(vecAmountProduct.empty()){
        cout << "There are no products on the shelf." << "\n";
    } else {
        for (auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();) {
            const ProductFood *productFood = *product;
            delete * product;
            vecAmountProduct.erase(product);
            sumPrice(productFood->getPrice());
            capacity++;
        }
        cout << "You bought all products.\n";
    }
}

//Checking product for integrity.
void Shelf::checkIntegrity(const string &name) {
    if(vecAmountProduct.empty()) {
        cout << "There are no products on the shelf." << endl;
    } else {
    random_device rd;
    mt19937 generator(rd());
    for(auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();){
        const ProductFood * productFood = *product;
            if(productFood->getName() == name){
                bernoulli_distribution distribution(0.8);
                if(distribution(generator)){
                    product++;
                } else {
                    delete * product;
                    vecAmountProduct.erase(product); capacity++; damage++;
                }
            } else {
                product++;
            }
        }
        if(damage != 0){
            cout << "You checked " << name <<  " for integrity. " << "Damaged products - " << getDamageProduct() << ".\n";
            damage = 0;
        } else {
            cout << "No damaged products.\n";
        }
    }
}

void Shelf::checkAllIntegrity() {
    if(vecAmountProduct.empty()){
        cout << "There are no products on the shelf." << endl;
    } else {
        random_device rd;
        mt19937 generator(rd());
        for(auto product = vecAmountProduct.begin(); product != vecAmountProduct.end();){
            bernoulli_distribution distribution(0.8);
            if(distribution(generator)){
                product++;
            } else {
                delete * product;
                vecAmountProduct.erase(product); capacity++; damage++;
            }
        }
        if(damage != 0){
            cout << "You checked products for integrity. " << "Damaged products - " << getDamageProduct() << ".\n";
            damage = 0;
        } else {
            cout << "No damaged products.\n";
        }
    }
}

//Printing products on the shelf.
void Shelf::printProductFood() {
    if(vecAmountProduct.empty()){
        cout << " There are no products on the shelf." << endl;
    } else {
        for(auto product : vecAmountProduct){
            cout << product->Info() << "\n";
        }
    }
}






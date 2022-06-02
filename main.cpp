#include <iostream>
#include "Product.h"
#include "ProductFood.h"
#include "Yogurt.h"
#include "Milk.h"
#include "Sweet.h"
#include "Shelf.h"

int main() {
    string name, inside, packageType;
    int weight, fat, price, amountCalories, amount;
    string produceDate, todayDate, shelfLife;
    char selection;
    Shelf shelf;
    Yogurt *yogurt;
    Milk *milk;
    Sweet *sweet;
    do {
        cout << endl;
        cout << "|/////////////////////////////////////|\n";
        cout << "|//// Welcome to the product shop ////|\n";
        cout << "|/////////////////////////////////////|\n";
        cout << "|*************************************|\n";
        cout << "| Choose product:                     |\n";
        cout << "|*************************************|\n";
        cout << "| 1. Add Yogurt                       |\n";
        cout << "| 2. Add Milk                         |\n";
        cout << "| 3. Add Sweet                        |\n";
        cout << "|*************************************|\n";
        cout << "| Choose method:                      |\n";
        cout << "|*************************************|\n";
        cout << "| 4. Add Check date                   |\n";
        cout << "| 5. Add Sort                         |\n";
        cout << "| 6. Add GetMoney                     |\n";
        cout << "| 7. Add Print                        |\n";
        cout << "| 8. Add Print                        |\n";
        cout << "|*************************************|\n";
        cout << "Enter your selection:\n";
        cin >> selection;
        cout << endl;

            switch (selection) {
                case '1':
                    try {
                        cout << "You chose yogurt, let's add it to the shelf.\n";
                        cout << "Enter the name of the yogurt:\n"; cin >> name;
                        cout << "Production date input format example: DD/MM/YYYY.\n";
                        cout << "Enter production date:\n"; cin >> produceDate;
                        cout << "Weight is calculated in grams and cannot be less than 0.\n";
                        cout << "Enter weight:\n"; cin >> weight;
                        cout << "The price is calculated in dollars and cannot be less than 0.\n";
                        cout << "Enter price\n"; cin >> price;
                        cout << "Shelf life input format example: DD/MM/YYYY\n";
                        cout << "Enter shelf life:\n"; cin >> shelfLife;
                        cout << "Calories are counted in kcal and cannot be less than 0.\n";
                        cout << "Enter amount calories\n"; cin >> amountCalories;
                        cout << "The fat content of yogurt is not less than 0% and not more than 10%\n";
                        cout << "Enter fat:\n"; cin >> fat;
                        cout << "The inside of yogurt can be for example pineapple, mango, apple and other fruits\n";
                        cout << "Enter the inside of the yogurt:\n"; cin >> inside;
                        cout << "Enter amount of product\n"; cin >> amount;

                        yogurt = new Yogurt(name, produceDate, weight, price, shelfLife, amountCalories, fat, inside);
                        shelf.addProductFood(yogurt, amount);

                    } catch (exception& ex){
                        cout << ex.what() << endl;
                    }
                    break;
                case '4':
                    cout << "Check Expired products\n";
                    cout << "Enter today date\n";
                    cin >> todayDate;
                    shelf.loseShelfLifeProductFood(todayDate);
                    cout << "\n";
                    break;
                case '6':
                    cout << shelf.getAmountMoney();
                    break;
                case '8':
                    shelf.printProductFood();
                    break;
                default:
                    cout << selection << "wrong selection";
                    cout << endl;
            }
    } while(selection != 0);

    try{
        Yogurt m("Fresh", "12042022", 3, 56, "343", 32, 3.5, "carton" );
        cout << m.Info() << endl;
    }catch(exception& ex){
        cerr << ex.what() << endl;
    }

     Product p("wtwe", "34", 23, 23);
     cout << p.Info() << endl;
    cout << "Hello world" << endl;
    return 0;
}

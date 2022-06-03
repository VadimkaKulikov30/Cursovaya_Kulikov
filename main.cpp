#include <iostream>
#include "Product.h"
#include "Yogurt.h"
#include "Milk.h"
#include "Sweet.h"
#include "Shelf.h"

int main() {
    string name, inside, packageType;
    int weight, fat, price, amountCalories, amount;
    string produceDate, todayDate, shelfLife, sweetType;
    char selection;
    Shelf shelf;
    Yogurt *yogurt;
    Milk *milk;
    Sweet *sweet;
    do {
        cout << "|=========================================|\n";
        cout << "|       WELCOME TO THE PRODUCT SHOP       |\n";
        cout << "|=========================================|\n";
        cout << "| Choose product:                         |\n";
        cout << "|=========================================|\n";
        cout << "| 1. Yogurt.                              |\n";
        cout << "| 2. Milk.                                |\n";
        cout << "| 3. Sweet.                               |\n";
        cout << "|=========================================|\n";
        cout << "| Choose method:                          |\n";
        cout << "|=========================================|\n";
        cout << "| 4. Checking the product for shelf life. |\n";
        cout << "| 5. Sorting products on the shelf.       |\n";
        cout << "| 6. Buying products.                     |\n";
        cout << "| 7. Revenue of products sold.            |\n";
        cout << "| 8. Printing products on the shelf.      |\n";
        cout << "|=========================================|\n";
        cout << "| 9. Exit the program.                    |\n";
        cout << "|=========================================|\n";
        cout << "You can choose any of the 9 sub-items and\n"
                "follow the prompts. Good luck!\n";
        cout << "Enter your selection:\n";
        cin >> selection;
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
                        cout << "Enter price:\n"; cin >> price;
                        cout << "Shelf life input format example: DD/MM/YYYY.\n";
                        cout << "Enter shelf life:\n"; cin >> shelfLife;
                        cout << "Calories are counted in kcal and cannot be less than 0.\n";
                        cout << "Enter amount calories:\n"; cin >> amountCalories;
                        cout << "The fat content of yogurt is not less than 0% and not more than 10%.\n";
                        cout << "Enter fat:\n"; cin >> fat;
                        cout << "The inside of yogurt can be for example pineapple, mango, apple and other fruits.\n";
                        cout << "Enter the inside of the yogurt:\n"; cin >> inside;
                        cout << "Enter amount of product:\n"; cin >> amount;

                        yogurt = new Yogurt(name, produceDate, weight, price, shelfLife, amountCalories, fat, inside);
                        shelf.dateComparison(produceDate, shelfLife);
                        shelf.addProductFood(yogurt, amount);

                    } catch (exception& ex){
                        cout << ex.what() << endl;
                    }
                    break;
                case '2':
                    try {
                        cout << "You chose milk, let's add it to the shelf.\n";
                        cout << "Enter the name of the milk:\n"; cin >> name;
                        cout << "Production date input format example: DD/MM/YYYY.\n";
                        cout << "Enter production date:\n"; cin >> produceDate;
                        cout << "Weight is calculated in grams and cannot be less than 0.\n";
                        cout << "Enter weight:\n"; cin >> weight;
                        cout << "The price is calculated in dollars and cannot be less than 0.\n";
                        cout << "Enter price:\n"; cin >> price;
                        cout << "Shelf life input format example: DD/MM/YYYY.\n";
                        cout << "Enter shelf life:\n"; cin >> shelfLife;
                        cout << "Calories are counted in kcal and cannot be less than 0.\n";
                        cout << "Enter amount calories:\n"; cin >> amountCalories;
                        cout << "The fat content of yogurt is not less than 0% and not more than 14%.\n";
                        cout << "Enter fat:\n"; cin >> fat;
                        cout << "Milk is stored in a package.\n"
                                "For example cardboard, plastic bottle, glass and others.\n";
                        cout << "Enter package type:\n"; cin >> packageType;
                        cout << "Enter amount of product\n"; cin >> amount;

                        milk = new Milk(name, produceDate, weight, price, shelfLife, amountCalories, fat, packageType);
                        shelf.dateComparison(produceDate, shelfLife);
                        shelf.addProductFood(milk, amount);

                    } catch (exception& ex){
                        cout << ex.what() << endl;
                    }
                    break;
                case '3':
                    try {
                        cout << "You chose sweet, let's add it to the shelf.\n";
                        cout << "Enter the name of the sweet:\n"; cin >> name;
                        cout << "Production date input format example: DD/MM/YYYY.\n";
                        cout << "Enter production date:\n"; cin >> produceDate;
                        cout << "Weight is calculated in grams and cannot be less than 0.\n";
                        cout << "Enter weight:\n"; cin >> weight;
                        cout << "The price is calculated in dollars and cannot be less than 0.\n";
                        cout << "Enter price\n"; cin >> price;
                        cout << "Shelf life input format example: DD/MM/YYYY.\n";
                        cout << "Enter shelf life:\n"; cin >> shelfLife;
                        cout << "Calories are counted in kcal and cannot be less than 0.\n";
                        cout << "Enter amount calories:\n"; cin >> amountCalories;
                        cout << "You can choose different type of sweets.\n"
                                "For example chocolate, candy, marshmallows, waffles and others.\n";
                        cout << "Enter sweet type:\n"; cin >> sweetType;
                        cout << "Sweet is stored in a package.\n"
                                "For example cardboard, foil, plastic box and others\n";
                        cout << "Enter package type:\n"; cin >> packageType;
                        cout << "Enter amount of product\n"; cin >> amount;

                        sweet = new Sweet(name, produceDate, weight, price, shelfLife, amountCalories, sweetType, packageType);
                        shelf.dateComparison(produceDate, shelfLife);
                        shelf.addProductFood(sweet, amount);

                    } catch (exception& ex){
                        cout << ex.what() << endl;
                    }
                    break;
                case '4':
                    cout << "Check the shelf life of the products added to the shelf.\n";
                    cout << "Enter today date:\n"; cin >> todayDate;
                    shelf.loseShelfLifeProductFood(todayDate);
                    break;
                case '6':
                    cout << "In this subsection, you can buy a product that is on the shelf\n";
                    cout << "Enter product name:\n";
                    cin >> name;
                    shelf.buyProduct(name);
                    break;
                case '7':
                    cout << "You have sold products worth " << shelf.getAmountMoney() << " $\n";
                    break;
                case '8':
                    cout << "Products on the shelf:\n";
                    shelf.printProductFood();
                    break;
                case '9':
                    cout << "Thank you for using the program. Goodbye!\n";
                    exit(0);
                default:
                    cout << endl;
                    cout << "You made the wrong choice";
                    cout << endl;
            }
    } while(selection != 0);

    return 0;
}

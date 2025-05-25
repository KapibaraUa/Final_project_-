#include <iostream>

using namespace std;

struct Product {
    int id;
    char name[50];
    char brand[50];
    float price;
    char category[50];
    char arrivalDate[11];
    char expiryDate[11];
};

void addProduct(Product inventory[], int& productCount) {
    if (productCount < 100) {
        Product p;
        p.id = productCount + 1;
        cout << "Enter product name: ";
        cin >> p.name;
        cout << "Enter brand: ";
        cin >> p.brand;
        cout << "Enter price: ";
        cin >> p.price;
        cout << "Enter category: ";
        cin >> p.category;
        cout << "Enter arrival date (YYYY-MM-DD): ";
        cin >> p.arrivalDate;
        cout << "Enter expiry date (YYYY-MM-DD): ";
        cin >> p.expiryDate;
        inventory[productCount++] = p;
        cout << "Product added successfully!" << endl;
    }
    else {
        cout << "Inventory full!" << endl;
    }
}

void removeProduct(Product inventory[], int id, int& productCount) {
    if (id > 0 && id <= productCount) {
        for (int i = id - 1; i < productCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        productCount--;
        cout << "Product removed successfully!" << endl;
    }
    else {
        cout << "Invalid product ID!" << endl;
    }
}

void searchProductByName(Product inventory[], const char* name, int productCount) {
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            cout << "Found: " << inventory[i].name << ", Price: " << inventory[i].price << endl;
        }
    }
}

void sortProductsByPrice(Product inventory[], int productCount) {
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = 0; j < productCount - i - 1; j++) {
            if (inventory[j].price > inventory[j + 1].price) {
                Product temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
}

void displayProducts(Product inventory[], int productCount) {
    if (productCount == 0) {
        cout << "Нет товаров на складе.\n";
        return;
    }
    cout << "ID       Название                                            Производитель                                      Цена       Категория                                            Дата поступ. Дата ист.\n";

    for (int i = 0; i < productCount; i++) {
        cout << inventory[i].id << " "
            << inventory[i].name << " "
            << inventory[i].brand << " "
            << inventory[i].price << " "
            << inventory[i].category << " "
            << inventory[i].arrivalDate << " "
            << inventory[i].expiryDate << endl;
    }
}

int main() {

}

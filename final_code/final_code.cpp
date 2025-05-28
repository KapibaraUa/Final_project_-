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


    for (int i = 0; i < productCount; i++) {
        cout << "ID: " << inventory[i].id << " | "
             << "имя: " << inventory[i].name << " | "
             << "производитель: " << inventory[i].brand << " | "
             << "цена: " << inventory[i].price << " | "
             << "категория: " << inventory[i].category << " | "
             << "дата поступ.: " << inventory[i].arrivalDate << " | "
             << "дата ист.: " << inventory[i].expiryDate << endl;
    }


int main() {
    setlocale(LC_ALL, "");
    Product inventory[100];
    int productCount = 0;
    int choice;
    do {
        cout << "1. Add Product\n2. Remove Product\n3. Search Product by Name\n4. Sort Products by Price\n5. Display Products\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 6)
        {
            switch (choice) {
            case 1: addProduct(inventory, productCount); break;
            case 2: {
                int id;
                cout << "Enter product ID to remove: ";
                cin >> id;
                removeProduct(inventory, id, productCount);
                break;
            }
            case 3: {
                char name[50];
                cout << "Enter product name to search: ";
                cin >> name;
                searchProductByName(inventory, name, productCount);
                break;
            }
            case 4:
                sortProductsByPrice(inventory, productCount);
                cout << "Products sorted by price." << endl;
                break;
            case 5:
                displayProducts(inventory, productCount);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        }
        else
        {
            cout << "error number out of count" << endl;
        }

    } while (choice != 6);

    return 0;
}

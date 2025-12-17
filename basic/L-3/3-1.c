#include <stdio.h>

// Product structure
struct Product {
    int id;
    float price;
    char name[50];
};

// function to read product data
int readProduct(struct Product *p) {
    return scanf("%d %f %49s", &p->id, &p->price, p->name) == 3;
}

// function to display product data
void showProduct(struct Product p) {
    printf("\n--- Product Details ---\n");
    printf("Product ID: %d\n", p.id);
    printf("Price: %.2f\n", p.price);
    printf("Name: %s\n", p.name);
}

int main() {
    struct Product item;

    if (!readProduct(&item))
        return 1;

    showProduct(item);
    return 0;
}

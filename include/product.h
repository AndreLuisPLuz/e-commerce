#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct
{
    char* description;
    char* unit;
    unsigned available_stock;
    float sell_value;
}
product;

product* init_product(char* description, char* unit, unsigned stock, float value);

void free_product(product* product);

#endif
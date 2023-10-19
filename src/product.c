#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct
{
    char description[100];
    char unit[2];
    unsigned available_stock;
    float sell_value;
}
product;

product* init_product(char* description, char* unit, unsigned stock, float value)
{
    assert(strlen(description) < 100);
    assert(strlen(unit) < 2);

    product* new_product = malloc(sizeof(product));

    strcpy(new_product->description, description);
    strcpy(new_product->unit, unit);
    new_product->available_stock = stock;
    new_product->sell_value = value;

    return new_product;
}

void free_product(product* product)
{
    free(product);
}
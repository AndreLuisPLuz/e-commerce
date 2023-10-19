#ifndef CART_ITEM_H
#define CART_ITEM_H

#include "../include/product.h"

typedef struct cart_item
{
    product* item_product;
    unsigned quantity;
    float item_value;
    struct cart_item* next;
}
cart_item;

cart_item* init_cart_item(product* item_product, unsigned quantity);

void free_cart_item(cart_item* item);

void recursive_free_cart_item(cart_item* item);

void cart_append_forward(cart_item* item, cart_item* item_to_append);

#endif
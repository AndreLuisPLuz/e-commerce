#ifndef CART_H
#define CART_H

#include "../include/cart_item.h"

typedef struct
{
    unsigned size;
    float total_value;
    cart_item* head;
    cart_item* tail;
}
cart;

cart* init_cart();

void free_cart(cart* cart);

void append_cart_item(cart* cart, cart_item* item);

cart* get_nth_cart_item(cart* cart, unsigned n);

int get_cart_item_index(cart* cart, char* description);

void pop_nth_cart_item(cart* cart, unsigned n);

void pop_cart_item(cart* cart, char* description);

#endif
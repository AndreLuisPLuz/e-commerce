#include <stdlib.h>
#include "../include/product.h"

typedef struct cart_item
{
    product* item_product;
    unsigned quantity;
    float item_value;
    struct cart_item* next;
}
cart_item;

cart_item* init_cart_item(product* item_product, unsigned quantity)
{
    cart_item* new_cart_item = malloc(sizeof(cart_item));

    new_cart_item->item_product = item_product;
    new_cart_item->quantity = quantity;
    new_cart_item->item_value = item_product->sell_value * quantity;
    new_cart_item->next = NULL;

    return new_cart_item;
}

void free_cart_item(cart_item* item)
{
    free(item);
}

void recursive_free_cart_item(cart_item* item)
{
    if (item->next == NULL)
    {
        free(item);
    }
    else
    {
        recursive_free_cart_item(item->next);
        free(item);
    }
}

void cart_append_forward(cart_item* item, cart_item* item_to_append)
{
    if (item->next == NULL)
    {
        item->next = item_to_append;
    }
    else
    {
        cart_append_forward(item->next, item_to_append);
    }
}
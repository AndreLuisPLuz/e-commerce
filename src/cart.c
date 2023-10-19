#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "../include/cart_item.h"

typedef struct
{
    unsigned size;
    float total_value;
    cart_item* head;
    cart_item* tail;
}
cart;

cart* init_cart()
{
    cart* new_cart = malloc(sizeof(cart));

    new_cart->size = 0;
    new_cart->total_value = 0;
    new_cart->head = NULL;
    new_cart->tail = NULL;

    return new_cart;
}

void free_cart(cart* cart)
{
    if (cart->head != NULL)
    {
        recursive_free_cart_item(cart->head);
    }

    free(cart);
}

void append_cart_item(cart* cart, cart_item* item)
{
    cart_append_forward(cart->head, item);
    cart->size++;
}

cart* get_nth_cart_item(cart* cart, unsigned n)
{
    assert(n < cart->size);

    cart_item* current_item = cart->head;
    for (int i = 1; i < n; i++)
    {
        current_item = current_item->next;
    }

    return current_item;
}

int get_cart_item_index(cart* cart, char* description)
{
    bool item_found = false;
    unsigned count = 0;
    cart_item* current_item = cart->head;

    while(!item_found && count < cart->size)
    {
        if (strcmp(current_item->item_product->description, description) == 0)
        {
            item_found = true;
        }
        else{
            current_item = current_item->next;
            count++;
        }
    }

    return (item_found ? count : NULL);
}

void pop_nth_cart_item(cart* cart, unsigned n)
{
    assert(n < cart->size);

    cart_item* item = get_nth_cart_item(cart, n);

    if (n > 0)
    {
        cart_item* previous_item = get_nth_cart_item(cart, n-1);
        previous_item->next = item->next;
    }

    free_cart_item(item);
    cart->size--;
}

void pop_cart_item(cart* cart, char* description)
{
    int item_index = get_cart_item_index(cart, description);
    pop_nth_cart_item(cart, item_index);
}
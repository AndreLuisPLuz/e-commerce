#include <stdlib.h>
#include "../include/product.h"

typedef struct product_node
{
    product* product;
    product_node* next;
}
product_node;

typedef struct 
{
    unsigned size;
    product_node* head;
}
store_list;

product_node* init_product_node()
{
    product_node* node = malloc(sizeof(product_node));

    node->product = NULL;
    node->next = NULL;

    return node;
}

void free_product_node(product_node* node)
{
    free(node);
}

void recursive_free_product_node(product_node* node)
{
    if (node->next == NULL)
    {
        free(node);
    }
    else
    {
        recursive_free_cart_item(node->next);
        free(node);
    }
}

store_list* init_store_list()
{
    store_list* new_store_list = malloc(sizeof(store_list));

    new_store_list->size = 0;
    new_store_list->head = NULL;

    return new_store_list;
}

void free_store_list(store_list* list)
{
    // for (int i = 0; i < list->size; i++)
    // {
    //     free_product(list->product_list[i]);
    // }

    free(list);
}
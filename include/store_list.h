#ifndef STORE_LIST_H
#define STORE_LIST_H

#include "../include/product.h";

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

store_list* init_store_list();

void free_store_list(store_list* list);

#endif
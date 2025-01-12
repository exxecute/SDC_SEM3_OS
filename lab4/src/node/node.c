#include "node.h"

node_t* node_ctr(const char* name) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) {
        perror("Memory allocation failed");
        return NULL;
    }
    strncpy(new_node->name, name, NODE_MAX_NAME_LENGTH);
    new_node->next = NULL;
    return new_node;
}

void node_dtr(node_t* node) 
{
    free(node);
}

void node_insert_node(node_t** head, const char* name) 
{
    node_t* new_node = node_ctr(name);
    new_node->next = *head;
    *head = new_node;
}

node_t* node_find_node(node_t* head, const char* name) 
{
    while (head) 
    {
        if (strcmp(head->name, name) == 0) return head;
        head = head->next;
    }
    return NULL;
}

void node_delete_node(node_t** head, const char* name) 
{
    node_t* __temp = *head, *prev = NULL;

    while (__temp && strcmp(__temp->name, name) !=0) 
    {
        prev = __temp;
        __temp = __temp->next;
    }

    if (!__temp) return;

    if(!prev) 
    {
        *head = __temp->next;
    } 
    else 
    {
        prev->next = __temp->next;
    }
    node_dtr(__temp);
}

void node_free_list(node_t* head) 
{
    while (head) 
    {
        node_t* __temp = head;
        head = head->next;
        node_dtr(__temp);
    }
}

void node_print_list(node_t* head) 
{
    while (head) 
    {
        printf("%s", head->name);
        head = head->next;
        if (head) printf(", ");
    }
}

void node_print_node_info(node_t* node) 
{
    if (node) 
    {
        printf("Name: %s\n", node->name);
    } 
    else 
    {
        printf("Element not found.\n");
    }
}

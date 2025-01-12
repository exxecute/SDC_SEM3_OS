#ifndef NODE_H
#define NODE_H

#include <stdio.h>

#include <dirent.h>
#include <sys/stat.h>

#define NODE_MAX_NAME_LENGTH 0xff

typedef struct node_t {
    char name[NODE_MAX_NAME_LENGTH];
    struct node_t* next;
    ino_t inode;
    char type;
} node_t;

node_t* node_ctr(const char* name, ino_t inode, char date_time);
void node_dtr(node_t* node) ;

void node_insert_node(node_t** head, const char* name, ino_t inode, char type);
node_t* node_find_node(node_t* head, const char* name);
void node_delete_node(node_t** head, const char* name) ;
void node_print_list(node_t* head);
void node_free_list(node_t* head);
void node_print_node_info(node_t* node);

#endif // NODE_H
#include "directory_scanner.h"

#include "../node/node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define CONVERT_POINTER(pointer) ((directory_scanner_t)pointer)

typedef struct __directory_scanner
{
    node_t * list;
}__directory_scanner_t;

directory_scanner_t directory_scanner_ctr(void) 
{
    __directory_scanner_t* __directory_scanner = (__directory_scanner_t*)malloc(sizeof(__directory_scanner_t));
    __directory_scanner->list = NULL;
    return (__directory_scanner_t*)__directory_scanner;
}

void directory_scanner_dtr(directory_scanner_t directory_scanner) 
{
    node_free_list(directory_scanner->list);
    free(directory_scanner);
}

void directory_scanner_scan(directory_scanner_t directory_scanner, const char* dir_path) 
{
    __directory_scanner_t * ths = CONVERT_POINTER(directory_scanner);
    DIR* dir = opendir(dir_path);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent* entry;
    node_t* current = ths->list;

    node_free_list(ths->list);
    ths->list = NULL;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        node_insert_node(ths->list, entry->d_name);
    }

    closedir(dir);
}
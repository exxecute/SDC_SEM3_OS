#include "src/node/node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void scan_directory(node_t** head, const char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent* entry;
    node_t* current = *head;

    node_free_list(*head);
    *head = NULL;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        node_insert_node(head, entry->d_name);
    }

    closedir(dir);
}

int main(void)
{
    node_t* list = NULL;
    char dir_path[256] = "./";
    char input[256];
    int choice;

    while (1) {
        printf("\n1. Scan directory\n");
        printf("2. Print list\n");
        printf("3. Print element info\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter directory path (default is './'): ");
            fgets(dir_path, 256, stdin);
            dir_path[strcspn(dir_path, "\n")] = '\0';
            if (strlen(dir_path) == 0) strcpy(dir_path, "./");
            scan_directory(&list, dir_path);
            printf("Directory scanned successfully.\n");
            break;
            case 2:
                printf("list of elements:\n");
            node_print_list(list);
            break;
            case 3:
                printf("Enter element name: ");
            fgets(input, 256, stdin);
            input[strcspn(input, "\n")] = '\0';
            node_print_node_info(node_find_node(list, input));
            break;
            case 4:
                node_free_list(list);
            printf("Exiting...\n");
            exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
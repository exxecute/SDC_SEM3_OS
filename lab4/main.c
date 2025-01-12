#include "src/directory_scanner/directory_scanner.h"

int main(void)
{
    directory_scanner_t directory_scanner = directory_scanner_ctr();
    char dir_path[256] = "./";
    char input[256];
    int choice;

    char __is_tui = 1;

    while (__is_tui) {
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
                directory_scanner_scan(directory_scanner, dir_path);
                printf("Directory scanned successfully.\n");
                break;
            case 2:
                printf("list of elements:\n");
                directory_scanner_print(directory_scanner);
                break;
            case 3:
                printf("Enter element name: ");
                fgets(input, 256, stdin);
                input[strcspn(input, "\n")] = '\0';
                directory_scanner_print_directory_indo(directory_scanner, input);
                break;
            case 4:
                printf("Exiting...\n");
                __is_tui = 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    directory_scanner_dtr(directory_scanner);

    return 0;
}
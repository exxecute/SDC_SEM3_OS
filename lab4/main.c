#include "src/directory_scanner/directory_scanner.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum tui_variants
{
    TUI_SCAN = 0,
    TUI_PRINT_LIST,
    TUI_PRINT_ELEMENT_INFO,
    TUI_EXIT,
    TUI_LAST,
};

const static char* TUI_VARIANTS[TUI_LAST] = {
    "Scan directory",
    "Print list",
    "Print element info",
    "Exit",
};

int main(void)
{
    directory_scanner_t directory_scanner = directory_scanner_ctr();
    char dir_path[256] = "./";
    char input[256];
    int choice;

    char __is_tui = 1;

    while (__is_tui) {
        printf("\n");
        for(int tui_variant = TUI_SCAN; tui_variant < TUI_LAST; tui_variant++)
        {
            printf("%d. %s\n", tui_variant + 1, TUI_VARIANTS[tui_variant]);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (--choice) {
            case TUI_SCAN:
            {
                printf("Enter directory path (default is './'): ");
                getchar();
                fgets(dir_path, 256, stdin);
                dir_path[strcspn(dir_path, "\n")] = '\0';
                if (strlen(dir_path) == 0) strcpy(dir_path, "./");
                directory_scanner_scan(directory_scanner, dir_path);
                printf("Directory scanned successfully.\n");
                break;
            }
            case TUI_PRINT_LIST:
            {
                printf("List: ");
                directory_scanner_print(directory_scanner);
                printf("\n");
                break;
            }
            case TUI_PRINT_ELEMENT_INFO:
            {
                printf("Enter element name: ");
                getchar();
                fgets(input, 256, stdin);
                input[strcspn(input, "\n")] = '\0';
                directory_scanner_print_directory_indo(directory_scanner, input);
                printf("\n");
                break;
            }
            case TUI_EXIT:
            {
                __is_tui = 0;
                break;
            }
            default:
            {
                printf("Please try again.\n");
                break;
            }
        }
    }

    directory_scanner_dtr(directory_scanner);

    return 0;
}
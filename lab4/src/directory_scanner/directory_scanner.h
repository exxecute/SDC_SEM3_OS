#ifndef DIRECTORY_SCANNER_H
#define DIRECTORY_SCANNER_H

typedef struct __directory_scanner * directory_scanner_t;

directory_scanner_t directory_scanner_ctr(void);
void directory_scanner_dtr(directory_scanner_t directory_scanner);
void directory_scanner_scan(directory_scanner_t directory_scanner, const char* dir_path);
void directory_scanner_print(directory_scanner_t directory_scanner);
void directory_scanner_print_directory_indo(directory_scanner_t directory_scanner, const char* name);

#endif // DIRECTORY_SCANNER_H
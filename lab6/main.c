#include "src/file_writer/file_writer.h"

int main(void)
{
    file_writer_write("test.txt", "Hello world!", 12);
    printf("Lines: %d\n", file_writer_count_lines("test.txt"));
    return 0;
}
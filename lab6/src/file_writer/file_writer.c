#include "file_writer.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct file_writer
{
    int file_descriptor;
} file_writer_t;

static void __file_writer_close(file_writer_t * file_writer);
static void __file_writer_open(file_writer_t * file_writer, char * path);

void file_writer_write(char * file, char * data, int size)
{
    file_writer_t file_writer;
    file_writer.file_descriptor = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(file_writer.file_descriptor, data, size);
    close(file_writer.file_descriptor);
}

void file_writer_count_lines(char * file)
{
    file_writer_t file_writer;
    file_writer.file_descriptor = open(file, O_RDONLY);
    int count = 0;
    char c;
    while (read(file_writer.file_descriptor, &c, 1) > 0) 
    {
        if (c == '\n') count++;
    }
    close(file_writer.file_descriptor);
    return count;
}

//Libraries
//Description of function
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int memory_alloc(int size, char **mem);
int file_handler(FILE **fp);
int write_data(int size, char *mem, FILE **fp);
int close_file(FILE **fp, char *mem);

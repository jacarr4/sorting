#ifndef IO_H
#define IO_H 1

#define LINE_SIZE 255
#define MAX_ARRAY_LEN 255
#include <stdio.h>
#include <stdlib.h>

int *read_input(char *input_filename, int *length);
void write_output(char *output_filename, int *array, int length);

#endif

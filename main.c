#include <stdio.h>
#include "io.h"
#include "sort.h"

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: ./main <input>.txt <output>.txt <sorting algorithm>\n");
        printf("Sorting algorithms: 0 - Bubble Sort\n");
        printf("                    1 - Merge Sort\n");
        return -1;
    }
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    int sorting_algo = atoi(argv[3]);

    if(sorting_algo < 0 || sorting_algo > 1) {
        printf("Please choose a valid sorting algorithm.\n");
        return -1;
    }

    int length;

    int *array = read_input(input_filename, &length);

    if(sorting_algo == 0) {
        bubble_sort(array, length);
    } else if(sorting_algo == 1) {
        merge_sort(array, length);
    }

    write_output(output_filename, array, length);

    free(array);

    return 0;
}

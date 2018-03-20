#include "io.h"

int *read_input(char *input_filename, int *length) {
    FILE *fp = fopen(input_filename, "r");
    
    char *line = (char *)malloc(LINE_SIZE * sizeof(char));
    fgets(line, LINE_SIZE, fp);
    
    int n = atoi(line);
    
    int *array = malloc(MAX_ARRAY_LEN * sizeof(int));
    int array_index = 0;
    int num;
    
    for(int i = 0; i < n; i++) {
        fgets(line, LINE_SIZE, fp);
        num = atoi(line);
        array[array_index] = num;
        array_index++;
        if(array_index >= MAX_ARRAY_LEN) break;
    }
    
    fclose(fp);
    
    *length = array_index;

    return array;
}

void write_output(char *output_filename, int *array, int length) {
    FILE *fp = fopen(output_filename, "w");
    
    for(int i = 0; i < length; i++) {
        fprintf(fp,"%d\n", array[i]);
    }

    fclose(fp);
}

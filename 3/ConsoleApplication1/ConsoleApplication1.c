
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bmp_reader.h"



void input_string(char** string)
{
    int char_;
    int i = 0;
    rewind(stdin);
    while ((char_ = getchar()) != EOF && char_ != '\n')
    {
        (*string)[i++] = char_;
        (*string) = (char*)realloc((*string), (i + 1) * sizeof(char));
    }
    (*string)[i] = '\0';
}

int main()
{

    char* file_name = (char*)calloc(1, 1);
    printf("Enter the path to the file\n");
    input_string(&file_name);


    BMPFile* bmpf = loadBMPFile(file_name);

    negativ(bmpf, file_name);
    black_white(bmpf, file_name);
    median_filter(bmpf, file_name);
    gamma_correction(bmpf, file_name);

    freeBMPFile(bmpf);
    return 0;
}



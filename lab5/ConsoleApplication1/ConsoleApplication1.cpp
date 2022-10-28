

#include <iostream>

int main()
{
    int* mas = NULL;
    mas = (int*)malloc(5 * sizeof(int));
    free(mas);
    free(mas);
}


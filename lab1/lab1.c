#include <conio.h>
#include <windows.h>
#include <malloc.h>
#include "struct.h"
#include "io.h"
#include "pars.h"
#include "del.h"
#include "sort.h"



int amount = 0;
 int sort_order = 0;

int str_len(char* string) {
   int i = 0;
   while (string[i] != '\0') i++;
        return i;
}

void memory_free_struct(anim** anime) {
    for (int i = 0; i < amount; i++) {
        free((*anime)[i].title);
    }
    free(*anime);
}

int main() {
    anim* anime = NULL;
    int n = 0;
//    printf("Enter a number of animes\n");
  //  scanf_s("%d", &n);

  //  anime = (anim*)malloc(n * sizeof(anim));
   //input_anim(n, anime);
    anime = (anim*)malloc(0, sizeof(anim));
   pars(&anime);
    printf("\033[0d\033[2J");
    int f = 0;
    while (!f) {
        printf("\n\033[0d\033[2J");
        printf("1.add new struct\n2.delete struct\n3.sort structures\n4.show structures\n5.end program\n");
        int num = 0;
        scanf_s("%d", &num);
        switch (num) {
        case 1 :
            printf("\033[0d\033[2J");
            anime = (anim*)realloc(anime, (amount + 1) * sizeof(anim));
            input_anim(1, anime);
            break;
        case 2:
            printf("\n\033[0d\033[2J");
            delete_sctruct(&anime);
            
            break;
        case 3:
            sorts(anime);
            break;
        case 4:
            printf("\033[0d\033[2J");
            checkout(anime);
            break;
        case 5:
            f = 1;
        }
    }
   

    
    memory_free_struct(&anime);
    return 0;

}
// геман попуск
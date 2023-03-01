#include "io.h"
extern int amount;

void input_string(char** string)
{
    int char_;
    int i = 0;
    (*string) = (char*)calloc(1, 1);

    rewind(stdin);
    while ((char_ = getchar()) != -1 && char_ != '\n')
    {
        i++;
        (*string) = (char*)realloc((*string), (i + 1) * sizeof(char));
        (*string)[i - 1] = char_;

    }
    (*string)[i] = '\0';

}


void input_anim(int n, anim* anime) {
    for (int i = 0; i < n; i++) {
        printf("title: ");
        input_string(&anime[amount].title);
        printf("year: ");
        scanf_s("%d", &(anime[amount]).year);
        printf("type: ");
        scanf_s("%d", &anime[amount].type);
        amount++;
        //printf("length: ");

    }
}


void checkout(anim* anime) {
    printf("your structures:\n\n");
    for (int i = 0; i < amount; i++) {
        printf("title: %s \nyear: %d\ntype: ", anime[i].title, anime[i].year);

        switch (anime[i].type)
        {
        case SERIAL:
            printf("TV serial\n");
            break;
        case FILM:
            printf("Film\n");
            break;
        case OVA:
            printf("OVA\n");
            break;
        case ONA:
            printf("ONA\n");
            break;
        case SPECIAL:
            printf("Special\n");
            break;

        }
        printf("\n");
    }
    printf("Press Enter to continue");
    int key = _getch();

    while (key != 13) {
        printf("\nunknown command\n");
        printf("Press Enter");
        key = _getch();
    }

}
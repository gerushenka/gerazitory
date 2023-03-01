#include "pars.h"

extern int amount;

void finput_string(char** string, FILE* animes)
{
    char char_;
    int i = 0;
    (*string) = (char*)calloc(255, sizeof(char));
    while ((char_ = fgetc(animes)) != '<')
    {
        i++;
        (*string)[i - 1] = char_;

    }
    (*string)[i] = '\0';
}
void find_year(FILE* animes) {
    char* mask = "<span class=\"misc\"><span class=\"right\">";
    int i = 0;
    char a;
    while (!feof(animes)) {
        a = fgetc(animes);
        if (a == mask[i]) {
            i++;
        }
        else {
            i = 0;
        }

        if (i == strlen(mask)) {
            break;
        }
    }
}

void in_struct(anim* anime, FILE* animes) {
    finput_string(&anime[amount].title, animes);
    int i = 0;
    find_year(animes);
    anime[amount].year = 0;
    char a;
    a = fgetc(animes);
    while (a != '<') {
        anime[amount].year *= 10;
        anime[amount].year += (int)a - 48;
        a = fgetc(animes);

    }
    //-48 -95 -48 -65 -48 -75 -47 -120 -48 -69 spec
    //-48 -92
    fseek(animes, 12, SEEK_CUR);
    char c = 0;
    int count = 0;
    while (c != '<') {
        c = fgetc(animes);
        count++;
    }
    fseek(animes, -10, SEEK_CUR);
    c = fgetc(animes);

    anime[amount].type = 0;
    if (count == 15)
        anime[amount].type = 0;
    if (count == 11) {
        anime[amount].type = 1;
        if ((int)c == -95) {
            anime[amount].type = 4;

        }
    }
    if (count == 4) {
        fseek(animes, -3, SEEK_CUR);
        char c = fgetc(animes);
        if (c == 'V')
        anime[amount].type = 2;
        else
            anime[amount].type = 3;

    }


}

void find_struct(FILE* animes, anim** anime) {
    char* mask = "<span class=\"name-en\">";
    int i = 0;
    int j = 0;
    char a;
    while (!feof(animes) && amount != 300) {

        a = fgetc(animes);

        if (a == mask[i]) {
            i++;
        }
        else {
            i = 0;
        }

        if (i == strlen(mask)) {
            (*anime) = (anim*)realloc((*anime), (amount + 1) * sizeof(anim));
            if (amount == 295) {
                j = 0;
            }
            in_struct(*anime, animes);
           
            amount++;

        }
    }
}

void pars(anim* anime) {
    FILE* animes;
    fopen_s(&animes, "anime.html", "r+t");
    fseek(animes, 0, SEEK_SET);
    find_struct(animes, anime);

    fclose(animes);

}
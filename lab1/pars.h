#pragma once
#include "struct.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void finput_string(char** string, FILE* animes);
void find_year(FILE* animes);
void in_struct(anim* anime, FILE* animes);
void find_struct(FILE* animes, anim** anime);
void pars(anim* anime);
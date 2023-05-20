#pragma once
#pragma pack(1)
typedef struct
{
  unsigned char ID[2];
  unsigned int file_size;
  unsigned char unused[4];
  unsigned int pixel_offset;
} BMPHeader;

typedef struct
{
    unsigned int header_size;
    unsigned int width;
    unsigned int height;
    unsigned short color_planes;
    unsigned short bits_per_pixel; 
    unsigned int comp;
    unsigned int data_size;
    unsigned int pwidth;
    unsigned int pheight;
    unsigned int colors_count;
    unsigned int imp_colors_count;
} DIBHeader;


typedef struct BMPFile {
    BMPHeader bhdr;
    DIBHeader dhdr;
    char* data;
}BMPFile;

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

#pragma pop
BMPFile* loadBMPFile(char* fname);
void freeBMPFile(BMPFile* bmp_file);
void negativ(BMPFile* bmp_file, FILE* fp);
void black_white(BMPFile* bmp_file, char* fname);
void gamma_correction(BMPFile* bmp_file, char* fname);
void median_filter(BMPFile* bmp_file, char* fname);
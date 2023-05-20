#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "bmp_reader.h"


BMPFile* loadBMPFile(char* fname) {
	FILE* fp = fopen(fname, "r");
	if (!fp) {
		printf("can't load file");
		exit(0);
	}
	BMPFile* bmp_file = (BMPFile*)malloc(sizeof(BMPFile));
	fread(&bmp_file->bhdr, sizeof(BMPHeader), 1, fp);
	fread(&bmp_file->dhdr, sizeof(DIBHeader), 1, fp);
	bmp_file->data = (unsigned char*)malloc(bmp_file->dhdr.data_size);
	fseek(fp, bmp_file->bhdr.pixel_offset, SEEK_SET);
	fread(bmp_file->data, sizeof(bmp_file->dhdr.data_size), 1, fp);
	fclose(fp);
	return(bmp_file);
}

void freeBMPFile(BMPFile* bmp_file) {
	if (bmp_file) {
		return(bmp_file);
	}
}


void to_header(char** image_data, BMPFile* bmp_file, FILE* fp, FILE* obrabotka) {
	fwrite(&bmp_file->bhdr, sizeof(BMPHeader), 1, obrabotka);
	fwrite(&bmp_file->dhdr, sizeof(DIBHeader), 1, obrabotka);
	fseek(obrabotka, bmp_file->bhdr.pixel_offset, SEEK_SET);
	fseek(fp, bmp_file->bhdr.pixel_offset, SEEK_SET);
    (*image_data) = (unsigned char*)malloc(sizeof(unsigned char) * bmp_file->dhdr.data_size);
	fread((*image_data), sizeof(unsigned char), bmp_file->dhdr.data_size, fp);


}
void correct_open(FILE* fp) {
	if (!fp) {
		printf("can't load file");
		exit(0);
	}
}
	
void negativ(BMPFile* bmp_file,char* fname) {
	FILE* fp = fopen(fname, "r");
	correct_open(fp);
	FILE* negativ = fopen("negativ.bmp", "wb");
	correct_open(negativ);
	unsigned char* image_data = NULL;
	to_header(&image_data, bmp_file, fp, negativ);
	for (int i = 0; i < bmp_file->dhdr.data_size; i++) {
		image_data[i] = 255 - image_data[i];
	}
	fwrite(image_data, sizeof(unsigned char), bmp_file->dhdr.data_size, negativ);
	fclose(negativ);
	fclose(fp);
}

void black_white(BMPFile* bmp_file, char* fname) {
	FILE* fp = fopen(fname, "r");
	correct_open(fp);
	FILE* bwf = fopen("black_white.bmp", "wb");
	correct_open(bwf);
	unsigned char* image_data = NULL;
	to_header(&image_data, bmp_file, fp, bwf);

	int brightness = 0;
	for (int i = 0; i < bmp_file->dhdr.data_size; i+=3) {
		brightness = 0.2126 * image_data[i+2] + 0.7152 * image_data[i + 1] + 0.0722 * image_data[i + 1];
		image_data[i] = brightness;
		image_data[i+1] = brightness;
		image_data[i+2] = brightness;
	}
	fwrite(image_data, sizeof(unsigned char), bmp_file->dhdr.data_size, bwf);
	fclose(bwf);
	fclose(fp);
}




void gamma_correction(BMPFile* bmp_file, char* fname) {
	printf("enter gamma: ");
	float gamma = 0;
	scanf("%f", &gamma);
	float inv_gamma = 1.0 / gamma;
	FILE* fp = fopen(fname, "r");
	correct_open(fp);
	FILE* gammaf = fopen("gamma_cor.bmp", "wb");
	correct_open(gammaf);
	unsigned char* image_data = NULL;
	to_header(&image_data, bmp_file, fp, gammaf);

	for (int i = 0; i < bmp_file->dhdr.data_size; i += 3) {
		float r = (float)image_data[i + 2];
		float g = (float)image_data[i + 1];
		float b = (float)image_data[i];
		r = powf(r / 255.0, inv_gamma) * 255.0;
		g = powf(g / 255.0, inv_gamma) * 255.0;
		b = powf(b / 255.0, inv_gamma) * 255.0;
		image_data[i + 2] = (short)r;
		image_data[i + 1] = (short)g;
		image_data[i] = (short)b;
	}
	fwrite(image_data, sizeof(unsigned char), bmp_file->dhdr.data_size, gammaf);
	fclose(gammaf);
	fclose(fp);
}



void swap(Pixel* a, Pixel* b) {
	Pixel temp = *a;
	*a = *b;
	*b = temp;
}

void sort(Pixel* arr, int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j].r > arr[j + 1].r) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

Pixel get_median_pixel(Pixel* pixels, int n) {
	sort(pixels, n);
	return pixels[n / 2];
}
int cmpfunc(const void* a, const void* b) {
	return (*(unsigned char*)a - *(unsigned char*)b);
}
void median_filter(BMPFile* bmp_file, char* fname) {
	printf("Enter kernel size (an odd number): ");
	int kernel_size;
	scanf("%d", &kernel_size);
	while (kernel_size % 2 == 0) {
		printf("Kernel size must be an odd number. Enter again: ");
		scanf("%d", &kernel_size);
	}

	FILE* fp = fopen(fname, "rb");

	correct_open(fp);

	FILE* median = fopen("median_filter.bmp", "wb");
	correct_open(median);

	unsigned char* image_data = NULL;
	to_header(&image_data, bmp_file, fp, median);
	int width = bmp_file->dhdr.width;
	int height = bmp_file->dhdr.height;
	int border_size = kernel_size / 2;
	for (int y = border_size; y < height - border_size; y++) {
		for (int x = border_size; x < width - border_size; x++) {
			int index = (y * width + x) * 3;

			unsigned char* kernel= (char*)malloc(kernel_size * kernel_size * 3 * sizeof(char));
			int kernel_index = 0;
			for (int ky = -border_size; ky <= border_size; ky++) {
				for (int kx = -border_size; kx <= border_size; kx++) {
					int pixel_index = ((y + ky) * width + (x + kx)) * 3;
					kernel[kernel_index++] = image_data[pixel_index];
					kernel[kernel_index++] = image_data[pixel_index + 1];
					kernel[kernel_index++] = image_data[pixel_index + 2];
				}
			}

			qsort(kernel, kernel_size * kernel_size, 3, cmpfunc);
			int median_index = (kernel_size * kernel_size) / 2 * 3;
			image_data[index] = kernel[median_index];
			image_data[index + 1] = kernel[median_index + 1];
			image_data[index + 2] = kernel[median_index + 2];
		}
	}

	fwrite(image_data, sizeof(unsigned char), bmp_file->dhdr.data_size, median);

	fclose(median);
	fclose(fp);
}
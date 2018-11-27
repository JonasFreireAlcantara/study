#include <stdio.h>
#include <string.h>


#define HEIGHT 28
#define WIDTH 28
#define BITS_PER_PIXEL 8


struct bmp_header {
	uint8_t signature[2];
	uint32_t file_size;
	uint32_t reserved;
	uint32_t data_offset;
};

struct info_header {
	uint32_t size;
	uint32_t width;	// Horizontal width of bitmap in pixels
	uint32_t height;// Vertical width of bitmap in pixels
	uint16_t planes;
	uint16_t bits_per_pixel;
	uint32_t compression;
	uint32_t image_size;
	uint32_t x_pixels_per_m;
	uint32_t y_pixels_per_m;
	uint32_t colors_used;
	uint32_t important_colors;
};

int main() {
	
	struct bmp_header* bmp_hdr = 
		(struct bmp_header*) malloc(sizeof(bmp_header));
		
	struct info_header* info_hdr = 
		(struct info_header*) malloc(sizeof(info_header));
		
	FILE* out_file = fopen('image.bmp', 'wb');
	FILE* in_file = fopen('train-images-idx3-ubyte', 'rb');
	
	strcpy()
	
	
	
	
	return 0;
}

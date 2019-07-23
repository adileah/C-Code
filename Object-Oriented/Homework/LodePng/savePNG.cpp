/*    @file savePNG.cpp   
      @author Paul Talaga & Andrew Greensted
      @date April 21, 2017
      
      Inspired from: http://www.labbookpages.co.uk/software/imgProc/libPNG.html

			@description Implements a function to write a char array to a png file.
			
			Be sure to compile with -lpng.
			Install libpng12-dev first:  sudo apt-get install libpng12-dev
*/

#include <cstdlib>  // for free
#include <png.h>

// Buffer should be a char array of size width*height*3.  This assumes an 8-bit
// color channel, RGB order, and no transparency.
int writePNGImage(const char* filename, unsigned width, unsigned height, char *buffer)
{
	int code = 0;
	FILE *fp = NULL;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;
	
	// Open file for writing (binary mode)
	fp = fopen(filename, "wb");
	if (fp == NULL) {
		fprintf(stderr, "Could not open file %s for writing\n", filename);
		code = 1;
		goto finalise;
	}

	// Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		fprintf(stderr, "Could not allocate write struct\n");
		code = 1;
		goto finalise;
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fprintf(stderr, "Could not allocate info struct\n");
		code = 1;
		goto finalise;
	}

	// Setup Exception handling
	if (setjmp(png_jmpbuf(png_ptr))) {
		fprintf(stderr, "Error during png creation\n");
		code = 1;
		goto finalise;
	}

	png_init_io(png_ptr, fp);

	// Write header (8 bit colour depth)
	png_set_IHDR(png_ptr, info_ptr, width, height,
			8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	png_write_info(png_ptr, info_ptr);

  // Write row by row by changing the pointer value
	for (unsigned y = 0 ; y < height ; y++) {
		png_write_row(png_ptr, (png_bytep)buffer + y * width * 3);
	}
	

	// End write
	png_write_end(png_ptr, NULL);

	finalise:
	if (fp != NULL) fclose(fp);
	if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
	if (row != NULL) free(row);

	return code;
}



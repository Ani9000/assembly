//circle in between
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
volatile int pixel_buffer_start; // global variable
void clear_screen();
void waiting();
void draw_line(int x0, int y0, int x1, int y1, short int color);
void plot_pixel(int x, int y, short int line_color);
void swap(int * a, int * b);

void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void clear_screen(){

	for(int x = 0; x < 320; x++){
		for(int y = 0; y < 240; y++){
			plot_pixel(x, y, 0x0);
		}
	}
}

void drawCircle(int xc, int yc, int x, int y) 
{ 
    plot_pixel(xc+x, yc+y, 0x001F); 
    plot_pixel(xc-x, yc+y, 0x001F); 
    plot_pixel(xc+x, yc-y, 0x001F); 
    plot_pixel(xc-x, yc-y, 0x001F); 
    plot_pixel(xc+y, yc+x, 0x001F); 
    plot_pixel(xc-y, yc+x, 0x001F); 
    plot_pixel(xc+y, yc-x, 0x001F); 
    plot_pixel(xc-y, yc-x, 0x001F); 
} 
  
// Function for circle-generation 
// using Bresenham's algorithm 
void circleBres(int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y); 
    } 
} 



int main(void)
{
	 int increment = 1;
	int EndOfScreen = 0;
	
    volatile int * pixel_ctrl_ptr = (int *)0xFF203020;
    /* Read location of the pixel buffer from the pixel buffer controller */
    pixel_buffer_start = *pixel_ctrl_ptr;

    clear_screen();

    circleBres(150, 100, 40);    // function call 

	
	while(1){
	}
	return 0;
}

void plot_pixel(int x, int y, short int line_color)
{
    *(short int *)(pixel_buffer_start + (y << 10) + (x << 1)) = line_color;
}

void waiting(){
    volatile int * pixel_ctrl_ptr = 0xFF203020;
    volatile int * status =(int *)0xFF20302C;

    *pixel_ctrl_ptr = 1;
	
    while((*status & 0x01) != 0) 
		status = status;
}    

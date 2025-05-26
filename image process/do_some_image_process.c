#include <stdlib.h>
#include <stdio.h>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"




int main(){
	const char* file_name="lenna.png";
	const char* saveout_file_name="lenna_edit.png";
	int w,h,c;//width,height,color_channel_num
	
	unsigned char* image_buffer=stbi_load(file_name,&w,&h,&c,0);
	
	
	
	printf("%d %d %d\n",w,h,c);
	
	//h*w*c
	
	unsigned char r,g,b;//red,green,blue
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			
			r=image_buffer[i*w*c+j*c];
			g=image_buffer[i*w*c+j*c+1];
			b=image_buffer[i*w*c+j*c+2];
			
			image_buffer[i*w*c+j*c]=b;
			image_buffer[i*w*c+j*c+2]=r;
			
			
		}
	}
	stbi_write_png(saveout_file_name, w,h,c,image_buffer,0);
	stbi_image_free(image_buffer);
	return 0;
}



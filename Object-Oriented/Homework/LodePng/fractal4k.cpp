/*    @file fractal1.cpp  
      @author < Fill me in>
      @date < Fill me in>

			@description < Fill me in>
*/

#include <iostream>
#include <string>
#include "savePNG.cpp"
#include "MyComplex.h"

// https://en.wikipedia.org/wiki/Newton's_method
void doNewton(MyComplex &point, unsigned &itter, unsigned max_itter){
  // These lines below are out of order!
  MyComplex old(1000,1000);
  itter = 0;
  while(point.dist2(old) > 0.001 && itter < max_itter){
  point = point - (point * point * point - MyComplex(1,0)) / (MyComplex(3,0) * point * point);
  old = point;
  itter++;
  } 
  
}

int main(){
  unsigned width = 800;  // Use 3840 for 4k
  unsigned height = 600;  // Use 2160 for 4k
  string filename = "fractal.png";
  
  char* image = new char[height * width *3];  // The stack isn't large enough
    // for the image, so we need to use the heap.
  
  double xmin = -10.0;
  double xmax = 10.0;
  double ymin = -10.0;
  double ymax = 10.0;
  
  for(unsigned x = 0; x < width; x++){
    for(unsigned y = 0; y < height; y++){
      MyComplex start((double)x/width * (xmax - xmin) + xmin,
                      ymax - (double)y/height * (ymax - ymin));
      unsigned itter = 0;
      doNewton(start, itter, 25);
      //cout << "Itter: " << itter << " ";
      //cout << "Start: " << start.getAsString() << endl;
      image[y * width * 3 + x * 3 + 0] = itter * 10;   // Red value  (char has max value 255)
      image[y * width * 3 + x * 3 + 1] = itter * 10;   // Green value
      image[y * width * 3 + x * 3 + 2] = itter * 10; // Blue value
      
    }
    if((x + 1)  % (width / 20) == 0) cout << "Done %: " << (x + 1) * 100 / width << endl;
  }
  
 
  
  // Writes the image array to a png file.  image is typecasted from a 3D
  // array to a 1D array with the same number of elements.
  writePNGImage(filename.c_str(), width, height, (char*)image);
  
   cout << "Done writing " << filename << endl;
   
  delete[] image;  // Return dynamic memory
  
  return 0;
}

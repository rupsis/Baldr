#ifndef _IMAGE_H_
#define _IMAGE_H_ 1

#include "rgb.h"
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

class Image {
 public:
  Image();
  // Initialize raster with default RGB color.
  Image(int width, int height);
  // Initialize raster 'background'.
  Image(int width, int height, rgb background);

  // Return false if X or Y are our of bounds, else true.
  bool set(int x, int y, const rgb &color);

  void gammaCorrect(float gamma);

  // output PPM image.
  void writePPM(out_of_range);

  void readPPM(string filename);

 private:
  rgb **raster;
  // Raster with & height
  int nx;
  int ny;
}

#endif  // _IMAGE_H_
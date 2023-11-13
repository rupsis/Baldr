#include "Image.h"
#include <iostream>

using namespace std;

// Unsigned, so only need to worry about upper bounds.
static unsigned int pixelClamp(unsigned int pixelColor) {
  if (pixelColor > 255)
    return 255;
  return pixelColor;
}

static float readPixel(char pixel) {
  return ((float)(unsigned char)pixel) / 255.0;
}

Image::Image() {}

Image::Image(int width, int height) {
  nx = width;
  ny = height;

  // Allocate memory for raster.
  raster = new rgb *[nx];
  for (int i = 0; i < nx; i++) {
    raster[i] = new rgb[ny];
  }
}

Image::Image(int width, int height, rgb background) {
  nx = width;
  ny = height;

  // Allocate memory for raster.
  raster = new rgb *[nx];
  for (int i = 0; i < nx; i++) {
    raster[i] = new rgb[ny];
    // set background color to each.
    for (int j = 0; j < ny; j++) {
      raster[i][j] = background;
    }
  }
}

bool Image::set(int x, int y, const rgb &color) {
  if (x > nx || x < 0)
    return false;
  if (y > ny || y < 0)
    return false;
  raster[x][y] = color;
}

void Image::gammaCorrect(float gamma) {
  rgb temp;

  // Power
  float p = 1.0 / gamma;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; i < ny; j++) {
      temp = raster[i][j];
      raster[i][j] = rgb(pow(temp.r(), p), pow(temp.g(), p), pow(temp.b(), p));
    }
  }
}

// output PPM image.
void Image::writePPM(ostream &out) {
  // PPM header information.
  // PPM's "Magic Number" P3 = text, P6 = byte format.
  out << "P6\n"
      // X, Y dimensions of the image.
      << nx << " " << ny
      << "\n"
      // number of color values.
      << "255\n";

  unsigned int ired, igreen, iblue;
  for (int i = ny - 1; i >= 0; i--) {
    for (int j = 0; j < nx; j++) {
      ired = (unsigned int)(256 * raster[j][i].r());
      igreen = (unsigned int)(256 * raster[j][i].g());
      iblue = (unsigned int)(256 * raster[j][i].b());

      out.put((unsigned char)pixelClamp(ired));
      out.put((unsigned char)pixelClamp(igreen));
      out.put((unsigned char)pixelClamp(iblue));
    }
  }
}

// Read in a binary PPM image.
void Image::readPPM(string file_name) {
  // Open file stream.
  ifstream in;
  in.open(file_name.c_str());
  if (!in.is_open()) {
    cerr << "Error -- Couldn't open file \'" << file_name << "\'. \n";
    exit(-1);
  }
  char ch, type;
  char red, green, blue;
  int cols, rows;
  int num;

  // Read the header first.
  in.get(ch);
  in.get(type);
  in >> cols >> rows >> num;

  nx = cols;
  ny = rows;

  // Allocate raster
  raster = new rgb *[nx];
  for (int i = ny - 1; i >= 0; i--) {
    for (int j = 0; j < nx; j++) {
      in.get(red);
      in.get(green);
      in.get(blue);
      raster[j][i] = rgb(readPixel(red), readPixel(green), readPixel(blue));
    }
  }
}

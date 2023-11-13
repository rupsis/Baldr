

#include "Image.h"
#include "Shape.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Vector3.h"
#include "rgb.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  HitRecord rec;
  bool is_hit;

  // Max t parameter for Ray(s)
  float tmax;

  // Viewing direction, -Z into screen
  Vector3 dir(0, 0, -1);

  //  Geometry Setup
  vector<Shape *> shapes;
  shapes.push_back(new Sphere(Vector3(250, 250, -1000), 150, rgb(0.2f, 0.2f, 0.8f)));
  shapes.push_back(new Triangle(Vector3(300.0f, 600.0f, -800),
                                Vector3(0.0f, 100.0f, -1000),
                                Vector3(450.0f, 20.0f, -1000),
                                rgb(0.2f, 0.2f, 0.8f)));
}
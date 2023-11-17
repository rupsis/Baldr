

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
  bool is_a_hit;

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
                                rgb(0.8f, 0.2f, 0.2f)));

  Image im(500, 500);

  // Loop over image and calculate hit record
  // TODO, update image to expose width / height
  for (int i = 0; i < 500; i++) {
    for (int j = 0; j < 500; j++) {
      tmax = 100000.0f;
      is_a_hit = false;
      Ray r(Vector3(i, j, 0), dir);

      //  Loop over Shapes
      for (int k = 0; k < shapes.size(); k++) {
        // TODO figure out time
        if (shapes[k]->hit(r, 0.00001f, tmax, 0, rec)) {
          tmax = rec.t;
          is_a_hit = true;
        }

        if (is_a_hit) {
          im.set(i, j, rec.color);
        }
        else {
          im.set(i, j, rgb(0.2, 0.2, 0.2));
        }
      }
    }
  }
  im.writePPM(cout);
}
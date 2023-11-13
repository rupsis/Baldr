#ifndef _SPHERE_H_
#define _SPHERE_H_ 1

#include "Ray.h"
#include "Shape.h"
#include "Vector3.h"
#include "rgb.h"

class Sphere : public Shape {
 public:
  Sphere(const Vector3 &_center, float _radius, const rgb &_color);
  //   BBox boundingBox() const;
  bool hit(const Ray &r, float tmin, float tmax, float time, HitRecord &record) const;
  bool shadowHit(const Ray &r, float tmin, float tmax, float time) const;

  Vector3 center;
  float radius;
  rgb color;
};

#endif
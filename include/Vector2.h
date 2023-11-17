#ifndef _VECTOR2_H_
#define _VECTOR2_H_ 1

#include <iostream>
#include <math.h>

using namespace std;

class Vector2 {
 public:
  Vector2() {}
  Vector2(float e0, float e1);
  Vector2(const Vector2 &v) {
    *this = v;
  };

  float x() const {
    return e[0];
  }
  float y() const {
    return e[1];
  }
  const Vector2 &operator+() const;

  Vector2 operator-() const;

  float operator[](int i) const {
    return e[i];
  }
  float &operator[](int i) {
    return e[i];
  }

  float length() const;
  float squaredLength() const;

  void makeUnitVector();

  void setX(float _x) {
    e[0] = _x;
  }
  void setY(float _y) {
    e[1] = _y;
  }

  float minComponent() const;
  float minAbsComponent() const;
  int indexOfMinComponent() const;
  int indexOfMinAbsComponent() const;

  float maxComponent() const;
  float maxAbsComponent() const;
  int indexOfMaxComponent() const;
  int indexOfMaxAbsComponent() const;

  friend bool operator==(const Vector2 &v1, const Vector2 &v2);
  friend bool operator!=(const Vector2 &v1, const Vector2 &v2);

  friend istream &operator>>(istream &is, Vector2 &t);
  friend ostream &operator<<(ostream &os, const Vector2 &t);

  friend Vector2 operator+(const Vector2 &v1, const Vector2 &v2);
  friend Vector2 operator-(const Vector2 &v1, const Vector2 &v2);
  friend Vector2 operator/(const Vector2 &vec, float scalar);
  friend Vector2 operator*(const Vector2 &vec, float scalar);
  friend Vector2 operator*(float scalar, const Vector2 &vec);

  Vector2 &operator=(const Vector2 &v2);
  Vector2 &operator+=(const Vector2 &v2);
  Vector2 &operator-=(const Vector2 &v2);
  Vector2 &operator*=(const float t);
  Vector2 &operator/=(const float t);

  friend Vector2 unitVector(const Vector2 &v);
  friend Vector2 minVector(const Vector2 &v1, const Vector2 &v2);
  friend Vector2 maxVector(const Vector2 &v1, const Vector2 &v2);

  float e[2];
};

inline Vector2::Vector2(float e0, float e1) {
  e[0] = e0;
  e[1] = e1;
}

inline const Vector2 &Vector2::operator+() const {
  return *this;
}

inline Vector2 Vector2::operator-() const {
  return Vector2(-e[0], -e[1]);
}

inline float Vector2::length() const {
  return sqrt(e[0] * e[0] + e[1] * e[1]);
}

inline float Vector2::squaredLength() const {
  return e[0] * e[0] + e[1] * e[1];
}

inline float Vector2::minComponent() const {
  float lowest = e[0];
  if (e[1] < lowest)
    lowest = e[1];
  return lowest;
}

inline float Vector2::minAbsComponent() const {
  float lowest = fabs(e[0]);
  if (fabs(e[1]) < lowest)
    lowest = fabs(e[1]);
  return lowest;
}

inline int Vector2::indexOfMinComponent() const {
  int index = 0;
  float lowest = e[0];

  if (e[1] < lowest) {
    lowest = e[1];
    index = 1;
  }

  return index;
}

inline int Vector2::indexOfMinAbsComponent() const {
  int index = 0;
  float lowest = fabs(e[0]);

  if (fabs(e[1]) < lowest) {
    lowest = fabs(e[1]);
    index = 1;
  }

  return index;
}

inline float Vector2::maxComponent() const {
  float largest = e[0];
  if (e[1] > largest)
    largest = e[1];
  return largest;
}

inline float Vector2::maxAbsComponent() const {
  float largest = fabs(e[0]);
  if (fabs(e[1]) > largest)
    largest = fabs(e[1]);
  return largest;
}

inline int Vector2::indexOfMaxComponent() const {
  int index = 0;
  float highest = e[0];

  if (e[1] > highest) {
    highest = e[1];
    index = 1;
  }

  return index;
}

inline int Vector2::indexOfMaxAbsComponent() const {
  int index = 0;
  float highest = fabs(e[0]);

  if (fabs(e[1]) > highest) {
    highest = fabs(e[1]);
    index = 1;
  }

  return index;
}

inline bool operator==(const Vector2 &v1, const Vector2 &v2) {
  if (v1.e[0] != v2.e[0])
    return false;
  if (v1.e[1] != v2.e[1])
    return false;

  return true;
}

inline bool operator!=(const Vector2 &v1, const Vector2 &v2) {
  return !(v1 == v2);
}

inline Vector2 operator+(const Vector2 &v1, const Vector2 &v2) {
  return Vector2(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1]);
}

inline Vector2 operator-(const Vector2 &v1, const Vector2 &v2) {
  return Vector2(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1]);
}

inline Vector2 operator/(const Vector2 &vec, float scalar) {
  return Vector2(vec.e[0] / scalar, vec.e[1] / scalar);
}

inline Vector2 operator*(const Vector2 &vec, float scalar) {
  return Vector2(vec.e[0] * scalar, vec.e[1] * scalar);
}

inline Vector2 operator*(float scalar, const Vector2 &vec) {
  return Vector2(scalar * vec.e[0], scalar * vec.e[1]);
}

inline Vector2 &Vector2::operator=(const Vector2 &v2) {
  e[0] = v2.e[0];
  e[1] = v2.e[1];
}

inline Vector2 &Vector2::operator+=(const Vector2 &v2) {
  *this = *this + v2;
  return *this;
}

inline Vector2 &Vector2::operator-=(const Vector2 &v2) {
  *this = *this - v2;
  return *this;
}

inline Vector2 &Vector2::operator*=(float t) {
  *this = *this * t;
  return *this;
}

inline Vector2 &Vector2::operator/=(float t) {
  *this = *this * t;
  return *this;
}

inline Vector2 unitVector(const Vector2 &v) {
  float length = v.length();
  return v / length;
}

inline Vector2 minVector(const Vector2 &v1, const Vector2 &v2) {
  Vector2 vec(v1);
  if (v2.x() < v1.x())
    vec.setX(v2.x());
  if (v2.y() < v1.y())
    vec.setY(v2.y());
  return vec;
}

inline Vector2 maxVector(const Vector2 &v1, const Vector2 &v2) {
  Vector2 vec(v1);
  if (v2.x() > v1.x())
    vec.setX(v2.x());
  if (v2.y() > v1.y())
    vec.setY(v2.y());
  return vec;
}

#endif

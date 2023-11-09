#ifndef _ONB_H_
#define _ONB_H_ 1

#include "Vector3.h"

class ONB {
 public:
  ONB(){};

  OND(const Vector3 &a, const Vector3 &b, const Vector3 &c) {
    U = a;
    V = b;
    W = c;
  }

  void intFromU(const Vector3 &u);
  void intFromV(const Vector3 &v);
  void intFromW(const Vector3 &w);

  void set(const Vector3 &a, const Vector3 &b, const Vector3 &c) {
    U = a;
    V = b;
    W = c;
  }

  // Calculate the ONB from 2 vectors.
  // First vector is the fixed vector (it's normalized)
  // Second is normalized, and it's direction can be adjusted.
  void intFromUV(const Vector3 &u, const Vector3 &v);
  void intFromVU(const Vector3 &v, const Vector3 &u);

  void intFromUW(const Vector3 &u, const Vector3 &w);
  void intFromWU(const Vector3 &W, const Vector3 &u);

  void intFromVW(const Vector3 &v, const Vector3 &w);
  void intFromWV(const Vector3 &w, const Vector3 &v);

  friend istream &operator>>(istream &is, ONB &t);
  friend ostream &operator<<(ostream &os, const ONB &t);
  friend bool operator==(const ONB &o1, const ONB &o2);

  // Get components from the ONB
  Vector3 u() const {
    return U;
  }
  Vector3 v() const {
    return V;
  }
  Vector3 w() const {
    return W;
  }

  Vector3 U, V, W;
}

#endif
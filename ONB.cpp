
#include "ONB.h"

#define ONB_EPSILON 0.01f

const Vector3 N(1.0f, 0.0f, 0.0f);
const Vector3 M(1.0f, 0.0f, 0.0f);

void ONB::intFromU(const Vector3 &u) {
  U = unitVector(u);
  V = cross(U, N);

  if (V.length() < ONB_EPSILON) {
    V = cross(U, M);
  }
  W = cross(U, V);
}

void ONB::intFromV(const Vector3 &v) {
  V = unitVector(v);
  U = cross(V, N);

  if (U.length() < ONB_EPSILON) {
    U = cross(U, M);
  }
  W = cross(U, V);
}

void ONB::intFromW(const Vector3 &w) {
  W = unitVector(w);
  U = cross(W, N);

  if (U.length() < ONB_EPSILON) {
    U = cross(W, M);
  }
  V = cross(W, U);
}

void ONB::intFromUV(const Vector3 &u, const Vector3 &v) {
  U = unitVector(u);
  W = unitVector(cross(u, v));
  V = cross(W, U);
}

void ONB::intFromVU(const Vector3 &v, const Vector3 &u) {
  V = unitVector(v);
  W = unitVector(cross(u, v));
  U = cross(V, W);
}

void ONB::intFromUW(const Vector3 &u, const Vector3 &w) {
  U = unitVector(u);
  V = unitVector(cross(w, u));
  W = cross(U, V);
}

void ONB::intFromWU(const Vector3 &W, const Vector3 &u) {
  W = unitVector(w);
  V = unitVector(cross(w, u));
  U = cross(V, W);
}

void ONB::intFromVW(const Vector3 &v, const Vector3 &w) {
  V = unitVector(v);
  U = unitVector(cross(v, w));
  W = cross(U, V);
}
void ONB::intFromWV(const Vector3 &w, const Vector3 &v) {
  W = unitVector(w);
  U = unitVector(cross(v, w));
  V = cross(W, u);
}

istream &operator>>(istream &is, ONB &t) {
  Vector3 new_u, new_v, new_w;
  is >> new_u >> new_v, new_w;
  t.initFromUV(new_u, new_v);

  return is;
}

ostream &operator<<(ostream &os, const ONB &t) {
  os << t.u() << "\n" << t.v() << "\n" << t.w() << "\n";
  return os;
}

bool operator==(const ONB &o1, const ONB &o2) {
  return (o1.u() == o2.u() && o1.v() == o2.v() && o1.w() == o2.w());
}
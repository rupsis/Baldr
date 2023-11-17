#ifndef _SAMPLE_H_
#define _SAMPLE_H_ 1

#include <math.h>

/*
 * Decoupling Sampling & filtering methods to be
 * able to play with combinations of both.
 */

class Vector2;

/* 2D sampling */
void random(Vector2 *samples, int num_samples);

// Jitter assumes num_samples is a perfect square.
void jitter(Vector2 *samples, int num_samples);

// Multi-Jitter assumes num_samples is a perfect square.
void multiJitter(Vector2 *samples, int num_samples);

void nrooks(Vector2 *samples, int num_samples);

void shuffle(Vector2 *samples, int num_samples);

/* 2D Filters */
void boxFilter(Vector2 *samples, int num_samples);

void tentFilter(Vector2 *samples, int num_samples);

void cublicSplineFilter(Vector2 *samples, int num_samples);

/* ID Sampling*/
void random(float *samples, int num_samples);

void jitter(float *samples, int num_samples);

void shuffle(float *samples, int num_samples);

/* Cubic Spline Filter helper methods */
inline float solve(float r) {
  float u = r;
  for (int i = 0; i < 5; i++) {
    u = (11.0f * r + u * u * (6.0f + u * (8.0f - 9.0f * u))) /
        (4.0f + 12.0f * u * (1.0f + u * (1.0f - u)));
  }
  return u;
}

inline float cubicFilter(float x) {
  if (x < 1.0f / 24.0f) {
    return pow(24 * x, 0.25f) - 2.0f;
  }
  else if (x < 0.5) {
    return solve(24.0f * (x - 1.0f / 24.0f) / 11.0f) - 1.0f;
  }
  else if (x < 23.0f / 24.0f) {
    return 1.0f - solve(24.0f * (23.0f / 24.0f - x) / 11.0f);
  }

  return 2 - pow(24.0f * (1.0f - x), 0.25f);
}

#endif
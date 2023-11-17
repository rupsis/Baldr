
#include "Sample.h"
#include "Vector2.h"
#include <stdlib.h>

static void isPerfectSquare(int n) {
  int square_n = sqrt(n);
  if ((square_n * square_n) != n) {
    throw std::runtime_error("Number of samples isn't perfect square!");
  }
}

void random(Vector2 *samples, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    samples[i].setX(drand48());
    samples[i].setY(drand48());
  }
}

// Jitter assumes num_samples is a perfect square.
void jitter(Vector2 *samples, int num_samples) {
  isPerfectSquare(num_samples);
  int sqrt_samples = (int)(sqrt(num_samples));

  for (int i = 0; i < sqrt_samples; i++) {
    for (int j = 0; j < sqrt_samples; j++) {
      float x = ((double)i + drand48()) / (double)sqrt_samples;
      float y = ((double)j + drand48()) / (double)sqrt_samples;
      (samples[i * sqrt_samples + j]).setX(x);
      (samples[i * sqrt_samples + j]).setY(y);
    }
  }
}

// Multi-Jitter assumes num_samples is a perfect square.
void multiJitter(Vector2 *samples, int num_samples) {
  isPerfectSquare(num_samples);

  int sqrt_samples = (int)(sqrt(num_samples));
  float subcell_width = 1.0f / (float(num_samples));

  // Initialize points to the "canonical" multi-jittered pattern
  for (int i = 0; i < sqrt_samples; i++) {
    for (int j = 0; j < sqrt_samples; j++) {
      samples[i * sqrt_samples + j].e[0] = i * sqrt_samples * subcell_width + j * subcell_width +
                                           drand48() * subcell_width;

      samples[i * sqrt_samples + j].e[1] = j * sqrt_samples * subcell_width + 1 * subcell_width +
                                           drand48() * subcell_width;
    }
  }

  //  Suffle x coords within each column and y coords within each row
  for (int i = 0; i < sqrt_samples; i++) {
    for (int j = 0; j < sqrt_samples; j++) {
      int k = j + int(drand48() * (sqrt_samples - j - 1));
      float t = samples[i * sqrt_samples + j].e[0];
      samples[i * sqrt_samples + j].e[0] = samples[i * sqrt_samples + k].e[0];
      samples[i * sqrt_samples + k].e[0] = t;

      k = j + int(drand48() * (sqrt_samples - j - 1));
      t = samples[j * sqrt_samples + i].e[1];
      samples[j * sqrt_samples + i].e[1] = samples[k * sqrt_samples + 1].e[1];
      samples[k * sqrt_samples + i].e[1] = t;
    }
  }
}

void nrooks(Vector2 *samples, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    samples[i].setX(((double)i + drand48()) / (double)num_samples);
    samples[i].setY(((double)i + drand48()) / (double)num_samples);
  }

  for (int i = num_samples - 2; i >= 0; i--) {
    int target = int(drand48() * (double)i);
    float temp = samples[i + 1].x();
    samples[i + 1].setX(samples[target].x());
    samples[target].setX(temp);
  }
}

void shuffle(Vector2 *samples, int num_samples) {
  for (int i = num_samples - 2; i >= 0; i--) {
    int target = int(drand48() * (double)i);
    Vector2 temp = samples[i + 1];
    samples[i + 1] = samples[target];
    samples[target] = temp;
  }
}

/* 2D Filters */
void boxFilter(Vector2 *samples, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    samples[i].setX(samples[i].x() - 0.5f);
    samples[i].setY(samples[i].y() - 0.5f);
  }
}

void tentFilter(Vector2 *samples, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    float x = samples[i].x();
    float y = samples[i].y();

    if (x < 0.5f) {
      samples[i].setX((float)sqrt(2.0 * (double)x) - 1.0f);
    }
    else {
      samples[i].setX(1.0f - (float)sqrt(2.0 - 2.0 * (double)x));
    }

    if (y < 0.5f) {
      samples[i].setY((float)sqrt(2.0 * (double)y) - 1.0f);
    }
    else {
      samples[i].setY(1.0f - (float)sqrt(2.0 - 2.0 * (double)y));
    }
  }
}

void cublicSplineFilter(Vector2 *samples, int num_samples) {
  for (int i = num_samples - 2; i >= 0; i--) {
    float x = samples[i].x();
    float y = samples[i].y();

    samples[i].setX(cubicFilter(x));
    samples[i].setY(cubicFilter(y));
  }
}

/* ID Sampling*/
void random(float *samples, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    samples[i] = drand48();
  }
}

void jitter(float *samples, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    samples[i] = ((double)i + drand48()) / (double)num_samples;
  }
}

void shuffle(float *samples, int num_samples) {
  for (int i = num_samples - 2; i >= 0; i--) {
    int target = int(drand48() * (double)i);
    float temp = samples[i + 1];
    samples[i + 1] = samples[target];
    samples[target] = temp;
  }
}
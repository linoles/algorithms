#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// UVa 11130 - Billiard bounces, O(1) на тест
int main()
{
  /*
    (тут A ~ 60°)
        w
    |/\‾‾‾‾‾|
    |\ \   \|
  h | \ •  /| h
    |  \  / |
    |___\/__|
        w
  */

  int w1, h1, v1, A1, s1;
  while (scanf("%d %d %d %d %d", &w1, &h1, &v1, &A1, &s1) && w1 != 0)
  {
    // Преобразуем целочисленные в double, чтоб не переводить их потом. И угол A сразу превращаем в радианы
    double w = w1, h = h1, v = v1, A = A1 * M_PI / 180.0, s = s1;

    double S = v * s / 2.0;                  // До остановки
    double Sx = S * cos(A), Sy = S * sin(A); // По осям

    int vert = 0, hor = 0;

    if (Sx >= w / 2.0)
      vert = 1 + (int)((Sx - w / 2.0) / w);

    if (Sy >= h / 2.0)
      hor = 1 + (int)((Sy - h / 2.0) / h);

    printf("%d %d\n", vert, hor);
  }

  return 0;
}
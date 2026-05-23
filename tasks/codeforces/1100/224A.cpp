#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 224A (1100) - Параллелепипед, O(n)
int main()
{
  int x, y, z; // Пусть x - S нижнего прямоугольника; y, z - S боковых
  scanf("%d %d %d", &x, &y, &z);

  // Пусть a, b - стороны нижнего прямоугольника, h - высота фигуры, тогда
  // ab = x, ah = y, bh = z
  for (int a = 1; a <= x; a++)
  {
    // ah = y  =>  h = y / a
    double h = (double)y / (double)a;
    // bh = z  =>  b = z / h
    double b = (double)z / (double)h;
    // Проверяем, целые ли получаются b и h,
    // а также выполняется ли ab = x
    if (floor(b) == ceil(b) && floor(h) == ceil(h) && a * b == x)
    {
      printf("%d", 4 * (a + (int)b + (int)h));
      return 0;
    }
  }

  return 0;
}
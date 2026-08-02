
#include <bits/stdc++.h>
using namespace std;

// Kattis betting, O(1)
int main()
{
  long double a;
  scanf("%Lf", &a);
  long double b = 100.0 - a;

  // Простая формула, вывод до 10 знаков после запятой
  printf("%.10Lf\n%.10Lf", 100.0 / a, 100.0 / b);

  return 0;
}
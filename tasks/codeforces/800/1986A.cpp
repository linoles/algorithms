#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Codeforces 1986A (800) - Ось X, O(n)
int main()
{
  int t, x1, x2, x3; // 1 ≤ t ≤ 10^3, 1 ≤ x1, x2, x3 ≤ 10
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &x1, &x2, &x3);

    // Сортируем за O(1)  :)
    if (x1 > x2)
      swap(x1, x2);
    if (x2 > x3)
      swap(x2, x3);
    if (x1 > x2)
      swap(x1, x2);
    
    // Решаем простым подбором с жадным алгоритмом
    int min_diff = x3 - x1;
    for (int i = x1; i <= x3; i++) {
      int diff = abs(x1 - i) + abs(x2 - i) + abs(x3 - i);
      if (min_diff > diff) min_diff = diff;
    }

    printf("%d\n", min_diff);
  }

  return 0;
}
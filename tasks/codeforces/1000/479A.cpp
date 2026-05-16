#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 479A (1000) - Выражение, O(1)
int main()
{
  int a, b, c, res = 0; // 1 ≤ a, b, c ≤ 10
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  // Также примитивное решение: подобрать лучшую операцию
  if (a >= b && a >= c)
    res = a * ((b + c > b * c) ? b + c : b * c); // a * (b + c)
  else if (b >= a && b >= c)
    if (a >= c)
      res = a * (b + c); // a * (b + c)
    else
      res = c * (a + b); // (a + b) * c
  else if (c >= a && c >= b)
    res = c * ((b + a > b * a) ? b + a : b * a); // (a + b) * c

  if (res > a * b * c)
    printf("%d", res);
  else
    printf("%d", a * b * c);

  return 0;
}
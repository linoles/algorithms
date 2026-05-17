#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1992A (800) - Одни плюсы, O(1), т.к. цикл с константной границей
int main()
{
  int t, a, b, c; // 1 ≤ t ≤ 1000, 1 ≤ a, b, c ≤ 10
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &a, &b, &c);

    // 5 раз находим наименьшее и увеличиваем его
    for (int i = 0; i < 5; i++)
    {
      if (b <= a && b <= c)
        b++;
      else if (a <= b && a <= c)
        a++;
      else if (c <= a && c <= b)
        c++;
    }

    printf("%d\n", a * b * c);
  }

  return 0;
}
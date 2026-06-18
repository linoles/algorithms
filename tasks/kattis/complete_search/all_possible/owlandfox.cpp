#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis owlandfox, O(n * log10 n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    // Сумма цифр в n
    int s = 0, cpy = n;
    while (cpy > 0)
    {
      s += cpy % 10;
      cpy /= 10;
    }

    // Сложно оценить временную сложность выполнения этого цикла
    // Хоть мы и понимаем, что он быстро завершится, но получается, что рамки: [INT_MIN; n - 1],
    // поэтому это всё-таки O(n)
    for (int x = n - 1;; x--)
    {
      // Считаем сумму цифр в этом числе
      int xs = 0, cpy = x;
      while (cpy > 0)
      {
        xs += cpy % 10;
        cpy /= 10;
      }

      if (s - xs == 1)
      {
        printf("%d\n", x);
        break;
      }
    }
  }

  return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// UVa 11254 - Consecutive Integers, O(√n)
int main()
{
  int n;
  while (scanf("%d", &n) && n != -1)
  {
    // Сумма арифм. прогрессии:
    // S(n) = (a[0] + a[n - 1]) / 2 * n = (2 * a[0] + n - 1) / 2 * n
    // 2 * a[0] + n - 1 = S * 2 / n  =>  a[0] = (S * 2 / n - n + 1) / 2
    // a[0] + a[n - 1] = S * 2 / n  =>  a[n - 1] = S * 2 / n - a[0]

    // Перебираем кол-во членов последовательности с √2n до 1
    for (double r = floor(sqrt(2 * n)); r >= 1; r--)
    {
      // Находим первый член последовательности с шагом 1, суммой n и r членов
      double a1 = ((double)n * 2.0 / (double)r - (double)r + 1.0) / 2.0;
      // Если a1 - целое число
      if (floor(a1) == ceil(a1))
      {
        // Находим последний член и выводим
        int an = n * 2 / r - (int)a1;
        printf("%d = %d + ... + %d\n", n, (int)a1, an);
        break;
      }
    }
  }

  return 0;
}
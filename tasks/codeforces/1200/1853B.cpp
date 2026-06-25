#include <bits/stdc++.h>
using namespace std;

// Codeforces 1853B - Фибоначчарсис, O(n * min(k, ~45))
int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);

    /*
    Для любой посл. Фибоначчи все элементы выражаются через первые два:
      f[1] = x
      f[2] = y
      f[3] = x + y
      f[4] = x + 2y
      f[5] = 2x + 3y
      f[6] = 3x + 5y ...
    f[i] = fibo[i - 2] * x + fibo[i - 1] * y, где
    fibo - последовательность Фибоначчи (fibo[1] = 1, fibo[2] = 2, fibo[x] = fibo[x - 1] + fibo[x - 2])

    В итоге надо найти кол-во пар (x, y), при которых f[k] = n, то есть
    fibo[k - 2] * x + fibo[k - 1] * y = n и 0 <= x <= y
    */

    int ans = 0;
    // Перебираем первый элемент - x
    for (int i = 1; i <= n; i++)
    {
      int y = n, x = i;
      bool ok = 1;
      // Восстанавливаем последовательность назад: f[k - j - 2] = f[k - j] - f[k - j - 1]
      for (int j = 0; j < k - 2 && ok; j++)
      {
        int fx = x;
        x = y - fx;
        y = fx;
        ok &= x <= y;         // Своеобразная замена if: неубывание
        ok &= min(x, y) >= 0; // Своеобразная замена if: неотрицательность
      }
      if (ok)
        ans++;
    }

    printf("%d\n\n", ans);
  }

  return 0;
}

// Решение с разбора, т.к. я до этого не додумался
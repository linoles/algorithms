#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// UVa 00725 - Division, O(1)
int main()
{
  int n;
  while (true)
  {
    scanf("%d", &n);
    if (n == 0)
      break;

    // Перебираем x
    bool found = 0;
    for (int x = 1234; x <= 98765; x++)
    {
      // Получаем все цифры x
      int cpy = x, used_mask = 0;
      bool ok = 1;
      while (cpy > 0)
      {
        if (used_mask & (1 << (cpy % 10)))
          ok = 0;
        used_mask |= (1 << (cpy % 10));
        cpy /= 10;
      }

      if (!ok)
        continue;

      // x / y = n  =>  y = x / n
      double y = (double)x / (double)n;

      if (ceil(y) == floor(y) && x != y)
      {
        // Получаем все цифры y
        int cpy = y;
        bool ok = 1;
        while (cpy > 0 && ok)
        {
          if (used_mask & (1 << (cpy % 10)))
            ok = 0;
          used_mask |= (1 << (cpy % 10));
          cpy /= 10;
        }

        // 1022 в случае, когда не использован 0 (ведущий)
        if (!ok || used_mask < 1022)
          continue;

        found = 1;
        printf("%05d / %05d = %d\n", x, (int)y, n);
      }
    }

    if (!found)
      printf("There are no solutions for %d.\n", n);
    printf("\n");
  }

  return 0;
}

// (Решение неверное)
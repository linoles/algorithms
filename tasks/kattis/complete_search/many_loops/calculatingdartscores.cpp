
#include <bits/stdc++.h>
using namespace std;

// Kattis calculatingdartscores, O(1)
int main()
{
  int n;
  scanf("%d", &n);

  // Перебираем все возможные комбинации бросков (1-3)
  for (int t1 = 0; t1 <= 3; t1++)
  {
    for (int p1 = 0; p1 <= 20; p1++)
    {
      if (t1 == 0 && p1 > 0)
        continue;
      if (t1 > 0 && p1 == 0)
        continue;

      int score1 = p1 * t1;
      if (score1 > n)
        continue;

      for (int t2 = 0; t2 <= 3; t2++)
      {
        for (int p2 = 0; p2 <= 20; p2++)
        {
          if (t2 == 0 && p2 > 0)
            continue;
          if (t2 > 0 && p2 == 0)
            continue;

          int score2 = p2 * t2;
          if (score1 + score2 > n)
            continue;

          for (int t3 = 0; t3 <= 3; t3++)
          {
            for (int p3 = 0; p3 <= 20; p3++)
            {
              if (t3 == 0 && p3 > 0)
                continue;
              if (t3 > 0 && p3 == 0)
                continue;

              int score3 = p3 * t3;

              // Проверяем, что не 0 бросков (хотя бы один бросок)
              if ((t1 == 0 && t2 == 0 && t3 == 0))
                continue;

              if (score1 + score2 + score3 == n)
              {
                // Выводим в порядке triple, double, single
                if (t1 == 3)
                  printf("triple %d\n", p1);
                if (t2 == 3)
                  printf("triple %d\n", p2);
                if (t3 == 3)
                  printf("triple %d\n", p3);
                if (t1 == 2)
                  printf("double %d\n", p1);
                if (t2 == 2)
                  printf("double %d\n", p2);
                if (t3 == 2)
                  printf("double %d\n", p3);
                if (t1 == 1)
                  printf("single %d\n", p1);
                if (t2 == 1)
                  printf("single %d\n", p2);
                if (t3 == 1)
                  printf("single %d\n", p3);
                return 0;
              }
            }
          }
        }
      }
    }
  }

  // Случай n == 0
  if (n == 0)
  {
    return 0;
  }

  printf("impossible\n");
  return 0;
}
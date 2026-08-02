
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1485A (1000) - Прибавляй и дели, O()
int main()
{
  int t, a, b;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &a, &b);

    // Если b = 1, то деление на 1 бесполезно
    int opers = 0;
    if (b == 1)
    {
      b++;
      opers++;
    }

    // Находим наименьшее кол-во операций такое, что a / (b + k) = 0
    int best_opers = INT_MAX;
    for (int k = 0; k <= 30; k++)
    {
      int temp = a; // temp - int => деление будет округляться вниз
      int cur_opers = 0;
      while (temp >= 1)
      {
        temp /= b + k;
        cur_opers++;
      }

      best_opers = min(best_opers, cur_opers + k);
    }

    printf("%d\n", opers + best_opers);
  }

  return 0;
}
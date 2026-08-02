
#include <bits/stdc++.h>
using namespace std;

// Kattis islands, O(1)
int main()
{
  int p;
  scanf("%d", &p);
  while (p--)
  {
    int a[13], t;
    scanf("%d", &t);
    for (int i = 0; i < 12; i++)
      scanf("%d", &a[i]);

    int res = 0;
    for (int i = 1; i < 11; i++)
      for (int j = i; j < 12; j++)
      {
        // Подпоследовательность будет непрерывной, i - начало, j - конец (индексы)
        int before = a[i - 1], after = a[j + 1];
        bool ok = 1;
        // Проверяем, является ли островом
        for (int x = i; x <= j; x++)
          if (a[x] <= before || a[x] <= after)
          {
            ok = 0;
            break;
          }

        if (ok)
          res++;
      }

    printf("%d %d\n", t, res);
  }

  return 0;
}
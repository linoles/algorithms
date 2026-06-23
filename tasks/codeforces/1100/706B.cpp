#include <bits/stdc++.h>
using namespace std;

// Codeforces 706B - Интересный напиток, O((m + n) * log n)
int main()
{
  int n, q, m;
  scanf("%d", &n);
  int x[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &x[i]);

  sort(x, x + n); // Сортируем для бинарного поиска

  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &m);

    // Классический бинарный поиск: ищем первый элемент из x >= m
    int lo = 0, hi = n, mid;
    while (lo < hi)
    {
      mid = (hi - lo) / 2 + lo;
      if (m < x[mid])
        hi = mid;
      else
        lo = mid + 1;
    }

    // Также можно просто printf("%d\n", upper_bound(x, x + n, m) - x);
    printf("%d\n", lo);
  }

  return 0;
}
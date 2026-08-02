
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1770A (1000) - Косия и доски, O(n²)
int main()
{
  int t, n, m;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &m);
    ll a[n + 1], b[m + 1];
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);
    for (int i = 0; i < m; i++)
      scanf("%lld", &b[i]);

    // Замечательная задача: n, m <= 100, поэтому O(n²) "в лоб" тоже подойдёт
    // Просто каждый операцию ищем минимум и присваиваем ему b[j], как по условию
    for (int i = 0; i < m; i++)
    {
      ll min_el = a[0];
      int min_ind = 0;
      for (int j = 0; j < n; j++)
        if (min_el > a[j])
        {
          min_el = a[j];
          min_ind = j;
        }

      a[min_ind] = b[i];
    }

    // Затем находим итоговую сумму
    ll sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];

    printf("%lld\n\n", sum);
  }

  return 0;
}
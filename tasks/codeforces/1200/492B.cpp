#include <bits/stdc++.h>
using namespace std;

// Codeforces 492B - Ваня и фонари, O(n * log n)
int main()
{
  int n, l;
  scanf("%d %d", &n, &l);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  sort(a, a + n);

  // Тут даже бинарный поиск не нужен, т.к. фонарей максимум всего 1000
  // Учитываем расстояние от начала улицы до первого и от последнего до конца
  double res = max(a[0], l - a[n - 1]);
  for (int i = 1; i < n; i++)
    res = max(res, ((double)a[i] - a[i - 1]) / 2.0);

  printf("%.10f", res);

  return 0;
}
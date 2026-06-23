#include <bits/stdc++.h>
using namespace std;

// UVa 11057 - Exact Sum, O(n * log n + n)
int main()
{
  int n, m;
  while (scanf("%d", &n) != EOF)
  {
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    scanf("%d", &m);

    // Для D&C всегда нужна сортировка
    sort(a, a + n);

    // l - первая книга, r - вторая
    int l = 0, r = n - 1;
    int best_l = -1, best_r = -1; // Храним лучшие для минимизации расстояния между ценами книг
    while (l < r)
    {
      if (a[l] + a[r] > m)
        r--;
      else if (a[l] + a[r] < m)
        l++;
      else
      {
        best_l = l;
        best_r = r;
        l++;
      }
    }

    printf("Peter should buy books whose prices are %d and %d.\n\n", a[best_l], a[best_r]);
  }

  return 0;
}
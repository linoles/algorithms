#include <bits/stdc++.h>
using namespace std;

// UVa 12192 - Grapevine, O(q * m * log n)
int main()
{
  int n, m, q, l, u;
  while (scanf("%d %d", &n, &m) && n != 0 && m != 0)
  {
    int a[505][505];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);

    scanf("%d", &q);

    while (q--)
    {
      scanf("%d %d", &l, &u);

      int best = 0;
      vector<int> boundary(m);

      // Для каждого столбца j находим первую строку, где значение >= l
      for (int j = 0; j < m; j++)
      {
        int lo = 0, hi = n - 1, ans = n;

        // Бинарный поиск
        while (lo <= hi)
        {
          int mid = (lo + hi) / 2;
          if (a[mid][j] >= l)
          {
            ans = mid;
            hi = mid - 1;
          }
          else
            lo = mid + 1;
        }

        boundary[j] = ans;
      }

      for (int j = 0; j < m; j++)
      {
        int i = boundary[j];

        // Если в столбце нет клеток >= l, пропускаем
        if (i == n)
          continue;

        // Также проверяем на то, чтобы значение не превышало макс. границу
        if (a[i][j] > u)
          continue;

        //
        int max_size = min(n - i, m - j);
        int lo = 1, hi = max_size, ans = 0;

        while (lo <= hi)
        {
          int mid = (lo + hi) / 2;

          // Чтобы проверить, что квадрат размера size с углом (i, j) полностью состоит из клеток <= U,
          // достаточно проверить только его нижний правый угол
          if (a[i + mid - 1][j + mid - 1] <= u)
          {
            ans = mid;
            lo = mid + 1;
          }
          else
            hi = mid - 1;
        }

        best = max(best, ans);
      }

      printf("%d\n", best);
    }

    printf("-\n");
  }

  return 0;
}
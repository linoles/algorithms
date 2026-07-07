#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, m, temp, q, lx, rx, ly, ry;
  scanf("%d %d", &n, &m);
  // Также сразу строим преф. суммы
  vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &temp);
      a[i + 1][j + 1] = a[i][j + 1] + a[i + 1][j] - a[i][j] + temp;
    }

  scanf("%d", &q);
  while (q--)
  {
    scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
    lx--, ly--; // Перевод в полуинтервалы
    printf("%lld\n", a[rx][ry] - a[rx][ly] - a[lx][ry] + a[lx][ly]);
  }

  return 0;
}
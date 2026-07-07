#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n

typedef long long ll;

int main()
{
  int n, m, q, lx, ly, rx, ry, d;
  scanf("%d %d", &n, &m);
  vector<vector<ll>> b(n + 1, vector<ll>(m + 1)), a(n, vector<ll>(m, 0));
  forn(i, n) forn(j, m) scanf("%lld", &b[i + 1][j + 1]);
  forn(i, n) forn(j, m) a[i][j] = b[i + 1][j + 1] - b[i][j + 1] - b[i + 1][j] + b[i][j];

  scanf("%d", &q);
  while (q--)
  {
    scanf("%d %d %d %d %d", &lx, &ly, &rx, &ry, &d);
    lx--, ly--;
    a[lx][ly] += d;
    if (lx < n && ry < m)
      a[lx][ry] -= d;
    if (rx < n && ly < m)
      a[rx][ly] -= d;
    if (rx < n && ry < m)
      a[rx][ry] += d;
  }

  vector<vector<ll>> res(n + 1, vector<ll>(m + 1, 0));
  forn(i, n) forn(j, m) res[i + 1][j + 1] = res[i + 1][j] + res[i][j + 1] - res[i][j] + a[i][j];

  forn(i, n)
  {
    forn(j, m) printf("%lld ", res[i + 1][j + 1]);
    printf("\n");
  }

  return 0;
}
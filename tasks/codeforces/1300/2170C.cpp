#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

// Codeforces 2170C - Частное и остаток, O(n * log n)
int main()
{
  int t, n;
  ll k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %lld", &n, &k);
    int q[n + 1], r[n + 1];
    forn(i, n) scanf("%d", &q[i]);
    forn(i, n) scanf("%d", &r[i]);

    // Чем больше q, тем меньше потолок для r
    sort(q, q + n, greater<int>());
    sort(r, r + n);

    // Если знать заранее qi и rj, то можно спокойно выбрать любое x, y, удовл. условию:
    // x = qi * y + rj для любого y > rj
    int j = 0;
    ll ans = 0;
    for (int i = 0; i < n && j < n; i++)
    {
      // x <= k  =>  qi * y + rj <= k, y > rj
      // Минимальное y = rj + 1: x = qi * (rj + 1) + rj <= k
      // qi * rj + qi + r <= k, rj * (qi + 1) <= k - qi, rj <= (k - qi) / (qi + 1)
      ll max_rj = (k - q[i]) / (q[i] + 1);
      if (r[j] <= max_rj) // В итоге пара (qi, rj) может существовать при rj <= (k - qi) / (qi + 1)
        ans++, j++;
    }

    printf("%lld\n\n", ans);
  }

  return 0;
}
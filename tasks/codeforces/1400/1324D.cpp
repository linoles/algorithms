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

// Codeforces 1324D - Пара тем, O(n * log n)
int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1], b[n + 1];
  forn(i, n) scanf("%d", &a[i]);
  forn(i, n) scanf("%d", &b[i]);

  // c - массив с разницами a и b
  int c[n + 1];
  forn(i, n) c[i] = a[i] - b[i];

  sort(c, c + n);

  ll ans = 0;
  // Перебираем i, а внутри находим j
  forn(i, n)
  {
    if (c[i] <= 0)
      continue;
    // Ищем первый cj >= -ci + 1
    int lo = 0, hi = n;
    while (lo < hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (c[mid] < -c[i] + 1)
        lo = mid + 1;
      else
        hi = mid;
    }
    ans += i - lo;
  }

  printf("%lld", ans);

  return 0;
}

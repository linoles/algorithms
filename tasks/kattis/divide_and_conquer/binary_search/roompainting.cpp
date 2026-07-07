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

// Kattis roompainting, O(m * log n)
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int a[n + 1], b[m + 1];
  forn(i, n) scanf("%d", &a[i]);
  forn(i, m) scanf("%d", &b[i]);

  sort(a, a + n);

  // Для каждого i бинарным поиском ищем первый aj > bi
  ll ans = 0;
  forn(i, m)
  {
    int lo = 0, hi = n;
    while (lo < hi)
    {
      int mid = (lo + hi) / 2;
      if (a[mid] < b[i])
        lo = mid + 1;
      else
        hi = mid;
    }

    // Добавляем именно лишнюю краску
    ans += a[lo] - b[i];
  }

  printf("%lld", ans);

  return 0;
}

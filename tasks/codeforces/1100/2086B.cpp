#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// O(1) благодаря префиксным суммам
ll sum(ll l, ll r, vector<ll> &pref, ll n)
{
  // Используем unsigned long long, чтоб не выйти за пределы LONG_LONG_MAX
  ull left = (ull)pref[n] * ((ull)l / n) + pref[l % n];      // Сумма 0...l
  ull right = (ull)pref[n] * ((ull)r / n) + pref[r % n + 1]; // Сумма 0...r+1
  return (ll)(right - left);                                 // sum(l, r) = sum(0, r+1) - sum(0, l)
}

// Codeforces 2086B - Большой массив и отрезки, O(log(n * k))
int main()
{
  int t, n, k;
  ll x;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %lld", &n, &k, &x);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // Заместо создания массива b, можно просто обусловиться, что b[i] = a[i % n], если i < n * k

    // Создаём и заполняем массив преф. сумм для получения суммы на отрезке за O(1)
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + a[i - 1];

    // Допустим, нужно получить сумму на промежутке [l...r], l = 5, r = 12:
    // На позиции x число в преф. суммах b будет pref[n] * (x / n) + pref[x % n + 1]
    // Т.е. sum(l, r) = (pref[n] * (r / n) + pref[r % n + 1]) - (pref[n] * (l / n) + pref[l % n])

    // Если подбирать просто l, тогда оптимальнее всего подобрать r = n * k - 1, чтобы получить макс. сумму
    // Простой бин. поиск:
    ll lo = -1, hi = (ll)n * k - 1;
    while (lo < hi)
    {
      ll mid = lo + (hi - lo + 1) / 2;
      if (sum(mid, (ll)n * k - 1, pref, n) >= x)
        lo = mid;
      else
        hi = mid - 1;
    }

    printf("%lld\n\n", lo + 1);
  }

  return 0;
}
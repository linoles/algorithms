#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1850E - Картон для картин, O(n * log(√c))
int main()
{
  int t, n;
  ll c;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %lld", &n, &c);
    int s[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &s[i]);

    // Чтобы добавить к квадрату NxN рамку WxW, нужно (w² + n)² картона
    // Бинарным поиском за O(log n) ищем w, внутри за O(n) ищем нужное c
    ll lo = 0, hi = ceill(sqrtl(c)); // Если n = 1, s = [0], то тут достигается макс. w = √c / 2
    while (lo < hi)
    {
      ll ans = 0, w = lo + (hi - lo) / 2;     // w = mid
      for (int i = 0; i < n && ans <= c; i++) // Считаем сумму
        ans += (2 * w + s[i]) * (2 * w + s[i]);

      if (ans >= c)
        hi = w;
      else if (ans < c)
        lo = w + 1;
    }

    printf("%lld\n\n", lo);
  }

  return 0;
}
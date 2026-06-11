#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1541B (1200) - Приятные пары, O(n * log n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    ll a[n + 2];
    for (int i = 1; i <= n; i++)
      scanf("%lld", &a[i]);

    // Перебираем все пары
    ll ans = 0;
    for (ll i = 1; i < n; i++)
    {
      // Первое возможное j
      ll j = a[i] - (i % a[i]);
      if (j <= i)
        j += ((i - j) / a[i] + 1) * a[i];

      for (; j <= n; j += a[i]) // Лучший шаг
        if (i < j && i + j == a[i] * a[j])
          ans++;
    }

    printf("%lld\n\n", ans);
  }

  return 0;
}
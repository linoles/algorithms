#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1000000007LL;

ll pow_mod(ll base, ll exp, ll mod)
{
  ll res = 1;
  while (exp > 0)
  {
    if (exp % 2 == 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    ll sum = 0;
    
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      sum += a[i];
    }

    // Находим непрерывный отрезок с максимальной суммой элементов
    // Пусть его сумма x. Добавляем к нему x, затем к получившемуся 2x, 4x... И так всего k раз
    // 1x, 2x, 4x, ...
    // S = x * (2^0 + 2^1 + 2^2 + ... + 2^(k-1)) = x * (2^k - 1)
    // Т.к. число огромное, получить его не получится, но пусть 10^9 + 7 = M, тогда:
    // S % M = ((x % M) * ((2^k % M) - 1 + M)) % M  (2^k возводим за O(log n))

    ll cur = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
      cur = (cur + a[i] > 0) ? (cur + a[i]) : 0;
      mx = max(mx, cur);
    }

    ll ans = ((mx % M) * ((pow_mod(2, k, M) % M) - 1 + M)) % M + sum;
    printf("%lld\n\n", (ans % M + M) % M);
  }
}

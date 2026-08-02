#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);
  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
  if (n <= 1)
  {
    printf("%d", a[0]);
    return 0;
  }
  // dp[i] = минимальное время на первых i клиентов
  vector<ll> dp(n+1, 0);
  dp[1] = a[0];
  dp[2] = min(dp[1] + a[1], (ll)b[0]);
  for (int i = 3; i <= n; i++)
    dp[i] = min({dp[i-1] + a[i-1], dp[i-2] + b[i-2], dp[i-3] + c[i-3]});
  printf("%lld", dp[n]);
}
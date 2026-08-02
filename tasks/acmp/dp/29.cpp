#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  // dp[i] = кол-во энергии на путь к i-ной платформе
  vector<ll> dp(n + 1, 0);
  dp[2] = abs(a[0] - ((n == 1) ? 0 : a[1]));
  for (int i = 3; i <= n; i++)
    dp[i] = min(dp[i - 1] + abs(a[i - 1] - a[i - 2]), dp[i - 2] + 3 * abs(a[i - 1] - a[i - 3]));

  printf("%lld", dp[n]);
}
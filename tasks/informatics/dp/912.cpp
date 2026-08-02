#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  // Если посл. длины n начать с нуля, вариантов будет dp[n-1]
  // Если начать с 1, то первые три цифры будут 100 или 110: вариантов 2dp[n-3]
  // Если начать с 

  vector<ll> dp(max(4, n + 1), 0);
  dp[1] = 2, dp[2] = 4, dp[3] = 7;
  for (int i = 4; i <= n; i++)
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  
  printf("%lld\n", dp[n]);
}

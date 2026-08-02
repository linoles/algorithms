#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  // Если уложить в начало B или C, будет по dp[n-1] вариантов
  // Если уложить в начало A, то следующим будет либо B или C, будет dp[n-2] вариантов

  vector<ll> dp(max(3, n + 1), 3);
  dp[2] = 8;
  for (int i = 3; i <= n; i++)
    dp[i] = 2 * dp[i-1] + 2 * dp[i-2];
  
  printf("%lld", dp[n]);
}
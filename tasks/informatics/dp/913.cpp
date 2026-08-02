#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  // Если уложить B в начало стопки длиной n, останется dp[n] вариантов
  // Если уложить A в начало стопки длиной n, останется dp[n-1] вариантов, т.к. в начале будут AB

  vector<ll> dp(max(3, n + 1), 2);
  dp[2] = 3;
  for (int i = 3; i <= n; i++)
    dp[i] = dp[i-2] + dp[i-1];
  
  printf("%lld", dp[n]);
}

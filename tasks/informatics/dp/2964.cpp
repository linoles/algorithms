#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, m, P;
  scanf("%d %d", &n, &m);
  vector<ll> dp(m, 0);
  scanf("%lld", &dp[0]);
  for (int j = 1; j < m; j++)
  {
    scanf("%d", &P);
    dp[j] = min(dp[j-1], (ll)P);
  }
  for (int i = 1; i < n; i++)
  {
    scanf("%d", &P);
    dp[0] = min(dp[0], (ll)P);
    for (int j = 1; j < m; j++)
    {
      scanf("%d", &P);
      dp[j] = P ? (dp[j-1] + dp[j]) : 0;
    }
  }
  if (dp[m-1] == 0) printf("Impossible");
  else printf("%lld", dp[m-1]);
}
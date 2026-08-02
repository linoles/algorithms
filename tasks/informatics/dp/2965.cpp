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
    dp[j] = dp[j-1] + P;
  }
  for (int i = 1; i < n; i++)
  {
    scanf("%d", &P);
    dp[0] = dp[0] + P;
    for (int j = 1; j < m; j++)
    {
      scanf("%d", &P);
      dp[j] = P + max(dp[j-1], dp[j]);
    }
  }
  printf("%lld", dp[m-1]);
}
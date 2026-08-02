#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<ll> dp(m, 1);
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      dp[j] = dp[j-1] + dp[j];
  
  printf("%lld", dp[m-1]);
}
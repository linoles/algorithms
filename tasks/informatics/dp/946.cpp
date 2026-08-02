#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<ll>> dp(n, vector<ll>(m, 0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
    {
      // В клетку (i, j) можно попасть из (i-1, j-2) или (i-2, j-1)
      if (j > 1)
        dp[i][j] += dp[i-1][j-2];
      if (i > 1)
        dp[i][j] += dp[i-2][j-1];
    }

  printf("%lld", dp[n-1][m-1]);
}
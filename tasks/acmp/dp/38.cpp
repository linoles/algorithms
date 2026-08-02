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

  // dp[i][j] - максимальная разница, которую может получит игрок, чей ход, на подмассиве a[i...j]
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
    dp[i][i] = a[i];

  for (int len = 2; len <= n; len++)
    for (int i = 0; i + len - 1 < n; i++)
    {
      int j = i + len - 1;
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    }

  printf("%d", (dp[0][n - 1] > 0) ? 1 : ((dp[0][n - 1] == 0) ? 0 : 2));
}
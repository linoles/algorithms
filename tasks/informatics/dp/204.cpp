#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);

  // dp[i][j] = длина НОП последовательностей a[1...i] и b[1...j]
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + 1;
      else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
    }
  
  printf("%d", dp[n][m]);
}
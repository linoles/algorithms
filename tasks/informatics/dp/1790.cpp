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
  vector<int> ans;
  int i = n, j = m;
  while (i > 0 && j > 0)
  {
    if (a[i-1] == b[j-1])
    {
      ans.push_back(a[i-1]);
      i--; j--;
    }
    else if (dp[i-1][j] >= dp[i][j-1]) i--;
    else j--;
  }
  reverse(ans.begin(), ans.end());
  
  for (int x : ans) printf("%d ", x);
}
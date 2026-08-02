#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, m, P;
  scanf("%d %d", &n, &m);
  ll dp[n][m];
  scanf("%lld", &dp[0][0]);
  for (int j = 1; j < m; j++)
  {
    scanf("%d", &P);
    dp[0][j] = dp[0][j-1] + P;
  }
  for (int i = 1; i < n; i++)
  {
    scanf("%d", &P);
    dp[i][0] = dp[i-1][0] + P;
    for (int j = 1; j < m; j++)
    {
      scanf("%d", &P);
      dp[i][j] = P + max(dp[i-1][j], dp[i][j-1]);
    }
  }
  
  printf("%lld\n", dp[n-1][m-1]);
  vector<char> res;
  int i = n-1, j = m-1;
  while (i > 0 && j > 0)
  {
    if (dp[i][j-1] >= dp[i-1][j]) {
      j--; res.push_back('R');
    }
    else {
      i--; res.push_back('D');
    }
  }
  while (i > 0) {
    i--; res.push_back('D');
  }
  while (j > 0) {
    j--; res.push_back('R');
  }
  for (int i = (int)res.size()-1; i >= 0; i--)
    printf("%c ", res[i]);
}
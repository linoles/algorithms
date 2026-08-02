#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);
  if (n == 0)
    return 0;
  vector<vector<ll>> dp(2, vector<ll>(n, 0));
  dp[0][0] = 1;
  int prev = 0;
  printf("1\n");
  for (int i = 1; i < n; i++)
  {
    dp[!prev][0] = 1, dp[!prev][i] = 1;
    printf("1 ");
    for (int j = 1; j < i; j++)
    {
      dp[!prev][j] = dp[prev][j - 1] + dp[prev][j];
      printf("%lld ", dp[!prev][j]);
    }
    printf("1\n");
    prev = !prev;
  }
}

/*
Неоптимизированная версия:

vector<vector<ll>> dp(n, vector<ll>(n, 0));
dp[0][0] = 1;
printf("1\n");
for (int i = 1; i < n; i++)
{
  dp[i][0] = 1, dp[i][i] = 1;
  printf("1 ");
  for (int j = 1; j < i; j++)
  {
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    printf("%lld ", dp[i][j]);
  }
  printf("1\n");
}
*/

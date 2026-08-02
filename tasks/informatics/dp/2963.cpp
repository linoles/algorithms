#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  // dp[i] = мин. операций, чтоб получить i
  vector<int> dp(max(4, n + 1), 0);
  dp[1] = 0, dp[2] = 1, dp[3] = 1;
  for (int i = 4; i <= n; i++)
    dp[i] = min({dp[i - 1] + 1,             // Прибавить 1 к прошлому
                 dp[i / 2] + (i % 2) + 1,   // Умножить какое-то на два и добавить остаток
                 dp[i / 3] + (i % 3) + 1}); // Умножить какое-то на три и добавить остаток

  printf("%d", dp[n]);
}
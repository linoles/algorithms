#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  // dp[i] = мин. операций, чтоб получить i
  vector<int> dp(max(4, n + 1), 0);
  dp[2] = 1, dp[3] = 1;
  for (int i = 4; i <= n; i++)
    dp[i] = min({dp[i - 1] + 1,             // Прибавить 1 к прошлому
                 dp[i / 2] + (i % 2) + 1,   // Умножить какое-то на два и добавить остаток
                 dp[i / 3] + (i % 3) + 1}); // Умножить какое-то на три и добавить остаток

  string ans;
  int cur = n;
  while (cur > 1)
  {
    if (cur % 3 == 0 && dp[cur] == dp[cur/3] + 1)
    {
      ans = '3' + ans;
      cur /= 3;
    }
    else if (cur % 2 == 0 && dp[cur] == dp[cur/2] + 1)
    {
      ans = '2' + ans;
      cur /= 2;
    }
    else
    {
      ans = '1' + ans;
      cur--;
    }
  }

  printf("%s", ans.c_str());
}
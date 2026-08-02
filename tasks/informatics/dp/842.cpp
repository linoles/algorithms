#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  // dp[i] = последняя цифра числа i в числах Фибоначчи
  vector<int> dp(n + 1, 1);
  for (int i = 2; i <= n; i++)
    dp[i] = (dp[i-2] + dp[i-1]) % 10;
  
  printf("%d\n", dp[n]);
}
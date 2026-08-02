#include <bits/stdc++.h>
using namespace std;

// Вывод __int128
void pr_int128(__int128 num)
{
  string str;
  while (num > 0)
  {
    str = char('0' + (num % 10)) + str;
    num /= 10;
  }
  printf("%s", str.c_str());
}

int main()
{
  int n;
  scanf("%d", &n);

  // Если начать бинарную строку длины n с 0, то вариантов будет dp[n-1]
  // Если начать её с 1, то следующее число будет 0 и вариантов будет dp[n-2]

  // dp[n] = кол-во способов построить такую последовательность
  vector<__int128> dp(max(3, n + 1), 0);
  dp[1] = 2, dp[2] = 3;
  for (int i = 3; i <= n; i++)
    dp[i] = dp[i - 2] + dp[i - 1];

  pr_int128(dp[n]);
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  if (n == 1)
  {
    printf("1\n");
    return 0;
  }
  else if (n == 2)
  {
    printf("2\n");
    return 0;
  }
  else if (n == 3)
  {
    printf("4\n");
    return 0;
  }

  // dp[i] = кол-во способов подняться на ступеньку i
  vector<ll> dp(n + 1, 0);
  dp[1] = 1, dp[2] = 2, dp[3] = 4;
  for (int i = 4; i <= n; i++)
    dp[i] = dp[i-3] + dp[i-2] + dp[i-1];

  // Кол-во способов подняться на n-ую ступеньку = кол-во способов спуститься с неё
  printf("%lld\n", dp[n]);
}
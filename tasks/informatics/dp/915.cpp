#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  // dp[i] = требуемая сумма для того, чтоб пройти первые i ступенек
  vector<int> dp(n + 1, 0);
  dp[1] = a[0];
  for (int i = 2; i <= n; i++)
    dp[i] = min(dp[i-2] + a[i-1], dp[i-1] + a[i-1]);

  printf("%d", dp[n]);
}
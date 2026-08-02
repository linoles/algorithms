#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // dp[i] = результат, если начать из точки i
    vector<int> dp(n, 0);
    for (int i = n-1; i >= 0; i--)
    {
      dp[i] = a[i];
      if (i + a[i] < n)
        dp[i] += dp[i + a[i]];
    }
    printf("%d\n\n", *max_element(dp.begin(), dp.end()));
  }
}
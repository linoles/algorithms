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

    // dp[i] = -1, если нельзя сделать первые i элементов неубывающей последовательностью,
    // иначе последний элемент
    vector<int> dp(n, 0);
    dp[1] = (a[0] / 10 <= a[0] % 10) ? (a[0] % 10) : a[0];
    for (int i = 2; i < n; i++)
    {
      // 1 вариант: оставить как есть, если следующее число не меньше текущего
      // 2 вариант: разделить, если next >= (x%10) >= (x/10) >= prev
      // иначе: -1
      if (dp[i-1] == -1)
        dp[i] = -1;
      else if (a[i-1] >= 10 && a[i] >= a[i-1] % 10 && a[i-1] % 10 >= a[i-1] / 10 && a[i-1] / 10 >= dp[i-1])
        dp[i] = a[i-1] % 10;
      else if (a[i-1] >= dp[i-1])
        dp[i] = a[i-1];
      else
        dp[i] = -1;
    }
    bool ans = dp[n-1] != -1 &&
              (a[n-1] >= dp[n-1] || (a[n-1] / 10 >= dp[n-1] && a[n-1] % 10 >= a[n-1] / 10));
    printf(ans ? "YES\n\n" : "NO\n\n");
  }
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  sort(a, a+n);

  if (n == 2) {
    printf("%d", a[1] - a[0]); return 0;
  }
  else if (n == 3) {
    printf("%d", a[2] - a[0]); return 0;
  }

  // dp[i] = минимальная суммарная длина ниточек, если ограничиваться первыми i гвоздиками
  vector<ll> dp(n+1, 0);
  dp[2] = a[1] - a[0];           // Обмотать первые два
  dp[3] = dp[2] + (a[2] - a[1]); // Обмотать 1 и 2, 2 и 3
  for (int i = 4; i < n; i++)
    // Каждый новый гвоздик можно либо соединить с предыдущим: dp[i-2] + (a[i-1] - a[i-2]),
    // либо со следующим: dp[i-1] + (a[i] - a[i-1])
    dp[i] = min(dp[i-2] + (a[i-1] - a[i-2]), dp[i-1] + (a[i] - a[i-1]));
  printf("%lld", dp[n] = dp[n-2] + (a[n-1] - a[n-2]));
}

//   0 2 4 10 12
// 0 0 2 4  6  6
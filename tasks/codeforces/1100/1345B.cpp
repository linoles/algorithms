#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);

    // dp[h] - сколько потребуется карт, чтоб построить пирамиду высоты h
    vector<ll> dp(2, 0);
    dp[1] = 2;
    int last = 1;
    while (dp[last] < n)
    {
      dp.push_back(dp[last] + last + (last + 1) * 2);
      last++;
    }

    ll rem = n, ans = 0;
    while (true)
    {
      int idx = dp.size() - 1;
      while (idx > 0 && dp[idx] > rem)
        idx--;
      if (idx == 0)
        break;
      rem -= dp[idx], ans++;
    }

    printf("%lld\n\n", ans);
  }
}
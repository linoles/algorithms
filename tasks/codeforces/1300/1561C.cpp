#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1561C - Самый нижний уровень, O()
int main()
{
  int t, n, k;
  ll temp;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    vector<pair<ll, ll>> c;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &k);
      ll req = 0;
      for (int j = 0; j < k; j++)
      {
        scanf("%lld", &temp);
        req = max(req, temp - j + 1);
      }
      c.push_back(make_pair(req, k));
    }

    sort(c.begin(), c.end());

    // Теперь идём по каждой пещере сначала. Предполагаем, что требуется max - k + 1 силы на первую
    ll power = 0, cur = 0;
    for (auto [req, cnt] : c)
    {
      if (cur < req)
      {
        power += req - cur;
        cur = req;
      }
      cur += cnt;
    }

    printf("%lld\n\n", power);
  }

  return 0;
}
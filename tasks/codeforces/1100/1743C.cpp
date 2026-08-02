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
    char s[n]; int a[n];
    scanf(" %s", &s);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int last_zero = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '0')
        last_zero = a[i];
      else if (s[i] == '1')
      {
        if (last_zero > a[i])
        {
          ans += last_zero;
          last_zero = a[i];
        }
        else
          ans += a[i];
      }
    }
    printf("%lld\n\n", ans);
  }
}

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
    int c[n];
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    sort(c, c+n);

    if (c[0] != 1) {
      printf("NO\n\n"); continue;
    }

    bool ok = 1;
    ll mx = 1;
    for (int i = 1; i < n && ok; i++)
    {
      if ((ll)c[i] > mx)
        ok = 0;
      mx += c[i];
    }
    printf(ok ? "YES\n\n" : "NO\n\n");
  }
}

// Каждое число в отсортированном массиве не должно превышать суммы предыдущих
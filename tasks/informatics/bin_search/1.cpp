#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне

typedef long long ll;
typedef vector<int> vi;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n + 1];
  forn(i, n) scanf("%d", &a[i]);

  int l = 1, r = a[n - 1] - a[0], ans = 0;
  while (l <= r)
  {
    int mid = l + (r - l) / 2;

    bool ok = 0;
    int cows = 1, last_pos = a[0];
    forab(i, 1, n) if (a[i] - last_pos >= mid)
    {
      cows++;
      last_pos = a[i];
      if (cows >= k)
      {
        ok = 1;
        break;
      }
    }

    if (ok)
    {
      ans = mid;
      l = mid + 1;
    }
    else
      r = mid - 1;
  }

  printf("%d", ans);

  return 0;
}
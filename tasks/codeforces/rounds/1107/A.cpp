#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define forab(i, a, b) for (int i = a; i <= b; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;

int main()
{
  int t, x, y;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &x, &y);

    printf((x % y == 0) ? "YES\n" : "NO\n");
  }
}
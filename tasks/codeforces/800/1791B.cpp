#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char s[n];
    scanf(" %s", &s);

    int x = 0, y = 0;
    bool ans = 0;
    for (int i = 0; i < n && !ans; i++)
    {
      if (s[i] == 'L') x--;
      if (s[i] == 'R') x++;
      if (s[i] == 'D') y--;
      if (s[i] == 'U') y++;
      if (x == 1 && y == 1) ans = 1;
    }
    printf(ans ? "YES\n" : "NO\n");
  }
}
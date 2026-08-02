#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, n, m;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &m);
    char s[n][m];
    for (int i = 0; i < n; i++)
      scanf("%s", &s[i]);

    bool ok = 1;

    for (int i = 0; i < n && ok; i++)
      for (int j = 0; j < m && ok; j++)
        if (s[i][j] == '1')
        {
          bool left = 1, top = 1;

          // Слева строка единиц
          for (int x = 0; x < j && left; x++)
            if (s[i][x] == '0')
              left = 0;

          // Или справа строка единиц
          for (int y = 0; y < i && top; y++)
            if (s[y][j] == '0')
              top = 0;

          if (!left && !top)
            ok = 0;
        }

    printf(ok ? "YES\n\n" : "NO\n\n");
  }
}
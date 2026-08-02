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
    char buffer[n + 1];
    scanf("%s", &buffer);
    string a = buffer;
    scanf("%s", &buffer);
    string b = buffer;

    int ans = 0, i = 0;
    while (i < n)
    {
      // MEX = 2
      if (a[i] != b[i])
      {
        ans += 2;
        i++;
      }
      // MEX = 1
      else if (a[i] == '0' && b[i] == '0')
      {
        // MEX следующего = 0
        if (i + 1 < n && a[i + 1] == '1' && b[i + 1] == '1')
        {
          ans += 2;
          i += 2;
        }
        // Берём один
        else
        {
          ans++;
          i++;
        }
      }
      // MEX = 0
      else
      {
        // MEX следующего = 1
        if (i + 1 < n && a[i + 1] == '0' && b[i + 1] == '0')
        {
          ans += 2;
          i += 2;
        }
        // Берём один
        else
          i++;
      }
    }

    printf("%d\n\n", ans);
  }
}

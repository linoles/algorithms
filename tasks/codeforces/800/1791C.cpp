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

    bool found = 0;
    int l = 0, r = n-1;
    while (l < r && !found)
    {
      int k = (s[l] - '0') + (s[r] - '0');
      if (k != 1)
      {
        printf("%d\n\n", r - l + 1);
        found = 1;
      }
      l++, r--;
    }
    if (!found && l > r) printf("0\n\n");
    else if (!found && l == r) printf("1\n\n");
  }
}
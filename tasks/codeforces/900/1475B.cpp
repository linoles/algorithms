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

    if (n % 2020 == 0 || n % 2021 == 0)
    {
      printf("YES\n");
      continue;
    }

    bool found = 0;
    for (int i = 0; i < n / 2021.0; i++)
    {
      int j = n - 2021 * i;
      if (j % 2020 == 0)
      {
        printf("YES\n");
        found = 1;
      }
    }

    if (!found)
      printf("NO\n");
  }

  return 0;
}
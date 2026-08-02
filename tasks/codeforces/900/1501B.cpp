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
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    vector<int> ans(n, 0);
    int cream = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      cream = max(cream, a[i]);

      if (cream > 0)
      {
        ans[i] = 1;
        cream--;
      }
    }

    for (int i = 0; i < n; i++)
      printf("%d ", ans[i]);
    printf("\n\n");
  }
}
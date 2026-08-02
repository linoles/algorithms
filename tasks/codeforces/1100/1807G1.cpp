#include <bits/stdc++.h>
using namespace std;

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

    // Теперь для каждого i в c нужно определить, можно ли составить число c[i],
    // используя предыдущие элементы массива c (имеющими индекс j < i)

    bool ok = 1;
    for (int i = 1; i < n && ok; i++)
    {
      int rem = c[i];
      for (int j = i-1; j >= 0 && rem > 0; j--)
        if (rem - c[j] >= 0)
          rem -= c[j];
      if (rem != 0) ok = 0;
    }
    printf(ok ? "YES\n\n" : "NO\n\n");
  }
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces Round 1100 A - Слаймы на прямой, O(n)
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

    // a[j] < x: a[j]++
    // a[j] > x: a[j]--
    // Нужно выбрать такое x, что max(a[n - 1] - a[x], a[x] - a[0]) минимальное
    int min_ind = 0, max_ind = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[min_ind] > a[i])
        min_ind = i;
      if (a[max_ind] < a[i])
        max_ind = i;
    }

    printf("%d\n\n", (int)ceil((double)(a[max_ind] - a[min_ind]) / 2.0));
  }

  return 0;
}
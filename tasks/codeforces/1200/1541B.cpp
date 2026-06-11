#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1541B (1200) - Приятные пары, O()
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

    // Максимальная сумма двух индексов = 2n - 1
    for (int i = 0; i < n; i++)
      if (a[i] > 2 * n - 1)
        a[i] = -1;
    
    printf("%c", a[n]);
  }

  return 0;
}
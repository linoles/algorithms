#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1368A (800) - C+=, O(n) (я не уверен)
int main()
{
  int t, n, a, b; // 1 ≤ t ≤ 100, 1 ≤ a, b ≤ n ≤ 10^9
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &a, &b, &n);

    // Пока получили нужное a или b прибавляем большее к меньшему
    int res = 0;
    while (a <= n && b <= n)
    {
      res++;
      if (b >= a)
        a += b;
      else
        b += a;
    }

    printf("%d\n", res);
  }

  return 0;
}
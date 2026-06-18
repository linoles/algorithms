#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis easiest, O()
int main() {
  int n;
  while (scanf("%d", &n) && n != 0)
  {
    int sum = 0, cpy = n;
    while (cpy > 0)
    {
      sum += cpy % 10;
      cpy /= 10;
    }
    for (int p = 11;; p++)
    {
      int res = p * n, res_sum = 0;
      while (res > 0)
      {
        res_sum += res % 10;
        res /= 10;
      }

      if (res_sum == sum)
      {
        printf("%d\n", p);
        break;
      }
    }
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Codeforces 750A - Новый год и спешка, O(n)
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  
  int sum = 0, res = 0;
  for (int i = 1; i <= n; i++)
  {
    // Всего времени 4 * 60 = 240 мин
    if (sum + 5 * i > 240 - k)
      break;
    sum += 5 * i;
    res++;
  }

  printf("%d", res);

  return 0;
}
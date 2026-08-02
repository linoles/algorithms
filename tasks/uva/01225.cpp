
#include <bits/stdc++.h>
using namespace std;

// UVa 01225 - Digit Counting, O(n * log10 n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);

    vector<int> d(10, 0); // Кол-во встреч
    for (int i = 1; i <= n; i++)
    {
      // Проходимся по цифрам
      int cpy = i;
      while (cpy > 0)
      {
        d[cpy % 10]++;
        cpy /= 10;
      }
    }

    for (int i = 0; i < 9; i++)
      printf("%d ", d[i]);
    printf("%d\n", d[9]);
  }

  return 0;
}
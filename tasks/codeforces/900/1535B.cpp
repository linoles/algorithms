

#include <bits/stdc++.h>
using namespace std;

// Codeforces 1535B (900) - Переупорядочение массива, O(n²)
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

    // Когда a[i] кратно 2, то gcd(a[i], 2 * a[j]) >= 2
    // Когда a[i] не кратно 2, то gcd(a[i], 2 * a[j]) = gcd(a[i], a[j])
    // Поэтому лучше расположить чётные числа в начале, а затем остальные
    vector<int> sorted(a, a + n);
    int last_even = -1;
    for (int i = 0; i < n; i++)
      if (sorted[i] % 2 == 0)
      {
        swap(sorted[i], sorted[last_even + 1]);
        last_even++;
      }

    // Теперь просто считаем кол-во подходящих пар
    int res = 0;
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
        if (gcd(sorted[i], 2 * sorted[j]) > 1)
          res++;

    printf("%d\n", res);
  }

  return 0;
}
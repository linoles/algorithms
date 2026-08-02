
#include <bits/stdc++.h>
using namespace std;

// Codeforces 467B (1100) - Федя и новая игра, O(n * log2(max(x)))
int main()
{
  int n, m, k, res;
  scanf("%d %d %d", &n, &m, &k);
  int x[m + 2];
  for (int i = 0; i < m + 1; i++)
    scanf("%d", &x[i]); // Я не сделал решение сразу тут, т.к. не знаем самого Федю до конца ввода

  // Проходимся по каждому
  for (int i = 0; i < m; i++)
  {
    // Считаем, сколько битов отличается
    int diff_bits = 0;
    for (int j = 0; j < max(ceil(log2(x[m]) + 1), ceil(log2(x[i]) + 1)); j++)
    {
      // a >> b сдвигает a на b бит влево,
      // a >> b & 1 сохраняет только бит b в числе a, считая справа налево
      if ((x[i] >> j & 1) != (x[m] >> j & 1))
        diff_bits++;
    }
    if (diff_bits <= k)
      res++;
  }

  printf("%d", res);

  return 0;
}
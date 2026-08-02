

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1891B (1100) - Дежавю, O(n * k), макс. k = 30, поэтому решение приемлемо
int main()
{
  int t, n, q;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &q);
    ll a[n + 1];
    int x[q + 1];
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);
    for (int i = 0; i < q; i++)
      scanf("%d", &x[i]);

    // Если число делится на 2^k, оно делится на все 2^m такие, что m <= k
    // После прибавления к числу 2^(x[i]-1), оно перестаёт делиться на 2^(x[i]),
    // но продолжает делиться на меньшие степени

    // Например: a[j] = 48, делится на 2^4
    // 48 + 2^3 = 56. 56 уже не делится на 2^4, но кратно 2^3

    // Поэтому после обработки n из x все последующие не делятся на 2^(x+k), k >= 0
    // Убираем ненужные элементы x, чтобы useful_x была убывающей последовательностью
    vector<int> useful_x;
    int last = 100;
    for (int i = 0; i < q; i++)
    {
      if (x[i] < last)
      {
        useful_x.push_back(x[i]);
        last = x[i];
      }
    }

    for (int xi : useful_x)
      // Сами операции
      for (int i = 0; i < n; i++)
        // 1LL = (ll)1, 1LL << n = (ll)2^n
        if (a[i] % (1LL << xi) == 0)
          a[i] += 1LL << (xi - 1);

    for (int i = 0; i < n; i++)
      printf("%lld ", a[i]);
    printf("\n\n");
  }

  return 0;
}
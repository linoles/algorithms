#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces Round 1100 B - Это шедевр!, O()
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    ll a[n + 1], b[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++)
      scanf("%lld", &b[i]);

    // Ищем максимальный элемент a и b
    int a_max_ind = 0;
    for (int i = 1; i < n; i++)
      if (a[a_max_ind] < a[i])
        a_max_ind = i;
    int b_max_ind = 0;
    for (int i = 1; i < n; i++)
      if (b[b_max_ind] < b[i])
        b_max_ind = i;

    // Так как нам нужен макс. элемент среди двух массивов, меняем,
    // только если требуется и это возможно сделать операцией (swap(a[x], b[x]))
    if (a[a_max_ind] < b[b_max_ind] && a_max_ind == b_max_ind)
      swap(a[a_max_ind], b[b_max_ind]);

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      // Затем меняем элементы местами, если на этом месте в b стоит большее число
      if (i != a_max_ind && a[i] > b[i])
        swap(a[i], b[i]);
      sum += b[i]; // и сразу считаем итоговую сумму b
    }

    printf("%d\n\n", sum + a[a_max_ind]);
  }

  return 0;
}
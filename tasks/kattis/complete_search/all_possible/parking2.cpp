#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis parking2, O(n * log n)
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

    sort(a, a + n);

    // Самое выгодное место - ровно между первым и последним магазином
    int st = (a[n - 1] - a[0]) / 2 + a[0];

    int res = st - a[0]; // Сколько пройти от машины до первого магазина
    // Затем идти по магазинам в порядке возрастания координаты
    for (int i = 1; i < n; i++)
      res += a[i] - a[i - 1];
    // Затем дойти от последнего магазина до машины
    res += a[n - 1] - st;

    printf("%d\n", res);
  }

  return 0;
}
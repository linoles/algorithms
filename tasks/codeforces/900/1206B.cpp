#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  // Нужно превратить все числа в -1 или 1. Но чисел равных -1 должно быть чётное кол-во
  int cnt = 0, mx = INT_MIN, zeros = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] <= -1)
    {
      cnt++;
      mx = max(a[i], mx);
    }
    else if (a[i] == 0)
      zeros++;
  }

  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] <= -1)
      res += -1 - a[i];
    else
      res += abs(1 - a[i]);
  }

  // Если кол-во чисел, которые превратили в -1 нечётное, то одно из чисел превращаем из -1 в 1
  if (cnt % 2 != 0 && zeros == 0)
    res += 2;

  printf("%lld", res);
}
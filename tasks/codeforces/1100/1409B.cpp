#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1409B (1100) - Минимальное произведение, O(1)
int main()
{
  int t;
  ll a, b, x, y, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%lld %lld %lld %lld %lld", &a, &b, &x, &y, &n);

    // Перебираем варианты
    // Первый вариант: сначала уменьшаем b до упора, потом тем, что осталось, уменьшаем a
    ll var1_a = a, var1_b = b, var1_n = n;
    ll diff = (var1_a - x >= var1_n) ? var1_n : var1_a - x;
    var1_a -= diff;
    var1_n -= diff;

    if (var1_n > 0)
    {
      diff = (var1_b - y >= var1_n) ? var1_n : var1_b - y;
      var1_b -= diff;
      var1_n -= diff;
    }

    diff = (b - y >= n) ? n : b - y;
    b -= diff;
    n -= diff;

    // Второй вариант: сначала уменьшаем a до упора, потом тем, что осталось, уменьшаем b
    if (n > 0)
    {
      diff = (a - x >= n) ? n : a - x;
      a -= diff;
      n -= diff;
    }

    // Сравниваем варианты, присваиваем лучший
    if ((ll)(var1_a * var1_b) < (ll)(a * b))
    {
      a = var1_a;
      b = var1_b;
    }

    printf("%lld\n\n", (ll)(a * b));
  }

  return 0;
}
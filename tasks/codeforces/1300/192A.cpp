#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 192A - Модные числа, O(√n * log √n)
int main()
{
  int n;
  scanf("%d", &n);

  bool found = 0;
  // Перебираем первое k
  for (int k = 1; k < sqrt(n) && !found; k++)
  {
    // Пусть m - число из формулы второго треугольника, тогда
    // n = k(k + 1)/2 + m(m + 1)/2  =>  m(m + 1) = 2n - k(k + 1)
    // Бинарным поиском ищем m
    ll lo = 0, hi = ceil(sqrt(n)) * 2;
    while (lo < hi)
    {
      ll mid = lo + (hi - lo) / 2;
      if (mid * (mid + 1) < 2 * (ll)n - (ll)k * (k + 1))
        lo = mid + 1;
      else
        hi = mid;
    }

    // Если оба числа подобраны правильно
    if (lo * (lo + 1) == 2 * (ll)n - (ll)k * (k + 1))
      found = 1;
  }

  printf(found ? "YES" : "NO");

  return 0;
}

// Всего 142302 итераций при n = 1e9
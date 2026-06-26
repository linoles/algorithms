#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXP = 1000000; // Ограничение простого делителя (√x <= 10^6)
bitset<MAXP + 1> isPrime; // Используем bitset для скорости

// Поиск простых чисел решетом Эратосфена за O(MAXP log log mAXP)
void sieve()
{
  isPrime.set(); // Устанавливаем все биты true
  isPrime[0] = isPrime[1] = 0; // 0 и 1 - не простые

  for (int i = 2; i * i <= MAXP; i++)
    if (isPrime[i]) // Если i - простое
      for (int j = i * i; j <= MAXP; j += i)
        isPrime[j] = 0; // Тогда вычёркиваем все кратные i
}

// Codeforces 230B - Т-простые числа, O(n)
int main()
{
  sieve();

  int n;
  ll x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &x); // А когда не %lld?

    // Т-простым числом может быть только квадрат простого числа, тогда у него будет три делителя:
    // 1, √x, x. Поэтому мы просто делаем предподсчёт решетом Эратосфена

    // Ищем корень и корректируем из-за погрешности double
    ll r = sqrtl(x);
    while ((r + 1) * (r + 1) <= x)
      r++;
    while (r * r > x)
      r--;

    // Проверяем условие
    if (r * r == x && r <= MAXP && isPrime[r])
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
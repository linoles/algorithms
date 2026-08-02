#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

// UVa 00410 - Station Balance, O(n * log n)
int main()
{
  int c, s, count = 0;
  while (scanf("%d %d", &c, &s) != EOF)
  {
    vi a(s);
    forn(i, s) scanf("%d", &a[i]);

    printf("Set #%d\n", ++count);

    // Заполняем нулями до размера 2C
    while (s < 2 * c)
    {
      s++;
      a.push_back(0);
    }

    // Сортируем результат
    sort(all(a));

    vi res(c);
    double sum = 0;
    forn(i, c)
    {
      // В c[i] кладём a[i] и a[s - i - 1]
      printf("%2d:", i);
      res[i] = a[i] + a[s - i - 1];
      sum += res[i];

      // Если один из них 0, то просто не выводим его
      if (a[i])
        printf(" %d", a[i]);
      if (a[s - i - 1])
        printf(" %d", a[s - i - 1]);
      printf("\n");
    }

    // Считаем дизбаланс
    double am = sum / c, imb = 0;
    forn(i, c) imb += abs(res[i] - am);

    printf("IMBALANCE = %.5lf\n\n", imb);
  }

  return 0;
}
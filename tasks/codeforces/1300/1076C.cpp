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

// Codeforces 1076C - Мемная задача, O(1)
int main()
{
  int t, d;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &d);

    // Если a + b = d, a * b = d, тогда a, b - корни x² - d * x + d = 0
    // Дискриминант будет D = d² - 4 * d = d(d - 4)

    int D = d * (d - 4);
    // Если дискриминант меньше 0, корней в поле действительных чисел нет
    if (D < 0)
      printf("N\n");
    // Иначе находим корни уравнения
    else
      printf("Y %.9f %.9f\n", (d - sqrt(D)) / 2.0, (d + sqrt(D)) / 2.0);
  }

  return 0;
}
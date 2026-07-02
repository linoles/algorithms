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

// Codeforces 2143B - Скидки, O(n * log n + k * log k)
int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    vi a(n), b(k);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, k) scanf("%d", &b[i]);

    // Легче всего использовать купоны на минималное число предметов, тогда получится
    // сделать бесплатными максимальное число товаров. Используем купоны на самые дорогие товары
    sort(all(b));
    sort(all(a), greater<int>());

    // Этот указатель показывает на последний купленный товар
    int l = -1; // Осталось товаров: n - l - 1
    ll ans = 0;
    forn(i, k)
    {
      if (b[i] > n - l - 1)
        break;

      // Прибавляем стоимость товаров
      forab(j, l + 1, l + b[i] + 1) ans += a[j];
      l += b[i];
      ans -= a[l]; // Последний товар бесплатный
    }

    // Оставшиеся товары докупаем без акций
    forab(i, l + 1, n) ans += a[i];

    printf("%lld\n\n", ans);
  }

  return 0;
}
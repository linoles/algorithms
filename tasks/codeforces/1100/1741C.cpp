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

// Codeforces 1741C - Минимизируй толщину, O(n²)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    ll sum = 0;
    forn(i, n)
    {
      scanf("%d", &a[i]);
      sum += a[i];
    }

    // Первый подотрезок будет всегда начинаться с 0. Переберём конец первого отрезка - r
    // Тогда для каждого посчитаем толщину, если получится разбить массив на подотрезки с таким
    // начальным отрезком
    int ans = n;
    for (int r = n - 2; r >= 0; r--)
    {
      sum -= a[r + 1];

      // Ищем подотрезки суммой = sum
      bool ok = 1;
      int len = r + 1, l = r + 1;
      ll cur_sum = 0;
      forab(i, r + 1, n)
      {
        cur_sum += a[i];
        // Если сумма больше, так разбить гарантированно нельзя
        if (cur_sum > sum)
          ok = 0;
        else if (cur_sum == sum)
        {
          len = max(len, i - l + 1);
          l = i + 1;
          cur_sum = 0;
        }
      }

      // Если в конце остался отрезок с неправильной суммой, так разбить нельзя
      if (cur_sum != sum && cur_sum != 0)
        ok = 0;
      // Иначе сохраняем ещё длину последнего отрезка
      else
        len = max(len, n - l);

      if (ok)
        ans = min(ans, len);
    }

    printf("%d\n\n", ans);
  }

  return 0;
}
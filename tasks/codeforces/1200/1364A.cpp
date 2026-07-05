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

// Codeforces 1364A - XXXXX, O(n)
int main()
{
  int t, n, x, a;
  scanf("%d", &t);
  while (t--)
  {
    ll sum = 0;
    int l = -1, r;
    scanf("%d %d", &n, &x);
    forn(i, n)
    {
      scanf("%d", &a);
      sum += a;

      if (a % x != 0)
      {
        // Первое число, не кратное x
        if (l == -1)
          l = i;
        // Последнее число, не кратное x
        r = i;
      }
    }

    if (sum % x != 0) // Если взять все числа, получится сумма, не кратная x
      printf("%d\n\n", n);
    else if (l == -1) // Не существует чисел не кратных x
      printf("-1\n\n");
    else
      // Либо выбираем отрезок [0...l + 1], либо [r...n]
      printf("%d\n\n", n - min(n - r, l + 1));
  }

  return 0;
}
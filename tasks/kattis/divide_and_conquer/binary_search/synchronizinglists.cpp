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

// Kattis synchronizinglists, O(n * log n)
int main()
{
  int n;
  while (scanf("%d", &n) && n != 0)
  {
    int a[n + 1], b[n + 1];
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) scanf("%d", &b[i]);

    // Строим отсортированные массивы
    vi sa(a, a + n), sb(b, b + n), res(n);
    sort(all(sa));
    sort(all(sb));

    forn(i, n)
    {
      // Тут i - индекс числа из массива a, поэтому по a[i] найдём индекс j этого числа из sa
      int j = lower_bound(all(sa), a[i]) - sa.begin();

      // Теперь, зная позицию числа в отсортированном массиве и в изначальном,
      // мы можем просто поставить на эту позицию число sb[j]
      res[i] = sb[j];
    }

    forn(i, n) printf("%d\n", res[i]);
    printf("\n\n");
  }

  return 0;
}

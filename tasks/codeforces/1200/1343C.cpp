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

int sign(int x)
{
  return (x > 0) ? 1 : -1;
}

// Codeforces 1343C - Чередующаяся последовательность, O(n²)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    // Ищем подпоследовательности, где все элементы с одинаковым знаком
    vector<vi> signs;
    vi cur = {a[0]};
    forab(i, 1, n)
    {
      if (sign(a[i]) != sign(a[i - 1]))
      {
        signs.push_back(cur);
        cur = {};
      }
      cur.push_back(a[i]);
    }
    signs.push_back(cur); // Последняя последовательность

    // Среди них, чтобы максимизировать сумму, добавляем максимальный элемент из каждой посл.
    ll res = 0;
    forn(i, signs.size()) res += *max_element(all(signs[i]));

    printf("%lld\n\n", res);
  }

  return 0;
}
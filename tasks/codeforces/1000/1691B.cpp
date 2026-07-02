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

// Codeforces 1691B - Обмен обувью, O(n²)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    int l = 0, r = 0;
    bool ok = 1;
    // Временно заполняем перестановку просто индексами от 1 до n
    vi p(n);
    forn(i, n) p[i] = i + 1;

    while (r < n)
    {
      // Двигаем правый указатель, пока одинаковые размеры обуви
      while (r < n - 1 && a[r] == a[r + 1])
        r++;
      // Если всего 1 человек с таким размером
      if (l == r)
        ok = 0;
      // Иначе переворачиваем индексы для правильного распределения
      else
        rotate(p.begin() + l, p.begin() + r, p.begin() + r + 1);
      l = r + 1;
      r++;
    }

    if (!ok)
      printf("-1\n\n");
    else
    {
      forn(i, n) printf("%d ", p[i]);
      printf("\n\n");
    }
  }

  return 0;
}
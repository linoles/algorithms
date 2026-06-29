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

// Codeforces 2146C - Неправильный бинарный поиск, O()
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char buffer[n + 1];
    scanf("%s", &buffer);
    string s = buffer;

    vi p(n);
    bool ok = 1;

    int l = 0;
    while (l < n)
    {
      // Пропускаем, если цифра по индексу не 0
      if (s[l] == '1')
      {
        p[l] = l + 1;
        l++;
        continue;
      }

      // Двигаем r
      int r = l;
      while (r + 1 < n && s[r + 1] == '0')
        r++;

      // Если пустой отрезок, то перестановки не существует
      if (r - l == 0)
      {
        ok = 0;
        break;
      }

      // Заполняем p[l...r]
      forab(i, l, r + 1) p[i] = i + 2;
      p[r] = l + 1;
      l = r + 1;
    }

    printf(ok ? "YES\n" : "NO\n\n");
    if (ok)
    {
      forn(i, n) printf("%d ", p[i]);
      printf("\n\n");
    }
  }

  return 0;
}
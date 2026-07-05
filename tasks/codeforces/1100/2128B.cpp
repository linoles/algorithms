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

// Codeforces 2128B - Процесс на Деке, O(n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    // Грубо говоря, массив плохой, если он содержит строго убывающую или строго возрастающую
    // непрерывную подпоследовательность из 5 элементов.
    // Пытаемся сделать что-то вроде q1 > q2 < q3 > q4 < ...

    string res = "";
    int l = 0, r = n - 1; // Последний оставшийся слева и справа
    forab(i, 1, n + 1)
    {
      // Выбираем сторону, откуда взять
      bool side = (i % 2) ? a[l] < a[r] : a[l] > a[r];

      if (side)
      {
        res += "L";
        l++;
      }
      else
      {
        res += "R";
        r--;
      }
    }

    printf("%s\n\n", res.c_str());
  }

  return 0;
}

// 7 1 6 2 5 3 4
// 2 1 4 3 6 5 8 7 9
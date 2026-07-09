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

// Функция проверки ряда
bool check_row(vi &row, int x)
{
  // Поиск весов, которые мы не можем поднять
  vi heavy;
  forn(i, row.size()) if (row[i] > x) heavy.push_back(row[i]);

  // Дальше проверяем, образуют ли тяжёлые грузы корректные пары
  for (int i = 0; i < (int)heavy.size(); i += 2)
    if (i + 1 >= (int)heavy.size() || heavy[i] != heavy[i + 1])
      return 0;
  return 1;

  // Тяжелые грузы (> x) нельзя поднимать, их порядок в ряде не может измениться
  // Чтобы соединить два тяжёлых груза, они должны стоять рядом в посл. тяжёлых грузов
  // Значит после удаления лёгких грузов, тяжёлые должны идти парами: [w, w, v, v, ...]
}

// Kattis freeweights, O(n * log n)
int main()
{
  int n;
  scanf("%d", &n);
  vi a(n), b(n);
  forn(i, n) scanf("%d", &a[i]);
  forn(i, n) scanf("%d", &b[i]);

  // BSTA
  int lo = 0, hi = 1e9 + 1;
  while (lo < hi)
  {
    int mid = (lo + hi) / 2;
    if (check_row(a, mid) && check_row(b, mid))
      hi = mid;
    else
      lo = mid + 1;
  }

  printf("%d", lo);

  return 0;
}
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

// Kattis hindex, O(n * log n)
int main()
{
  int n;
  scanf("%d", &n);
  int c[n + 1];
  forn(i, n) scanf("%d", &c[i]);

  sort(c, c + n);

  // BSTA - Ищем ответ бинарным поиском
  int lo = 0, hi = n;
  while (lo < hi)
  {
    int mid = (lo + hi + 1) / 2;
    // Вычисляем кол-во статей с минимум mid цитат
    int p = n - (upper_bound(c, c + n, mid - 1) - c);
    if (p < mid)
      hi = mid - 1;
    else
      lo = mid;
  }
  printf("%d", lo);

  return 0;
}

// Да, намного легче в бин. поиске делать просто линейный поиск, и я сначала сделал такое решение,
// но затем я почему-то решил, что (n * log n + log²n) меньше, чем (n * log n)
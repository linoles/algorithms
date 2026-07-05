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

// Codeforces 302B - Евгений и плейлист, O(n + m)
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int c[n + 1], t[n + 1], v[m + 1];
  forn(i, n) scanf("%d %d", &c[i], &t[i]);
  forn(i, m) scanf("%d", &v[i]);

  // Проходимся по возможным ответам
  int time = 0, moment = 0; // Прошедшее время и индекс последнего рассмотренного момента
  forn(i, n)
  {
    time += c[i] * t[i];
    // Для всех записанных моментов, пока время на моменте не больше прошедшего, выводим песню
    while (moment < m && v[moment] <= time)
    {
      printf("%d\n", i + 1);
      moment++;
    }

    if (moment >= m)
      break;
  }

  return 0;
}
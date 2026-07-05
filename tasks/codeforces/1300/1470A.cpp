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

// Codeforces 1470A - Странный день рождения, O(n * log n)
int main()
{
  int t, n, m;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &m);
    int k[n + 1], c[m + 1];
    forn(i, n) scanf("%d", &k[i]);
    forn(i, m) scanf("%d", &c[i]);

    // Выгоднее всего покупать дешёвые подарки для наибольших k
    sort(k, k + n, greater<int>());

    ll ans = 0;
    int ptr = 0; // Указатель на самый дешёвый доступный подарок
    forn(i, n)
    {
      // Покупка подарка ptr
      if (ptr <= k[i] && c[ptr] < c[k[i] - 1])
      {
        ans += c[ptr];
        ptr++;
      }
      // Просто отдать деньги
      else
        ans += c[k[i] - 1];
    }

    printf("%lld\n\n", ans);
  }

  return 0;
}
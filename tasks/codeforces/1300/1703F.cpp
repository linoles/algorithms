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

// Codeforces 1703F - Очередная задача про пары, удовлетворяющие неравенству, O(n²)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    ll ans = 0;
    // i находится точно левее j
    forn(i, n)
    {
      if (a[i] >= i + 1)
        continue;

      // Ищем j
      forab(j, i + 2, n) if (i + 1 < a[j] && a[j] < j + 1)
          ans++;
    }

    printf("%d\n\n", ans);
  }

  return 0;
}

// Я оставил это решение TLE. Как-нибудь в будущем я к нему вернусь и исправлю, но проблема сейчас
// в том, что тут необходимо знание Fenwick/Segment Tree
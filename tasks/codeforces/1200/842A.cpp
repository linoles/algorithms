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

// Codeforces 842A - Кирилл и игра, O(y - x)
int main()
{
  int l, r, x, y, k;
  scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);

  // Ищем a, b, такие, что a ∈ [l;r], b ∈ [x;y] и a / b = k (a = b * k)
  // Перебираем b и для какого-то должен будет появиться a = b * k в диапазоне [l;r]
  bool ans = 0;
  forab(b, x, y + 1)
  {
    ll a = (ll)b * k;
    if (a >= l && a <= r)
    {
      ans = 1;
      break;
    }
  }
  printf(ans ? "YES" : "NO");

  return 0;
}

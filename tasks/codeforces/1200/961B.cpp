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

// Codeforces 961B - Сон на лекции, O(n)
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  vi a(n), t(n);
  forn(i, n) scanf("%d", &a[i]);
  forn(i, n) scanf("%d", &t[i]);

  ll sum = 0; // Кол-во теорем, которые Мишка уже записал
  forn(i, n) if (t[i]) sum += a[i];

  // Преф. суммы только тех лекций, когда Мишка спал
  vll pref(n + 1, 0);
  forab(i, 1, n + 1) pref[i] = pref[i - 1] + ((!t[i - 1]) ? a[i - 1] : 0);

  // Ищем самый выгодный отрезок длины k
  ll ans = 0;
  forab(r, k - 1, n)
  {
    ll s = pref[r + 1] - pref[r - k + 1];
    ans = max(ans, s);
  }

  printf("%lld", ans + sum);

  return 0;
}
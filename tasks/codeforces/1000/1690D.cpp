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

// Codeforces 1690D - Чёрно-белая полоса, O(n)
int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    char buffer[n + 1];
    scanf("%s", &buffer);
    string s = buffer;

    // Ищем отрезок длины k с наименьшим кол-вом белых клеток
    int ans = INT_MAX, cur = 0;
    forn(r, n)
    {
      // Если текущая клетка белая, добавляем к текущему кол-ву
      if (s[r] == 'W')
        cur++;
      if (r >= k - 1)
      {
        // Если клетка, которую миновали, была белой, удаляем её из cur
        if (r >= k && s[r - k] == 'W')
          cur--;
        ans = min(cur, ans);
      }
    }

    printf("%d\n\n", ans);
  }

  return 0;
}
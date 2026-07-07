#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

// Kattis firefly, O(n * log n)
int main()
{
  int n, h, temp;
  scanf("%d %d", &n, &h);
  vi sc, sg; // sc - с полотка, sg - со дна
  forn(i, n)
  {
    scanf("%d", &temp);
    if (i % 2 == 0)
      sg.pb(temp);
    else
      sc.pb(temp);
  }

  // Сортируем сталактиты и сталагмиты
  sort(all(sg));
  sort(all(sc));

  // Перебираем ответ
  int ans = INT_MAX, count = 0;
  forab(res, 1, h + 1)
  {
    int dest = 0;

    // Сталагмиты: длина >= res
    dest += sg.size() - (lower_bound(all(sg), res) - sg.begin());

    // Сталактиты: длина > (h - res)
    dest += sc.size() - (upper_bound(all(sc), h - res) - sc.begin());

    // Если нашли минимальную высоту
    if (dest < ans)
    {
      ans = dest;
      count = 1;
    }
    // Или нашли ещё один ответ с такой высотой
    else if (dest == ans)
      count++;
  }

  printf("%d %d", ans, count);

  return 0;
}
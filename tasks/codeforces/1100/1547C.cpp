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

// Codeforces 1547C - Парное программирование, O(n + m)
int main()
{
  int t, n, k, m;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &k, &n, &m);
    int a[n + 1], b[m + 1];
    forn(i, n) scanf("%d", &a[i]);
    forn(i, m) scanf("%d", &b[i]);

    vi res;
    int i = 0, j = 0, cur = k; // Указатели на массив a и b
    bool ok = 1;

    // Мы вставляем элементы из массивов, пока не упрёмся в первый a[i] или b[j] > cur
    while ((i < n || j < m) && ok)
    {
      // Если Монокарп наткнулся на несуществующую строку,
      // тогда двигаем Поликарпа, пока он не создаст достаточно строк
      while (i < n && a[i] > cur && ok)
      {
        // Если не можем двигать Поликарпа, выходим
        if (j >= m || b[j] > cur)
        {
          ok = 0;
          break;
        }

        if (b[j] == 0)
          cur++;
        res.push_back(b[j]);
        j++;
      }
      
      // Если Поликарп наткнулся на несуществующую строку,
      // тогда двигаем Монокарпа, пока он не создаст достаточно строк
      while (j < m && b[j] > cur && ok)
      {
        // Если не можем двигать Монокарпа, выходим
        if (i >= n || a[i] > cur)
        {
          ok = 0;
          break;
        }
        
        if (a[i] == 0)
          cur++;
        res.push_back(a[i]);
        i++;
      }

      // В конце концов надо кого-то ещё двинуть
      if (i < n && a[i] <= cur)
      {
        if (a[i] == 0)
          cur++;
        res.push_back(a[i]);
        i++;
      }
      else if (j < m && b[j] <= cur)
      {
        if (b[j] == 0)
          cur++;
        res.push_back(b[j]);
        j++;
      }
      // Если никто не сдвинулся, то выход
      else
      {
        ok = 0;
        break;
      }
    }

    if (!ok)
      printf("-1\n\n");
    else
    {
      for (int x : res)
        printf("%d ", x);
      printf("\n\n");
    }
  }

  return 0;
}
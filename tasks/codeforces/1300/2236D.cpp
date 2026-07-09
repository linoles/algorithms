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

// Codeforces 2236D - Совершенно новое татарское телешоу, O(n * log n)
int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    // Нужно каждый ход выбирать такой y, что y >= x, а также y - x <= k

    // Если Арсений выберет максимум, то если максимумом изначально было:
    // 1. чётное кол-во, то Егор победит
    // 2. нечётное кол-во, то Егор проиграет

    sort(a, a + n);

    // Находим для каждого числа кол-во его встреч в массиве
    vector<pii> b = {{a[0], 1}};
    forab(i, 1, n)
    {
      if (a[i] == a[i - 1])
        b.back().second++;
      else
        b.push_back(make_pair(a[i], 1));
    }

    while (b.size() > 0)
    {
      // b[n - 1] - текущий максимум, b[n - 2] - второй по величине элемент
      n = b.size();

      // Если кол-во вхождений в массив максимума чётно, то Арсений выбирает этот элемент
      if (b[n - 1].second % 2 == 0)
      {
        printf("YES\n\n");
        break;
      }
      // Иначе если нет второго максимума, то нет варианта победить
      else if (n == 1)
      {
        printf("NO\n\n");
        break;
      }
      // А если есть и разница между ними не превышает k, то выбираем второй максимум
      else if (b[n - 1].first - b[n - 2].first <= k)
      {
        printf("YES\n\n");
        break;
      }

      // Иначе удаляем максимум и продолжаем операции
      b.pop_back();
    }
  }

  return 0;
}
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

// Codeforces 1884B - Дом с привидениями, O(n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char buffer[n + 1];
    scanf("%s", &buffer);
    string s = buffer;

    reverse(all(s));

    vi zero_pos;
    forn(i, n) if (s[i] == '0') zero_pos.push_back(i);

    // Бинарная строка s будет делиться на 2^i, если последние i бит равны нулю,
    // То есть для каждого i нужно передвинуть единицы как можно дальше влево
    // Если число включенных битов равно on, тогда сделать это можно до i = n - on (= zeros)

    // Заполняем преф. суммы позиций нулей
    vll pref(zero_pos.size() + 1, 0);
    forab(i, 1, (int)zero_pos.size() + 1) pref[i] = pref[i - 1] + zero_pos[i - 1];

    ll sum_one = 0, sum_zero = 0; // Сумма позиций единиц и сумма первых cnt нулей
    int cnt = 0, ptr = 0;         // Кол-во единиц и указатель для поиска нулей справа
    forab(i, 1, n + 1)
    {
      if (i > zero_pos.size())
      {
        printf("-1 ");
        continue;
      }

      int idx = i - 1;
      // Добавляем единицу, если надо
      if (s[idx] == '1')
      {
        cnt++;
        sum_one += idx;
      }

      // Двигаем ptr до первой встречи zero_pos[ptr] > idx
      while (ptr < zero_pos.size() && zero_pos[ptr] <= idx)
        ptr++;

      // Если единиц 0, выводим 0
      if (cnt == 0)
        sum_zero = 0;
      // Иначе считаем префиксными суммами индексы нулей
      else
        sum_zero = pref[ptr + cnt] - pref[ptr];

      printf("%lld ", sum_zero - sum_one);
    }

    printf("\n\n");
  }

  return 0;
}
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

// Codeforces 1719C - Турнир по борьбе, O(n + q)
int main()
{
  int t, n, q, i, k, temp;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &q);
    deque<pii> a;                            // Номер, сила
    vi first_win(n + 1, -1), wins(n + 1, 0); // Сохраняем кол-во побед и первую победу
    int mx = -1, mx_i;                       // Самый сильный и его номер
    forn(j, n)
    {
      scanf("%d", &temp);
      if (temp > mx)
      {
        mx = temp;
        mx_i = j + 1;
      }
      a.emplace_back(j + 1, temp);
    }

    // Если самый сильный спорстмен встанет в начало очереди, то он всегда будет побеждать тех,
    // кто стоит дальше него, поэтому достаточно посчитать победы до встречи с сильнейшим

    // Считаем кол-во побед, пока не встретится самый сильный
    int f = 0;
    while (true)
    {
      // Получаем участников
      pii p1 = a.front();
      a.pop_front();
      pii p2 = a.front();
      a.pop_front();

      // Меняем, чтобы на p1 был сильнейший из этих двух
      if (p1.second < p2.second)
        swap(p1, p2);

      a.push_front(p1); // Победитель в начало
      a.push_back(p2);  // Проигравший в конец

      // Если встретили самого сильного, выходим
      if (p1.second == mx)
        break;

      // Гарантированно если p1 выигрывает, то только подряд, т.к. потом он уходит за сильнейшего
      if (first_win[p1.first] == -1)
        first_win[p1.first] = f;
      wins[p1.first]++;

      f++;
    }

    while (q--)
    {
      scanf("%d %d", &i, &k);

      // Если выбран самый сильный
      if (mx_i == i)
        printf("%d\n", max(0, k - f));
      else if (first_win[i] == -1 || k <= first_win[i])
        printf("0\n");
      else
        printf("%d\n", min(wins[i], k - first_win[i]));
    }

    printf("\n");
  }

  return 0;
}

// Это первая задача, на которой я получил MLE :)
// Изначально я хранил кол-во побед для каждого на каждом раунде до встречи сильнейшего
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    int a[n], x[n];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &x[i]);
      x[i] = abs(x[i]); // Считаем, что все монстры справа и двигаются налево
      // Из-за модуля позиции могут повторяться
    }

    // Для каждой позиции запоминаем здоровье монстров с этими позициями
    vector<vector<int>> hp(n + 1, vector<int>());
    for (int i = 0; i < n; i++)
      hp[x[i]].push_back(a[i]);

    sort(x, x + n);

    // Восстанавливаем соответствующее здоровье
    vector<int> last(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
      a[i] = hp[x[i]][last[x[i]]];
      last[x[i]]++;
    }

    // Выгоднее всего убивать самых ближайших монстров
    // Заместо изменения всех координат монстров, считаем, что двигается игрок по +1
    int pos = 0, alive = 0; // alive - указатель на ближайшего живого
    while (alive < n && pos < x[alive])
    {
      // Наносим первым монстрам k урона
      int rem = k;
      while (rem > 0 && alive < n)
      {
        // Убиваем монстра или берём весь остаток, если не хватает
        int take = min(rem, a[alive]);
        rem -= take;
        a[alive] -= take;

        // Если монстр убит, двигаем указатель
        if (a[alive] == 0)
          alive++;
        // Иначе rem = 0
        else
          break;
      }
      
      pos++;
    }

    printf(alive == n ? "YES\n\n" : "NO\n\n");
  }
}
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
using namespace std;

// Kattis musicalchairs, O(n²)
int main()
{
  int n;
  scanf("%d", &n);

  vector<int> k(n + 1);
  for (int i = 1; i <= n; i++)
    scanf("%d", &k[i]);

  // Связный список участников
  list<int> people;
  for (int i = 1; i <= n; i++)
    people.push_back(i);

  auto it = people.begin();
  int cur_k = k[1];

  while (people.size() > 1)
  {
    // Делаем cur_k - 1 шагов (пропускаем людей)
    int steps = (cur_k - 1) % people.size(); // Пропускаем лишние шаги

    // Симуляция
    for (int i = 0; i < steps; i++)
      if (++it == people.end())
        it = people.begin();

    // Удаляем текущего
    auto to_remove = it++;
    if (it == people.end())
      it = people.begin();
    people.erase(to_remove);

    // Обновляем k для следующего
    if (!people.empty())
      cur_k = k[*it];
  }

  printf("%d\n", *people.begin());
  return 0;
}

// Это, кстати, ещё один способ решения проблемы Флавия - связным списком
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> vi;

/*
 * Поиск родителя без оптимизации
int findSet(int i, vi &p) {
  if (p[i] == i) return i;
  return findSet(p[i], p);
}
*/

// Поиск родителя с оптимизацией
int findSet(int i, vi &p)
{
  if (p[i] == i)
    return i;
  return p[i] = findSet(p[i], p);
}

// Проверяет, входят ли i и j в одно множество
// Работает, т.к. представители множеств не могут повторяться
bool isSameSet(int i, int j, vi &p)
{
  return findSet(i, p) == findSet(j, p);
}

// Объединение множеств
void unionSet(int i, int j, vi &p, vi &ranks) {
  int x = findSet(i, p); int y = findSet(j, p); // x != j
  
  if (ranks[x] < ranks[y]) swap(x, y);
  p[y] = x;
  
  if (ranks[x] == ranks[y]) ranks[x]++;
}

int main()
{
  // Union-Find disjoint set
  vi p = {0, 1, 2, 3, 4, 5};     // p[i] - родитель (parent) элемента i, p[i] = i у корня
  vi ranks = {0, 0, 0, 0, 0, 0}; // ranks[i] - высота элемента i в дереве

  unionSet(1, 2, p, ranks);
  unionSet(3, 4, p, ranks);
  unionSet(2, 3, p, ranks);
  unionSet(4, 5, p, ranks);

  vi p1(p); // Тот же p, но будет изменяться, т.к. findSet принимает ссылку для оптимизации
  cout << findSet(0, p1) << " " << findSet(1, p1) << " " << findSet(2, p1) << " " << findSet(3, p1) << " " << findSet(4, p1) << " " << findSet(5, p1) << "\n";
  cout << ranks[0] << " " << ranks[1] << " " << ranks[2] << " " << ranks[3] << " " << ranks[4] << " " << ranks[5] << "\n";
  cout << isSameSet(2, 3, p1) << " " << isSameSet(0, 5, p1);

  return 0;
}
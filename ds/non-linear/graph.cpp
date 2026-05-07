#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
  int n, m; // n - вершин, m - рёбер
  cin >> n >> m;

  vector<vii> AL(n + 1);  // Список вершин
  vector<vector<int>> EL; // Список рёбер

  for (int i = 0; i < m; i++)
  {
    int u, v, w, w2; // u - откуда, v - куда, w - вес вершины, w2 - вес ребра
    cin >> u >> v >> w >> w2;

    AL[u].push_back({v, w}); // Вершина
    EL.push_back({u, v, w2});    // Ребро
  }

  cout << "\n";

  // Вывод вершин
  for (int i = 1; i <= n; i++)
  {
    cout << "Node " << i << ": ";
    for (auto [to, weight] : AL[i])
    {
      cout << "to " << to << " (w: " << weight << ") ";
    }
    cout << "\n";
  }

  cout << "\n";

  // Вывод рёбер
  for (vector<int> x : EL)
  {
    cout << "Edge: from " << x.at(0) << " to " << x.at(1) << " with w: " << x[2] << "\n";
  }

  return 0;
}

/*

Пример ввода:

4 6
1 2 10 5
1 3 5 7
2 4 8 9
3 4 2 2
2 3 3 4
4 1 7 1

4 6 - вершин рёбер
1 2 10 5 и т.д. - откуда куда вес_вершины вес_ребра

*/
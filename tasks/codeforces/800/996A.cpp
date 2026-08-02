#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  vector<int> dens = {100, 20, 10, 5, 1};

  // Жадный алгоритм
  int ans = 0, sum = 0;
  while (sum < n)
  {
    ans++;
    // Ищем максимальный номинал
    auto it = dens.begin();
    // Скорее всего, можно улучшить до log(dens.size())
    while (*it + sum > n)
      it++;
    sum += *it;
  }

  printf("%d", ans);
}
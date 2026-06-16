#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis geppetto, O(2^n * n)
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> conflicts(n, 0);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    conflicts[a] |= (1 << b);
    conflicts[b] |= (1 << a);
  }

  int t = 0;
  for (int mask = 0; mask < (1 << n); mask++)
  {
    bool add = 1;
    for (int i = 0; i < n; i++)
      // Включен ли ингредиент в пиццу и конфликтует ли ингредиент с одним из других ингредиентов
      if (mask & (1 << i) && conflicts[i] & mask)
        add = 0;

    if (add)
      t++;
  }

  printf("%d", t);

  return 0;
}

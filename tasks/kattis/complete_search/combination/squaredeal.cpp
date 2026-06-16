#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis squareldeal, O(1)
int main()
{
  pair<int, int> a[4];
  for (int i = 0; i < 3; i++)
    scanf("%d %d", &a[i].first, &a[i].second);

  sort(a, a + 3);

  bool found = 0;
  do
  {
    if (found)
      break;
    for (int mask = 0; mask < 8 && !found; mask++)
    {
      pair<int, int> x = make_pair((mask & 1) ? a[0].first : a[0].second, (mask & 1) ? a[0].second : a[0].first);
      pair<int, int> y = make_pair((mask & 2) ? a[1].first : a[1].second, (mask & 2) ? a[1].second : a[1].first);
      pair<int, int> z = make_pair((mask & 4) ? a[2].first : a[2].second, (mask & 4) ? a[2].second : a[2].first);
      int h1 = x.first, h2 = y.first, h3 = z.first;
      int w1 = x.second, w2 = y.second, w3 = z.second;

      // Все случаи образования квадрата
      if ((h1 == h2 && h1 == h3 && w1 + w2 + w3 == h1) ||
          (w1 == w2 && w1 == w3 && h1 + h2 + h3 == w1) ||
          (h1 == h2 && h1 + h3 == w1 + w2 && w1 + w2 == w3) ||
          (w1 == w2 && w1 + w3 == h1 + h2 && h1 + h2 == h3) ||
          (h1 == h2 && w1 + w2 == w3 && h1 + h3 == w1 + w2) ||
          (w1 == w2 && h1 + h2 == h3 && w1 + w3 == h1 + h2) ||
          (h1 == h2 && w1 + w2 == w3 && h1 + h3 == w1 + w2) ||
          (w1 == w2 && h1 + h2 == h3 && w1 + w3 == h1 + h2) ||
          (h1 == h2 && h1 + h3 == w1 + w2 && w1 + w2 == w3) ||
          (w1 == w2 && w1 + w3 == h1 + h2 && h1 + h2 == h3) ||
          (h1 + h2 == h3 && w1 == w2 && w1 + w3 == h1 + h2) ||
          (w1 + w2 == w3 && h1 == h2 && h1 + h3 == w1 + w2))
        found = 1;
    }
  } while (next_permutation(a, a + 3));

  printf(found ? "YES" : "NO");

  return 0;
}
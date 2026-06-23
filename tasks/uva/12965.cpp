#include <bits/stdc++.h>
using namespace std;

// UVa 12965 - Angry Birds, O((p + c) * log (p + c))
int main()
{
  int t;
  scanf("%d", &t);

  while (t--)
  {
    int p, c;
    scanf("%d %d", &p, &c);

    vector<int> prod(p), cust(c);
    for (int i = 0; i < p; i++)
      scanf("%d", &prod[i]);
    for (int i = 0; i < c; i++)
      scanf("%d", &cust[i]);

    vector<int> candidates = prod;
    candidates.insert(candidates.end(), cust.begin(), cust.end());
    candidates.push_back(0);
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    int best_price = -1;
    int best_angry = INT_MAX;

    for (int price : candidates)
    {
      // Продюсеры злятся, если их цена > price
      int sad_prod = prod.end() - upper_bound(prod.begin(), prod.end(), price);
      // Потребители злятся, если их цена < price
      int sad_cust = lower_bound(cust.begin(), cust.end(), price) - cust.begin();

      int angry = sad_prod + sad_cust;

      if (angry < best_angry || (angry == best_angry && price < best_price))
      {
        best_angry = angry;
        best_price = price;
      }
    }

    printf("%d %d\n", best_price, best_angry);
  }

  return 0;
}
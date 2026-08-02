
#include <bits/stdc++.h>
using namespace std;

// Kattis perket, O(2^n * n)
int main()
{
  int n;
  scanf("%d", &n);
  pair<int, int> sb[n + 1]; // first (s) - кислотность, second (b) - горечь
  for (int i = 0; i < n; i++)
    scanf("%d %d", &sb[i].first, &sb[i].second);

  // s_t = s1 * s2 * ... * s_t
  // b_t = b1 + b2 + ... + b_t
  // Ответ: min(|b_t - s_t|)
  int min_res = INT_MAX;
  for (int mask = 1; mask < (1 << n); mask++)
  {
    // Ищем общую кислотность и горечь
    int st = 1, bt = 0;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i))
      {
        st *= sb[i].first;
        bt += sb[i].second;
      }

    min_res = min(min_res, abs(st - bt));
  }

  printf("%d", min_res);

  return 0;
}
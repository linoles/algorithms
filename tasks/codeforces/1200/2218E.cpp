#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 2218E - 67-я задача про XOR, O(n²)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // a xor b = b xor a, (a xor b) xor c = a xor (b xor c)
    // Это значит, что порядок операций не важен - результат будет одинаковым
    // По итогу мы просто ищем максимальный результат x ^ y среди пар значений (x, y) в массиве a

    int max_res = -1;
    for (int x : a)
      for (int y : a)
        max_res = max(max_res, x ^ y);
    
    printf("%d\n\n", max_res);
  }

  return 0;
}
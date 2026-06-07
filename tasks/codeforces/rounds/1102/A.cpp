#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Codeforces Round 1102 A - Евклид, последовательность, два числа, O(n * log n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int b[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &b[i]);

    // a[i] % a[i + 1] = a[i + 2]
    // Можно заметить, что эта последовательность будет в любом случае невозрастающей, а значит
    // если отсортировать массив в порядке убывания, то если это не будет последовательность
    // алгоритма Евклида, то нельзя сделать такую перестановку, а иначе a[0] = x, a[1] = y
    sort(b, b + n, greater<int>());
    bool res = true;
    for (int i = 0; i < n - 2; i++)
      if (b[i] % b[i + 1] != b[i + 2])
      {
        res = false;
        break;
      }

    if (!res) printf("%d\n\n", -1);
    else printf("%d %d\n\n", b[0], b[1]);
  }

  return 0;
}
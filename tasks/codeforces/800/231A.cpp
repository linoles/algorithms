#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 231A (800) - Команда, O(n) для ввода
int main()
{
  int n, res = 0, a, b, c;
  scanf("%d", &n); // 1 ≤ n ≤ 1000
  while (n--)
  {
    scanf("%d %d %d", &a, &b, &c);
    if (a + b + c >= 2)
      res++; // Если двое или больше придумали решение, задача будет реализована
  }

  cout << res;

  return 0;
}
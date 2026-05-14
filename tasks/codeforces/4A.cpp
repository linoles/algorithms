#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 4A (800) - Арбуз, O(1)
int main()
{
  int w; // 1 ≤ w ≤ 100
  scanf("%d", &w);

  cout << ((w % 2 == 0 && w > 2) ? "YES" : "NO"); // Если вес чётен и больше 2, его можно поделить на 2 чётных части

  return 0;
}
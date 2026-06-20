#include <iostream>
#include <list>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Kattis toys, O(n)
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  // Симуляция прохождения
  int pos = 0;
  for (int i = 1; i <= n; i++)
    pos = (pos + k) % i;

  printf("%d", pos);

  return 0;
}
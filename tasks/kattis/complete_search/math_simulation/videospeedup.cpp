#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis videospeedup, O(n)
int main()
{
  int n, p, k;
  scanf("%d %d %d", &n, &p, &k);
  int t[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &t[i]);

  // Просто симулируем прогресс просмотра видео
  double res = t[0];
  for (int i = 1; i < n; i++)
    res += double(t[i] - t[i - 1]) * (1.0 + double(p) * i / 100);
  // И последний кусок
  res += double(k - t[n - 1]) * (1.0 + double(p) * n / 100);

  printf("%f", res);

  return 0;
}
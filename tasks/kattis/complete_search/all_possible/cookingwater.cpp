#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis cookingwater, O()
int main()
{
  int n, min_diff, min_time = INT_MAX;
  scanf("%d", &n);
  int left = 0, right = 1000;
  bool possible = 1;
  for (int i = 0; i < n; i++)
  {
    int f, s;
    scanf("%d %d", &f, &s);
    right = min(right, s);
    left = max(left, f);
    if (left > right)
      possible = 0;
  }

  printf(possible ? "gunilla has a point" : "edward is right");

  return 0;
}
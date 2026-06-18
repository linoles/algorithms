#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis trollhunt, O(1)
int main()
{
  int b, k, g;
  scanf("%d %d %d", &b, &k, &g);
  b--;                // Тролль точно не под начальным мостом
  int groups = k / g; // С округлением вниз
  printf("%d", (int)ceil((double)b / (double)groups));

  return 0;
}
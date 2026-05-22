#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Это не задача, простой код для поиска различий в ожидаемом ответе и полученном
int main()
{
  int t;
  printf("Enter number of tests: ");
  scanf("%d", &t);
  char in[t + 1][1000], out[t + 1][1000];

  printf("\n\nNow enter %d tests real output lines:\n", t);
  for (int i = 0; i < t; i++)
    scanf("%s", in[i]);

  printf("\n\nNow enter %d your code output lines:\n", t);
  for (int i = 0; i < t; i++)
    scanf("%s", out[i]);

  printf("\n\n");
  bool found = 0;
  for (int i = 0; i < t; i++)
    if (strcmp(in[i], out[i]) != 0)
    {
      found = 1;
      printf("Error (difference): line %d (%d 0-indexed).\nExpected: \"%s\", found: \"%s\"\n\n", i + 1, i, in[i], out[i]);
    }

  if (!found)
    printf("There's no errors in your code output!");

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/101021/problem/1
int main()
{
  // Делаем запросы, уменьшая каждый раз интервал в два раза
  int lo = 0, hi = 1e6;
  while (lo < hi)
  {
    int mid = lo + (hi - lo + 1) / 2;
    printf("%d\n", mid);
    fflush(stdout);

    char buffer[10];
    scanf("%s", buffer);
    string s = buffer;

    if (s == "<")
      hi = mid - 1;
    else
      lo = mid;
  }

  printf("! %d", lo);

  return 0;
}

// Абсолютно всегда 20 запросов
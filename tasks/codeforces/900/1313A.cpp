#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1313A (900) - Ресторан быстрого питания, O(1)
int main()
{
  int t, a, b, c; // 1 ≤ t ≤ 500, 0 ≤ a, b, c ≤ 10
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &a, &b, &c);

    int res = 0;
    // Да, это очень примитивно и глупо, но это первое, что пришло мне в голову
    // Идея в том, что таких вариаций всего 7:
    // a|b|c, ab|ac|bc, abc
    // Ну так почему бы не перепробовать все в самом выгодном порядке?

    if (a)
    {
      res++;
      a--;
    }
    if (b)
    {
      res++;
      b--;
    }
    if (c)
    {
      res++;
      c--;
    }
    if (c <= a && c <= b)
    {
      if (a && b)
      {
        res++;
        a--;
        b--;
      }
      if (b && c)
      {
        res++;
        b--;
        c--;
      }
      if (a && c)
      {
        res++;
        a--;
        c--;
      }
    }
    else
    {
      if (a && c)
      {
        res++;
        a--;
        c--;
      }
      if (b && c)
      {
        res++;
        b--;
        c--;
      }
      if (a && b)
      {
        res++;
        a--;
        b--;
      }
    }
    if (a && b && c)
      res++;

    printf("%d\n", res);
  }

  return 0;
}
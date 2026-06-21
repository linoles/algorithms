#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, h;

void gen(int num, int last_bit)
{
  // Только если длина равна n и Hamming distance равен h
  if (last_bit == n - 1 && __builtin_popcount(num xor 0) == h)
  {
    // Составляем строку
    string bin = "";
    for (int i = 0; i < n; i++)
    {
      if (num & (1 << i))
        bin.push_back('1');
      else
        bin.push_back('0');
    }

    printf("%s\n", bin.c_str());
    return;
  }
  else if (last_bit == n - 1)
    return;

  // Генерируем со следующим нулём
  gen(num, last_bit + 1);

  // Генерируем со следующей единицей
  num |= (1 << (last_bit + 1));
  gen(num, last_bit + 1);
  num xor (1 << (last_bit + 1));
}

// UVa 00729 - The Hamming Distance Problem
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &h);

    gen(0, -1);

    if (t > 0)
      printf("\n");
  }

  return 0;
}
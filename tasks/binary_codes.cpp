#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
string cur;

// O(2^n)
void gen(int pos)
{
  if (pos == n)
  {
    printf("%s\n", cur.c_str());
    return;
  }

  // Все варианты с следующим нулём
  cur.push_back('0');
  gen(pos + 1);
  cur.pop_back();

  // Все варианты с следующей единицей
  cur.push_back('1');
  gen(pos + 1);
  cur.pop_back();
}

/*
  gen(0)

   |———— 0
   |    |——— 00
   |    |——— 01
   |
   |———— 1
        |——— 10
        |——— 11
*/

// Суть: сформировать все бинарные числа длины до n
int main()
{
  scanf("%d", &n);
  gen(0);

  return 0;
}
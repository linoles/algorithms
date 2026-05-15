#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Codeforces 236A (800) - Девушка или Юноша, O(n) для копирования, можно ускорить bool[]
int main()
{
  char name[100]; // 0 ≤ n ≤ 100, массив char самый быстрый
  scanf("%s", &name);
  unordered_set<char> st(name, name + strlen(name)); // Убираем дубликаты

  cout << ((size(st) % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!");

  return 0;
}
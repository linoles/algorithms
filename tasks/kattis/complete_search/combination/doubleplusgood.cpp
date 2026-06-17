#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Kattis doubleplusgood, O(2^n * n^2)
int main()
{
  char buffer[36];
  scanf("%s", &buffer);
  string s = buffer;

  // Находим все плюсы
  vector<int> pl;
  for (int i = 0; i < s.size(); i++)
  {
    char c = s[i];
    if (c == '+')
      pl.push_back(i);
  }

  // Находим все числа (тут бы s.split("+") :))
  vector<ll> nums;
  stringstream ss(s);
  string token;
  while (getline(ss, token, '+'))
    nums.push_back(stoll(token));

  unordered_set<int> t; // Не считаем дубликаты
  for (int mask = 0; mask < (1 << pl.size()); mask++)
  {
    // в mask 1 = конкатенация, 0 = сложение
    ll res = 0, deleted = 0;
    // Считаем сначала все конкатенации
    vector<ll> cpy(nums.begin(), nums.end());
    for (int i = 0; i < pl.size(); i++)
      if (mask & (1 << i))
      {
        cpy[i - deleted] = stoll(to_string(cpy[i - deleted]) + to_string(cpy[i + 1 - deleted])); // Конкатенация
        cpy.erase(cpy.begin() + i + 1 - deleted);
        deleted++;
      }
    
    // Суммируем оставшееся
    for (ll x : cpy)
      res += x;
    t.insert(res);
  }

  printf("%d", t.size());

  return 0;
}
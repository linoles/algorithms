#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// O(n! * n)
void gen(vector<int> &nums, unordered_map<int, bool> &used)
{
  // Массив собран, вывод
  if (nums.size() == n)
  {
    for (int x : nums)
      printf("%d ", x);
    printf("\n");
    return;
  }

  for (int x : a)
  {
    // Пропускаем уже использованные
    if (used[x]) continue; // Вместо хеш-таблицы лучше, конечно, пронумеровать числа и сделать vector<bool> по индексам
    
    // Идём "глубже"
    nums.push_back(x);
    used[x] = 1;
    gen(nums, used);
    nums.pop_back();
    used[x] = 0;
  }
}

// Генерация перестановок без next_permutations
int main()
{
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  vector<int> temp = {};
  unordered_map<int, bool> used = {};
  gen(temp, used);

  return 0;
}

// Кол-во перестановок фиксированно n! и не зависит от сортировки массива, как в next_permutation
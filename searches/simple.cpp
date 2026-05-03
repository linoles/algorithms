#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Простой поиск

  * На вход подаётся отсортированный массив и заданное число
  * Возвращается индекс или -1, если не найдено
  * Скорость: O(n), память: O(1)
*/
int simple_search(vector<int> nums, int query) {
  for (int i = 0; i < size(nums); ++i) {
    if (nums[i] == query) {
      return i;
    }
  }

  return -1;
}

int main() {
  // Проверка работы алгоритма вводом
  int n; // Кол-во чисел в массиве
  scanf("%d\n", &n);

  vector<int> nums; // Отсортированный массив
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d ", &temp);
    nums.push_back(temp);
  }

  int query;
  scanf("%d", &query);

  printf("\nResult: %d", simple_search(nums, query));

  return 0;
}

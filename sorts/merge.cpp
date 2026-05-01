#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Функция объединения массивов
vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> res;
  int i = 0; int j = 0; // указатели

  // Работает, т.к. обе части отсортированны
  while (i < size(left) && j < size(right)) {
    if (left[i] > right[j]) {
      res.push_back(right[j]);
      ++j;
    } else {
      res.push_back(left[i]);
      ++i;
    }
  }

  // Добавляем оставшиеся части массивов
  while(i < size(left)) {
    res.push_back(left[i]);
    ++i;
  }
  while(j < size(right)) {
    res.push_back(right[j]);
    ++j;
  }
  
  return res;
}

/*
  ## Сортировка слиянием

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n * log n), память O(n)
*/
vector<int> merge_sort(vector<int> nums) {
  if (size(nums) <= 1) return nums; // Базовый случай

  int mid = floor(size(nums) / 2); // Индекс числа по центру
  vector<int> left(nums.begin(), nums.begin() + mid); // Левая часть
  vector<int> right(nums.begin() + mid, nums.end()); // Правая часть

  left = merge_sort(left); // Рекурсивный вызов
  right = merge_sort(right); // Рекурсивный вызов

  return merge(left, right);
}

int main() {
  // Проверка работы алгоритма вводом
  int n; // Кол-во чисел в массиве
  scanf("%d", &n);

  vector<int> nums; // Начальный массив
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }

  vector<int> res = merge_sort(nums);

  // Вывод результата
  for (int num : res) {
    printf("%d ", num);
  }

  return 0;
}
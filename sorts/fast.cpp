#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Сортировка Хоара

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n * log n), память O(n)
*/
vector<int> fast_sort(vector<int> nums) {
  if (size(nums) <= 1) return nums; // Базовый случай

  int pivot = nums[size(nums) / 2]; // pivot - вариация с средним элементом
  vector<int> left, middle, right;

  for (int x : nums) { // Распределение чисел из начального массива
    if (x < pivot) left.push_back(x);
    else if (x > pivot) right.push_back(x);
    else middle.push_back(x);
  }

  left = fast_sort(left); // Рекурсивный вызов
  right = fast_sort(right); // Рекурсивный вызов

  left.insert(left.end(), middle.begin(), middle.end()); // Добавление к левой части middle-массив
  left.insert(left.end(), right.begin(), right.end()); // Добавление к левой части правый массив
  return left;
}

int main()
{
  // Проверка работы алгоритма вводом
  int n; // Кол-во чисел в массиве
  scanf("%d", &n);

  vector<int> nums; // Начальный массив
  for (int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }

  vector<int> res = fast_sort(nums);

  // Вывод результата
  for (int num : res)
  {
    printf("%d ", num);
  }

  return 0;
}
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Сортировка пузырьком

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n²), память O(n)
*/
vector<int> bubble_sort(vector<int> nums) {
  for (int i = 0; i < size(nums); i++) {
    for (int j = 1; j < size(nums) - i; j++) {
      if (nums[j - 1] > nums[j]) {
        swap(nums[j - 1], nums[j]);
      }
    }
  }

  return nums;
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

  vector<int> res = bubble_sort(nums);

  // Вывод результата
  for (int num : res) {
    printf("%d ", num);
  }

  return 0;
}
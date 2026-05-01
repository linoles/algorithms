#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int find_smallest(vector<int> nums) {
  int smallest = nums[0];
  int smallest_ind = 0;

  for (int i = 0; i < size(nums); ++i) {
    if (nums[i] < smallest) {
      smallest = nums[i];
      smallest_ind = i;
    }
  }

  return smallest_ind;
}

/*
  ## Сортировка выбором

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n²), память O(n)
*/
vector<int> selection_sort(vector<int> &nums) {
  vector<int> res;
  int nums_size = size(nums);

  for (int i = 0; i < nums_size; ++i) {
    int smallest_ind = find_smallest(nums);
    res.push_back(nums[smallest_ind]);
    nums.erase(nums.begin() + smallest_ind);
  }

  return res;
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

  vector<int> res = selection_sort(nums);

  // Вывод результата
  for (int num : res) {
    printf("%d ", num);
  }

  return 0;
}
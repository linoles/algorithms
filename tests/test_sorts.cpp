#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

// Подключаем сортировки
#include "../sorts/bubble.cpp"
#include "../sorts/selection.cpp"
#include "../sorts/insertion.cpp"
#include "../sorts/fast.cpp"
#include "../sorts/merge.cpp"
#include "../sorts/counting.cpp"

// Функция для вывода массива
void printArray(const vector<int> &arr, const string &title = "")
{
  if (!title.empty())
  {
    cout << "  " << title << ": [";
  }
  else
  {
    cout << "  [";
  }

  for (size_t i = 0; i < arr.size(); i++)
  {
    cout << arr[i];
    if (i < arr.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

// Функция для проверки, отсортирован ли массив
bool isSorted(const vector<int> &arr)
{
  for (size_t i = 1; i < arr.size(); i++)
  {
    if (arr[i] < arr[i - 1])
      return false;
  }
  return true;
}

// Генерация случайного массива
vector<int> generateRandomArray(int size, int minVal = 0, int maxVal = 10000)
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(minVal, maxVal);

  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    arr[i] = dist(gen);
  }
  return arr;
}

void testSort(const string &name, vector<int> (*sortFunc)(vector<int>))
{
  cout << "\n[TEST] " << name << endl;
  cout << "----------------------------------------" << endl;

  // Тест 1: Пустой массив
  {
    vector<int> arr = {};
    vector<int> expected = {};
    vector<int> result = sortFunc(arr);

    cout << "  Test: Empty array (" << name << ")" << endl;
    cout << "  Result: " << (result == expected ? "PASS" : "FAIL") << endl;
    cout << endl;
  }

  // Тест 2: Один элемент
  {
    vector<int> arr = {42};
    vector<int> expected = {42};
    vector<int> result = sortFunc(arr);

    cout << "  Test: Single element (" << name << ")" << endl;
    printArray(result, "Result");
    cout << "  Status: " << (result == expected ? "PASS" : "FAIL") << endl;
    cout << endl;
  }

  // Тест 3: Уже отсортированный
  {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};
    vector<int> result = sortFunc(arr);

    cout << "  Test: Already sorted (" << name << ")" << endl;
    printArray(result, "Result");
    cout << "  Status: " << (result == expected ? "PASS" : "FAIL") << endl;
    cout << endl;
  }

  // Тест 4: Обратный порядок (самый важный!)
  {
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> expected = {1, 2, 3, 4, 5};

    cout << "  Test: Reverse order (" << name << ")" << endl;
    printArray(arr, "Input");
    vector<int> result = sortFunc(arr);
    printArray(result, "Result");
    cout << "  Expected: ";
    printArray(expected);
    cout << "  Status: " << (result == expected ? "PASS" : "FAIL") << endl;
    cout << endl;
  }

  // Тест 5: Случайный массив
  {
    vector<int> arr = {3, 7, 1, 9, 2, 8, 4, 6, 5};
    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    cout << "  Test: Random array (" << name << ")" << endl;
    printArray(arr, "Input");
    vector<int> result = sortFunc(arr);
    printArray(result, "Result");
    cout << "  Expected: ";
    printArray(expected);
    cout << "  Status: " << (result == expected ? "PASS" : "FAIL") << endl;
    cout << endl;
  }

  // Тест 6: Массив с дубликатами
  {
    vector<int> arr = {3, 1, 3, 2, 1, 3, 2};
    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    cout << "  Test: Array with duplicates (" << name << ")" << endl;
    printArray(arr, "Input");
    vector<int> result = sortFunc(arr);
    printArray(result, "Result");
    cout << "  Expected: ";
    printArray(expected);
    cout << "  Status: " << (result == expected ? "PASS" : "FAIL") << endl;
    cout << endl;
  }

  // Тест 7: Отрицательные числа
  {
    vector<int> arr = {-5, 3, -1, 0, -2, 4, -3};
    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    cout << "  Test: Negative numbers (" << name << ")" << endl;
    printArray(arr, "Input");
    vector<int> result = sortFunc(arr);
    printArray(result, "Result");
    cout << "  Expected: ";
    printArray(expected);
    cout << "  Status: " << (result == expected ? "PASS" : "FAIL") << endl;
    cout << endl;
  }
}

// Замер производительности для одного размера
void benchmarkSort(const string &name, vector<int> (*sortFunc)(vector<int>), int size)
{
  vector<int> arr = generateRandomArray(size);

  cout << "  " << name << " on " << size << " elements: ";

  auto start = chrono::high_resolution_clock::now();
  vector<int> result = sortFunc(arr);
  auto end = chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

  bool sorted = isSorted(result);

  if (sorted)
  {
    cout << (duration.count() / 1000.0) << " ms [OK]" << endl;
  }
  else
  {
    cout << "[FAIL] NOT SORTED!" << endl;
  }
}

// Полное тестирование производительности для всех размеров
void benchmarkAllSorts(int sizes[], int numSizes)
{
  cout << "\n========================================" << endl;
  cout << "        PERFORMANCE BENCHMARK" << endl;
  cout << "========================================" << endl;

  vector<pair<string, vector<int> (*)(vector<int>)>> sorts = {
      {"Bubble", bubble_sort},
      {"Selection", selection_sort},
      {"Insertion", insertion_sort},
      {"Quick", fast_sort},
      {"Merge", merge_sort},
      {"Counting", counting_sort}};

  for (int s = 0; s < numSizes; s++)
  {
    int size = sizes[s];
    cout << "\n[SIZE] " << size << endl;
    cout << "----------------------------------------" << endl;

    for (const auto &sort : sorts)
    {
      benchmarkSort(sort.first, sort.second, size);
    }
  }
}

int main()
{
  cout << "========================================" << endl;
  cout << "     SORTING ALGORITHMS TEST SUITE" << endl;
  cout << "========================================" << endl;

  testSort("Bubble", bubble_sort);
  testSort("Selection", selection_sort);
  testSort("Insertion", insertion_sort);
  testSort("Quick", fast_sort);
  testSort("Merge", merge_sort);
  testSort("Counting", counting_sort);

  int sizes[] = {100, 500, 1000, 5000, 10000};
  int numSizes = sizeof(sizes) / sizeof(sizes[0]);
  benchmarkAllSorts(sizes, numSizes);

  return 0;
}

// Напомню, что версия быстрой сортировки, представленная тут, не самая быстрая, поэтому в некоторых местах сортировка слиянием может быть быстрее
// Да, сортировка подсчётом может быть быстрая, но она не работает с double (float) и медленна с большими интервалами
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <windows.h>
#include <random>

using namespace std;

// Подключаем ваши сортировки
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

// Универсальная функция тестирования (с реальными expected)
void testSort(const string &name, vector<int> (*sortFunc)(vector<int>))
{
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  cout << "\n📊 Тестируем: " << name << endl;
  cout << "----------------------------------------" << endl;

  // Тест 1: Пустой массив
  {
    vector<int> arr = {};
    vector<int> expected = {};
    vector<int> result = sortFunc(arr);

    cout << "  Тест: Пустой массив (" << name << ")" << endl;
    cout << "  Результат: " << (result == expected ? "✅" : "❌") << endl;
    cout << endl;
  }

  // Тест 2: Один элемент
  {
    vector<int> arr = {42};
    vector<int> expected = {42};
    vector<int> result = sortFunc(arr);

    cout << "  Тест: Один элемент (" << name << ")" << endl;
    printArray(result, "Результат");
    cout << "  Статус: " << (result == expected ? "✅" : "❌") << endl;
    cout << endl;
  }

  // Тест 3: Уже отсортированный
  {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};
    vector<int> result = sortFunc(arr);

    cout << "  Тест: Уже отсортированный (" << name << ")" << endl;
    printArray(result, "Результат");
    cout << "  Статус: " << (result == expected ? "✅" : "❌") << endl;
    cout << endl;
  }

  // Тест 4: Обратный порядок (самый важный!)
  {
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> expected = {1, 2, 3, 4, 5};

    cout << "  Тест: Обратный порядок (" << name << ")" << endl;
    printArray(arr, "Исходный");
    vector<int> result = sortFunc(arr);
    printArray(result, "Результат");
    cout << "  Ожидалось: ";
    printArray(expected);
    cout << "  Статус: " << (result == expected ? "✅" : "❌") << endl;
    cout << endl;
  }

  // Тест 5: Случайный массив
  {
    vector<int> arr = {3, 7, 1, 9, 2, 8, 4, 6, 5};
    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    cout << "  Тест: Случайный массив (" << name << ")" << endl;
    printArray(arr, "Исходный");
    vector<int> result = sortFunc(arr);
    printArray(result, "Результат");
    cout << "  Ожидалось: ";
    printArray(expected);
    cout << "  Статус: " << (result == expected ? "✅" : "❌") << endl;
    cout << endl;
  }

  // Тест 6: Массив с дубликатами
  {
    vector<int> arr = {3, 1, 3, 2, 1, 3, 2};
    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    cout << "  Тест: Массив с дубликатами (" << name << ")" << endl;
    printArray(arr, "Исходный");
    vector<int> result = sortFunc(arr);
    printArray(result, "Результат");
    cout << "  Ожидалось: ";
    printArray(expected);
    cout << "  Статус: " << (result == expected ? "✅" : "❌") << endl;
    cout << endl;
  }

  // Тест 7: Отрицательные числа
  {
    vector<int> arr = {-5, 3, -1, 0, -2, 4, -3};
    vector<int> expected = arr;
    sort(expected.begin(), expected.end());

    cout << "  Тест: Отрицательные числа (" << name << ")" << endl;
    printArray(arr, "Исходный");
    vector<int> result = sortFunc(arr);
    printArray(result, "Результат");
    cout << "  Ожидалось: ";
    printArray(expected);
    cout << "  Статус: " << (result == expected ? "✅" : "❌") << endl;
    cout << endl;
  }
}

// Замер производительности для одного размера
void benchmarkSort(const string &name, vector<int> (*sortFunc)(vector<int>), int size)
{
  vector<int> arr = generateRandomArray(size);

  cout << "  " << name << " на " << size << " элементах: ";

  auto start = chrono::high_resolution_clock::now();
  vector<int> result = sortFunc(arr);
  auto end = chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

  // Проверяем, что массив действительно отсортирован
  bool sorted = isSorted(result);

  if (sorted)
  {
    cout << (duration.count() / 1000.0) << " ms ✅" << endl;
  }
  else
  {
    cout << "❌ НЕ ОТСОРТИРОВАНО!" << endl;
  }
}

// Полное тестирование производительности для всех размеров
void benchmarkAllSorts(int sizes[], int numSizes)
{
  cout << "\n========================================" << endl;
  cout << "    ⚡ ЗАМЕРЫ ПРОИЗВОДИТЕЛЬНОСТИ" << endl;
  cout << "========================================" << endl;

  vector<pair<string, vector<int> (*)(vector<int>)>> sorts = {
      {"Пузырьком", bubble_sort},
      {"Выбором", selection_sort},
      {"Вставкой", insertion_sort},
      {"Быстрая", fast_sort},
      {"Слиянием", merge_sort},
      {"Подсчётом", counting_sort}};

  for (int s = 0; s < numSizes; s++)
  {
    int size = sizes[s];
    cout << "\n📊 Размер массива: " << size << endl;
    cout << "----------------------------------------" << endl;

    for (const auto &sort : sorts)
    {
      benchmarkSort(sort.first, sort.second, size);
    }
  }
}

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  cout << "========================================" << endl;
  cout << "    🧪 ТЕСТИРОВАНИЕ АЛГОРИТМОВ СОРТИРОВКИ" << endl;
  cout << "========================================" << endl;

  // Тестируем каждую сортировку
  testSort("Пузырьком", bubble_sort);
  testSort("Выбором", selection_sort);
  testSort("Вставкой", insertion_sort);
  testSort("Быстрая", fast_sort);
  testSort("Слиянием", merge_sort);
  testSort("Подсчётом", counting_sort);

  // Замеры производительности для разных размеров
  int sizes[] = {100, 500, 1000, 5000, 10000};
  int numSizes = sizeof(sizes) / sizeof(sizes[0]);
  benchmarkAllSorts(sizes, numSizes);

  return 0;
}
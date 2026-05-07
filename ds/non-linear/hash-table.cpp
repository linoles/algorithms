#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
  unordered_map<string, int> table1(16);     // Создание с размером массива значений
  unordered_map<string, int> table2(table1); // Копирование
  unordered_map<string, int> table3(table2); // Перемещение
  unordered_map<string, int> table = {
      {"a", 12},
      {"b", 25},
      {"c", 83},
      {"d", 100},
  }; // Инициализация
  map<string, int> ordered_table = {
      {"a", 12},
      {"b", 25},
      {"c", 83},
      {"d", 100},
  }; // Сортированная хэш-таблица

  // Итераторы
  for (auto it = table.begin(); it != table.end(); it++)
  {
    cout << it->first << ": " << it->second << "\n"; // Получение элементов
  }
  cout << "\n";
  for (auto it = ordered_table.begin(); it != ordered_table.end(); it++)
  {
    cout << it->first << ": " << it->second << "\n"; // Получение элементов
  }

  // Размер, вместимость
  cout << "\nSize: " << size(table);
  cout << "\nMax size: " << table.max_size();
  cout << "\nIs empty: " << table.empty();

  // Доступ, чтение
  table["c"] = 40;    // Добавляет или меняет значение
  int e = table["e"]; // Создаеёт {"e", 0}
  cout << "\n\nc: " << table["c"];

  // Вставка
  table["f"] = -50;
  table.insert({"g", -51});

  // Удаление
  auto deleted = table.erase("f");
  // table.erase(table.begin(), table.end());  // очистка таблицы

  return 0;
}
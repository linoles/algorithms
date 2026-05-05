#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  // Инициализация
  priority_queue<int> max_heap; // Max-Heap - по умолчанию
  priority_queue<int> heap_2;
  priority_queue<int, vector<int>, greater<int>> min_heap; // Min-Heap

  // Вставка
  max_heap.push(50);
  max_heap.push(30);
  max_heap.push(10);

  // Вставка внутрь
  max_heap.emplace(40);

  cout << "Max item: " << max_heap.top(); // Корневой элемент

  // Удаление
  max_heap.pop();
  max_heap.pop();

  cout << "\n\nMax item: " << max_heap.top(); // Корневой элемент
  cout << "\nIs empty: " << max_heap.empty(); // Пуст ли

  max_heap.swap(heap_2); // Свап куч

  return 0;
}
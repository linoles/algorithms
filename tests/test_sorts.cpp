#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
#include <atomic>

using namespace std;

// ================= MEMORY TRACKING =================

atomic<size_t> allocated_bytes(0);
atomic<size_t> allocation_count(0);

template <typename T>
struct CountingAllocator
{
  using value_type = T;

  CountingAllocator() noexcept {}
  template <class U>
  CountingAllocator(const CountingAllocator<U> &) noexcept {}

  T *allocate(size_t n)
  {
    size_t bytes = n * sizeof(T);
    allocated_bytes += bytes;
    allocation_count++;
    return std::allocator<T>().allocate(n);
  }

  void deallocate(T *p, size_t n) noexcept
  {
    std::allocator<T>().deallocate(p, n);
  }
};

using CountingVector = vector<int, CountingAllocator<int>>;

// ================= SORTS =================

#include "../sorts/bubble.cpp"
#include "../sorts/selection.cpp"
#include "../sorts/insertion.cpp"
#include "../sorts/fast.cpp"
#include "../sorts/merge.cpp"
#include "../sorts/counting.cpp"
#include "../sorts/heap.cpp"

// ================= HELPERS =================

bool isSorted(const CountingVector &arr)
{
  for (size_t i = 1; i < arr.size(); i++)
    if (arr[i] < arr[i - 1])
      return false;
  return true;
}

CountingVector generateRandomArray(int size)
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(0, 10000);

  CountingVector arr(size);
  for (int i = 0; i < size; i++)
    arr[i] = dist(gen);

  return arr;
}

// ================= BENCHMARK =================

template <typename Func>
void benchmarkSort(const string &name, Func sortFunc, int size, ofstream &csv)
{
  const int RUNS = 5;

  double total_time = 0;
  size_t total_memory = 0;
  size_t total_allocs = 0;

  for (int i = 0; i < RUNS; i++)
  {
    CountingVector arr = generateRandomArray(size);

    allocated_bytes = 0;
    allocation_count = 0;

    auto start = chrono::high_resolution_clock::now();
    auto result = sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    total_time += duration.count() / 1000.0;
    total_memory += allocated_bytes;
    total_allocs += allocation_count;
  }

  double avg_time = total_time / RUNS;
  size_t avg_memory = total_memory / RUNS;
  size_t avg_allocs = total_allocs / RUNS;

  cout << "  " << name
       << " | time: " << avg_time << " ms"
       << " | mem: " << avg_memory << " B"
       << " | allocs: " << avg_allocs
       << endl;

  csv << name << "," << size << "," << avg_time << ","
      << avg_memory << "," << avg_allocs << "\n";
}

// ================= MAIN BENCH =================

void benchmarkAllSorts(int sizes[], int numSizes)
{
  ofstream csv("results.csv");
  csv << "Algorithm,Size,Time(ms),Memory(bytes),Allocations\n";

  cout << "========================================" << endl;
  cout << "        PERFORMANCE BENCHMARK" << endl;
  cout << "========================================" << endl;

  for (int s = 0; s < numSizes; s++)
  {
    int size = sizes[s];

    cout << "\n[SIZE] " << size << endl;
    cout << "----------------------------------------" << endl;

    benchmarkSort("Bubble", bubble_sort<int, CountingAllocator<int>>, size, csv);
    benchmarkSort("Selection", selection_sort<int, CountingAllocator<int>>, size, csv);
    benchmarkSort("Insertion", insertion_sort<int, CountingAllocator<int>>, size, csv);
    benchmarkSort("Fast", fast_sort<int, CountingAllocator<int>>, size, csv);
    benchmarkSort("Merge", merge_sort<int, CountingAllocator<int>>, size, csv);
    benchmarkSort("Counting", counting_sort<int, CountingAllocator<int>>, size, csv);
    benchmarkSort("Heap", heap_sort<int, CountingAllocator<int>>, size, csv);
  }

  csv.close();
}

// ================= MAIN =================

int main()
{
  int sizes[] = {100, 500, 1000, 5000, 10000};
  int numSizes = sizeof(sizes) / sizeof(sizes[0]);

  benchmarkAllSorts(sizes, numSizes);

  cout << "\nResults saved to results.csv\n";

  return 0;
}

// Напомню, что версия быстрой сортировки, представленная тут, не самая быстрая, поэтому в некоторых местах сортировка слиянием может быть быстрее
// Да, сортировка подсчётом может быть быстрая, но она не работает с double (float) и медленна с большими интервалами
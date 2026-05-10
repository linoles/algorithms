#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/* LSOne(S) - получение последнего бита, равного 1:
 * Пусть S = 52, тогда -(S) = -52
 *
 * 52d = 110100b
 * -52d = 11001100b
 * (-52d = 52d XOR 255d + 1d = 00110100b XOR 11111111b + 1b = 11001011b + 1b = 11001100b)
 *
 * 110100
 *    ^
 * Последний включенный бит
 *
 * Эта проверка последнего бита так и выполняется: (S) & -(S)
 * 00110100 & (AND)
 * 11001100
 * 00000100 = 100b = 4d
 */
#define LSOne(S) ((S) & -(S))
typedef vector<int> vi;

struct FenwickTree
{
private:
  vi ft;

public:
  FenwickTree(int n)
  {
    ft.assign(n + 1, 0);
  }

  int rsq(int j)
  {
    int sum = 0;

    while (j > 0)
    {
      sum += ft[j];
      j -= LSOne(j);
    }

    return sum;
  }

  // O(log n)
  int rsq(int i, int j)
  {
    return rsq(j) - rsq(i - 1);
  }

  // O(log n)
  void update(int i, int val)
  {
    for (; i < ft.size(); i += LSOne(i))
    {
      ft[i] += val;
    }
  }

  // O(n)
  void build(vi &nums)
  {
    int n = nums.size();
    ft.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
      ft[i] += nums[i - 1];
      int parent = i + LSOne(i);
      if (parent <= n)
        ft[parent] += ft[i];
    }
  }

  // O(log²n)
  int select(int k)
  {
    int l = 1;
    int r = ft.size() - 1;
    int ans = ft.size() + 1;

    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (rsq(mid) >= k)
      {
        ans = mid;
        r = ans - 1;
      }
      else
      {
        l = mid + 1;
      }
    }

    return ans;
  }
};

/*
 * Range update and point query
 * Обновление интервалов добавлением +val
 * Получение конкретного query
 */
struct RUPQ
{
private:
  vi ft;

public:
  RUPQ(int n)
  {
    ft.assign(n + 1, 0);
  }

  // Просто вывод diff
  void cout_diff()
  {
    for (int x : ft)
    {
      cout << x << " ";
    }
  }

  // Обновление одного числа O(log n)
  void update(int i, int val)
  {
    while (i < ft.size())
    {
      ft[i] += val;
      i += LSOne(i);
    }
  }

  // Обновление интервала O(log n)
  void range_update(int l, int r, int val)
  {
    update(l, val);
    update(r + 1, -val);
  }

  // Получение query O(log n)
  int point_query(int i)
  {
    int sum = 0;

    while (i > 0)
    {
      sum += ft[i];
      i -= LSOne(i);
    }

    return sum;
  }
};

struct RURQ
{
private:
  RUPQ bit1, bit2; // prefix(i) = i * query(B1, i) − query(B2, i)
  int n;

public:
  RURQ(int n) : bit1(n), bit2(n), n(n) {};

  // Обновление интервала O(log n)
  void range_update(int l, int r, int val)
  {
    bit1.update(l, val);
    bit1.update(r + 1, -val);

    bit2.update(l, (l - 1) * val);
    bit2.update(r + 1, -val * r);
  }

  // Префиксные суммы
  int prefix_sum(int i)
  {
    return i * bit1.point_query(i) - bit2.point_query(i);
  }

  // Получение интервала O(log n)
  int rsq(int l, int r)
  {
    return prefix_sum(r) - prefix_sum(l - 1);
  }

  // Простой вывод деревьев
  void cout_rupq()
  {
    bit1.cout_diff();
    cout << "\n";
    bit2.cout_diff();
  }
};

int main()
{
  FenwickTree ft(8);

  // Заполнение дерева
  vi nums = {1, 3, 5, 7, 9, 11, 13, 15};
  ft.build(nums);

  cout << "sum [2...7] = " << ft.rsq(2, 7) << "\n";   // 3 + 5 + 7 + 9 + 11 + 13
  cout << "sum [1...5] = " << ft.rsq(1, 5) << "\n";   // 1 + 3 + 5 + 7 + 9
  cout << "sum [5...7] = " << ft.rsq(5, 7) << "\n";   // 9 + 11 + 13
  cout << "sum [3...3] = " << ft.rsq(3, 3) << "\n\n"; // 5

  cout << "select(26) = " << ft.select(26) << "\n";   // Такое минимальное i, что [1...i] >= 26
  cout << "select(49) = " << ft.select(49) << "\n\n"; // Такое минимальное i, что [1...i] >= 49

  RUPQ rupq(8);

  // 0 0 0 0 0 0 0 0 0 изначально
  rupq.range_update(2, 5, 5); // 0 0 +5 0 0 0 -5 0 0
                              //      ^        ^
                              //      l       r+1
                              //
                              // l - левая граница, r - правая
  rupq.cout_diff();
  cout << "\n"; // Вывод для наглядности

  rupq.range_update(3, 4, 3); // 0 0 +5 +3 +8 -3 -8 0 0
                              //         ^     ^
                              //         l    r+1
                              //
                              // l - левая граница, r - правая
  rupq.cout_diff();
  cout << "\n\n"; // Вывод для наглядности

  cout << rupq.point_query(5) << "\n";
  cout << rupq.point_query(3) << "\n\n\n";

  RURQ rurq(8);

  rurq.cout_rupq();
  cout << "\n\n";

  rurq.range_update(2, 5, 3); // Массив становится: 0 3 3 3 3 0 0 0
  rurq.cout_rupq();           // Префиксные суммы: 0 3 6 9 12 12 12
  cout << "\n\n";

  rurq.range_update(4, 7, 5); // Массив становится: 0 3 3 8 8 5 5 0
  rurq.cout_rupq();           // Префиксные суммы: 0 3 6 14 22 27 32 32
  cout << "\n\n";

  rurq.range_update(1, 4, 2); // Массив становится: 2 5 5 10 8 5 5 0
  rurq.cout_rupq();           // Префиксные суммы: 2 7 12 22 30 35 40 40
  cout << "\n\n\n";

  cout << "rsq(3, 5): " << rurq.rsq(3, 5) << "\n"; // - - 5 10 8 - - -
  cout << "rsq(4, 7): " << rurq.rsq(4, 7) << "\n"; // - - - 10 8 5 5 -
  cout << "rsq(1, 8): " << rurq.rsq(1, 8);         // 2 5 5 10 8 5 5 0

  return 0;
}
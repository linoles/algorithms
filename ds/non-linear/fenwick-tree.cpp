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
    int r = ft.size();
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

  cout << "select(26) = " << ft.select(26) << "\n"; // Такое минимальное i, что [1...i] >= 26
  cout << "select(49) = " << ft.select(49) << "\n"; // Такое минимальное i, что [1...i] >= 49

  return 0;
}
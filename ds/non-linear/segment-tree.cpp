#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

typedef vector<int> vi;

struct SegmentTree
{
private:
  vi st, nums, lazy;
  int n;

  // Вспомогательные функции для подробного объяснения

  // Проверить, снаружи ли диапазон [l,r] диапазона [i,j]
  bool checkIfOutside(int l, int r, int i, int j)
  {
    return i > j;
  }

  // Проверить, внутри ли диапазон [l,r] диапазона [i,j]
  bool checkIfInside(int l, int r, int i, int j)
  {
    return (l >= i) && (r <= j);
  }

  // Проверить, больше ли диапазон [l,r] диапазона [i,j]
  bool checkIfLarger(int l, int r, int i, int j)
  {
    return !checkIfOutside(l, r, i, j) && !checkIfInside(l, r, i, j);
  }

public:
  SegmentTree(int n, vi &a)
  {
    this->n = n;
    this->nums = a;

    st.assign(pow(2, ceil(log2(n))) * 2 - 1, INT_MAX);
    lazy.assign(pow(2, ceil(log2(n))) * 2 - 1, 0);

    build(1, 0, n - 1);
  };

  // Инициализация O(n)
  void build(int p, int l, int r)
  {
    if (l == r)
      st[p] = nums[l];
    else
    {
      int mid = (l + r) / 2;

      build(2 * p, l, mid);
      build(2 * p + 1, mid + 1, r);

      st[p] = min(st[p * 2], st[p * 2 + 1]);
    }
  }

  // Максимум на отрезке
  int rmq(int p, int l, int r, int i, int j)
  {
    if (i > r || j < l)
      return INT_MAX;
    if (checkIfInside(l, r, i, j))
      return st[p];

    int mid = (l + r) / 2;

    return min(
        rmq(p * 2, l, mid, i, j),
        rmq(p * 2 + 1, mid + 1, r, i, j));
  }

  // Протолкнуть lazy детям
  void push(int p)
  {
    if (lazy[p] != 0)
    {
      st[2 * p] = lazy[p];
      st[2 * p + 1] = lazy[p];

      lazy[2 * p] = lazy[p];
      lazy[2 * p + 1] = lazy[p];

      lazy[p] = 0;
    }
  }

  // Обновление на интервале
  void update(int p, int l, int r, int i, int j, int val)
  {
    if (i > r || j < l)
      return;

    if (checkIfInside(l, r, i, j))
    {
      st[p] = val;
      lazy[p] = val;
      return;
    }

    push(p);

    int mid = (l + r) / 2;
    update(p * 2, l, mid, i, j, val);
    update(p * 2 + 1, mid + 1, r, i, j, val);

    st[p] = min(st[p * 2], st[p * 2 + 1]);
  }
};

int main()
{
  vi nums = {18, 17, 13, 19, 15, 11, 20};
  SegmentTree st(7, nums);

  // 1, 0, 6 - всегда, 6 = n -1
  cout << st.rmq(1, 0, 6, 1, 4) << "\n";    // - 17 13 19 15  -       -     13
  cout << st.rmq(1, 0, 6, 3, 5) << "\n";    // -  -  - 19 15 11       -     11
  cout << st.rmq(1, 0, 6, 7, 7) << "\n\n";  // -  -  -  -  -  - INT_MAX     INT_MAX

                                            // 18 17 13 19 15 11 20 INT_MAX
                                            // ============================
  st.update(1, 0, 6, 2, 4, 30);             // 18 17 30 30 30 11 20 INT_MAX
  st.update(1, 0, 6, 1, 3, 15);             // 18 15 15 15 30 11 20 INT_MAX

  cout << st.rmq(1, 0, 6, 1, 4) << "\n";    // - 15 15 15 30  -       -     15
  cout << st.rmq(1, 0, 6, 3, 5) << "\n";    // -  -  - 15 30 11       -     11
  cout << st.rmq(1, 0, 6, 4, 4) << "\n";    // -  -  -  - 30  -       -     30
  cout << st.rmq(1, 0, 6, 7, 7) << "\n";    // -  -  -  -  -  - INT_MAX     INT_MAX

  return 0;
}
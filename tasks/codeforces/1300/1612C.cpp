#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

// Сумма последовательности 1...n за O(1)
ll sum_1_to_n(ll n)
{
  if (n % 2 == 0)
    return (n / 2) * (n + 1);
  else
    return ((n + 1) / 2) * n;
}

// Сумма последовательности n...m за O(1)
ll sum_n_to_m(ll n, ll m)
{
  return sum_1_to_n(m) - sum_1_to_n(n - 1);
}

// Codeforces 1612C - Бан в чате, O(log n)
int main()
{
  int t, k;
  ll x;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %lld", &k, &x);

    // Если составить массив кол-ва эмоутов на каждое сообщение i,
    // то он будет выглядеть так: {1, 2, ..., n, n - 1, n - 2, ..., 0}

    // Среди преф. сумм такого массива бинарным поиском найдём первое число >= x
    int lo = 0, hi = 2 * k - 2;
    while (lo < hi)
    {
      // Если mid < k, то рассматриваемое число - сумма последовательности 1...mid+1
      // Иначе прибавляется ещё сумма чисел от 2 * k - mid - 1 до k - 1
      int mid = lo + (hi - lo) / 2;
      ll num = sum_1_to_n(min(k, mid + 1));
      if (mid >= k)
        num += sum_n_to_m(2 * k - mid - 1, k - 1);

      if (num < x)
        lo = mid + 1;
      else
        hi = mid;
    }

    printf("%d\n\n", lo + 1);
  }

  return 0;
}
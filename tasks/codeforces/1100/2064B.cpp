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

// Codeforces 2064B - Разнообразие не приветствуется, O(n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    // Нужно найти подотрезок, состоящий из различных элементов наибольшей длины

    // Заполняем массив частот значений
    vi freq(n + 1, 0);
    forn(i, n) freq[a[i]]++;

    // len[i] - длина подотрезка уникальных элементов, заканчивающегося на позиции i
    vi len(n + 1, 0);
    len[0] = freq[a[0]] == 1; // Для первого элемента 1, если он уникален
    // Если элемент уникален, то увеличиваем длину, иначе оставляем len[i] = 0
    forab(i, 1, n) if (freq[a[i]] == 1) len[i] = len[i - 1] + 1;

    // Ищем максимальную длину
    int mx = *max_element(all(len));
    if (mx == 0)
    {
      // Если максимальная длина 0, то нет смысла ничего удалять
      printf("0\n\n");
      continue;
    }

    // Ищем отрезок с максимальной длиной
    forn(i, n) if (len[i] == mx)
    {
      printf("%d %d\n\n", i - len[i] + 2, i + 1);
      break;
    }
  }

  return 0;
}
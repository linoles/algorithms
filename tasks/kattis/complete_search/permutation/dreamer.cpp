
#include <bits/stdc++.h>
using namespace std;

// Является ли год високосным
bool is_leap(int year)
{
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Существует ли такая дата
bool is_date(int day, int month, int year)
{
  if (month < 1 || month > 12)
    return false;
  int dm[14];
  dm[1] = 31;
  dm[2] = is_leap(year) ? 29 : 28;
  dm[3] = 31;
  dm[4] = 30;
  dm[5] = 31;
  dm[6] = 30;
  dm[7] = 31;
  dm[8] = 31;
  dm[9] = 30;
  dm[10] = 31;
  dm[11] = 30;
  dm[12] = 31;
  return day <= dm[month] && day >= 1 && year >= 2000;
}

// Kattis dreamer, O(n)
int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    int a[9];
    scanf("%1d%1d %1d%1d %1d%1d%1d%1d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]);

    sort(a, a + 8);

    bool first_found = 0;
    int first_year, first_month, first_day;
    int total = 0;
    do
    {
      // Получаем и проверяем дату
      int month = a[2] * 10 + a[3];
      int day = a[0] * 10 + a[1];
      int year = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
      bool is_this_date = is_date(day, month, year);

      if (is_this_date)
      {
        // Самая первая дата
        if (!first_found || year < first_year || (year == first_year && month < first_month) || (year == first_year && month == first_month && day < first_day))
        {
          first_found = 1;
          first_year = year;
          first_month = month;
          first_day = day;
        }
        total++;
      }
    } while (next_permutation(a, a + 8));

    if (total == 0)
      printf("0\n");
    else
      printf("%d %.2d %.2d %.4d\n", total, first_day, first_month, first_year);
  }

  return 0;
}
#include <algorithm>
#include <iostream>
#include "../sorts/fast.cpp"
using namespace std;

int find_smallest(vector<int> &nums) {
  int ind = 0; int num = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] < num) {
      num = nums[i];
      ind = i;
    }
  }
  return ind;
}

// O(n²)
int quadratic_solve(vector<int> nums, int k) {
  for (int i = 0; i < k - 1; i++) {
    nums.erase(nums.begin() + find_smallest(nums));
  }
  return nums[find_smallest(nums)];
}


// O(n * log n)
int nlogn_solve(vector<int> nums, int k) {
  vector<int> arr = fast_sort(nums);
  return arr[k - 1];
}


int rand_partition(vector<int> &nums, int l, int r) {
  int pivot_ind = l + rand() % (r - l + 1);
  int pivot = nums[pivot_ind];
  
  swap(nums[pivot_ind], nums[r]);

  int i = l;
  for (int j = i; j < r; j++) {
    if (nums[j] < pivot) {
      swap(nums[i], nums[j]);
      i++;
    }
  }

  swap(nums[i], nums[r]);
  
  return i;
}

// O(n)
int linear_solve(vector<int> nums, int k, int l, int r) {
  if (l == r) return nums[l];
  int q = rand_partition(nums, l, r);
  if (q + 1 == k)
    return nums[q];
  else if (q + 1 > k)
    return linear_solve(nums, k, l, q - 1);
  else
    return linear_solve(nums, k, q + 1, r);
}

int main() {
  int n;
  scanf("%d", &n);

  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }

  int k;
  scanf("%d", &k);

  cout << "\n" << quadratic_solve(nums, k);
  cout << "\n" << nlogn_solve(nums, k);
  cout << "\n" << linear_solve(nums, k, 0, n - 1);

  return 0;
}
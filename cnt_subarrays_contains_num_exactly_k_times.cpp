#include <bits/stdc++.h>  

int countSubarrays(const std::vector<int>& arr, int target, int k) {
  int count = 0, occurrences = 0;
  std::unordered_map<int, int> prefixSumMap;

  // Initialize prefix sum map with 0 occurrences at index -1.
  prefixSumMap[-1] = 0;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == target) {
      occurrences++;
    } else {
      occurrences = 0;
    }

    // Count subarrays with occurrences == k.
    if (occurrences == k) {
      count++;
    }

    // Subtract occurrences k times from prefix sum map for subarrays ending at i.
    prefixSumMap[i] = prefixSumMap[i - k] + (occurrences >= k);

    // Count subarrays with occurrences > k using prefix sum map.
    if (i >= k - 1) {
      count -= prefixSumMap[i - k];
    }
  }

  return count;
}

int main() {
  std::vector<int> arr = {1, 2, 1, 5, 1};
  int target = 1, k = 2;
  int count = countSubarrays(arr, target, k);
  std::cout << "Number of subarrays: " << count << std::endl;
  std::cout << (1<<5) << "\n";
  return 0;
}


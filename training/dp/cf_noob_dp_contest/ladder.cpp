#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::freopen("ladder.in", "r", stdin);
  std::freopen("ladder.out", "w", stdout);
  
  int stairs_count;
  std::cin >> stairs_count;
  
  // Add validation for stairs_count
  if (stairs_count < 0 || stairs_count > 1000000) {
    std::cerr << "Invalid stairs count: " << stairs_count << std::endl;
    return 1;
  }
  
  auto stairs_scores = ReadArray(stairs_count);
  std::vector<int> best_score_on_prefix(stairs_count + 1, std::numeric_limits<int>::min());
  best_score_on_prefix[0] = 0;
  
  for (int stair = 1; stair <= stairs_count; ++stair) {
    best_score_on_prefix[stair] = std::max(best_score_on_prefix[stair],
      best_score_on_prefix[stair - 1] + stairs_scores[stair - 1]);
    if (2 <= stair) {
      best_score_on_prefix[stair] = std::max(best_score_on_prefix[stair],
        best_score_on_prefix[stair - 2] + stairs_scores[stair - 1]);
    }
  }
  
  std::cout << best_score_on_prefix[stairs_count];
  return 0;
}

template <typename T>
std::vector<T> ReadArray(int size, std::istream& in_stream) {
  if (!size) {
    in_stream >> size;
  }
  
  // Add validation for size
  if (size < 0 || size > 1000000) {
    throw std::invalid_argument("Invalid array size: " + std::to_string(size));
  }
  
  std::vector<T> array(size);
  for (auto& element : array) {
    in_stream >> element;
  }
  return array;
}
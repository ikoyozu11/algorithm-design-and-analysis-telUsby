#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int tsp_brute_force(vector<vector<int>>& dist_matrix) {
  int n = dist_matrix.size();
  vector<int> cities(n);
  for (int i = 0; i < n; ++i) {
    cities[i] = i;
  }
  
  int min_cost = INT_MAX;
  do {
    int cost = 0;
    for (int i = 0; i < n - 1; ++i) {
      cost += dist_matrix[cities[i]][cities[i + 1]];
    }
    cost += dist_matrix[cities[n - 1]][cities[0]];
    min_cost = min(min_cost, cost);
  } while (next_permutation(cities.begin() + 1, cities.end()));
  
  return min_cost;
}

int main() {
  vector<vector<int>> dist_matrix = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
  };
  
  int min_cost = tsp_brute_force(dist_matrix);
  cout << "Minimum Cost: " << min_cost << endl;
  
  return 0;
}
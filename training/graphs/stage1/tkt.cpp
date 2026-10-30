#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

long long distinct_pairs(int n) {
    return (long long)n * (n - 1) / 2;
}

vector<vector<int>> find_connected_components(int n, const vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<bool> visited(n, false);
    vector<vector<int>> components;

    auto dfs = [&](int node, vector<int>& component) {
        vector<int> stack = {node};
        while (!stack.empty()) {
            int curr = stack.back();
            stack.pop_back();
            for (int neighbor : graph[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    component.push_back(neighbor);
                    stack.push_back(neighbor);
                }
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            vector<int> component = {i};
            dfs(i, component);
            components.push_back(component);
        }
    }

    return components;
}

long long count_valid_tickets(const vector<vector<int>>& components) {
    long long total_valid_pairs = 0;
    for (const auto& component : components) {
        int size = component.size();
        if (size > 1) {
            total_valid_pairs += (long long)size * (size - 1) / 2;
        }
    }
    return total_valid_pairs;
}

double calculate_probability(long long total_pairs, long long valid_tickets) {
    if (total_pairs == 0) return 0.0;
    return (double)valid_tickets / total_pairs;
}

double solve(int n, int m, const vector<pair<int, int>>& edges) {
    long long total_pairs = distinct_pairs(n);
    auto components = find_connected_components(n, edges);
    long long valid_tickets = count_valid_tickets(components);
    return calculate_probability(total_pairs, valid_tickets);
}

int main() {
    int n = 5;  // number of cities
    int m = 3;  // number of claimed rail segments
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {3, 4}};  // claimed rail segments

    double result = solve(n, m, edges);
    printf("Probability of earning points: %.6f\n", result);

    return 0;
}


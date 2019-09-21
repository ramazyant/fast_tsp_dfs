#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

int best = INT_MAX;

void TSP(int n, int source, int k, int cost, std::vector<int> &vertices, std::vector<std::vector<int>> &graph, int & result) {
    if (cost > best) {
        return;
    }
    //
    if (k == n && graph[source][0]) {
        result = std::min(result, cost + graph[source][0]);
        best = result;
        return;
    }
    //
    for (int i = 0; i < n; i++) {
        if (std::abs(vertices[i] - 1) && graph[source][i]) {
            vertices[i] = 1;
            TSP(n, i, k + 1, cost + graph[source][i], vertices, graph, result);
            vertices[i] = 0;
        }
    }
}

int main() {
    int n, input, min_path = INT_MAX;
    std::cin >> n;
    //
    std::vector<std::vector<int>> graph;
    std::vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> input;
            temp[j] = input;
        }
        graph.push_back(temp);
    }
    //
    std::fill(temp.begin(), temp.end(), 0);
    temp[0] = 1;
    //
    TSP(n, 0, 1, 0, temp, graph, min_path);
    //
    if (n == 1) {
        std::cout << 0 << std::endl;
    } else if (min_path == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << min_path << std::endl;
    }
    //
    return 0;
}

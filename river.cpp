#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int id, distance;
    std::vector<int> neighbours;

    Node(int id, int distance) : id(id), distance(distance) {}
    void add(int neighbour){
        neighbours.push_back(neighbour);
    }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);



    int n, m, s, d;
    std::cin >> n >> m >> s >> d;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> distances(n, -1);
    std::vector<bool> visited(n, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int maxDist = 0;
    std::queue<Node> q;
    q.push(Node(s, 0));
    distances[s] = 0;
    visited[s] = true;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        maxDist = std::max(maxDist, node.distance);

        for (int neigh : graph[node.id]) {
            if (!visited[neigh]) {
                distances[neigh] = node.distance + 1;
                visited[neigh] = true;
                q.push(Node(neigh, distances[neigh]));
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (i != s && distances[i]*2 <= d && distances[i] > 0 && visited[i]) {
            count++;
        }
    }

    std::cout << maxDist << " " << count << "\n";

    return 0;}

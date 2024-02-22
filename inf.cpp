#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Point {
    int row, col, distance, monitoredCount;

    Point(int row, int col, int distance, int monitoredCount)
        : row(row), col(col), distance(distance), monitoredCount(monitoredCount) {}

    bool operator>(const Point& other) const {
        return distance > other.distance || (distance == other.distance && monitoredCount > other.monitoredCount);
    }
};

bool isWithinBounds(int row, int col, int numRows, int numCols) {
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

pair<int, int> findShortestPath(vector<vector<char>>& map, int numRows, int numCols) {
    int startRow, startCol, endRow, endCol;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (map[i][j] == 'S') {
                startRow = i;
                startCol = j;
            } else if (map[i][j] == 'X') {
                endRow = i;
                endCol = j;
            }
        }
    }

    const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

    priority_queue<Point, vector<Point>, greater<Point>> pq;
    pq.push(Point(startRow, startCol, 0, 0));

    while (!pq.empty()) {
        Point current = pq.top();
        pq.pop();

        int row = current.row;
        int col = current.col;
        int distance = current.distance;
        int monitoredCount = current.monitoredCount;

        if (row == endRow && col == endCol) {
            return {distance, monitoredCount};
        }

        if (visited[row][col]) {
            continue;
        }

        visited[row][col] = true;

        for (int i = 0; i < 4; ++i) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];

            if (isWithinBounds(newRow, newCol, numRows, numCols) && !visited[newRow][newCol] && map[newRow][newCol] != '#') {
                int newMonitoredCount = monitoredCount + (map[newRow][newCol] == 'M' ? 1 : 0);
                pq.push(Point(newRow, newCol, distance + 1, newMonitoredCount));
            }
        }
    }

    return {INT_MAX, INT_MAX};
}

int main() {
    int numRows, numCols;
    cin >> numRows >> numCols;

    vector<vector<char>> map(numRows, vector<char>(numCols));

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> map[i][j];
        }
    }

    pair<int, int> result = findShortestPath(map, numRows, numCols);

    cout << result.first << " " << result.second << endl;

    return 0;
}

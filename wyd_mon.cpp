#include <iostream>
#include <algorithm>

using namespace std;

bool compareColumns(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

bool canPlaceCameras(pair<int, int>* columns, int n) {
    sort(columns, columns + n, compareColumns);

    bool* selected = new bool[n];
    fill(selected, selected + n, false);

    for (int i = 0; i < n; ++i) {
        int start = columns[i].first, end = columns[i].second;

        bool found = false;

        for (int j = start; j <= end; ++j) {
            if (!selected[j]) {
                selected[j] = true;
                found = true;
                break;
            }
        }

        if (!found) {
            delete[] selected;
            return false;
        }
    }

    delete[] selected;
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        pair<int, int>* columns = new pair<int, int>[n];

        for (int i = 0; i < n; ++i) {
            cin >> columns[i].first >> columns[i].second;
        }

        if (canPlaceCameras(columns, n)) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }

        delete[] columns;
    }

    return 0;
}

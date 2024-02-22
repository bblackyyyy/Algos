#include <iostream>
#include <algorithm> 
using namespace std;

const int MAX = 1000; 

int countComb(int calories[], int n, int k, int index = 0, int currentSum = 0) {
    if (currentSum > k) return 0;
    if (currentSum == k) return 1;
    if (index == n) return 0;

    int include = countComb(calories, n, k, index + 1, currentSum + calories[index]);
    int exclude = countComb(calories, n, k, index + 1, currentSum);

    return include + exclude;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int calories[MAX];
        for (int i = 0; i < n; ++i) {
            cin >> calories[i];
        }
        cin >> k;

        sort(calories, calories + n, greater<int>());

        cout << countComb(calories, n, k) << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

struct Box {
    float* val = nullptr;
    int num;
    int id;
    int sum;
};

bool compareBoxes(Box a, Box b) {
    if (a.sum == b.sum) {
        return a.id < b.id;
    }
    return a.sum < b.sum;
}

void countingSort(Box arr[], int n, int exp, int maxDigits) {
    const int RANGE = 1002;
    Box output[n];
    int count[RANGE] = {0};

    for (int i = 0; i < n; i++) {
        int index = static_cast<int>(arr[i].sum / exp) % RANGE;
        count[index]++;
    }

    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = static_cast<int>(arr[i].sum / exp) % RANGE;
        int pos = --count[index];
        output[pos] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    m = m + 1;

    Box arr[n];

    for (int i = 0; i < n; i++) {
        arr[i].val = new float[m];
        arr[i].num = m;
        arr[i].id = i;
        arr[i].sum = 0;

        for (int j = 0; j < m - 1; j++) {
            cin >> arr[i].val[j];
            arr[i].sum += arr[i].val[j] * 1000;
        }
    }

    for (int exp = 1; exp <= 1000; exp *= 10) {
        countingSort(arr, n, exp, m);
    }

    
    
      bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < n - 1; i++) {
                if (arr[i].sum == arr[i + 1].sum && arr[i].id < arr[i + 1].id) {
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped);

    int nn = n - p;
    for (int i = n - 1; i >= nn; i--) {
        for (int j = 0; j < m - 1; j++) {
            cout << arr[i].val[j] << " ";
        }
        cout << endl;
        delete[] arr[i].val;
    }

    return 0;
}

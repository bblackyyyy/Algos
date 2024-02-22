#include <iostream>
#include <cstring>

using namespace std;

struct Place {
    char name[20];
    int act;
    int id;
};

// void swap(Place& a, Place& b) {
//     Place temp = a;
//     a = b;
//     b = temp;
// }

void heapify(Place* heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && (heap[left].act > heap[largest].act || (heap[left].act == heap[largest].act && heap[left].id < heap[largest].id))) {
        largest = left;
    }
    if (right < n && (heap[right].act > heap[largest].act || (heap[right].act == heap[largest].act && heap[right].id < heap[largest].id))) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void add(Place* heap, int& size, const Place& loc) {
    int i = size++;
    heap[i] = loc;
    while (i != 0 && (heap[(i - 1) / 2].act < heap[i].act || (heap[(i - 1) / 2].act == heap[i].act && heap[(i - 1) / 2].id > heap[i].id))) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Place get(Place* heap, int& size) {
  // if (size == 0) {
  //     throw runtime_error(" ");
  // }
    Place maxItem = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(heap, size, 0);
    return maxItem;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, L;
    char name[20];

    cin >> n;
    Place* heap = new Place[n];
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        cin >> name >> L;
        Place p;
        strcpy(p.name, name);
        p.act = L;
        p.id = i;
        add(heap, heapSize, p);
    }

    cin >> k;

    while (heapSize > 0 && k > 0) {
        Place loc = get(heap, heapSize);
        if (loc.act <= k) {
            k -= loc.act;
            cout << loc.name << " ";
        }
    }

    cout << endl;

    delete[] heap;

    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory>
using namespace std;

double P(int i, int j);// {
//    return 30 - sqrt((i - 5) * (i - 5) + (j - 5) * (j - 5));
//}

double findPeak(int startRow, int endRow, int startCol, int endCol) {
    if (startRow > endRow || startCol > endCol)
        return -1;

    int midRow = (startRow + endRow) / 2;
    int midCol = (startCol + endCol) / 2;

    double maxVal = P(midRow, midCol);
    int maxIndexRow = midRow;
    int maxIndexCol = midCol;

   
    if (midRow > startRow && P(midRow - 1, midCol) > maxVal) {
        return findPeak(startRow, midRow - 1, startCol, endCol);
    }
    if (midRow < endRow && P(midRow + 1, midCol) > maxVal) {
        return findPeak(midRow + 1, endRow, startCol, endCol);
    }
    if (midCol > startCol && P(midRow, midCol - 1) > maxVal) {
        return findPeak(startRow, endRow, startCol, midCol - 1);
    }
    if (midCol < endCol && P(midRow, midCol + 1) > maxVal) {
        return findPeak(startRow, endRow, midCol + 1, endCol);
    }

    
    for (int j = startCol; j <= endCol; j++) {
        double val = P(midRow, j);
        if (val > maxVal) {
            maxVal = val;
            maxIndexRow = midRow;
            maxIndexCol = j;
        }
    }

    
    for (int i = startRow; i <= endRow; i++) {
        double val = P(i, midCol);
        if (val > maxVal) {
            maxVal = val;
            maxIndexRow = i;
            maxIndexCol = midCol;
        }
    }

    return maxVal;
}

int main() {
    int n, m;
    cin >> n >> m;

    
    double peak = findPeak(0, n - 1, 0, m - 1);

  
    
        int peakInt = std::floor(peak);
        cout << peakInt << endl;
    

    return 0;
}

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** S, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** S, const int rowCount, const int colCount);
bool SortIteratively(int** S, const int rowCount, const int colCount);
void Change(int** S, const int row1, const int row2, const int colCount);
void CalcIteratively(int** S, const int rowCount, const int colCount, int& sum, int& count);

int main() {
    srand((unsigned)time(NULL));

    const int rowCount = 7;  
    const int colCount = 6; 
    const int Low = 9;
    const int High = 61;

    int** S = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        S[i] = new int[colCount];

    
    Create(S, rowCount, colCount, Low, High);
    cout << endl;
    Print(S, rowCount, colCount);

    
    cout <<  endl;
    while (SortIteratively(S, rowCount, colCount)) {
        cout << endl;
        Print(S, rowCount, colCount);
    }

   
    int sum = 0, count = 0;
    CalcIteratively(S, rowCount, colCount, sum, count);

   
    cout << endl;
    Print(S, rowCount, colCount);
    cout << "S = " << sum << endl;
    cout << "k = " << count << endl;

   
    for (int i = 0; i < rowCount; i++)
        delete[] S[i];
    delete[] S;

    return 0;
}

void Create(int** S, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            S[i][j] = Low + rand() % (High - Low + 1);  // Випадкові числа в діапазоні (9, 61)
        }
    }
}

void Print(int** S, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << S[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


bool SortIteratively(int** S, const int rowCount, const int colCount) {
    bool swapped = false;

    for (int i = 0; i < rowCount - 1; i++) {
        for (int j = 0; j < rowCount - i - 1; j++) {
            if ((S[j][0] > S[j + 1][0]) ||
                (S[j][0] == S[j + 1][0] && S[j][1] < S[j + 1][1]) ||
                (S[j][0] == S[j + 1][0] && S[j][1] == S[j + 1][1] && S[j][2] < S[j + 1][2])) {
                Change(S, j, j + 1, colCount);
                swapped = true;
            }
        }
    }

    return swapped;
}


void Change(int** S, const int row1, const int row2, const int colCount) {
    for (int i = 0; i < colCount; i++) {
        int temp = S[row1][i];
        S[row1][i] = S[row2][i];
        S[row2][i] = temp;
    }
}

void CalcIteratively(int** S, const int rowCount, const int colCount, int& sum, int& count) {
    sum = 0;
    count = 0;

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            
            if (S[i][j] % 2 != 0 && (i + j) % 7 == 0) {
                continue;  
            }
            sum += S[i][j];
            count++;
            S[i][j] = 0;  
        }
    }
}

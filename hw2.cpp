#include <iostream>
#include <fstream>
#define small_col 4
#define smallOD_col 3

using namespace std;

// read from Small.txt and return a int array
void ReadSmall() {
    int N = 0;
    ifstream readfile("Small.txt");
    if (!readfile) {
        cout << "wrong" << endl;
        system ("pause");
        return;
    }

    readfile >> N;

    int small_array[N][small_col];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < small_col; j++) {
            readfile >> small_array[i][j]; 
            printf("row%d, col%d, val=%d\n", i, j, small_array[i][j]);
        }
    }
    readfile.close();
    return;

    // continue for printing and creating other data structures
}

void ReadSmallOD() {
    int N = 0;
    ifstream readfile("SmallOD.txt");
    if (!readfile) {
        cout << "wrong" << endl;
        system ("pause");
        return;
    }

    readfile >> N;

    int smallOD_array[N][smallOD_col];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < smallOD_col; j++) {
            readfile >> smallOD_array[i][j]; 
            printf("row%d, col%d, val=%d\n", i, j, smallOD_array[i][j]);
        }
    }
    readfile.close();
    return;

    // continue for printing and creating other data structures
}

int main() {
    ReadSmall();
    ReadSmallOD();
    return 0;
}

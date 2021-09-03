// g++ hw2.cpp -o hw2.out -std=c++11
#include <iostream>
#include <deque>
#include <fstream>
#include <math.h>
#define small_col 4
#define smallOD_col 3

using namespace std;

void hw2_push_back(int next_node, int i, deque<int> &d, int small_array[][small_col], int *Cost, int *Pre_Node) {
    auto it = d.begin();
    while(it != d.end()) {
        if(*it == next_node) {
            // cout << "Found existed node " << next_node << endl;
            for(int j = 0; j < i; j++) {
                int old_current_node = small_array[j][0];
                int old_next_node = small_array[j][1];
                int old_cost = small_array[j][2];
                if(old_current_node == next_node) {
                    if(Cost[old_current_node - 1] != (int)INFINITY && Cost[old_current_node - 1] + old_cost < Cost[old_next_node - 1]) {
                        Cost[old_next_node - 1] = Cost[old_current_node - 1] + old_cost;
                        Pre_Node[old_next_node - 1] = old_current_node;
                        hw2_push_back(old_next_node, i, d, small_array, Cost, Pre_Node);
                    }
                }
            }
            break; 
        }
        it++;
    }
    if(it == d.end()) {
        d.push_back(next_node);
        // cout << "Push back new node " << next_node << endl;
        // for (auto it = d.begin(); it != d.end(); ++it) {
        //     cout << *it << " ";
        // }
        // cout << "\n";
    }
}

void PrintQueue(int end_node, int start_node, int *Pre_Node, int *Cost) {
    int pre_node = Pre_Node[end_node];
    
    while(pre_node != start_node) {
        cout << "<-" << pre_node;
        pre_node = Pre_Node[pre_node - 1];
    }
    if(pre_node == start_node) {
        cout << "<-" << pre_node;        
    }

    cout << "  cost=" << Cost[end_node] << endl;
}

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
    int max_node = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < small_col; j++) {
            readfile >> small_array[i][j]; 
            // printf("row%d, col%d, val=%d\n", i, j, small_array[i][j]);
        }
        max_node = max(max_node, small_array[i][0]);
    }
    readfile.close();
    
    for(int i = 0; i < max_node; i++) {
        deque<int> d = {};
        for(int ii = 0; ii <= i; ii++) {
            d.push_back(ii + 1);
        }
        int Pre_Node[max_node];
        int Cost[max_node];
        for(int j = 0; j < max_node; j++) {
            if(j == i) {
                Pre_Node[j] = j + 1;
                Cost[j] = 0;
            }
            else {
                Pre_Node[j] = -1;
                Cost[j] = (int)INFINITY;
            }
        }

        // iterate N times, N = input row number
        for(int k = 0; k < N; k++) {
            int current_node = small_array[k][0];
            int next_node = small_array[k][1];
            int cost = small_array[k][2];
            if( Cost[current_node - 1] != (int)INFINITY && Cost[current_node - 1] + cost < Cost[next_node - 1]) {
                Cost[next_node - 1] = Cost[current_node - 1] + cost;
                Pre_Node[next_node - 1] = current_node;
                hw2_push_back(next_node, k, d, small_array, Cost, Pre_Node);
            }
        }
        
        // // for checking!
        // cout << "Pre_Node" << endl;
        // for(int i = 0; i < 6; i++) {
        //     cout << Pre_Node[i] << "\t";
        // }
        // cout << endl << "Cost" << endl;
        // for(int i = 0; i < 6; i++) {
        //     cout << Cost[i] << "\t";
        // }

        cout << "\nResult for " << i+1 << endl;
        for(int l = 0; l < max_node; l++){
            if(l != i) {
                cout << l+1;
                PrintQueue(l, i+1, Pre_Node, Cost);
            }
        }
        cout << "\n\n";
    }
    return;
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
            // printf("row%d, col%d, val=%d\n", i, j, smallOD_array[i][j]);
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

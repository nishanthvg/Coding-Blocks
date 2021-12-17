#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int number) {
    // cout << i << " " << j << endl;
    for(int x = 0; x < n; x++) {
        if(mat[i][x] == number || mat[x][j] == number) {
            return false;
        } 
    }

    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;
    // cout << sx << " " <<  sy << endl;
    // cout << " -- " <<number <<  endl;
    for(int x = sx; x < (sx + 3); x++) {
        for(int y = sy; y < (sy + 3); y++) {
            if(mat[x][y] == number) {
                return false;
            }
        }
    }

    return true;
}

bool solver(int mat[][9], int i, int j,int n) {
    if(i == n) {
        //print the matrix 
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                cout << mat[x][y] << " ";
            }
            cout << endl;
        }
        return true;
    }

    if(j == n) {
        // cout << "base_case 2" <<endl;
        return solver(mat, i + 1, 0, n);
    }

    if(mat[i][j] != 0){
        // cout << "base_case 3" <<endl;
        return solver(mat, i, j+1, n);
    }

    for(int number = 1; number <= 9; number++) {
        if(canPlace(mat, i, j, n, number)) {
            mat[i][j] = number;

            bool checkPlacement = solver(mat, i ,j+1, n);
            if(checkPlacement) {
                return true;
            }
        }
    }
    mat[i][j] = 0;
    return false;
}

int main() {
    int n = 9;
    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    solver(mat, 0,0,n);
    return 0;
}
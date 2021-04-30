#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

float f[4][4];
float F1[4][4] = {0};
float F[4][4] = {0};
float H[4][4] = {
    { 1,  1,  1,  1},
    { 2,  1, -1, -2},
    { 1, -1, -1,  1},
    { 1, -2,  2, -1}};
float Ht[4][4] = {0};

int main (){

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> f[i][j];
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            Ht[j][i] = H[i][j];
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                F1[i][j] += H[i][k] * f[k][j];
            }
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << F1[i][j] << ' ';
        }
        cout << endl << endl;
    }


    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                F[i][j] += F1[i][k] * Ht[k][j];
            }
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << F[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}



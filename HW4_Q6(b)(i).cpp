#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int Reference_frame[8][8];    // [y][x]
int Target_frame[4][4]        // [y][x]
 = {{120, 141, 162, 183},
    {131, 152, 173, 194},
    {142, 163, 183, 204},
    {148, 168, 189, 209}};

int main(){

    // Conatruct the Reference frame
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> Reference_frame[i][j];
        }
    }

    int error_matrix[4][4];
    int min_error_matrix[4][4];
    int sum = 0, min = -1;
    int min_x = -1, min_y = -1;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            sum = 0;
            for(int k=0; k<4; k++){
                for(int l=0; l<4; l++){
                    error_matrix[k][l] = Reference_frame[i+k][j+l] - Target_frame[k][l];
                    sum +=  abs(error_matrix[k][l]);
                }
            }
            if(sum < min || min == -1) {
                min = sum;
                min_x = j;
                min_y = i;
                for(int k=0; k<4; k++){
                    for(int l=0; l<4; l++){
                        min_error_matrix[k][l] = error_matrix[k][l];
                    }
                }
            }
        }
    }
    
    cout << "Error matrix" << endl;
    for(int k=0; k<4; k++){
        for(int l=0; l<4; l++){
            cout << setw(3) << min_error_matrix[k][l] << ' ';
        }
        cout << endl;
    }
    cout<< "MV(x, y) = (" << min_x << ", " << min_y << ")\n";
    cout << "MAE = " << min << " / 16 = " << (float)min/16 << endl;

    return 0;
}
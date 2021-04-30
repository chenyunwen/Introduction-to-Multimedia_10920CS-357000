#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int Reference_frame[13][13];    // [x][y]
int Target_frame[4][4];         // [x][y]

int main(){

    // Conatruct the intensity values of Reference frame
    for(int i=0; i<13; i++){
        for(int j=0; j<13; j++){
            Reference_frame[i][j] = 80;
        }
    }

    Reference_frame[1][5]
    = Reference_frame[2][3]
    = Reference_frame[2][4]
    = Reference_frame[2][5]
    = Reference_frame[3][2]
    = Reference_frame[3][3]
    = Reference_frame[4][3]
    = Reference_frame[4][4]
    = 20;

    cout << "\nReference frame" << endl;
    for(int i=0; i<13; i++){
        for(int j=0; j<13; j++){
            cout << Reference_frame[j][i] << ' ';
        }
        cout << endl;
    }

    // Conatruct the intensity values of Target frame
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            Target_frame[i][j] = 80;
        }
    }
    Target_frame[0][1]
    = Target_frame[0][2]
    = Target_frame[0][3]
    = Target_frame[1][0]
    = Target_frame[1][1]
    = Target_frame[1][2]
    = Target_frame[2][1]
    = Target_frame[2][2]
    = Target_frame[3][1]
    = 20;

    cout << "\nmacroblocks\n";
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << Target_frame[j][i] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    int error_matrix[4][4];
    int min_error_matrix[4][4];
    int sum = 0, min = 60*4*4;
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
            if(sum < min) {
                min = sum;
                min_x = j-5;
                min_y = i-5;
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
            cout << setw(3) << min_error_matrix[l][k] << ' ';
        }
        cout << endl;
    }
    cout<< "MV(x, y) = (" << min_x << ", " << min_y << ")\n";
    cout << "MAE = " << min << " / 16 = " << (float)min/16 << endl;

    return 0;
}
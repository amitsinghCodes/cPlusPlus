#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define ROWS 5
#define COLS 5

int findLargestSquare(int matrix[ROWS][COLS]) {
    int dp[ROWS][COLS] = {0};  // DP array to store largest square sizes
    int maxSquareSize = 0;

    // Copy the first row and first column from the original matrix
    for (int i = 0; i < ROWS; i++)
        dp[i][0] = matrix[i][0];

    for (int j = 0; j < COLS; j++)
        dp[0][j] = matrix[0][j];

    // Compute the DP values for squares
    for (int i = 1; i < ROWS; i++) {
        for (int j = 1; j < COLS; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxSquareSize = max(maxSquareSize, dp[i][j]);
            }
        }
    }

    return maxSquareSize;  // Returns the side length of the largest square
}

int main(){
    string  letters[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}
    };

    for (int i = 0; i<2; i++){
        for(int j = 0;  j<4; j++){
            cout<< letters[i][j]<< "\n";
        }
    }

    string letters2[2][2][2] = {
        {
        {"AB", "BC"}, {"CD" ,"DE"}
        },
        {
            {"EF","FG"},{"GH","HI"}
        }
    };

    for (int i = 0; i<2; i++){
    for(int j = 0; j<2; j++){
        for(int k =0; k<2 ;  k++){
            cout<<letters2[i][j][k]<<"\n";}}}

            char array[4][4] = {
                {'a','b','c','d'},
                {'e','f','g','h'},
                {'i','j','k','l'},
                {'m','n','o','p'}
            };
            for (int i = 0; i<4; i++){
                for(int j = 0; j<4; j++){
                    cout<<array[i][j]<<i<<j<<"\n";
                }
            }


            int matrix[ROWS][COLS] = {
                {0, 1, 0, 0, 1},
                {0, 1, 1, 1, 1},
                {0, 1, 1, 1, 0},
                {0, 1, 1, 1, 0},
                {0, 0, 0, 1, 1}
            };
        
            int maxSquare = findLargestSquare(matrix);
            cout << "Largest square side length: " << maxSquare << endl;
        
            
    return 0;
}
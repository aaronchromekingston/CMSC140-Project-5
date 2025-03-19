/*
 * Class: CMSC140
 * Instructor: Charles Naegeli
 * Project 5
 * Description: Lo Shu Magic Square validator using parallel arrays.
 * Due Date:
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Aaron Kingston
 */
//io stream inclusion
#include <iostream>
using namespace std;
//-------------------------------------------------------------------------------------------------------------------------//
// constnats (global)
const int  ROWS = 3;
const int COLS = 3;
const int MIN = 1;
const int MAX = 9;
//
//prototype functions
    // void statements
void fillArray (int arrayRow1 [] , int arrayRow2 [] , int arrayRow3 [] ) ;
void showArray (int arrayRow1 [] , int arrayRow2 [] , int arrayRow3 [] ) ;
//bool section off / down
bool isMagicSquare (int arrayRow1 [] , int arrayRow2 [] , int arrayRow3 [] ) ;
bool checkRange  (int arrayRow1 [] , int arrayRow2 [] , int arrayRow3 [] ) ;
bool checkUnique  (int arrayRow1 [] , int arrayRow2 [] , int arrayRow3 [] ) ;
bool checkRowSum  (int arrayRow1 [] , int arrayRow2 [] , int arrayRow3 [] ) ;
bool checkColSum  (int arrayRow1 [] , int arrayRow2 [] , int arrayRow3 [] ) ;
bool checkDiagSum  (int arrayRow1 [] , int arrayRow2 [] , int arrayRow3 [] ) ;
//-------------------------------------------------------------------------------------------------------------------------//
int main () {
    int row1[COLS], row2[COLS], row3[COLS];
        char repeat;

        do {
//grid fill
            fillArray(row1, row2, row3);

//grid display
            showArray(row1, row2, row3);
//check magic square
            if (isMagicSquare(row1, row2, row3)) {
                cout << "This is a Lo Shu Magic Square!\n";
            } else {
                cout << "This is NOT a Lo Shu Magic Square.\n";
            }
//try again prompt
            cout << "Do you want to try again? (y/n): ";
            cin >> repeat;
        } while (repeat == 'y' || repeat == 'Y');

        cout << "\nProgram terminated.\n";
        return 0;
    }
void fillArray (int arrayRow1[], int arrayRow2[], int arrayRow3[]) {
    cout << "Enter 3 values for Row 1 (1-9): ";
    for (int i = 0; i < COLS; i++) {
        cin >> arrayRow1[i];
    }
    cout << "Enter 3 values for Row 2 (1-9): ";
        for (int i = 0; i < COLS; i++) {
            cin >> arrayRow2[i];
        }
        cout << "Enter 3 values for Row 3 (1-9): ";
        for (int i = 0; i < COLS; i++) {
            cin >> arrayRow3[i];
        }
    }
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[]) {
    cout << "\nThe entered square is:\n";
    for (int i = 0; i < COLS; i++) {
        cout << arrayRow1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < COLS; i++) {
        cout << arrayRow2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < COLS; i++) {
        cout << arrayRow3[i] << " ";
    }
    cout << endl;
}
//bool section organization ->
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[]) {
    return checkRange(arrayRow1, arrayRow2, arrayRow3) &&
           checkUnique(arrayRow1, arrayRow2, arrayRow3) &&
           checkRowSum(arrayRow1, arrayRow2, arrayRow3) &&
           checkColSum(arrayRow1, arrayRow2, arrayRow3) &&
           checkDiagSum(arrayRow1, arrayRow2, arrayRow3);
}
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[]) {
    for (int i = 0; i < COLS; i++) {
        if (arrayRow1[i] < MIN || arrayRow1[i] > MAX ||
            arrayRow2[i] < MIN || arrayRow2[i] > MAX ||
            arrayRow3[i] < MIN || arrayRow3[i] > MAX) {
            return false;
        }
    }
    return true;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[]) {
    bool seen[MAX] = {false};
    int allValues[ROWS * COLS] = {
        arrayRow1[0], arrayRow1[1], arrayRow1[2],
        arrayRow2[0], arrayRow2[1], arrayRow2[2],
        arrayRow3[0], arrayRow3[1], arrayRow3[2]
    };

    for (int i = 0; i < ROWS * COLS; i++) {
        if (seen[allValues[i] - 1]) { // if all the values are seen.
            return false;
        }
        seen[allValues[i] - 1] = true;
    }
    return true;
}

bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[]) {
    int sum1 = arrayRow1[0] + arrayRow1[1] + arrayRow1[2];
    int sum2 = arrayRow2[0] + arrayRow2[1] + arrayRow2[2];
    int sum3 = arrayRow3[0] + arrayRow3[1] + arrayRow3[2];
    return (sum1 == sum2) && (sum2 == sum3);
}

bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[]) {
    for (int i = 0; i < COLS; i++) {
        if (arrayRow1[i] + arrayRow2[i] + arrayRow3[i] != 15) {
            return false;
        }
    }
    return true;
}

bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[]) {
    int diag1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    int diag2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];
    return diag1 == diag2;
}

#include<iostream>
using namespace std;

char space[3][3] = {{'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}};
int row;
int column;
char token = 'x';
bool tie = false;
string n1 = "";
string n2 = "";

void functionOne() {
    cout << "     |     |     \n";
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
    cout << "     |     |     \n";
}

void functionTwo() {
    int digit;
    if (token == 'x') {
        cout << n1 << ", please enter a number (1-9): ";
        cin >> digit;
    } else {
        cout << n2 << ", please enter a number (1-9): ";
        cin >> digit;
    }

    if (digit >= 1 && digit <= 9) {
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (space[row][column] != 'x' && space[row][column] != '0') {
            if (token == 'x') {
                space[row][column] = 'x';
                token = '0';
            } else {
                space[row][column] = '0';
                token = 'x';
            }
        } else {
            cout << "Invalid move. Please choose an empty space.\n";
            functionTwo(); // Ask for input again
        }
    } else {
        cout << "Invalid input. Please enter a number between 1 and 9.\n";
        functionTwo(); // Ask for input again
    }
}

bool functionThree() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }

    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
        return true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player: ";
    cin >> n1;
    cout << "Enter the name of the second player: ";
    cin >> n2;

    cout << n1 << " is Player 1, so he/she will play 'x'.\n";
    cout << n2 << " is Player 2, so he/she will play '0'.\n";

    while (!functionThree()) {
        functionOne();
        functionTwo();
        functionThree();
    }

    functionOne(); // Display the final board
    if (token == 'x' && !tie) {
        cout << n1 << " Wins!" << endl;
    } else if (token == '0' && !tie) {
        cout << n2 << " Wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}

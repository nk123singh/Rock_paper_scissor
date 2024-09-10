#include <iostream>
#include <ctime>
using namespace std;

char getComputerMove() {
    srand(time(0));
    int move = rand() % 3;
    if (move == 0) return 'r';
    if (move == 1) return 'p';
    return 's';
}

int getResult(char playerMove, char computerMove) {
    if (playerMove == computerMove) return 0;
    if ((playerMove == 'r' && computerMove == 's') ||
        (playerMove == 'p' && computerMove == 'r') ||
        (playerMove == 's' && computerMove == 'p')) return 1;
    return -1;
}

void displayMove(char move) {
    if (move == 'r') cout << "ROCK";
    else if (move == 'p') cout << "PAPER";
    else if (move == 's') cout << "SCISSORS";
}

int main() {
    char playerMove;
    int n, u_score = 0, c_score = 0;
    char playAgain;

    do {
        cout << "Enter the number of rounds: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter your move (r for ROCK, p for PAPER, s for SCISSORS): ";
            cin >> playerMove;

            while (playerMove != 'r' && playerMove != 'p' && playerMove != 's') {
                cout << "Invalid move. Please enter r for ROCK, p for PAPER, s for SCISSORS: ";
                cin >> playerMove;
            }

            char computerMove = getComputerMove();
            cout << "Computer chose: ";
            displayMove(computerMove);
            cout << endl;

            int result = getResult(playerMove, computerMove);
            if (result == 1) {
                u_score++;
                cout << "You win this round!" << endl;
            } else if (result == -1) {
                c_score++;
                cout << "Computer wins this round!" << endl;
            } else {
                cout << "This round is a draw!" << endl;
            }

            cout << "Score: You " << u_score << " - " << c_score << " Computer" << endl;
        }

        if (u_score > c_score) {
            cout << "You win the game!" << endl;
        } else if (u_score < c_score) {
            cout << "You lose the game!" << endl;
        } else {
            cout << "The game is a draw!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y');

    return 0;
}


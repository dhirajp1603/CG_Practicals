//Written By Dhirajkumar Pachling
/* Write a C++ program to implement the game Tic Tac Toe. Apply the concept of
polymorphism */

//CODE

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Player {
public:
char mark;
virtual void makeMove(char board[], int player) = 0;
};
class HumanPlayer : public Player {
public:
HumanPlayer(char m) {
mark = m;
}
void makeMove(char board[], int player) override {
int choice;
cout << "Player " << player << "'s chance" << endl;
cout << "Enter the position between [1-9] where you want to mark: ";
cin >> choice;
if (choice >= 1 && choice <= 9 && board[choice] == ' ') {
board[choice] = mark;
} else {
cout << "Invalid move. Try again." << endl;
makeMove(board, player);
}
}
};
class AI_Player : public Player {
public:
AI_Player(char m) {
mark = m;
}
void makeMove(char board[], int player) override {
int choice;
do {
choice = rand() % 9 + 1;
} while (board[choice] != ' ');
cout << "AI player chose position " << choice << endl;
board[choice] = mark;
}
};
int checkwin(const char board[]) {
if ((board[1] == board[2] && board[2] == board[3] && board[1] != ' ') ||
(board[4] == board[5] && board[5] == board[6] && board[4] != ' ') ||
(board[7] == board[8] && board[8] == board[9] && board[7] != ' ') ||
(board[1] == board[4] && board[4] == board[7] && board[1] != ' ') ||
(board[2] == board[5] && board[5] == board[8] && board[2] != ' ') ||
(board[3] == board[6] && board[6] == board[9] && board[3] != ' ') ||
(board[1] == board[5] && board[5] == board[9] && board[5] != ' ') ||
(board[3] == board[5] && board[5] == board[7] && board[5] != ' ')) {
return 1;
} else if (board[1] != ' ' && board[2] != ' ' && board[3] != ' ' &&
board[4] != ' ' && board[5] != ' ' && board[6] != ' ' &&
board[7] != ' ' && board[8] != ' ' && board[9] != ' ') {
return 0;
} else {
return -1;
}
}
void display(const char board[]) {
cout << " " << board[1] << " | " << board[2] << " | " << board[3] << " " << endl;
cout << "___|___|___" << endl;
cout << " " << board[4] << " | " << board[5] << " | " << board[6] << " " << endl;
cout << "___|___|___" << endl;
cout << " " << board[7] << " | " << board[8] << " | " << board[9] << " " << endl;
cout << " | | " << endl;
}
int main() {
srand(static_cast<unsigned>(time(0)));
char board[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
int player = 1;
Player* players[2];
players[0] = new HumanPlayer('X');
players[1] = new AI_Player('O');
int result = 0;
int flag = 0;
while (flag == 0) {
display(board);
players[player - 1]->makeMove(board, player);
result = checkwin(board);
if (result == 1 || result == 2) {
display(board);
cout << "Congratulations! Player " << player << " has won." << endl;
flag = 1;
} else if (result == 0) {
display(board);
cout << "Game Draw" << endl;
flag = 1;
}
player = (player == 1) ? 2 : 1;
}
delete players[0];
delete players[1];
return 0;
}

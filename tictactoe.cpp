#include <iostream>
#include <string>

using namespace std;

char space[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; //rows and column numbers of the ttt structure
int row;
int column;
char token = 'x';
bool tie = false;
string p1="";
string p2="";

void displayLayout() {

	//create the layout
	cout << "	|	|		\n";
	cout << "    " << space[0][0] << "   |   " << space[0][1]  << "   |   " <<space[0][2] <<"\n";
	cout << " _______|_______|_______\n";
	cout << "	|	|		\n";
	cout << "    " << space[1][0] << "   |   " << space[1][1] << "   |   " << space[1][2] << "\n";
	cout << " _______|_______|_______\n";
	cout << "	|	|		\n";
	cout << "    " << space[2][0] << "   |   " << space[2][1] << "   |   " << space[2][2] << "\n";
	cout << "	|	|		\n";
} 

void playerTurn() {
	char digit;

	//player 1 is 'x' while player 2 is 'o'
	//get input from user
	if (token == 'x') {
		cout << p1 << " [x] please enter : ";
		cin >> digit;
	}

	else if (token == 'o') {
		cout << p2 << " [o] please enter : ";
		cin >> digit;
	}

	//assign the space
	if (digit == '1') {
		row = 0;
		column = 0;
	}
	else if (digit == '2') {
		row = 0;
		column = 1;
	}
	else if (digit == '3') {
		row = 0;
		column = 2;
	}
	else if (digit == '4') {
		row = 1;
		column = 0;
	}
	else if (digit == '5') {
		row = 1;
		column = 1;
	}
	else if (digit == '6') {
		row = 1;
		column = 2;
	}
	else if (digit == '7') {
		row = 2;
		column = 0;
	}
	else if (digit == '8') {
		row = 2;
		column = 1;
	}
	else if (digit == '9') {
		row = 2;
		column = 2;
	}
	else {
		cout << "Invalid move! " << endl; //error message
		return;
	}

	//check to see if it is an unused space
	//update positions
	if (token == 'x' && space[row][column] != 'x' && space[row][column] != 'o') {
		space[row][column] = 'x';
		token = 'o'; //player 2's turn
	}
	else if (token == 'o' && space[row][column] != 'x' && space[row][column] != 'o') {
		space[row][column] = 'o';
		token = 'x'; //player 1's turn
	}
	else {
		cout << "There is no empty space!" << endl; //when the space is used
		return;
	}
	//ends
	displayLayout(); 
}

//to get game status
bool checkWin() {//check for 3 in a line to win

	//iterate to check through each rows (horizontal) and each columns (vertical)
	for (int i = 0; i < 3; i++) {
		if (space[i][0] == space[i][1] && space[i][1] == space[i][2] || space[0][i] == space [1][i] && space[1][i] == space [2][i]) {//check if 1st and 2nd | 1st and 3rd elements are the same
			return false;
		}
	}
	//to check diagonally
	if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
		return false;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (space[i][j] != 'x' && space[i][j] != 'o') { //if it is neither x or o --> means the game is not over
				return true;
			}
		}
	}
	tie = true;
	return false;
}

int main() {
	//get inputs for player names

	cout << "Enter the name of Player 1 [x] : ";
	getline(cin, p1);
	cout << "Enter the name of Player 2 [o] : ";
	getline(cin, p2);
	cout << p1 << " is Player 1 so he/she will start first.\n";
	displayLayout();

	while (checkWin()) {//iterate until true
		
		playerTurn();
		checkWin();
	}

	if (token == 'o' && tie == false) {
		cout << p1 << " wins!" << endl;
	}
	else if (token == 'x' && tie == false) {
		cout << p2 << " wins!" << endl;
	}
	else {
		cout << "It is a draw!" << endl;
	}
}
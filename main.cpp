#include <iostream>
#include <windows.h>
using namespace std;

void build(const char *values) {

	cout << "     |     |     " << endl;
	cout << "  " << values[0] << "  |";
	cout << "  " << values[1] << "  |";
	cout << "  " << values[2] << "  ";
	cout << endl << "-----|-----|-----" << endl;
	cout << "  " << values[3] << "  |";
	cout << "  " << values[4] << "  |";
	cout << "  " << values[5] << "  ";
	cout << endl << "-----|-----|-----" << endl;
	cout << "  " << values[6] << "  |";
	cout << "  " << values[7] << "  |";
	cout << "  " << values[8] << "  " << endl;
	cout << "     |     |     ";
}

int playerInput(const int p) {
	int choice;
	bool check;

	do {
		cout << endl << endl << "Player " << p << ": ";
		cin >> choice;
		check = choice > 0 || choice <= 9 || !cin.fail();

		if (!check) {
			cout << endl << "Not a valid selection!" << endl;
		}
	} while (check == false);

	return choice;
}

bool winner(const char* values) {
	bool check = (values[0] == values[1] && values[1] == values[2]) ||
		(values[0] == values[4] && values[4] == values[8]) ||
		(values[0] == values[3] && values[3] == values[6]) ||
		(values[3] == values[4] && values[4] == values[5]) ||
		(values[6] == values[7] && values[7] == values[8]) ||
		(values[6] == values[4] && values[4] == values[2]) ||
		(values[1] == values[4] && values[4] == values[7]) ||
		(values[2] == values[5] && values[5] == values[8]);

	return check;
}

void play() {
	char values[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int player;
	int i = 1;

	build(values);

	do {
		(i % 2) != 0 ? player = 1 : player = 2;

		switch (playerInput(player))
		{
		case 1:
			player == 1 ? values[0] = 'X' : values[0] = 'O';
			break;
		case 2:
			player == 1 ? values[1] = 'X' : values[1] = 'O';
			break;
		case 3:
			player == 1 ? values[2] = 'X' : values[2] = 'O';
			break;
		case 4:
			player == 1 ? values[3] = 'X' : values[3] = 'O';
			break;
		case 5:
			player == 1 ? values[4] = 'X' : values[4] = 'O';
			break;
		case 6:
			player == 1 ? values[5] = 'X' : values[5] = 'O';
			break;
		case 7:
			player == 1 ? values[6] = 'X' : values[6] = 'O';
			break;
		case 8:
			player == 1 ? values[7] = 'X' : values[7] = 'O';
			break;
		case 9:
			player == 1 ? values[8] = 'X' : values[8] = 'O';
			break;
		}
		build(values);
		i++;
	} while (!winner(values));

	if (winner(values)) {

		cout << endl << endl << "And the winner is.";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << "Player " << player;
	}
}

int main() {

	play();
}
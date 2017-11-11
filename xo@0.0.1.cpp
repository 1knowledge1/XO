#include <iostream>
using namespace std;

void output_area (bool X[][3], bool O[][3], int size = 3) {
	cout << "    1   2   3\n";
	cout << "  +---+---+---+\n";

	for (int i = 0; i < size; i++) {

		if (i == 0) cout << "a | ";
		if (i == 1) cout << "b | ";
		if (i == 2) cout << "c | ";

		for (int j = 0; j < 3; j++) {
			if (!(X[i][j] || O[i][j])) cout << ' ';
			else {
				if (X[i][j]) cout << 'X';
				if (O[i][j]) cout << 'O';
			}
			cout << " | ";
		}
		cout << "\n  +---+---+---+\n";
	}
}

void output_X (bool X[][3], bool O[][3]) {
	cout << '\n';
	int i = 1;
	if (!O[0][0] && !X[0][0]) { cout << i << ". mark cell a1 as X\n"; i++; }
	if (!O[0][1] && !X[0][1]) { cout << i << ". mark cell a2 as X\n"; i++; }
	if (!O[0][2] && !X[0][2]) { cout << i << ". mark cell a3 as X\n"; i++; }
	if (!O[1][0] && !X[1][0]) { cout << i << ". mark cell b1 as X\n"; i++; }
	if (!O[1][1] && !X[1][1]) { cout << i << ". mark cell b2 as X\n"; i++; }
	if (!O[1][2] && !X[1][2]) { cout << i << ". mark cell b3 as X\n"; i++; }
	if (!O[2][0] && !X[2][0]) { cout << i << ". mark cell c1 as X\n"; i++; }
	if (!O[2][1] && !X[2][1]) { cout << i << ". mark cell c2 as X\n"; i++; }
	if (!O[2][2] && !X[2][2]) { cout << i << ". mark cell c3 as X\n"; i++; }
	cout << i << ". quit\n\n";

}

void output_O (bool X[][3], bool O[][3]) {
	cout << '\n';
	int i = 1;
	if (!O[0][0] && !X[0][0]) { cout << i << ". mark cell a1 as O\n"; i++; }
	if (!O[0][1] && !X[0][1]) { cout << i << ". mark cell a2 as O\n"; i++; }
	if (!O[0][2] && !X[0][2]) { cout << i << ". mark cell a3 as O\n"; i++; }
	if (!O[1][0] && !X[1][0]) { cout << i << ". mark cell b1 as O\n"; i++; }
	if (!O[1][1] && !X[1][1]) { cout << i << ". mark cell b2 as O\n"; i++; }
	if (!O[1][2] && !X[1][2]) { cout << i << ". mark cell b3 as O\n"; i++; }
	if (!O[2][0] && !X[2][0]) { cout << i << ". mark cell c1 as O\n"; i++; }
	if (!O[2][1] && !X[2][1]) { cout << i << ". mark cell c2 as O\n"; i++; }
	if (!O[2][2] && !X[2][2]) { cout << i << ". mark cell c3 as O\n"; i++; }
	cout << i << ". quit\n\n";

}

bool mark_X (int op, bool X[][3], bool O[][3], int size = 3) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			if (!X[i][j] && !O[i][j]) {
				num++;
				if (op == num) X[i][j] = true;
			}
		}
	}
	num++;
	if (op == num) return true;
	else return false;
}

bool mark_O (int op, bool X[][3], bool O[][3], int size = 3) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			if (!O[i][j] && !X[i][j]) {
				num++;
				if (op == num) O[i][j] = true;
			}
		}
	}
	num++;
	if (op == num) return true;
	else return false;
}

void check_Xwin (bool &Xwin, bool X[][3], bool O[][3]) {
	for (int i = 0; i < 3; i++) {
		if (X[i][0] && X[i][1] && X[i][2]) Xwin = true;
		if (X[0][i] && X[1][i] && X[2][i]) Xwin = true;
	}
	if ((X[0][0] && X[1][1] && X[2][2]) || (X[2][0] && X[1][1] && X[0][2])) Xwin = true;
}

void check_Owin(bool &Owin, bool X[][3], bool O[][3]) {
	for (int i = 0; i < 3; i++) {
		if (O[i][0] && O[i][1] && O[i][2]) Owin = true;
		if (O[0][i] && O[1][i] && O[2][i]) Owin = true;
	}
	if ((O[0][0] && O[1][1] && O[2][2]) || (O[2][0] && O[1][1] && O[0][2])) Owin = true;
}

int main() {
	bool X[3][3] = {}, O[3][3] = {};
	bool Xwin = false, Owin = false;
	int op, counter = 1;

	output_area(X,O);

	while (!Xwin && !Owin) {

		if (counter % 2 == 1) output_X(X, O);
		else output_O(X, O);

		cin >> op;

		if (counter % 2 == 1) {
			if (mark_X(op, X, O)) break;
		}
		else if (mark_O(op, X, O)) break;

		output_area(X, O);

		if (counter % 2 == 1) check_Xwin(Xwin, X, O);
		else check_Owin(Owin, X, O);

		if ((op < (12 - counter)) && (op > 0)) counter++;
	}
	if (Xwin) cout << "\nplayer X wonn.\n";
	if (Owin) cout << "\nplayer O wonn.\n";

	return 0;
}

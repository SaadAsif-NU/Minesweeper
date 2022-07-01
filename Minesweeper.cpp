#include <iostream>
#include<thread>

#include<fstream>

using namespace std;

#define max_mine 99
#define max_side 25
#define max_move 526 // 25*25-99
class difficultylevel {
public:
	int level;
	int SIDE;
	int MINES;
	void setlevel(int l) {
		level = l;
		;
	}
	int getlevel() {
		return level;
	}
	void setside(int s, int m) {
		SIDE = s;
		MINES = m;
	}
	int getside() {
		return SIDE;
	}

	int getmine() {

		return MINES;
	}


};
class mygame {

public:
	virtual void printboard(char myboard[][max_side]) = 0;
	virtual bool playminesuntil(char myboard[][max_side], char realboard[][max_side], int mines[][2], int row, int col, int* moves_left) = 0;
	virtual void make_move(int* x, int* y) = 0;
	virtual void make_move(int* x, int* y,char v) = 0;
	virtual void replacemine(int row, int col, char board[][max_side]) = 0;

};
class board :public difficultylevel, public mygame {
public:
	char realboard[max_side][max_side], myboard[max_side][max_side];
	int moves_left;
	int x, y;
	int mines[max_mine][2];
	board(int s1, int m1) {
		SIDE = s1;
		MINES = m1;
		moves_left = SIDE * SIDE - MINES;
		cout<< max_side << endl << max_mine;
	}

	void initialise(char realboard[][max_side], char myboard[][max_side]) {
		srand(time(NULL)); //initalising random so that same config doesn't arise
		int i, j;
		for (i = 0;i < SIDE;i++) {
			for (j = 0;j < SIDE;j++)
			{
				myboard[i][j] = realboard[i][j] = '-';

			}
			cout << endl;
		}
		return;
	}
	void placemines(int mines[][2], char realboard[][max_side])
	{
		bool mark[max_side * max_side];

		memset(mark, false, sizeof(mark));

		for (int i = 0;i < MINES;)
		{
			int random = rand() % (SIDE * SIDE);
			int x = random / SIDE;
			int y = random % SIDE;

			if (mark[random] == false) //add mine if not present at position random
			{
				mines[i][0] = x;
				mines[i][1] = y;

				realboard[mines[i][0]][mines[i][1]] = '*';
				mark[random] = true;
				i++;
			}
		}
	}
	void printboard(char myboard[][max_side])
	{

		system("cls");
		
		cout << "\n\n\t\t\t    ";
		for (int i = 0;i < SIDE;i++)
		{
			if (i > 9)
				cout << i / 10 << " ";
			else
				cout << "  ";
		}

		cout << ("\n\t\t\t    ");

		for (int i = 0;i < SIDE;i++)
			cout << i % 10 << " ";

		cout << "\n\n";

		for (int i = 0;i < SIDE;i++)
		{
			cout << "\t\t\t    ";
			for (int j = 0;j < SIDE;j++) {
				cout << myboard[i][j] << " ";
			}
			cout << i;
			cout << "\n";
		}

		return;
	}

	bool playminesuntil(char myboard[][max_side], char realboard[][max_side], int mines[][2], int row, int col, int* moves_left)
	{
		if (myboard[row][col] != '-')
			return false;

		int i, j;
		if (realboard[row][col] == '*')
		{
			myboard[row][col] = '*';
			for (i = 0;i < MINES;i++)
				myboard[mines[i][0]][mines[i][1]] = '*';

			printboard(myboard);
			cout << "\nYou lost!\n";
			return (true);
		}

		else
		{
			int count = countadjacent(row, col, mines, realboard);
			(*moves_left)--;

			myboard[row][col] = count + '0';

			if (!count)
			{

				if (isvalid(row - 1, col) == true)
				{
					if (ismine(row - 1, col, realboard) == false)
						playminesuntil(myboard, realboard, mines, row - 1, col, moves_left);
				}


				if (isvalid(row + 1, col) == true)
				{
					if (ismine(row + 1, col, realboard) == false)
						playminesuntil(myboard, realboard, mines, row + 1, col, moves_left);
				}


				if (isvalid(row, col + 1) == true)
				{
					if (ismine(row, col + 1, realboard) == false)
						playminesuntil(myboard, realboard, mines, row, col + 1, moves_left);
				}


				if (isvalid(row, col - 1) == true)
				{
					if (ismine(row, col - 1, realboard) == false)
						playminesuntil(myboard, realboard, mines, row, col - 1, moves_left);
				}

				if (isvalid(row - 1, col + 1) == true)
				{
					if (ismine(row - 1, col + 1, realboard) == false)
						playminesuntil(myboard, realboard, mines, row - 1, col + 1, moves_left);
				}


				if (isvalid(row - 1, col - 1) == true)
				{
					if (ismine(row - 1, col - 1, realboard) == false)
						playminesuntil(myboard, realboard, mines, row - 1, col - 1, moves_left);
				}

				if (isvalid(row + 1, col + 1) == true)
				{
					if (ismine(row + 1, col + 1, realboard) == false)
						playminesuntil(myboard, realboard, mines, row + 1, col + 1, moves_left);
				}

				if (isvalid(row + 1, col - 1) == true)
				{
					if (ismine(row + 1, col - 1, realboard) == false)
						playminesuntil(myboard, realboard, mines, row + 1, col - 1, moves_left);
				}

			}
			return (false);
		}
	}
	bool isvalid(int row, int col)
	{
		return (row >= 0) && (row < SIDE) && (col >= 0) && (col < SIDE);
	}

	bool ismine(int row, int col, char board[][max_side])
	{
		if (board[row][col] == '*')
			return (true);
		else
			return (false);
	}

	int countadjacent(int row, int col, int mines[][2], char realboard[][max_side])
	{
		int count = 0;

		if (isvalid(row - 1, col) == true)
		{
			if (ismine(row - 1, col, realboard) == true)
				count++;
		}

		if (isvalid(row + 1, col) == true)
		{
			if (ismine(row + 1, col, realboard) == true)
				count++;
		}

		if (isvalid(row, col + 1) == true)
		{
			if (ismine(row, col + 1, realboard) == true)
				count++;
		}

		if (isvalid(row, col - 1) == true)
		{
			if (ismine(row, col - 1, realboard) == true)
				count++;
		}

		if (isvalid(row - 1, col - 1) == true)
		{
			if (ismine(row - 1, col - 1, realboard) == true)
				count++;
		}

		if (isvalid(row - 1, col + 1) == true)
		{
			if (ismine(row - 1, col + 1, realboard) == true)
				count++;
		}

		if (isvalid(row + 1, col - 1) == true)
		{
			if (ismine(row + 1, col - 1, realboard) == true)
				count++;
		}

		if (isvalid(row + 1, col + 1) == true)
		{
			if (ismine(row + 1, col + 1, realboard) == true)
				count++;
		}

		return (count);

	}
	void make_move(int* x, int* y)
	{
		while (true)
		{
			cout << "\nEnter your move: [row] [column] -> ";
			scanf_s("%d %d", x, y);
			/* Check values to make sure they're not larger than the board size.*/
			if ((*x < SIDE) && (*y < SIDE))
			{
				return;
			}
		}
	}
	void make_move(int* x, int* y, char v) {
		{
			while (true)
			{
				cout << "\nEnter your move: [row] [column] -> ";
				cin>>*x,* y;
				/* Check values to make sure they're not larger than the board size.*/
				if ((*x < SIDE) && (*y < SIDE))
				{
					return ;
				}
			}
		}
	}
	void replacemine(int row, int col, char board[][max_side])
	{
		for (int i = 0;i < SIDE;i++)
		{
			for (int j = 0;j < SIDE;j++)
			{
				if (board[i][j] != '*')
				{
					board[i][j] = '*';
					board[row][col] = '-';
					return;
				}
			}

		}

	}




};


int main() {
	cout << "                       WELCOME to MINESWEEPER Game" << endl;
	cout << "Choose the difficulty level" << endl;
	cout << "0. BEGINERR" << endl;
	cout << "1. INTERMEDIATE" << endl;
	cout << "2. ADVANCE " << endl;
	cout << "Chose (0-2)" << endl;
	int score=0;
	int myside;
	int mymine;
	int key;
	int l;
	cin >> l;
	difficultylevel obj1;
	
	system("cls");


	



	cout << "You have chosen " << obj1.getlevel() << endl;
	if (l == 0) {
		cout << "Weclome to Beginners Level" << endl;
		myside = 9;
		mymine = 10;
		obj1.setside(9, 10);
	}
	else if (l == 1) {
		cout << "Weclome to Intermediate Level" << endl;
		myside = 16;
		mymine = 40;
		obj1.setside(16, 40);
	}
	else if (l == 2) {
		cout << "Weclome to ADVANCE Level" << endl;
		myside = 24;
		mymine = 99;
		obj1.setside(24, 99);
	}
	else {
		system("cls");
		cout << "                                                  Invalid Input" << endl;
		exit(0);
	}

	int flag = mymine;
	bool gameover = false;
	char real[max_side][max_side], my[max_side][max_side];

	board obj2(myside, mymine);
	obj2.initialise(real, my);
	int mines[max_mine][2];
	obj2.placemines(mines, real);
	int cmd = 0;
	int x = 0, y = 0;
	string z;
	int movelft = myside * myside - mymine;

	mygame* ptr;
	ptr = &obj2;
	while (gameover == false) {
		system("cls");
		cout << "Current status of the Board" << endl;

		ptr->printboard(my);
	
		ptr->make_move(&x, &y);
		score = score + 10;
	 if (cmd == 0)
		{
			if (obj2.ismine(x, y, real) == true) //first attempt is a mine
				ptr->replacemine(x, y, real); //replace the mine at that location
		}
		cmd++;
		gameover = ptr->playminesuntil(my, real, mines, x, y, &movelft);
		if ((gameover == false) && (movelft == 0))
		{
			cout << " WOW! You won !\n";
			gameover = true;
		}
		

	}
	cout << "Your total score is" << score << endl;
	return 0;
}

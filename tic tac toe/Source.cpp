#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#include "Source.h"
using namespace std;
const int rows = 3, colums = 3;
char field[rows][colums] = {
	{'X',' ','0'},
	{' ','0','X'},
	{'X','0',' '}
};
int turn = 1;

// void goX();
// void go0();

bool file_exists(string path) {
	ifstream check;
	check.open(path);
	if (check.is_open()) {
		check.close();
		return true;
	}
	check.close();
	return false;
};

void saveGame()
{
	// std::system("cls");
	cout << "Введите название сохранения: ";
	string path;
	getline(cin, path);
	path = "saves\\" + path + ".save";

	if (file_exists(path)) {
		cout << "Сохранение занято. Хотите ли Вы перезаписать файл?\n";
		cout << "(n - нет; y - да) -> ";
		string answer;
		getline(cin, answer);
		while (answer != "n" && answer != "y") {
			cout << "Ошибка ввода. Повторите ввод.\n";
			cout << "(n - нет; y - да) -> ";
			getline(cin, answer);
		}
		if (answer == "n") {
			cout << "Сохранение отменено.\n";
			return;
		}
	}

	ofstream fout;
	fout.exceptions(ios::badbit | ios::failbit | ios::eofbit);
	fout.open(path);
	SYSTEMTIME date;
	GetSystemTime(&date);
	fout << "# comments start from \'#\'\n";
	fout << "# date: " << (date.wDay) << "." << (date.wMonth) << "." << date.wYear << " " << (date.wHour + 5) << ":" << date.wMinute << "\n";
	fout << turn << "\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++)
			if (field[i][j] == ' ')
				fout << '.';
			else
				fout << field[i][j];
		fout << "\n";
	}
	cout << "Игра сохранена.\n";
}

void load() {
	cout << "Введите название сохранения для загрузки: ";
	string path;
	getline(cin, path);
	path = "saves\\" + path + ".save";

	if (!file_exists(path))
		throw runtime_error("file does not exist");

	ifstream in;
	in.exceptions(ios::badbit | ios::failbit | ios::eofbit);



}

// void print_map();

int main() {
	setlocale(LC_ALL, "Russian");

	saveGame();

	return 0;
};
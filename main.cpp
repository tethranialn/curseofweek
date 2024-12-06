#include <iostream>;
#include <iomanip>;
#include <math.h>;
#include <fstream>;

using namespace std;
const unsigned N = 100;

int readFile(fstream& inputFile, float x[N], float y[N]);
void main(void)
{
	fstream inputFile;
	float x[N], y[N]; char tryAgain = '!'; unsigned file; bool fileSelected = false;
	//file selection
	while (fileSelected != true)
	{
		cout << skipws << "available files:\n\t0. \"in.txt\"\n\t1. \"in1.txt\"\n\t2. \"in2.txt\"\nselect the file to open: ";
		cin >> file;
		switch (file)
		{
		case 0:
		{
			inputFile.open("in.txt", ios::in);
			fileSelected = true;
			break;
		}
		case 1:
		{
			inputFile.open("in1.txt", ios::in);
			fileSelected = true;
			break;
		}
		case 2:
		{
			inputFile.open("in2.txt", ios::in);
			fileSelected = true;
			break;
		}
		default:
		{
			cout << "\nerror: file is not exist. please, press enter to try again: " << noskipws;
			cin.ignore();
			cin.get();
			system("cls");
			fileSelected = false;
			break;
		}
		}
	}
	switch (readFile(inputFile, x, y))
	{
	case -1:
	{
		cout << "\nthe number of points cannot be less than zero";
		return;
	}
	case 0:
	{
		cout << "\nsince the number of points is zero, programm cannot be executed";
		return;
	}
	default:
	{
		cout << "\nfile reading error";
		return;
	}
	}
	inputFile.close();
}
int readFile(fstream& inputFile, float x[N], float y[N])
{
	int number;
	inputFile >> number;
	if (number < 0)
	{
		return -1;
	}
	else if (number == 0)
	{
		return 0;
	}
	else if (number > N)
	{
		return number;
	}
	else
	{
		return number;
	}

}
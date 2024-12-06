#include <iostream>;
#include <iomanip>;
#include <math.h>;
#include <fstream>;

using namespace std;
const unsigned N = 100;

int readFile(fstream& inputFile, float x[N], float y[N], int& big_number);
void main(void)
{
	fstream inputFile;
	float x[N], y[N]; char tryAgain = '!'; unsigned file; bool fileSelected = false; int big_number = 0;
	//file selection
	while (fileSelected != true)
	{
		cout << skipws << "available files:\n";
		cout << "\t0. \"in.txt\"\n";
		cout << "\t1. \"in1.txt\"\n";
		cout << "\t2. \"in2.txt\"\n";
		cout << "\t3. \"in3.txt\"\n";
		cout << "\t4. \"in4.txt\"\n";
		cout << "\t5. \"in5.txt\"\n";
		cout<<"select the file to open : ";
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
		case 3:
		{
			inputFile.open("in3.txt", ios::in);
			fileSelected = true;
			break;
		}
		case 4:
		{
			inputFile.open("in4.txt", ios::in);
			fileSelected = true;
			break;
		}
		case 5: 
		{
			inputFile.open("in5.txt", ios::in);
			fileSelected = true;
			break;
		}
		default:
		{
			cout << "\nerror: this file is not exist. please, press enter to try again: " << noskipws;
			cin.ignore();
			cin.get();
			system("cls");
			fileSelected = false;
			break;
		}
		}
	}
	//checking file opening
	if (!inputFile.is_open())
	{
		cout << "this file is not open or does not exist. please, restart the programm";
		return;
	}
	//checking number of points 
	switch (readFile(inputFile, x, y, big_number))
	{
	case 0:
	{
		cout << "since the number of points is zero, programm cannot be executed";
		return;
	}
	case -1:
	{
		cout << "the number of points cannot be less than zero";
		return;
	}
	case -2:
	{
		cout << "file is empty";
		return;
	}
	case -3:
	{
		cout << "file reading error";
		return;
	}
	}
	if (big_number != 0)
	{
		cout << "specified number of points (" << big_number << ") has been reduced to " << N << '\n';
	}
	cout << "Hello world!";
	inputFile.close();
}
int readFile(fstream& inputFile, float x[N], float y[N], int& big_number)
{
	int number;
	inputFile >> number;
	if (inputFile.eof())
	{
		return -2;
	}
	else if (number < 0)
	{
		return -1;
	}
	else if (number == 0)
	{
		return 0;
	}
	else if (number > N)
	{
		big_number = number;
		number = N;
		return number;
	}
	else
	{
		return number;
	}
	return -3;
}
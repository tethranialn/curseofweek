#include <iostream>;
#include <iomanip>;
#include <math.h>;
#include <fstream>;

using namespace std;
const unsigned N = 100;

bool readFile(fstream i, float x[N], float y[N]);
void main(void)
{
	fstream inputFile;
	float x[N], y[N]; char tryAgain = '!'; unsigned file; bool fileSelected = false;
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
	inputFile.close();
}
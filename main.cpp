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
	float x[N], y[N]; char tryAgain; unsigned file;
	//o.open("out.txt", ios::out);
selectFile:
	{
		cout << skipws << "available files:\n\t0. \"in.txt\"\n\t1. \"in1.txt\"\n\t2. \"in2.txt\"\nselect the file to open: ";
		cin >> file;
	}
	switch (file)
	{
	case 0:
	{
		inputFile.open("in.txt", ios::in);
		break;
	}
	case 1:
	{
		inputFile.open("in1.txt", ios::in);
		break;
	}
	case 2:
	{
		inputFile.open("in2.txt", ios::in);
		break;
	}
	default:
	{
		cout << "\nerror: file is not exist. please, press enter to try again: "<< noskipws;
		cin >> tryAgain;
		system("cls");
		goto selectFile;
		break;
	}
	}
	inputFile.close();
}
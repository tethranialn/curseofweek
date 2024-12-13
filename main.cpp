#include <iostream>;
#include <iomanip>;
#include <math.h>;
#include <fstream>;

using namespace std;
const unsigned N = 50;

int readFile(fstream& inputFile, float x[N], float y[N], int& big_number, int& real_number, int& number);
void pointsCreation(float x[N], float y[N], float XP[100000][3], float YP[100000][3], int real_number);
int process(float XP[100000][3], float YP[100000][3], int& result);
void main(void)
{
	fstream inputFile;
	float x[N], y[N], XP[10000][3], YP[10000][3]; char tryAgain = '!'; unsigned file; bool fileSelected = false; int big_number = 0, real_number = 0, number = 0, result = 0;
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
	switch (readFile(inputFile, x, y, big_number, real_number, number))
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
	cout << "readed number of points: " << number << '\n';
	cout << "real number of points: " << real_number << '\n';
	//process
	pointsCreation(x, y, XP, YP, real_number);
	process(XP, YP, result);
	cout << "Hello world!";
	inputFile.close();
}
int readFile(fstream& inputFile, float x[N], float y[N], int& big_number, int& real_number, int& number)
{
	int i = 0; char s = '!'; float tmp_x, tmp_y;
	inputFile >> number;
	//checking number of points 
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
	//programm will work
	else
	{
		if (number > N)
		{
			big_number = number;
			number = N;
		}
		while(i < number)
		{
			inputFile << skipws;
			inputFile >> tmp_x;
			if (inputFile.eof())
			{
			//реакция на конец файла
				return number;
			}
			else
			{
				inputFile << noskipws;
				do inputFile >> s;
				while (s == ' ' || s == '\t');
				if (s == '\n')
				{
					//реакция на то, что есть только х
					continue;
				}
				else if (inputFile.eof())
				{
					//реакция на то, что есть только х
					return number;;
				}
				else
				{
					inputFile.seekg(-1, ios::cur);
					s = '!';
					inputFile << skipws;
					inputFile >> tmp_y;
					if (inputFile.eof())
					{
						//реакция на конец файла
						return number;
					}
					else
					{
						x[i] = tmp_x;
						y[i] = tmp_y;
						cout << i+1 << ".\t" << x[i] << ' ' << y[i] << '\n';
						i++;
						real_number = i;
						inputFile << noskipws;
						while (!inputFile.eof() && s != '\n') inputFile >> s;
						s = '!';
					}
				}
			}
		}
		return number;
	}
	return -3;
}
void pointsCreation(float x[N], float y[N], float XP[100000][3], float YP[100000][3], int real_number)
{
	int i, j, k, index = 0;
	for (i = 0; i < real_number; i++)
	{
		for (j = i + 1; j < real_number; j++)
		{
			for (k = j + 1; k < real_number; k++)
			{
				XP[index][0] = x[i];
				XP[index][1] = x[j];
				XP[index][2] = x[k];
				YP[index][0] = y[i];
				YP[index][1] = y[j];
				YP[index][2] = y[k];
				index++;
			}
		}
	}
	cout << endl;
	for (i = 0; i < index; i++) {
		cout << XP[i][0] << " " << YP[i][0] << "\t\t" << XP[i][1] << " " << YP[i][1] << "\t\t" << XP[i][2] << " " << YP[i][2] << endl;
	}
	return;
}
int process(float XP[100000][3], float YP[100000][3], int& result)
{

	return 0;
}

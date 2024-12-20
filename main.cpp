#include <iostream>;
#include <iomanip>;
#include <math.h>;
#include <fstream>;

using namespace std;
const unsigned N = 50;
fstream fresult, fprotocol;
bool P[10000];

int readFile(fstream& inputFile, float x[N], float y[N], int& big_number, int& real_number, int& number);
void pointsCreation(float x[N], float y[N], long double XP[100000][3], long double YP[100000][3], int real_number, int& index);
int process(long double XP[10000][3], long double YP[10000][3], int& result, int index);
double distance(double x1, double y1, double x2, double y2);
void main(void)
{
	fstream inputFile;
	float x[N], y[N]; long double  XP[10000][3], YP[10000][3]; char tryAgain = '!'; unsigned file; bool fileSelected = false;
	int big_number = 0, real_number = 0, number = 0, result = 0, index = 0, i, j = 0;
	fresult.open("result.txt", ios::out);
	fprotocol.open("protocol.txt", ios::out);
	if (!fprotocol.is_open())
	{
		cout << "protocol file is not open or does not exist. please, restart the programm";
		return;
	}
	if (!fresult.is_open())
	{
		cout << "result file is not open or does not exist. please, restart the programm";
		fprotocol << "result file is not open or does not exist. please, restart the programm";
		return;
	}
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
			fprotocol << "selected file: in.txt\n";
			break;
		}
		case 1:
		{
			inputFile.open("in1.txt", ios::in);
			fileSelected = true;
			fprotocol << "selected file: in1.txt\n";
			break;
		}
		case 2:
		{
			inputFile.open("in2.txt", ios::in);
			fileSelected = true;
			fprotocol << "selected file: in2.txt\n";
			break;
		}
		case 3:
		{
			inputFile.open("in3.txt", ios::in);
			fileSelected = true;
			fprotocol << "selected file: in3.txt\n";
			break;
		}
		case 4:
		{
			inputFile.open("in4.txt", ios::in);
			fileSelected = true;
			fprotocol << "selected file: in4.txt\n";
			break;
		}
		case 5: 
		{
			inputFile.open("in5.txt", ios::in);
			fileSelected = true;
			fprotocol << "selected file: in5.txt\n";
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
		fprotocol << "this file is not open or does not exist. please, restart the programm";
		fresult << "this file is not open or does not exist. please, restart the programm";
		return;
	}
	//checking number of points 
	switch (readFile(inputFile, x, y, big_number, real_number, number))
	{
	case 0:
	{
		cout << "since the number of points is zero, programm cannot be executed";
		fprotocol << "since the number of points is zero, programm cannot be executed";
		return;
	}
	case -1:
	{
		cout << "the number of points cannot be less than zero";
		fprotocol << "the number of points cannot be less than zero";
		return;
	}
	case -2:
	{
		cout << "file is empty";
		fprotocol << "file is empty";
		return;
	}
	case -3:
	{
		cout << "file reading error";
		fprotocol << "file reading error";
		return;
	}
	}
	if (big_number != 0)
	{
		//cout << "specified number of points (" << big_number << ") has been reduced to " << N << '\n';
		fprotocol << "specified number of points (" << big_number << ") has been reduced to " << N << '\n';
	}
	//cout << "readed number of points: " << number << '\n';
	//cout << "real number of points: " << real_number << '\n';
	fprotocol << "readed number of points: " << number << '\n';
	fprotocol << "real number of points: " << real_number << '\n';
	//process
	pointsCreation(x, y, XP, YP, real_number, index);
	process(XP, YP, result, index);
	//cout << "number of acute-angled triangles:" << result;
	fprotocol << "number of acute-angled triangles:" << result;
	fresult << "Task: Find all acute-angled triangles formed by any three points\n";
	//fresult << "number of acute-angled triangles:" << result << '\n';
	fresult << "Acute-angled triangles:\n";
	for (i = 0; i < index; i++)
	{
		if (P[i] == true)
		{
			j++;
			fresult << setw(2) << left << j << " (" << setw(3) << i+1 << ")." << right << "\t1." << '(' << setw(7) << left << XP[i][0] << ";" << setw(7) << right << YP[i][0] << ')' << "\t2." << '(' << setw(7) << left << XP[i][1] << ";" << setw(7) << right << YP[i][1] << ')' << "\t3." << '(' << setw(7) << left << XP[i][2] << ";" << setw(7) << right << YP[i][2] << ')' << endl;
		}
	}
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
				fprotocol << "end of inputFile\n";
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
					fprotocol << "there is no paired coordinate for x (" << tmp_x << ")\n";
					continue;
				}
				else if (inputFile.eof())
				{
					//реакция на то, что есть только х
					fprotocol << "there is no paired coordinate for x (" << tmp_x << ")\n";
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
						fprotocol << "end of inputFile\n";
						return number;
					}
					else
					{
						x[i] = tmp_x;
						y[i] = tmp_y;
						//cout << i+1 << ".\t" << x[i] << ' ' << y[i] << '\n';
						fprotocol << i + 1 << ".\t" << x[i] << ' ' << y[i] << '\n';
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
void pointsCreation(float x[N], float y[N], long double XP[100000][3], long double YP[100000][3], int real_number, int& index)
{
	int i, j, k;
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
	//cout << endl;
	fprotocol << "formed triples of coordinates:\n";
	for (i = 0; i < index; i++) {
		//cout << i+1 << ".\t" << XP[i][0] << " " << YP[i][0] << "\t\t" << XP[i][1] << " " << YP[i][1] << "\t\t" << XP[i][2] << " " << YP[i][2] << endl;
		//fresult << i + 1 << ".\t" << XP[i][0] << " " << YP[i][0] << "\t\t" << XP[i][1] << " " << YP[i][1] << "\t\t" << XP[i][2] << " " << YP[i][2] << endl;
		fprotocol << i + 1 << ".\t" << XP[i][0] << " " << YP[i][0] << "\t\t" << XP[i][1] << " " << YP[i][1] << "\t\t" << XP[i][2] << " " << YP[i][2] << endl;
	}
	return;
}
int process(long double XP[10000][3], long double YP[10000][3], int& result, int index)
{
	int longest, x, y, z, i;
	fprotocol << '\n' << "Analyzing triangles...\n";
	for (i = 0; i < index; i++)
	{
		x = distance(XP[i][0], YP[i][0], XP[i][1], YP[i][1]);
		fprotocol << "\na: " << x;
		y = distance(XP[i][1], YP[i][1], XP[i][2], YP[i][2]);
		fprotocol << "\nb: " << y;
		z = distance(XP[i][2], YP[i][2], XP[i][0], YP[i][0]);
		fprotocol << "\nc: " << z;
		longest = z;
		if (longest < x) {
			z = longest;
			longest = x;
			x = z;
		}
		if (longest < y) {
			z = longest;
			longest = y;
			y = z;
		}
		if (x * x + y * y > longest * longest) {
			//cout << i + 1 << ".\t" << "This is an acute-angled triangle.\n";
			fprotocol << '\n' << i + 1 << ".\t" << "This is an acute-angled triangle.\n";
			P[i] = true;
			result++;
		}
		else
		{
			//cout << i + 1 << ".\t" << "This is not an acute-angled triangle.\n";
			fprotocol << '\n' << i + 1 << ".\t" << "This is not an acute-angled triangle.\n";
			P[i] = false;
		}
	}
	return 0;
}
double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

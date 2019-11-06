#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;


int operator >(string a, string b)
{
	if (a.size() > b.size()) return 1;
	if (a.size() < b.size()) return 0;

	for(int i = 0; i < a.size(); i++)
	{
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return 0;
	}

	return 2;
}


void sortFile(string str, int size)
{
	fstream file(str);

	if(file.is_open())
	{
		fstream newFile;
		newFile.open("newFile.txt", ios_base::in | ios_base::out | ios_base::ate | ios_base::trunc);

		int i = 1;
		string s1, s2;

		file >> s1;
		cout << s1 << endl;
		while (size != i)
		{
			file >> s2;
			cout << s2 << endl;

			if((s1 > s2) == 1)
			{
				newFile << s2;
				newFile << '\n';
				newFile << s1;
				newFile << '\n';
			}
			else
			{
				newFile << s1;
				newFile << '\n';
				newFile << s2;
				newFile << '\n';
			}

			s1 = s2;

			i++;
		}

		
			
		newFile.close();
		file.close();
	}
}




int main()
{
	string filePath = "file.txt";
	fstream file;
	srand(time(NULL));
	int n;


	cin >> n;


	file.open(filePath, ios_base::in | ios_base::out | ios_base::ate | ios_base::trunc);

	if(file.is_open())
	{
		cout << "file is open" << endl;

		for (int i = 0; i < n; i++)
		{
			file << rand() % 1000;
			file << '\n';
		}
		file.close();


		sortFile(filePath, n);
	}
	else
	{
		cout << "can't open file" << endl;
	}


	system("pause");

	return 0;
}

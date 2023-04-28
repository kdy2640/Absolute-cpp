#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;
bool strCompare(const char cstring1[], const char cstring2[]);

int main()
{
	while (true)
	{
		char firInput[100], secInput[100];
		cout << "Input your first word upto 100" << endl;
		cin.getline(firInput, 100, '\n');
		cout << "Input your second word upto 100" << endl;
		cin.getline(secInput, 100, '\n');
		if (strCompare(firInput, secInput))
		{
			cout << "two word is same!" << endl;
		}
		else
		{
			cout << "two word is not same!" << endl;
		}
		char temp;
		cout << "quit program (Y,N)" << endl;
		cin >> temp;
		if (temp == 'y' || temp == 'Y') { break; }
		cin.ignore();
	}
}

bool strCompare(const char  cstring1[], const char  cstring2[])
{
	int len1 = strlen(cstring1);
	int len2 = strlen(cstring2);
	if (len1 != len2) return false;
	for (int i = 0; i < len1; i++)
	{
		if (cstring1[i] != cstring2[i]) return false;
	}
	return true;

}

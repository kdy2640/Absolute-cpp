#include<iostream>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;
int stringToInt(string input);
int main()
{
	while (true) {
		string Input;
		cout << "input origin sentence" << endl;
		getline(cin, Input, '\n');
		cout << stringToInt(Input) << endl << "Again? (Y,N)" << endl;
		string tempChar;
		getline(cin, tempChar, '\n');
		if (tempChar[0] == 'N' || tempChar[0] == 'n') break;
		cout << endl;
	}
}

int stringToInt(string input)
{//양수라고 가정
	int len = input.length();
	if (len > 9) return -1;
	int Ans = 0;
	for (int i = 1; i <= len; i++)
	{
		Ans += pow(10, len - i) * (input[i - 1] - '0');
	}
	return Ans;
}

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class Anagram {
public:
	Anagram(string Input);
	void setAnagram(string Input);
	bool checkAnagram(string Input);
private:
	string Origin;
	int AlphaArr[26] = {};
};

void disAssembleSentence(int arr[], string input)
{
	int len = input.length();
	for (int i = 0; i < len; i++)
	{
		if (isspace(input[i])) continue;
		else {
			arr[tolower(input[i]) - 97]++;
		}
	}
}

Anagram::Anagram(string Input) {
	Origin = Input;
	disAssembleSentence(AlphaArr, Input);
}
void Anagram::setAnagram(string input)
{
	Origin = input;
	disAssembleSentence(AlphaArr, input);
}
bool Anagram::checkAnagram(string input)
{
	int BetaArr[26] = {};
	disAssembleSentence(BetaArr, input);
	for (int i = 0; i < 26; i++)
	{
		if (BetaArr[i] != AlphaArr[i]) return false;
	}
	return true;
}
int main()
{
	while (true) {
		string Input;
		cout << "input origin sentence" << endl;
		getline(cin, Input, '\n');
		Anagram Ana(Input);
		string Temp;
		cout << "input compare sentence" << endl;
		getline(cin, Temp, '\n');
		if (Ana.checkAnagram(Temp)) {
			cout << "It is Anagram!" << endl;
		}
		else {
			cout << "It is not Anagram.." << endl;
		}
		cout << "Again? (Y,N)" << endl;
		string tempChar;
		getline(cin, tempChar, '\n');
		if (tempChar[0] == 'N' || tempChar[0] == 'n') break;
		cout << endl;
	}
}

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

void capslock(string& sentence, int index, int length);
bool isTrash(char input);

int main(int argc, char *argv[])
{
	string sentence;
	while(true)
	{
		string input;
		cout<< "input your sentence and enter blank to stop. your input is separeted by blank"<<endl;
		getline(cin,input);
		if(isspace(input[0])) break;
		sentence += input + " ";
	}
	sentence += " ";
	
	int len = sentence.length(); int wordCount = 0;
	bool isword = false;
	for(int i = 0; i<len; i++)
	{
		if(isTrash(sentence[i]))
		{
			if(isword) // 단어 다음 공백이므로 캡스락 신드롬 작동
			{
				isword = false;
				capslock(sentence,i-wordCount,wordCount);
				wordCount = 0;
			}else  continue;// 단어가 아닌데 공백이 나왔으므로 계속 진행
					
		}else // 공백 아님
		{
			isword = true; wordCount++;
			continue;
		}
			
	}
	cout << sentence;
	
	
	
	
}	

bool isTrash(char input)
{
	if(input == ' ' || input == '.' || input == ',' || input == '!' || input == '?' )return true;
	return false;
}
void capslock(string& sentence, int index, int length)
{
	sentence[index] = tolower(sentence[index]);
	for(int i = 1; i < length; i++)
	{
		sentence[index+i]=toupper(sentence[index+i]);
	}
}

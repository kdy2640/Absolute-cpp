#include<iostream>
#include<string>
#include<cctype>

using namespace std;

bool isTrash(char Input);
void changeKeyword(string& sentence, string keyword, string change);

int main(int argc, char *argv[])
{
	string sentence;
	getline(cin,sentence);	 		
	changeKeyword(sentence,"his","his or her");
	changeKeyword(sentence,"He", "He or She");
	changeKeyword(sentence,"he", "He or She");
	changeKeyword(sentence,"him", "him or her");
	cout << sentence;
}	

bool isTrash(char input)
{
	if(input == ' ' || input == '.' || input == ',' || input == '!' || input == '?' )return true;
	return false;
}
void changeKeyword(string& sentence, string keyword, string change)
{
	bool trigger;
	int index = sentence.find(keyword); int len = keyword.length(); int clen = change.length();
	if(index==0)
	{
		if(isTrash(sentence[len]))
		{
			sentence.erase(0,len);
			sentence.insert(0,change);
		}else
		{
			index++;
		}
	}
	while(index > 0)
	{
		if(isTrash(sentence[index-1]) && isTrash(sentence[index+len]))
		{
			sentence.erase(index,len);
			sentence.insert(index,change);
			index += clen;
			index = sentence.find(keyword,index);
		}else
		{
			index += 1;
			index = sentence.find(keyword,index);
		}
	}
		
}

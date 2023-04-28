#include<iostream>
#include<string>
#include<cctype>

using namespace std;
bool isVowel(char input);
void changeVowel(string& sentence, int index, int count);
void changeConsonant(string& sentence, int index, int count);

int main(int argc, char *argv[])
{
	string sentence;		
	cout << "input your sentence"<<endl;
	cin >>sentence;
	sentence += " ";
	int wordCount; int len = sentence.length();
	bool isWord=false;
	int i = 0;
	while(i<len)
	{
		cout << i << endl;
		if(isspace(sentence[i]))
		{
			if(isWord)
			{
				isWord = false;
				cout<<sentence[i=wordCount]<<endl;
				if(isVowel(sentence[i-wordCount]))
				{
					changeVowel(sentence,i-wordCount,wordCount);
					i +=2;	
				}else
				{
					changeConsonant(sentence,i-wordCount,wordCount);
					i+=1;
				}
				wordCount = 0;
				len =sentence.length();
			}
		}else
		{
			isWord= true;
			wordCount++;
		}
		i++;
	}
	cout << sentence;
	

}	

bool isVowel(char input)
{
		if(input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') return true;
		return false;	
}
void changeVowel(string& sentence, int index, int count)
{
	string answer;
	for(int i = 0; i < count; i++)
	{
		answer += sentence[index+i];
	}
	answer += "way";
	sentence.erase(index,count);
	sentence.insert(index,answer);
}
void changeConsonant(string& sentence, int index, int count)
{
		string answer;
	for(int i = 0; i < count; i++)
	{
		answer += sentence[index+i];
	}
	answer += answer[0] + "ay";
	answer.erase(0,1);
	sentence.erase(index,count);
	sentence.insert(index,answer);

}


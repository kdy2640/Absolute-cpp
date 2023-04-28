
/*Write a program that will read in a sentence of up to 100 characters and output  
the sentence with spacing corrected and with letters corrected for capitalization.  In other words, in the output sentence all strings of two or more blanks should be  compressed to a single blank. The sentence should start with an uppercase letter  but should contain no other uppercase letters. Do not worry about proper names;  if their first letter is changed to lowercase, that is acceptable. Treat a line break as  if it were a blank in the sense that a line break and any number of blanks are com ressed to a single blank. Assume that the sentence ends with a period and contains  no other periods. For example, the input  
 the Answer to life, the Universe, and everything  
IS 42.  
 should produce the following output:  
 The answer to life, the universe, and everything is 42*/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;


bool changeSen(string& sentence, int index);

int main(int argc, char *argv[])
{
	while(true)
	{
		bool isword = false; char Input;
		cin.ignore();
		string sentence;
		getline(cin,sentence);
		int sentLen = sentence.length(); int fourCount = 0;
		for(int i = 0; i < sentLen; i++)
		{
			if(sentence[i]==' ' || sentence[i] ==','|| sentence[i] =='.'|| sentence[i] =='!')
			{
				if(fourCount == 4)
				{
					changeSen(sentence,i-4);
				}
				fourCount = 0;
			}else
			{
				fourCount++;
			}
		}
		sentence[0] = toupper(sentence[0]);
		cout << sentence << endl ;
		cout << "quit program? (Y,N)"<<endl;
		cin >>Input;
		if(Input == 'Y') break;
		else{continue;}
	 	
	}	 		
}
bool changeSen(string& sentence, int index)
{
	string keyword = "love";
	for(int i =0; i < 4; i++)
	{
		sentence[index+i]=keyword[i];
	}
}
		

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

int main(int argc, char *argv[])
{
	string Input, name[3];
	getline(cin,Input);
	int len = Input.length(); int nameCount = 0;
	bool nameover = false;

	for(int i =0; i<len;i++)
	{
		if(Input[i]==' ') 
		{
			name[nameCount][0] = toupper(name[nameCount][0]);
			nameCount++; nameover = true; continue;}
		else
		{
			if(nameover) nameover = false;
			name[nameCount] += Input[i];
		}
	}
	if(nameCount == 1)
	{
		name[1][0] = toupper(name[1][0]);
		cout << name[1] <<", "<<name[0];
	}
	else
	{
		name[2][0] = toupper(name[2][0]);
		cout<< name[2]<<", "<<name[0]<<" "<<name[1][0] << ".";
	}	 		
}
		
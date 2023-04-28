#include<iostream>
#include<string>
#include<cctype>

using namespace std;
class Trivia
{
public:
	Trivia(int a);
	void startTrivia();
	void getTrivia(int index);
	void getprice() { cout << " Your price is " << pricesum << endl; };
private:
	int questionCount;
	string triviaArr[10], answerArr[10];
	int priceArr[10];
	int pricesum = 0;//
};
Trivia::Trivia(int a)
{
	questionCount = a;
	if (a > 10) {
		cout << "Trivia cant over 10!";
	}
	else {
		for (int i = 0; i < a; i++)
		{
			getTrivia(i);
		}
	}
};
void Trivia::startTrivia() {
	for (int i = 0; i < questionCount; i++)
	{
		string input;
		cout << triviaArr[i] << endl;
		cin >> input;
		cin.ignore();
		if (input == answerArr[i]) {
			cout << "Correct!" << endl;
			pricesum += priceArr[i];
		}
		else
		{
			cout << "Incorrect.." << endl;
		}
	}
	getprice();
};
void Trivia::getTrivia(int index)
{
	string temp;
	cout << "Input trivia" << endl;
	getline(cin, triviaArr[index], '\n');
	cout << "Input answer" << endl;
	getline(cin, answerArr[index], '\n');
	cout << "Input price" << endl;
	getline(cin, temp, '\n');
	priceArr[index] = stoi(temp);
}
int main()
{
	Trivia tri1(3);
	tri1.startTrivia();


}

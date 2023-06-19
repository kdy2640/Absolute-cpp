
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace GuessGame
{
	class Player
	{
	public:
		Player() {}
		virtual int getGuess() { return 0; }
	private:
	};
	class HPlayer : public Player
	{

	public:
		HPlayer() : Player() {}
		int getGuess()
		{
			cout << "Input your Guess." << endl;
			int num = 0;
			cin >> num;
			return num;
		}
	private:
	};
	class CPlayer : public Player
	{

	public:
		CPlayer() : Player() {}
		int getGuess()
		{
			int num = rand() % 101;
			while (Table[num] == true) {
				num = rand() % 101;
			}
			setTable(num, true);
			return num;
		}
		void setTable(int _index, bool _value) { Table[_index] = _value; }
	private:
		bool Table[100] = {};
	};

	bool checkForWin(int guess, int answer)
	{
		if (answer == guess)
		{
			cout << "You're right! You win!" << endl;
			return true;
		}
		else if (answer < guess)
			cout << "Your guess is too high." << endl;
		else
			cout << "Your guess is too low." << endl;
		return false;
	}
	void play(Player& player1, Player& player2)
	{
		int answer = 0, guess = 0;
		answer = rand() % 100;
		bool win = false;
		while (!win)
		{
			cout << "Player 1's turn to guess." << endl;
			guess = player1.getGuess();
			win = checkForWin(guess, answer);
			if (win) return;
			cout << "Player 2's turn to guess." << endl;
			guess = player2.getGuess();
			win = checkForWin(guess, answer);
			if (win) return;
		}
	}
}
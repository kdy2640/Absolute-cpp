
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace RD
{
	class Dice
	{
	public:
		Dice() : numSides(6) { srand(time(NULL)); }
		Dice(int _numSides) :numSides(_numSides) { srand(time(NULL)); }
		virtual int rollDice() const { return(rand() % numSides) + 1; }
	protected:
		int numSides;
	};
	class LoadedDice : public Dice
	{
	public:
		LoadedDice() :Dice() {}
		LoadedDice(int _v1) : Dice(_v1) {}
		int rollDice() const
		{
			if (rand() % 2 == 0) { cout << "Loaded?" << endl;  return numSides; }
			else Dice::rollDice();
		}
	protected:
	};
	// Take two dice objects, roll them, and return the sum 
	int rollTwoDice(const Dice& die1, const Dice& die2)
	{
		return die1.rollDice() + die2.rollDice();
	}
}
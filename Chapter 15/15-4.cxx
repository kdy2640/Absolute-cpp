
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace Game
{
	class Creature
	{
	public:
		Creature() :type(0), strength(10), hitpoints(10) {}
		Creature(int newType, int newStrength, int newHit) :type(newType), strength(newStrength), hitpoints(newHit) {}
		virtual int getDamage()
		{
			return rand() % strength;
		}
		string getSpecies() {
			switch (type)
			{
			case 0: return "Human";
			case 1: return "Cyberdemon";
			case 2: return "Balrog";
			case 3: return "Elf";
			}
			return "Unknown";
		}

		int getType() { return type; }
		int getStrength() { return strength; }
		int getHitPoints() { return hitpoints; }
		void setType(int _value) { type = _value; }
		void setStrength(int _value) { strength = _value; }
		void setHitPoints(int _value) { hitpoints = _value; }
	private:
		int type;
		int strength;
		int hitpoints;
	};
	class Human : public Creature
	{
	public:
		int getDamage() { return Creature::getDamage(); }
	private:
	};
	class Demon : public Creature
	{
	public:
		virtual int getDamage() {
			if (rand() % 100 < 5) { cout << " Demonic Attack! " << endl; return Creature::getDamage() + 50; }
			return  Creature::getDamage();
		}
	private:
	};
	class Cyberdemon : public Demon
	{
	public:
		Cyberdemon() { setType(1); setStrength(20); setHitPoints(100); }
		int getDamage() { return Demon::getDamage(); }
	private:
	};
	class Barlog : public Demon
	{
	public:
		Barlog() { setType(2); setStrength(15); setHitPoints(50); }
		int getDamage() { return Demon::getDamage() * 2; }
	private:
	};
	class Elf : public Creature
	{
	public:
		Elf() { setType(3); setStrength(12); setHitPoints(30); }

		int getDamage() {
			int Dam = Creature::getDamage();  if (rand() % 100 < 10) {
				Dam *= 2; cout << " Magical Attack! " << endl;
			}
			return Dam;
		}
	private:
	};

	void battleArena(Creature& _cr1, Creature& _cr2)
	{
		int stage = 0;
		cout << "--------------------------" << endl;
		cout << "Current Stage is " << stage << endl;
		cout << _cr1.getSpecies() << "'s HP is " << _cr1.getHitPoints() << endl;
		cout << _cr2.getSpecies() << "'s HP is " << _cr2.getHitPoints() << endl;
		cout << "Press Enter to next Stage or N to exit" << endl;
		cout << "--------------------------" << endl;
		char input[5] = {};
		cin.getline(input, 4, '\n');
		system("cls");
		while (input != "n" && input != "N")
		{
			stage++;
			cout << "--------------------------" << endl;
			int a = _cr1.getDamage();
			int b = _cr2.getDamage();
			if (_cr1.getHitPoints() < b)
			{
				cout << _cr2.getSpecies() << " inflicts " << b << " Damages to " << _cr2.getSpecies() << "!," << _cr2.getSpecies() << "'s HP is " << _cr2.getHitPoints() << endl;
				cout << _cr1.getSpecies() << "'s Hp is 0!" << endl;
				cout << _cr2.getSpecies() << " is Win!" << endl;
				break;
			}
			if (_cr2.getHitPoints() < a)
			{
				cout << _cr1.getSpecies() << " inflicts " << a << " Damages to " << _cr2.getSpecies() << "!," << _cr2.getSpecies() << "'s HP is " << _cr2.getHitPoints() << endl;
				cout << _cr2.getSpecies() << "'s Hp is 0!" << endl;
				cout << _cr1.getSpecies() << " is Win!" << endl;
				break;
			}
			_cr1.setHitPoints(_cr1.getHitPoints() - b);
			_cr2.setHitPoints(_cr2.getHitPoints() - a);

			cout << _cr1.getSpecies() << " inflicts " << a << " Damages to " << _cr2.getSpecies() << "!," << _cr2.getSpecies() << "'s HP is " << _cr2.getHitPoints() << endl;
			cout << _cr2.getSpecies() << " inflicts " << b << " Damages to " << _cr2.getSpecies() << "!," << _cr2.getSpecies() << "'s HP is " << _cr2.getHitPoints() << endl;
			cout << "--------------------------" << endl;
			cout << "Current Stage is " << stage << endl;
			cout << _cr1.getSpecies() << "'s HP is " << _cr1.getHitPoints() << endl;
			cout << _cr2.getSpecies() << "'s HP is " << _cr2.getHitPoints() << endl;
			cout << "Press Enter to next Stage or N to exit" << endl;
			cout << "--------------------------" << endl;
			cin.getline(input, 4, '\n');
			system("cls");
		}

	}

}

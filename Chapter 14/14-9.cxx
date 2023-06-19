
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
		int getDamage()
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
		void getDamage() { cout << getSpecies() << " inflicts " << Creature::getDamage() << " Damages!" << endl; }
	private:
	};
	class Demon : public Creature
	{
	public:
		int getDamage() {
			if (rand() % 100 < 5) { cout << " Demonic Attack! " << endl; return Creature::getDamage() + 50; }
			return  Creature::getDamage();
		}
	private:
	};
	class Cyberdemon : public Demon
	{
	public:
		Cyberdemon() { setType(1); setStrength(20); setHitPoints(100); }
		void getDamage() { cout << getSpecies() << " inflicts " << Demon::getDamage() << " Damages!" << endl; }
	private:
	};
	class Barlog : public Demon
	{
	public:
		Barlog() { setType(2); setStrength(15); setHitPoints(50); }
		void getDamage() { cout << getSpecies() << " inflicts " << Demon::getDamage() * 2 << " Damages!" << endl; }
	private:
	};
	class Elf : public Creature
	{
	public:
		Elf() { setType(3); setStrength(12); setHitPoints(30); }

		void getDamage() {
			int Dam = Creature::getDamage();  if (rand() % 100 < 10) {
				Dam *= 2; cout << " Magical Attack! " << endl;
			}
			cout << getSpecies() << " inflicts " << Dam << " Damages!" << endl;
		}
	private:
	};
}
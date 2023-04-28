
#include <iostream>
#include <vector>
using namespace std;
class Box
{
private:
	vector<string> pack;
public:
	Box() { pack.clear(); };
	void addPack(string b);
	string getPack(int i);
	void Clear() { pack.clear(); };
	void setPack(string b, int i);
	string getBox();
	friend const Box operator +(const Box& b1, const Box& b2);
};
void Box::addPack(string b) { pack.push_back(b); }
void Box::setPack(string b, int i) { if (i < pack.size()) pack[i] = b; }

string Box::getPack(int i) {

	if (i < pack.size())return pack[i];
	else return "";
}
string Box::getBox() {
	string s = "box contains: ";
	for (int i = 0; i < pack.size(); i++)
		s = s + pack[i] + " ";
	return s;
}
const Box operator +(const Box& b1, const Box& b2)
{
	Box newb;
	for (int i = 0; i < b1.pack.size(); i++)
		newb.addPack(b1.pack[i]);
	for (int i = 0; i < b2.pack.size(); i++)
		newb.addPack(b2.pack[i]); return newb;
}
int main()
{
	Box b1, b2;
	b1.addPack("Melon"); b1.addPack("Apple");
	b2.addPack("Apple"); b2.addPack("Banana"); b2.addPack("Mango");
	Box b3 = b1 + b2;
	cout << b1.getBox() << endl << b2.getBox() << endl << b3.getBox() << endl;
	return 0;
}
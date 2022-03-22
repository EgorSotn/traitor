#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;





struct pred
{
	bool operator()(const int a, int b) const {
		return a < b;
	}
};
//Даниил лох
//dfdf
<<<<<<< HEAD
//aafsfsfsfsggdf
//sfsfdsfsfdgf
//dsf
//lohhh
//addsdsdsfdghgjgmkhjkhk
=======
//lohhhhhh
>>>>>>> branch2
class Sport_gds {
private:
	
public:
	string name;
	int number;
	
	Sport_gds(const Sport_gds& obj) {
		name = obj.name;
		number = obj.number;
	}
	Sport_gds(){}
	virtual Sport_gds* copy() {
		return new Sport_gds(*this);
	}
	virtual void cop(multimap<int,Sport_gds*, pred>& m) {

		Sport_gds* obj = new Sport_gds(*this);
		m.emplace(obj->number,obj);
	}
	

	virtual void print() {
		cout << name << '\t' << number<<endl;
	}
	virtual ~Sport_gds(){}
};

class Tshirt : public Sport_gds {
	
public:
	static int count;
	Tshirt(string name, int number) {
		this->name = name;
		this->number = number;
		count++;
		
	}
	Tshirt(const Tshirt& obj):Sport_gds(obj) {
		name = obj.name;
		number = obj.number;
	}

	Tshirt* copy() { return new Tshirt(*this); }
	void cop(multimap<int, Sport_gds*, pred>& m) {

		Tshirt* obj = new Tshirt(*this);
		m.emplace(obj->number, obj);
	}
	

};
int Tshirt::count = 0;

class Cap : public Sport_gds {

public:
	static int count;
	Cap(string name, int number) {
		this->name = name;
		this->number = number;
		count++;
	}
	Cap(const Cap& obj) :Sport_gds(obj) {
		name = obj.name;
		number = obj.number;
	}
	Cap* copy() { return new Cap(*this); }
	void cop(multimap<int, Sport_gds*, pred>& m) {
		
		Cap* obj = new Cap(*this);
		m.emplace(obj->number, obj);
	}
};
int Cap::count = 0;

class Ball : public Sport_gds {
public:
	static int count;
	Ball(string name, int number) {
		this->name = name;
		this->number = number;
		count++;
	}
	Ball(const Cap& obj) :Sport_gds(obj) {
		name = obj.name;
		number = obj.number;
	}
	Ball* copy() { return new Ball(*this); }
	void cop(multimap<int, Sport_gds*, pred>& m) {

		Ball* obj = new Ball(*this);
		m.emplace(obj->number, obj);
	}
};
int Ball::count = 0;

class Backpack : public Sport_gds {

public:
	static int count;
	Backpack(string name, int number) {
		this->name = name;
		this->number = number;
		count++;
	}
	Backpack(const Backpack& obj) :Sport_gds(obj) {
		name = obj.name;
		number = obj.number;
	}
	Backpack* copy() { return new Backpack(*this); }
	void cop(multimap<int, Sport_gds*, pred>& m) {

		Backpack* obj = new Backpack(*this);
		m.emplace(obj->number, obj);
	}
};
int Backpack::count = 0;

class Sneakers : public Sport_gds {

public:
	static int count;
	Sneakers(string name, int number) {
		this->name = name;
		this->number = number;
		count++;
	}
	Sneakers(const Sneakers& obj) :Sport_gds(obj) {
		name = obj.name;
		number = obj.number;
	}
	Sneakers* copy() { return new Sneakers(*this); }
	void cop(multimap<int, Sport_gds*, pred>& m) {

		Sneakers* obj = new Sneakers(*this);
		m.emplace(obj->number, obj);
	}
};
int Sneakers::count = 0;

class Bike : public Sport_gds {

public:
	static int count;
	Bike(string name, int number) {
		this->name = name;
		this->number = number;
		count++;
	}
	Bike(const Sneakers& obj) :Sport_gds(obj) {
		name = obj.name;
		number = obj.number;
	}
	Bike* copy() { return new Bike(*this); }
	void cop(multimap<int, Sport_gds*, pred>& m) {

		Bike* obj = new Bike(*this);
		m.emplace(obj->number, obj);
	}
};
int Bike::count = 0;




struct pred1
{
	bool operator()(const string& a, const string& b) const{
		int sz = a.size() < b.size() ? a.size() : b.size();
		for (int i = 0; i < sz; ++i) {
			if (i == 2) continue;
			else
			{
				if (a[i] < b[i]) return 1;
				else if (a[i] > b[i]) return 0;
			}
		}
}
};
class Poller {
private:
	void parse(string line) {
		int endName = line.find_last_of(' ') ;
		name = line.substr(0, endName);
		line.erase(0, endName);
		number = stoi(line.substr(1, line.size()));
		}
	string name;
	int number;
public:
	Sport_gds* createGds(string line) {
		parse(line);

		if (name == "футболка") return new Tshirt(name, number);
		if (name == "бейсболка") return new Cap(name, number);
		if (name == "мяч") return new Ball(name, number);
		if (name == "рюкзак") return new Backpack(name, number);
		if (name == "кеды") return new Sneakers(name, number);
		if (name == "велосипед") return new Bike(name,number);
	}
};






int main() {

	ifstream file("Sport.txt");
	setlocale(LC_ALL, "Russian");

	if (file.fail())
	{
		cout << "Can not open file";
		return 1;
	}
		
	string str;
	vector<Sport_gds*> bd;
	multimap<int, Sport_gds*, pred> mbd;
	Poller poller;
	while (!file.eof()){
		str = "";

		getline(file, str);

		bd.push_back(poller.createGds(str));

	}
	cout << "Вывод объектов из вектора"<<endl;
	for (vector<Sport_gds*>::iterator it1 = bd.begin(); it1 != bd.end(); ++it1) {
		cout <<  ( * it1)->number<<'\t'<<(*it1)->name << endl;
	}

	/*for (vector<Sport_gds*>::iterator it1 = bd.begin(); it1 != bd.end(); ++it1) {
		Sport_gds* newObj = (*it1)->copy();
		mbd.emplace(newObj->number, newObj);
	}*/

	
	for (vector<Sport_gds*>::iterator it1 = bd.begin(); it1 != bd.end(); ++it1) {
		if((* it1)->name == "мяч") (*it1)->cop(mbd);
		
	}
	
	cout << "Вывод объектов из multimap"<<endl;
	for (map<int,Sport_gds*>::iterator it1 = mbd.begin(); it1 != mbd.end(); ++it1) {
		cout << it1->first << '\t' << it1->second->name << endl;
	}

	
	

	
	//вывод количество созданных объектов Bike
	cout << Bike::count << endl;


	//clear
	for (vector<Sport_gds*>::iterator it1 = bd.begin(); it1 != bd.end(); ++it1) {
		delete* it1;
	}
	for (map<int, Sport_gds*>::iterator it1 = mbd.begin(); it1 != mbd.end(); ++it1) {
		delete it1->second;
	}
	mbd.clear();
	return 0;
}
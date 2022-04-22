#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stack>
using namespace std;
class Place {
public:
	int id;
	Place* west;
	Place* east;
	Place* parent;
public:
	Place();
	Place(int id);
	virtual ~Place();
	void setWest(Place* west);
	void setEast(Place* east);
	void setparent(Place* _parent);
	Place* getWest();
	Place* getEast();
	int getID();
	virtual void showDescription() = 0;
	virtual unsigned getValue() = 0; 
};

class Relic :virtual public Place {
public:
	unsigned treasure;
	Relic(int id, unsigned treasure);
	void showDescription();
	unsigned getValue();
};

class Town :virtual public Place {
public:
	unsigned food;
	Town(int id, unsigned food);
	void showDescription();
	unsigned getValue();

};

class AncientTown : public Relic, public Town {
public:
	AncientTown(int id, unsigned treasure, unsigned food);
	void showDescription();
	unsigned getValue();
};

class Map {
public:
	int count;
	vector<Place*> places;
	stack<string> paths;
public:
	Map(ifstream& file);
	~Map();
	Place* getPlace(int id);
	void showPath(Place* dest);
};
#include<iostream>
#include "Map.h"
#include<fstream>
#include<string>
#include<istream>
#include<iomanip>
using namespace std;

Place::Place() {
	int id = 0;
	west = nullptr;
	east = nullptr;
	parent = nullptr;
}
Place::Place(int _id) {
	id = _id;
	west = nullptr;
	east = nullptr;
}
 Place::~Place() {

}
void Place::setWest(Place* _west) {
	west = _west;
}
void Place::setEast(Place* _east) {
	east = _east;
}
void Place::setparent(Place* _parent) {
	parent = _parent;
}
Place* Place::getWest() {
	return west;
}
Place* Place::getEast() {
	return east;
}
int Place::getID() {
	return id;
}

Relic::Relic(int _id, unsigned _treasure) :Place(_id){
	treasure = _treasure;
}
void Relic::showDescription() {
	cout << "ID:" << id << ",RELIC," << treasure << endl;
}
unsigned Relic::getValue() {
	return 5 * treasure;
}

Town::Town(int _id, unsigned _food) :Place(_id) {
	food = _food;
}
void Town::showDescription() {
	cout << "ID:" << id << ",TOWN," << food << endl;

}
unsigned Town::getValue() {
	return  2 * food;
}

AncientTown::AncientTown(int _id, unsigned _treasure, unsigned _food) :Place(_id),Town(_id,_food), Relic(_id,_treasure) {

}
void AncientTown::showDescription() {
	cout << "ID:" << id << ",ANCIENTTOWN," <<treasure<<","<< food << endl;

}
unsigned AncientTown::getValue() {
	return  food *2+ treasure*5;
}

Map::Map(ifstream& file) {
	file >> count; char ch; int type;
	for (int i = 0; i < count; i++) {
		int _id; unsigned _treasure; unsigned _food;
		file >> _id>>ch>>type>>ch>>_treasure>>ch>>_food;
		switch (type) {
		case 0:
		{Relic* relic = new Relic(_id, _treasure);
		places.push_back(relic); }
			break;
		case 1:
		{Town* town = new Town(_id, _food);
		places.push_back(town); }
			break;
		case 2:
		{AncientTown* at = new AncientTown(_id, _treasure, _food);
		places.push_back(at); }
			break;
		}
	}
	for (int i = 0; i < count; i++) {
		int _id1, _id2, _id3;
		file >> _id1 >> ch >> _id2 >> ch >> _id3;
		int j = 0,p=0,q=0;
		for (; j < count && places.at(j)->id != _id1; j++);
		for (; p < count && places.at(p)->id != _id2; p++);
		for (; q < count && places.at(q)->id != _id3; q++);
		if (q < count && p < count) {
			places.at(j)->setWest(places.at(p)); places.at(j)->setEast(places.at(q));
			places.at(p)->setparent(places.at(j)); 
			places.at(q)->setparent(places.at(j));
		}
		else if (q < count) {
			places.at(j)->setWest(nullptr); places.at(j)->setEast(places.at(q));
			places.at(q)->setparent(places.at(j));
		}
		else if (p < count) {
			places.at(j)->setWest(places.at(p)); places.at(j)->setEast(nullptr);
			places.at(p)->setparent(places.at(j));
		}
		else if (p >= count && q >= count) {
			places.at(j)->setWest(nullptr); places.at(j)->setEast(nullptr);
		}
	}
}
Map::~Map() {

}
Place* Map::getPlace(int _id) {
	int i = 0;
	for (; i < count && places.at(i)->id != _id; i++);
	if(i<count)
		return places.at(i);
	return nullptr;
}
void Map::showPath(Place* dest) {
	Place* node = places.at(0);
	int sum = 0;
	if (dest == nullptr) {
		return;
	}
	if (dest->id == node->id) {
		sum += node->getValue();
		while (!paths.empty()) {
			string ch = paths.top();
			cout << ch;
		}
		cout << "," << sum << endl;
		return;
	}
	int i = 0;
	for (; i < count && places.at(i)->id != dest->id; i++);
	Place* temp = places.at(i);
	while (temp->id!=node->id) {
		if (temp->parent->west->id == temp->id) {
			paths.push("W");
			sum += temp->getValue();
			temp = temp->parent;
		}
		else {
			paths.push("E");
			sum += temp->getValue();
			temp = temp->parent;
		}
	}
	sum += node->getValue();
	while (!paths.empty()) {
		string ch = paths.top();
		paths.pop();
		cout << ch;
	}
	cout << "," << sum << endl;
	return;
}

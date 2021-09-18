/*************************************************
 * Name: Dev Chauhan
 * Title: Classname.cpp
 * Date: 10/14/20
 * ***********************************************/
#include "HashTable.h"
#include "HashEntry.h"
#include "Creature.h"
#include <iostream>
using namespace std;

HashTable<Creature *> *myTable = new HashTable<Creature *>(10);

int Creature::getID() const
{
    return this->idNum;
}

string Creature::getName() const
{
    return this->Name;
}

string Creature::getDescription() const
{
    return this->Description;
}

float Creature::getlifePoint() const
{
    return this->lifePoint;
}

float Creature::gethitPoint() const
{
    return this->hitPoint;
}

void Creature::setID(int idnum)
{
    this->idNum = idnum;
}

void Creature::setName(string name)
{
    this->Name = name;
}

void Creature::setDescription(string description)
{
    this->Description = description;
}

void Creature::setlifePoint(float life)
{
    this->lifePoint = life;
}

void Creature::sethitPoint(float hit)
{
    this->hitPoint = hit;
}

void printCreature()
{
    int size;
    int key;
    string name, description, temp;
    float life, hit;
    Creature print;

    cout << "\nID: ";
    print.setID(key);
    cout << "\nNAME:  ";
    print.setName(temp);
    cout << "\nDESCRIPTION: ";
    print.setDescription(temp);
    cout << "\nLIFE POINT: ";
    print.setlifePoint(life);
    cout << "\nHIT POINT: ";
    print.sethitPoint(hit);

    cout << endl;
}
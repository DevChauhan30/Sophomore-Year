/*************************************************
 * Name: Dev Chauhan
 * Title: Creature.h
 * Date: 10/14/20
 * ***********************************************/

#ifndef Creature_H
#define Creature_H

#include <iostream>
using namespace std;

class Creature
{
    private:
        int idNum;
        string Name, Description;
		float lifePoint, hitPoint;
        Creature *myTable;
		
	public:
		Creature(int idnum, string name, string description, float life, float hit)
        {
			this->idNum = idnum;
			this->Name = name;
            this->Description = description;
			this->lifePoint = life;
            this->hitPoint = hit;
		}

        Creature()
        {
            
        }
        
        //accessor functions
		int getID() const;
		string getName() const;
        string getDescription() const;
		float getlifePoint() const;
        float gethitPoint() const;

        //mutator Functions
        void setID(int idnum);
        void setName(string name);
        void setDescription(string description);
        void setlifePoint(float life);
        void sethitPoint(float hit);
        
		friend ostream & operator<< (ostream & os, Creature c)
		{
			os << c.getID() << ", " << c.getName();
			return os;
		}
		
};

#endif
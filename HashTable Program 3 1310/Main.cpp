/*************************************************
 * Name: Dev Chauhan
 * Title: Main.cpp
 * Date: 10/14/20
 * ***********************************************/
#include "HashTable.h"
#include "HashEntry.h"
#include "Creature.h"
#include <iostream>
#include <Fstream>
#include <string>
#include <iomanip>
using namespace std;

int enterCreature(HashTable<Creature*> *myTable);
void enterCreatureFromFile(HashTable<Creature*> *myTable);
int searchCreature(HashTable<Creature*> *myTable);
void deleteCreature(HashTable<Creature*> *myTable);
void printCreature();

int main()
{
    HashTable<Creature*> *myTable = new HashTable<Creature*>(10);
    int choice;

    do
    {
        cout << "\n>>>>>CREATURE MANAGEMENT MENU \n\n" << endl;
        cout << " 1.\t Add Crature From File" << endl;
        cout << " 2.\t Add Creature Manually" << endl;
        cout << " 3.\t Search for Creature" << endl;
        cout << " 4.\t Delete a Creature" << endl;
        cout << " 5.\t Print Hash Table" << endl;
        cout << " 6.\t End Program" << endl;
        cout << " CHOOSE 1-6: ";
        cin >> choice;

        while(choice < 1 || choice > 6)// validating user choice
        {
            cout << "Error!! Please eneter 1 or 2." << endl;
            cout << "CHOICE: ";
            cin >> choice;
        }

        switch(choice)
		{	
			case 1: enterCreatureFromFile(myTable);
		
					break;
		
			case 2: enterCreature(myTable);
		
					break;
		
			case 3: searchCreature(myTable);
		
					break;
	
			case 4: deleteCreature(myTable);
		
					break;
		
			case 5: printCreature();
					
		            break;

            case 6: cout << "Good Bye->->->->";

                    break;        
		}
    } while (choice !=6);
    
  
}

void enterCreatureFromFile(HashTable<Creature*> *myTable)
{
	ifstream inFile;
	char temp[1000];
    int key;
	string Name, filename, Description;
	float lifePoint, hitPoint, life, hit; 
	Creature *t;
	t = new Creature;
	
	cin.ignore();
	cout << "What is the File name?" << endl;
	cout << "Filename: ";
	getline(cin, filename);

	inFile.open(filename.c_str());
	if(inFile.good())
	{
		inFile.getline(temp, 1000);
		while(!inFile.eof())
		{	
            inFile >> key;
            t->setID(key);
            inFile.getline(temp, 1000);
			inFile >> Name;
			t->setName(temp);
            inFile.ignore();
            inFile.getline(temp, 1000);
			inFile >> Description;
			t->setDescription(temp);
			inFile.ignore(); 
			inFile >> lifePoint;
			t->setlifePoint(life);
            inFile >> hitPoint;
            t->sethitPoint(hit);
		}
		
		cout <<" 10 creatures from " << filename << " have been added to the hash table." <<endl;
		inFile.close();
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

int enterCreature(HashTable<Creature*> *myTable)
{
    string temp;
    char tempChar;
    int key, life, hit;
	Creature print;
	
	do
	{
		cin.ignore();		
		cout << "\nKEY: ";
		cin >> key;		
		print.setID(key);

		cin.ignore();
		cout << "\nNAME: ";
		getline(cin, temp);
		print.setName(temp);

        cout << "\nDISCRIPTION: ";
		getline(cin, temp);
		print.setDescription(temp);
	
		cout << "\nLIFE POINTS: ";
		cin >> life;
		print.setlifePoint(life);

        cout << "\nHIT POINTS: ";
		cin >> hit;
		print.sethitPoint(hit);

		cout << "\nWould you like to add more creatures? (y or n): ";
		cin >> tempChar;
	
	}while(tempChar == 'y' || tempChar == 'Y');	
	
    cout << endl;	
		
}

void deleteCreature(HashTable<Creature*> *myTable) 
{
	int id, size;
	cout << "The following is a list of all the creatures you take care of: " << endl;
	myTable->printHashTable();
	cout << endl << endl;

	cout << "What is the ID of the creature uou wish to remove? " << endl;
	cout << "Creature ID: ";
	cin >> id;
	
}

int searchCreature(HashTable<Creature*> *myTable)
{
	int key, life, hit;
	string temp;
	Creature print;
	cout << "What is the key of the creature you are searching for?";
	cin >> key;

	if(myTable->getValue(key) != NULL)
    {
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
    }
	else
	{
		cout << "There are no creature with that key in the table." << endl;
	}
}
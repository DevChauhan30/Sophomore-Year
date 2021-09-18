/*************************************************
 * Name: Dev Chauhan
 * Title: HashEntry.h
 * Date: 10/14/20
 * ***********************************************/

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include "Creature.h"
#include "HashTable.h"
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class HashEntry
{
	private:
		int key;
		T value;
		HashEntry* next;
		
	public:
		HashEntry(int k, int v)
		{
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		
		int getKey()
		{
			return key;
		}
		T getValue()
		{
			return value;
		}
		HashEntry* getNext()
		{
			return next;
		}
		void setNext(HashEntry *next)
		{
			this->next = next;
		}
		void setValue(int v)
		{
			value = v;
		}
};

#endif
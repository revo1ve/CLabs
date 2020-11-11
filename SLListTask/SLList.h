#pragma once
#include <iostream>

using namespace std;

class SLList
{
private:
	int m_data;
	bool m_isFirst;
	SLList* m_nextElem;
public:
	int getData();
	bool isFirst();
	SLList* next();
	bool hasNext();
	void removeNext();
	void setData(int data);
	SLList* addElement(int data);
	static SLList* beginList(int data);
};

void printSLList(SLList* list);
int getElementFromEnd(SLList* list, int k);
void removeDuplicates(SLList* list);

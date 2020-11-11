#pragma once

class SLList
{
private:
	SLList* beginList(int data);
	SLList* m_nextElem;
	int m_data;
public:
	SLList(int data);
	int getData();
	void setData(int data);
	SLList* next();
	bool hasNext();
	SLList* addElement(int data);
	void removeNext();
};
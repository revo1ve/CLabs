#include "SLList.h"

int SLList::getData() { return m_data; }
bool SLList::isFirst() { return m_isFirst; }
SLList* SLList::next() { return m_nextElem; }
void SLList::setData(int data) { m_data = data; }
bool SLList::hasNext() { return m_nextElem != nullptr; }

SLList* SLList::beginList(int data)
{
	auto list = new SLList();
	list->m_isFirst = true;
	list->setData(data);
	return list;
}

SLList* SLList::addElement(int data)
{
	auto nextElem = new SLList();
	nextElem->setData(data);
	auto curr = this;
	while (curr->hasNext())
		curr = curr->next();
	curr->m_nextElem = nextElem;
	return nextElem;
}

void SLList::removeNext()
{
	if (hasNext())
	{
		auto next = m_nextElem;
		if (m_nextElem->hasNext())
			m_nextElem = m_nextElem->next();
		else m_nextElem = nullptr;
		delete next;
	}
}

void printSLList(SLList* list)
{
	while (list->hasNext())
	{
		cout << list->getData() << " ";
		list = list->next();
	}
	cout << list->getData();
}

int getElementFromEnd(SLList* list, int k)
{
	int listCount = 0;
	for (SLList* i = list; i->hasNext(); i = i->next())
		listCount++;
	int index = listCount - k;
	for (SLList* i = list; index >= 0 && i != nullptr; i = i->next())
	{
		if (index == 0)
			return i->getData();
		index--;
	}
	return -1;
}

void removeDuplicates(SLList* list)
{
	for (SLList* i = list; i != nullptr && i->hasNext(); i = i->next())
		for (SLList* j = i; j->hasNext();)
		{
			if (i->getData() == j->next()->getData())
				j->removeNext();
			else
				j = j->next();
		}
}

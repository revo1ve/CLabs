#include "SLList.h"
#include <ctime>

int main()
{
    srand((unsigned)time(0));
    setlocale(0, "RUS");

    SLList* list = SLList::beginList(rand() % 6);
    for (int i = 0; i < 9; i++)
        list->addElement(rand() % 6);

    cout << "Исходный список: ";
    printSLList(list);
    removeDuplicates(list);
    cout << "\n" << "Список без дубликатов: ";
    printSLList(list);

    int k = 0;
    cout << "\n" << "Введите индекс элемента с конца: ";
    cin >> k;
    cout << k << "-й элемент с конца: " << getElementFromEnd(list, k);
}

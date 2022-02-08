#include "doublelist.h"
int main()
{
	List<int> ch;
	ch.push_back(1);
	ch.push_back(19);
	ch.push_front(76);
	ch.push_back(434);
	ch.push_back(0);
	ch.insert(2, 83);
	ch.print();
	return 0;
}
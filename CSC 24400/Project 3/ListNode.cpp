#include "ListNode.hpp"

using namespace std;
ostream& operator << (ostream &os, const ListNode &ln)
{
	os << ln.element();
	return os;
}
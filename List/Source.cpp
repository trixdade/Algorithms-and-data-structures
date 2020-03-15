#include "List.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	try {
		List<int> a, b;

		a.insert(6);
		a.printList();
		a.del(6);
		a.printList();
		a.insert(4);
		a.insert(3);
		a.printList();
		a.del(3);
		a.del(5);
		a.printList();
	}

	catch (string s) {
		cout << s << endl;
	}
	system("pause");
	return 0;
}
#pragma once
#include "Table.h"

class USTable : public Table
{
private:
	vector<row> v;
public:
	USTable() {
		vector<row> temp;
		v = temp;
		counter = 0;
	}

	~USTable() {}

	void Insert(row& str) {
		Polynom* temp = Search(str.key);
		if (temp == NULL) {
			v.push_back(str);
			counter++;
		}
		else {
			cout << "This key is taken in Disordered table" << endl;
			return;//throw("This key is taken");
		}
	}

	void Delete(string& _key) {
		for (int i = 0, counter = 0; i < v.size(); i++, counter++)
			if (v[i].key == _key) {
				v.erase(v.begin() + i);
				break;
			}
	}

	Polynom* Search(string& _key) {
		for (int i = 0, counter = 0; i < v.size(); i++, counter++)
			if (v[i].key == _key)
				return v[i].data;
		return NULL;
	}
};
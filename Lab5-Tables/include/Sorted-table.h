#pragma once
#include "Table.h"


class STable : public Table
{
private:
	vector<row> v;
	int Binary_search(string& _key) {
		counter = 0;
		if (v.empty()) {
			counter++;
			return -1;//an empty table
		}
		else {
			int pos;
			int mid, st, fn;
			st = 0;
			fn = v.size() - 1;
			mid = 0;
			while (st <= fn) {
				counter++;
				mid = (st + fn) / 2;
				if (_key < v[mid].key)
					fn = mid - 1;
				else
					if (_key > v[mid].key)
						st = mid + 1;
					else
						return mid;
			}
			return -1;//st > fn
		}
	}
public:
	STable() {
		vector<row> temp;
		v = temp;
		counter = 0;
	}
	~STable() {}
	void Insert(row& str) {
		int pos = Binary_search(str.key);
		if (pos == -1) {
			counter++;
			v.push_back(str);
		}
		else
			if (v[pos].key == str.key) {
				cout << "This key is taken in Ordered table" << endl;
				return;
			}//throw("This key is taken");
			else {
				counter++;
				v.insert(v.begin() + pos, str);//????????????
			}
	}
	void Delete(string&_key) {
		int pos = Binary_search(_key);
		if (pos != -1) {
			if (v[pos].key == _key) {
				v.erase(v.begin() + pos);
				counter++;
			}
		}
	}
	Polynom* Search(string &_key) {
		int pos = Binary_search(_key);
		if ((pos == -1) || (v[pos].key != _key)) {
			return NULL;
		}
		else {
			return (v[pos].data);
		}	
	}
};
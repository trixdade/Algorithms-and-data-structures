#pragma once
#include "Table.h"
#include <list>
#include <math.h>


class HTable : public Table {
private:
	vector<list<row>> v;
	unsigned int MurmurHash2(string& _key) {
		unsigned int len = _key.size();
		const unsigned int m = 0x5bd1e995;
		const unsigned int seed = 0;
		const int r = 24;

		unsigned int h = seed ^ len;

		const unsigned char * data = (const unsigned char *)_key.c_str();
		unsigned int k;

		while (len >= 4)
		{
			k = data[0];
			k |= data[1] << 8;
			k |= data[2] << 16;
			k |= data[3] << 24;

			k *= m;
			k ^= k >> r;
			k *= m;

			h *= m;
			h ^= k;

			data += 4;
			len -= 4;
		}

		switch (len)
		{
		case 3:
			h ^= data[2] << 16;
		case 2:
			h ^= data[1] << 8;
		case 1:
			h ^= data[0];
			h *= m;
		};

		h ^= h >> 13;
		h *= m;
		h ^= h >> 15;

		return h % 1024;
	}
public:
	HTable() {
		vector<list<row>> temp(1024);
		v = temp;
		list<row>a;
		for (int i = 0; i < 1024; i++)
			v[i] = a;
		counter = 0;
	}
	void Insert(row& str) {
		counter = 0;
		unsigned int h = MurmurHash2(str.key);
		if (!v[h].empty())
			for (auto it = v[h].begin(); it != v[h].end(); it++, counter++) {
				if ((*it).key == str.key) {
					cout << "This key is taken in Hash-Table" << endl;
					return;
				}//throw("This key is taken");
			}
		v[h].push_back(str);
		counter++;
	}
	void Delete(string&_key) {
		counter = 0;
		unsigned int h = MurmurHash2(_key);
		for (auto it = v[h].begin(); it != v[h].end(); it++, counter++) {
			if ((*it).key == _key) {
				v[h].erase(it);
				break;
			}
		}

	}
	Polynom* Search(string&_key) {
		counter = 0;
		unsigned int h = MurmurHash2(_key);
		for (auto it = v[h].begin(); it != v[h].end(); it++, counter++) {
			if ((*it).key == _key)
				return (*it).data;
		}
		return NULL;
	}
	~HTable() {}
};

//#define SIZE 100
//
//template <class T1, class T2>
//class HTable {
//	T1** map;
//	bool* is_empty;
//	size_t max_size;
//	size_t(*hash_function)(T2);
//public:
//	const size_t& length = max_size;
//
//	HTable(size_t(*hashFunc)(T2), size_t size = SIZE) : max_size(size) {
//		if (max_size == 0) {
//			throw max_size;
//		}
//		if (*hashFunc == nullptr) {
//			throw hashFunc;
//		}
//
//		hash_function = hashFunc;
//		map = new T1*[max_size];
//		is_empty = new bool[max_size];
//
//		for (size_t i = 0; i < length; i++) {
//			map[i] = nullptr;
//		}
//	}
//
//	T1* Add(T2 key, T1 value) {
//		size_t index = hash_function(key) % length;
//
//		//if (map[index] != nullptr) {
//		//	//throw key;
//		//	return map[index];
//		//}
//
//		if (!is_empty[index]) {
//			return Set(key, value);
//		}
//
//		map[index] = new T1(value);
//		is_empty[index] = false;
//
//		return map[index];
//	}
//
//	T1* Find(T2 key, bool *isset = nullptr) { // isset => 1 - есть, 0 - нет
//		size_t index = hash_function(key);
//		if (isset != nullptr) {
//			(*isset) = (index < length) && !is_empty[index % length];
//		}
//
//		return map[index % length];
//	}
//
//	T1* Set(T2 key, T1 value) {
//		size_t index = hash_function(key) % length;
//		if (is_empty[index]) {
//			return Add(key, value);
//		}
//		 //*map[index]=value;
//		 return map[index];
//	}
//
//	void Delete(T2 key) {
//		size_t index = hash_function(key) % length;
//
//		//map[index] = nullptr;
//		is_empty[index] = true;
//
//		delete map[index];
//	}
//
//	~HTable() {
//		delete map;
//	}
//};

#pragma once
#include "stdafx.h"
#include "../Tables/Polynoms.h"

struct row {
	string key;
	Polynom* data;
};

class Table {
protected:
	int counter;
public:
	Table() {}
	virtual ~Table() {}
	virtual void Insert(row&) = 0;
	virtual void Delete(string&) = 0;
	virtual Polynom* Search(string&) = 0;
	int Count() { return counter; }
};
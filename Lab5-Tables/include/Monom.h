#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <SDKDDKVer.h>

using namespace std;

class Monom;
typedef Monom* Link; //��������� �� �����

class Monom {
	int power; //�������
	double cf;    //����������� 
	Link pointer;   //��������� �� ����.�����
public:
	Monom(int _power = 0, double _cf = 0, Link _pointer = NULL) // ����������� �������������
	{
		power = _power;
		cf = _cf;
		pointer = _pointer;
	}
	void SetPower(int _power)//��������� �������
	{
		power = _power;
	}
	void SetCf(double _cf) //��������� ����
	{
		cf = _cf;
	}
	void SetPointer(Link _pointer) //��������� ���������
	{
		pointer = _pointer;
	}
	int GetPower(void) const //�������� ������� 
	{
		return power;
	}
	double GetCf(void) const //�������� ����
	{
		return cf;
	}
	Monom* GetPointer(void) const  // �������� ���� ����� 
	{
		return pointer;
	}
};


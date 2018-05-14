/*--Èí¼şÊ®°à--55171021--ËïÅà¸Û--*/
/*--Singer.h--*/
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Singer
{
	int number;
	string name;
	float grades[4];
	float averageScore;
	static int appearPlayers;
public:
	~Singer();
	friend class List;
	void Initialize(const string name_, const float *grades_, const int number_);
	static void Appear();
	static void PrintAppear();
	Singer *next;
};
/*--Singer.cpp--*/
#include"Singer.h"

int Singer::appearPlayers = 0;

Singer::~Singer() {}

void Singer::Initialize(const string name_, const float *grades_, const int number_) {
	name = name_;
	number = number_;
	float totalPoints = 0;
	for (int index = 0; index < 4; index++) {
		grades[index] = grades_[index];
		totalPoints += grades[index];
	}
	averageScore = totalPoints / 4;
}

void Singer::Appear() {
	appearPlayers++;
}

void Singer::PrintAppear() {
	cout << "已出场" << appearPlayers << "名歌手.\n";
}
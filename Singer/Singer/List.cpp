/*--List.cpp--*/
#include "List.h"
#include<iomanip>


void List::CreateList() {
	string name_;
	char judge;
	int number_ = 0;
	float grades_[4];
	Singer *st1 = head, *st2 = head;
	while (st1 != NULL) {
		st2 = st1;
		st1 = st1->next;
		number_++;
	}
	do {
		st1 = new Singer;
		if (head == NULL)
			head = st1;
		else
			st2->next = st1;
		st1->next = NULL;
		number_++;
		cout << "请输入第" << number_ << "名歌手的姓名:\n";
		cin >> name_;
		cout << "请输入周杰伦、庾澄庆、那英和汪峰的打分情况:\n";
		cin >> grades_[0] >> grades_[1] >> grades_[2] >> grades_[3];
		st1->Initialize(name_, grades_, number_);
		Singer::Appear();
		cout << "按y添加下一位歌手信息，其他键不添加.\n";
		cin >> judge;
		st2 = st1;
	} while (judge == 'y');
	head = SortList();
	system("cls");
}

List::~List() {
	Singer *temp = head;
	Singer *q;
	while (temp != NULL) {
		q = temp->next;
		delete temp;
		temp = q;
	}
}

Singer* List::SortList() {
	if (head == NULL || head->next == NULL)return head;
	Singer *st2 = NULL;
	bool isChange = true;
	while (st2 != head->next && isChange) {
		Singer *st1 = head;
		isChange = false;
		for (; st1->next && st1->next != st2; st1 = st1->next) {
			if (st1->averageScore < st1->next->averageScore) {
				swap(st1->averageScore, st1->next->averageScore);
				swap(st1->grades[0], st1->next->grades[0]);
				swap(st1->grades[1], st1->next->grades[1]);
				swap(st1->grades[2], st1->next->grades[2]);
				swap(st1->grades[3], st1->next->grades[3]);
				swap(st1->name, st1->next->name);
				swap(st1->number, st1->next->number);
				isChange = true;
			}
		}
		st2 = st1;
	}
	return head;
}

void List::Print() {
	Singer *st1 = head;
	if (st1 == NULL)cout << "当前最高分:0\n当前最低分:0\n";
	else {
		cout << "当前最高分:" << setiosflags(ios::fixed) <<
			setprecision(2) << st1->averageScore << "分  编号:" <<
			st1->number << "  姓名:" << st1->name << endl;
		while (st1->next != NULL)st1 = st1->next;
		cout << "当前最低分:" << setiosflags(ios::fixed) <<
			setprecision(2) << st1->averageScore << "分  编号:" <<
			st1->number << "  姓名:" << st1->name << endl;
	}
}

void List::PrintList() {
	Singer *st1 = head;
	cout << setw(10) << setiosflags(ios::left) << "名次" << setw(10)
		<< "编号" << setw(10) << "姓名" << setw(6) << "|" << setw(10)
		<< "周杰伦" << setw(10) << "庾澄庆" << setw(10) << "那英" <<
		setw(10) << "汪峰" << setw(6) << "|" << setw(6) << "平均分\n"
		<< "------------------------------------------------"
		<< "--------------------------------------------\n";
	for (int index = 1; st1 != NULL; index++) {
		cout << setw(10) << setiosflags(ios::left) << index << setw(10) << st1->number
			<< setw(10) << st1->name << setw(6) << "|" << setw(10) << setiosflags(ios::fixed)
			<< setprecision(2) << st1->grades[0] << setw(10) << setiosflags(ios::fixed) <<
			setprecision(2) << st1->grades[1] << setw(10) << setiosflags(ios::fixed) <<
			setprecision(2) << st1->grades[2] << setw(10) << setiosflags(ios::fixed) <<
			setprecision(2) << st1->grades[3] << setw(6) << "|" << setw(6) <<
			setiosflags(ios::fixed) << setprecision(2) << st1->averageScore << endl;
		st1 = st1->next;
	}
}
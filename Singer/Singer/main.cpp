/*--main.cpp--*/
#include"List.h"

int main() {
	int navi;
	List list;
menu:
	cout << "********************���˵�********************\n\n"
		<< "1.��Ӹ�����Ϣ.\n\n2.�鿴��ǰ��߷֡���ͷ�ѡ��.\n"
		<< "\n3.�鿴�ѳ�������.\n\n4.�鿴��ǰ����.\n\n5.�˳�.\n\n"
		<< "**********************************************\n\n";
	cin >> navi;
	switch (navi)
	{
	case 1:
		system("cls"); list.CreateList(); system("pause"); system("cls"); goto menu;
	case 2:
		system("cls"); list.Print(); system("pause"); system("cls"); goto menu;
	case 3:
		system("cls"); Singer::PrintAppear(); system("pause"); system("cls"); goto menu;
	case 4:
		system("cls"); list.PrintList(); system("pause"); system("cls"); goto menu;
	case 5:break;
	}
	return 0;
}
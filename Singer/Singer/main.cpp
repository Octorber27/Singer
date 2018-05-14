/*--main.cpp--*/
#include"List.h"

int main() {
	int navi;
	List list;
menu:
	cout << "********************主菜单********************\n\n"
		<< "1.添加歌手信息.\n\n2.查看当前最高分、最低分选手.\n"
		<< "\n3.查看已出场人数.\n\n4.查看当前排名.\n\n5.退出.\n\n"
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
#include <iostream>
#include <cstdlib>
#include <string>
#include "BookInfoManagement.h"
#include "StudentInfoManagement.h"
#include"Fileoperate.h"
using namespace std;

Interface face;
Fileoperate operate;
int admin(string account);
int student(string account);
int BorrowBook(string account);


int main()
{
	int identity;										//当前登陆人员身份
	while (1)
	{
		int op= face.MainFace();
		switch (op)
		{
		case 0:
			return 0;
		case 1:
			cout << "输入账号、密码" << endl;
			string account, password;
			cin >> account >> password;
			identity = operate.GetIdentity(account, password);
			
			switch (identity)
			{
			case 0:
				cout << "登陆失败！！请重试...";
				return 1;
			case 1:
				cout << "学生"<<account<<"登陆成功！！" << endl;
				student(account);
				break;
			case 2:
				cout << "管理员"<<account<<"登陆成功！！" << endl;
				admin(account);
				break;
			}
			break;
		}

	}

	return 1;
}

int admin(string account)
{
	BookInfoManagement Book_Info_Manage;
	StudentInfoManagement Student_Info_Manage;
	while (1) {
		int op = face.AdminMainFace();
		switch (op)
		{
		case 1:
			Book_Info_Manage.BookInfoManage();
			break;
		case 2:
			Student_Info_Manage.StuInfoManage();
			break;
		case 0:
			return 0;
		}
	}
	return 1;
}

int student(string account)
{
	while (1)
	{
		int op = face.StuMainFace();
		switch (op)
		{
		case 1:
			BorrowBook(account);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			return 0;
		}
	}
	return 1;
}

int BorrowBook(string account)
{
	BookInfoManagement bm;
	fstream f;
	f.open("Bookdata.txt", ios::out);
	bm.SwitchFunction(5);
	cout << "输入要借的书籍序号：(0.退出)" << endl;
	int index;
	cin >> index;
	if (index == 0) return 0;
	else
	{
		int i = 1;
		while (i != index)i++;
		int count_rese = 0;                           //保存预约了该书的人数
		string id, name, author, publisher, pubdate;
		int remain;
		f >> id >> name >> author >> publisher >> pubdate >> remain;
		f.close();
		if (remain == 0)
		{
			cout << "该书籍库存不足，是否选择预约？" << endl;
			char op;
			cin >> op;
			if (op == 'Y' || op == 'y')
				;
				//ReserveBook();
			else
				return 0;
		}
		else							//有库存时需要验证是否有人预约了该书
		{
			f.open("Reservedata.txt",ios::out);
			;
		}
	}
	

}
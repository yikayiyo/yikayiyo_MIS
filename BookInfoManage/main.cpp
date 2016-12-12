#include <iostream>
#include <cstdlib>
#include <string>
#include "BookInfoManagement.h"
#include "StudentInfoManagement.h"
#include"Peroperate.h"
#include"Fileoperate.h"
using namespace std;

Interface face;
Fileoperate operate;
int admin(BookInfoManagement &bm);
int student(string account);


int main()
{
	BookInfoManagement bm;
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
				admin(bm);
				break;
			}
			break;
		}

	}

	return 1;
}

int admin(BookInfoManagement &bm)
{
	
	StudentInfoManagement Student_Info_Manage;
	while (1) {
		int op = face.AdminMainFace();
		switch (op)
		{
		case 1:
			bm.BookInfoManage();
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
	Peroperate p;
	while (1)
	{
		p.PersonalOperate(account);
		break;
	}
	return 1;
}

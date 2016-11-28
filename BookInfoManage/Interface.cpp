#include "Interface.h"

void Interface::BookLoadface()
{
	cout << endl << endl;
	cout << "		             图书信息管理       					"<<endl << endl;
	cout << "	#######################################################	" << endl;
	cout << "	#                                                     #	"<< endl;
	cout << "	# 1.添加图书记录  # 2.删除书籍记录  # 3.修改书籍信息  #	" << endl;
	cout << "	# 4.查询书籍记录  # 5.显示图书记录  # 6.退出          #	"<< endl;
	cout << "	#                                                     #	" << endl;
	cout << "	#######################################################	" << endl;

}

void Interface::BookSubloadface2()						   //文件为空，添加记录时的界面
{
	cout << endl << endl;
	cout << "	======================操 作 提 示======================	" << endl
		<< "	|	1.添加图书记录	|	6.退出                 |	" << endl
		<< "	=======================================================	" << endl;
	cout << endl;
}

void Interface::BookSubloadface()
{
	cout << endl << endl;
	cout << "	=======================操  作  提  示========================" << endl
		<< "	|  1.添加图书记录  |  2.删除图书记录  |   3.修改图书记录    |" << endl
		<< "	|  4.查询书籍记录  |  5.显示书籍记录  |   6.退出            |" << endl
		<< "	=============================================================" << endl;
	cout << endl;
}

char Interface::BookInputcharface()	//可删
{
	char op;
	cout << "要导入文件吗？(Y/N):";
	cin >> op;
	return op;
}

int Interface::BookOperateface()				//返回结果1-6代表不同操作
{
	string op;
	int flag, nflag=0;

	do
	{
		flag = 0;
		if (nflag)
		{
			cout << "超出范围...Again:";
			cin >> op;
		}
		else
		{
			cout << "输入你的操作: ";
			cin >> op;
		}

		if (op.length() != 1) { flag++; nflag++; }
		if (op[0] > '6' || op[0] < '0') { flag++; nflag++; }
	} while (flag);

	return op[0] - '0';
}

int Interface::BookOperateface2()						//文件为空，添加记录时的操作提示，返回1或6
{
	string op;
	int flag, nflag = 0;

	do
	{
		flag = 0;
		if (nflag)
		{
			cout << "超出范围...Again:";
			cin >> op;
		}
		else
		{
			cout << "输入你的操作: ";
			cin >> op;
		}

		if (op.length() != 1) { flag++; nflag++; }
		if (op[0]!='6' && op[0] != '1') { flag++; nflag++; }
	} while (flag);

	return op[0] - '0';
}

int Interface::BookAddface()						//添加书籍界面，返回要添加的书籍数目
{
	int num;
	cout << "请输入要添加的书籍数目：(输入0退出)";
	cin >> num;
	return num;
}

int Interface::BookDelface()						//删除书籍界面，返回书籍序号
{
	int index;
	cout << "请输入要删除的书籍序号：(输入0退出)";
	cin >> index;
	return index;
}

int Interface::BookSetface()								//设置界面，返回结果 0-7
{
	int index;
	cout << "请输入要修改的书籍序号(输入0退出)";
	cin >> index;
	if (index)
	{
		cout << "输入要修改的书籍的哪部分信息？(1.书号,2.书名,3.作者,4.出版社,5.出版日期,6.库存量,7.全部修改 0.退出)" <<endl;
		cout << "输入：";
	}
	return index;
}

int Interface::BookSearchface()								//搜索界面，返回结果0-5
{
	int no;
	cout << "输入要搜索的类型" << endl << "1.书号2.书名3.作者4.出版社5.出版日期 0.退出" << endl;
	cout << "类型：" ;
	cin >> no;
	return no;
}

void Interface::BookAfterSearchface()						//搜索结果显示界面
{
	int i;
	cout << endl;
	for (i = 0; i < 50;i++)cout << "-";
	cout << "搜索结果：";
	for (i = 0; i < 50; i++)cout << "-";
	cout << endl;
}



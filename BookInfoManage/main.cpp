#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
using namespace std;

const int Num_book = 100; //最大书籍总数
int No_book = 1;		  //序号从1开始
int Total_book = 0;       //当前书籍总数
Interface Face_book;      //书籍管理界面
Fileoperate Infile_book;  //读入文件
Fileoperate OutFile_book; //读出文件
Book book[Num_book];	  //书对象数组
int switchfun(int);		  //功能函数选择
void InBookFile();		  //读入书籍函数
void OutBookFile();		  //读出文件函数
void AllBookShow();		  //打印书籍信息
void BookInfoManage();	  //书籍信息管理

int main()
{
	BookInfoManage();
	return 1;
}

int switchfun(int op_num)
{
	int i;
	string id;
	string name;
	string author;
	string publisher;
	string pubdate;
	int amount;

	if (op_num == 1)							//添加
	{
		int num = Face_book.BookAddface();
		if(num==0){	cout << "已退出.";getchar(); getchar();return 0;}
		for (i = 0; i < num; i++)
		{
			cout << "输入第"<<(i+1)<<"本书籍的信息：" << endl;
			cout << "输入书籍编号：";
			cin >> id;
			cout << "输入书籍名称：";
			cin >> name;
			cout << "输入书籍作者：";
			cin >> author;
			cout << "输入出版社：";
			cin >> publisher;
			cout << "输入出版日期：";
			cin >> pubdate;
			cout << "输入库存：";
			cin >> amount;
			cout << endl;
			Total_book++;
			book[Total_book - 1].SetIndex(Total_book);
			book[Total_book - 1].SetInfo(id, name, author, publisher, pubdate, amount);
		}
		if (i == num)cout << "添加完成！" << endl;
			
	}
	else if (op_num == 2)							//删除
	{
		int no;
		no = Face_book.BookDelface();
		if (no == 0) { cout << "已退出."; getchar(); getchar(); return 0; }
		for (i = no; i < Total_book; i++) { book[i].SetIndex(i); book[i - 1] = book[i]; }	//后面的元素覆盖前面的元素 
		cout << endl<<"删除书籍信息成功！"<<endl;
		cout << "任意键继续...";
		getchar(); getchar();
		Total_book--;
	}
	else if (op_num == 3)							//修改
	{
		int no;					//要修改的书籍序号,为0时退出
		int item;				//要修改的项目
		int flag=0;
		no = Face_book.BookSetface();
		if (0 == no) { cout << "已退出."; getchar(); getchar(); return 0; }
		cin >> item;
		switch (item)
		{
		case 0:
			cout << "已退出"; getchar(); getchar(); return 0;
			break;
		case 1:
			cout << "输入书籍编号：";
			book[no - 1].SetBookId();
			break;
		case 2:
			cout << "输入书籍名称：";
			book[no - 1].SetBookName();
			break;
		case 3:
			cout << "输入书籍作者：";
			book[no - 1].SetBookAuthor();
			break;
		case 4:
			cout << "输入出版社：";
			book[no - 1].SetBookPub();
			break;
		case 5:
			cout << "输入出版日期：";
			book[no - 1].SetBookPubDate();
			break;
		case 6:
			cout << "输入库存：";
			book[no - 1].SetBookAmount();
			break;
		case 7:
			cout << "输入书籍编号：";
			cin >> id;
			cout << "输入书籍名称：";
			cin >> name;
			cout << "输入书籍作者：";
			cin >> author;
			cout << "输入出版社：";
			cin >> publisher;
			cout << "输入出版日期：";
			cin >> pubdate;
			cout << "输入库存：";
			cin >> amount;
			cout << endl;
			book[no - 1].SetInfo(id, name, author, publisher, pubdate, amount);
			break;
		}

		cout << endl << endl << "已完成修改，结果为：" << endl;
		for (i = 0; i < 110; i++) cout << "-";
		cout << endl;
		book[no - 1].Show();
		for (i = 0; i < 110; i++) cout << "-";
		cout << endl;
		getchar(); getchar();

	}
	else if (op_num == 4)							//查询
	{
		int no;
		int Begin, End;							//开始结束为止
		int res = 0;							//符合条件人数

		string temp;

		no = Face_book.BookSearchface();
		//if (0 == no) { cout << "已退出，任意键继续..."; getchar(); getchar(); return 0; }
		int flag = 0;
		switch (no)
		{
		case 0:
		{
			cout << "已退出."; getchar(); getchar(); return 0;
		}
		case 1:																		//按书号搜索
		{
			cout << "请输入书号：";
			cin >> id;
			for (i=0;i<Total_book;i++)
			{
				temp = book[i].GetBookId();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "没有信息!!!"<<endl;
			else
			{
				cout <<endl<< "共有"<<res<<"条记录！"<<endl;
				res = 0;						//置0
				for (i = 0; i < 110;i++)	cout << "-";
			}
			getchar();
			break;
		}	
		case 2:																		//按书名搜索
			cout << "请输入书名：";
			cin >> name;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookName();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "没有信息!!!" << endl;
			else
			{
				cout << endl << "共有" << res << "条记录！" << endl;
				res = 0;						//置0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 3:																		//按作者搜索
			cout << "请输入作者：";
			cin >> author;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookAuthor();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "没有信息!!!" << endl;
			else
			{
				cout << endl << "共有" << res << "条记录！" << endl;
				res = 0;						//置0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 4:																//按出版社搜索
			cout << "请输入出版社：";
			cin >> id;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookPub();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "没有信息!!!" << endl;
			else
			{
				cout << endl << "共有" << res << "条记录！" << endl;
				res = 0;						//置0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		case 5:																//按出版日期搜索
			cout << "请输入出版日期：";
			cin >> id;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookPubDate();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.BookAfterSearchface();
					book[i].Show();
					res++;
				}
			}
			if (!flag) cout << "没有信息!!!" << endl;
			else
			{
				cout << endl << "共有" << res << "条记录！" << endl;
				res = 0;						//置0
				for (i = 0; i < 110; i++)	cout << "-";
			}
			getchar();
			break;
		}

	}
	else if (op_num == 5)							//显示
	{
		AllBookShow();
	}
	return 1;
}

void BookInfoManage()
{
	int op_num;         //操作序数
	char op_char;       //选择数
	char op_char2;      //是否保存
	Face_book.BookLoadface(); //加载界面

	int flag, nflag=0;
	do {
		flag = 0;
		if (nflag)cout << "输入不合法，重新输入：";
		op_char = Face_book.BookInputcharface();
		if (op_char != 'Y'&&op_char != 'y'&&op_char != 'N'&&op_char != 'n')
		{
			flag=1;
			nflag=1;
		}
	} while (flag);

	if (op_char == 'Y' || op_char == 'y')				//读入文件
	{
		InBookFile();
		char sub_op_char;
		nflag = 0;
		do
		{
			flag = 0;
			cout << "已经成功导入，要显示资料吗？(Y/N)";
			cin >> sub_op_char;
			if (sub_op_char != 'Y'&&sub_op_char != 'y'&&sub_op_char != 'N'&&sub_op_char != 'n')
				flag = 1;
		} while (flag);

		if (sub_op_char == 'Y' || sub_op_char == 'y') { AllBookShow();	Face_book.BookSubloadface(); }
	}
	else if(op_char == 'N' || op_char == 'n')
	{
		Face_book.BookSubloadface2();
	}

	while (1)				//程序执行过程
	{
		if (Total_book != 0) op_num = Face_book.BookOperateface();		//书籍为不0时，加载主界面
		else op_num = Face_book.BookOperateface2();						//书籍为0时需要添加，加载子界面
		if (op_num == 6) break;
		switchfun(op_num);
		cout << "任意键继续...";
		getchar();
		if (Total_book != 0) Face_book.BookSubloadface();
		else
		{
			cout << endl;
			cout << "书籍数目为0！";
			Face_book.BookSubloadface2();
		}
		
	}
	cout << "要保存数据吗？(Y/N)";
	cin >> op_char2;

	if (op_char2 == 'Y' || op_char2 == 'y') { OutBookFile();	cout << "已保存！" << endl; }	//保存到文件
	system("pause");
}

void InBookFile()
{
	int i;
	Infile_book.open_in_bookfile();
	int total = 0;
	while (Infile_book.Filecinbook())
	{
		book[total++] = Infile_book.Getbook();
	}
	Total_book=total-1;
	for (i = 0; i < Total_book; i++)
		book[i].SetIndex(1 + i);
	Infile_book.Closefile();
}

void OutBookFile()
{
	int i;
	OutFile_book.open_out_bookfile();

	for (i=0;i<Total_book;i++)
	{
		OutFile_book.Filecout(book[i]);
	}
	OutFile_book.Closefile();
}

void AllBookShow()
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "显示结果";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_book; i++)
		book[i].Show();
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "按任意键继续...";
	getchar(); getchar();
}

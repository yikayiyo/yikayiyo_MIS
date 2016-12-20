#include "BookInfoManagement.h"



void BookInfoManagement::BookInfoManage()
{

	int op_num;         //操作序数
	char op_char;       //选择数
	char op_char2;      //是否保存
	Face_book.BookLoadFace(); //加载界面

	int flag, nflag = 0;
	do {
		flag = 0;
		if (nflag)cout << "输入不合法，重新输入：";
		op_char = Face_book.ReadFromFileFace();
		if (op_char != 'Y'&&op_char != 'y'&&op_char != 'N'&&op_char != 'n')
		{
			flag = 1;
			nflag = 1;
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
			sub_op_char = Face_book.AfterReadFromFileFace();
			if (sub_op_char != 'Y'&&sub_op_char != 'y'&&sub_op_char != 'N'&&sub_op_char != 'n')
				flag = 1;
		} while (flag);

		if (sub_op_char == 'Y' || sub_op_char == 'y') { AllBookShow();	Face_book.BookSubLoadFace(); }
	}
	else if (op_char == 'N' || op_char == 'n')
	{
		Face_book.BookSubLoadFace2();
	}

	while (1)				//程序执行过程
	{
		if (Total_book != 0) op_num = Face_book.OperateFace();		//书籍为不0时，加载主界面
		else op_num = Face_book.OperateFace2();						//书籍为0时需要添加，加载子界面
		if (op_num == 6) break;
		SwitchFunction(op_num);
		cout << "任意键继续...";
		getchar();
		if (Total_book != 0) Face_book.BookSubLoadFace();
		else
		{
			cout << endl;
			cout << "书籍数目为0！";
			Face_book.BookSubLoadFace2();
		}

	}
	op_char2 = Face_book.WriteIntoFileFace();

	if (op_char2 == 'Y' || op_char2 == 'y') { OutBookFile();	cout << "已保存！" << endl; }	//保存到文件
	system("pause");
}

void BookInfoManagement::InBookFile()
{
	int i;
	Infile_book.open_in_bookfile();
	int total = 0;
	while (Infile_book.Filecinbook())
	{
		book[total++] = Infile_book.Getbook();
	}
	Total_book = total - 1;
	for (i = 0; i < Total_book; i++)
		book[i].SetIndex(1 + i);
	Infile_book.Closefile();
}

void BookInfoManagement::OutBookFile()
{
	int i;
	OutFile_book.open_out_bookfile();

	for (i = 0; i<Total_book; i++)
	{
		OutFile_book.Filecout(book[i]);
	}
	OutFile_book.Closefile();
}

void BookInfoManagement::AllBookShow()
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
	getchar();
}

int BookInfoManagement::SwitchFunction(int op_num)
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
		int num = Face_book.AddFace();
		if (num == 0) { cout << "已退出."; getchar(); getchar(); return 0; }
		for (i = 0; i < num; i++)
		{
			cout << "输入第" << (i + 1) << "本书籍的信息：" << endl;
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
		no = Face_book.DelFace();
		if (no == 0) { cout << "已退出."; getchar(); getchar(); return 0; }
		for (i = no; i < Total_book; i++) { book[i].SetIndex(i); book[i - 1] = book[i]; }	//后面的元素覆盖前面的元素 
		cout << endl << "删除书籍信息成功！" << endl;
		cout << "任意键继续...";
		getchar(); getchar();
		Total_book--;
	}
	else if (op_num == 3)							//修改
	{
		int no;					//要修改的书籍序号,为0时退出
		int item;				//要修改的项目
		int flag = 0;
		no = Face_book.BookSetFace();
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
		int Begin, End;							//开始结束位置
		int res = 0;							//符合条件人数

		string temp;

		no = Face_book.BookSearchFace();
		//if (0 == no) { cout << "已退出，任意键继续..."; getchar(); getchar(); return 0; }
		int flag = 0;
		switch (no)
		{
		case 0:
		{
			cout << "已退出，任意键继续..."; getchar(); getchar(); return 0;
		}
		case 1:																		//按书号搜索
		{
			cout << "请输入书号：";
			cin >> id;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookId();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.AfterSearchFace();
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
		case 2:																		//按书名搜索
			cout << "请输入书名：";
			cin >> name;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookName();
				Begin = temp.find(name, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.AfterSearchFace();
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
				Begin = temp.find(author, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.AfterSearchFace();
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
			cin >> publisher;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookPub();
				Begin = temp.find(publisher, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.AfterSearchFace();
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
			cin >> pubdate;
			for (i = 0; i<Total_book; i++)
			{
				temp = book[i].GetBookPubDate();
				Begin = temp.find(pubdate, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_book.AfterSearchFace();
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

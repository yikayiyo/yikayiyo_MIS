#include "Peroperate.h"
const int Num_borrow = 100; //最大借阅记录总数
Borrow borrow[Num_borrow];	  //借阅对象数组
int No_borrow = 1;		  //序号从1开始
int Total_borrow = 0;       //当前总数

const int Num_reserve = 100; //最大预约记录总数
Reserve reserve[Num_reserve];	  //预约对象数组
int No_reserve = 1;		  //序号从1开始
int Total_reserve = 0;       //当前预约总数

void Peroperate::PersonalOperate(string sid)
{
	int op_num;
	InBorrowFile();
	InReserveFile();
	while (1)
	{
		op_num = face.StuMainFace();
		if (op_num == 0)break;
		SwitchFunction(sid, op_num);
		cout << "任意键继续...";
		getchar();
	}
	OutBorrowFile(); 
	OutReserveFile();
	bm.OutBookFile();
	system("pause");
}

void Peroperate::InBorrowFile()
{
	int i;
	Infile_borrow.open_in_borrowfile();
	int total = 0;
	while (Infile_borrow.Filecinborrow())
	{
		borrow[total++] = Infile_borrow.Getborrow();
	}
	Total_borrow = total - 1;
	for (i = 0; i < Total_borrow; i++)
		borrow[i].SetIndex(1 + i);
	Infile_borrow.Closefile();
}

void Peroperate::InReserveFile()
{
	int i;
	Infile_reserve.open_in_reservefile();
	int total = 0;
	while (Infile_reserve.Filecinreserve())
	{
		reserve[total++] = Infile_reserve.Getreserve();
	}
	Total_reserve = total - 1;
	for (i = 0; i < Total_reserve; i++)
		reserve[i].SetIndex(1 + i);
	Infile_reserve.Closefile();
}

void Peroperate::OutBorrowFile()
{
	int i;
	OutFile_borrow.open_out_borrowfile();

	for (i = 0; i<Total_borrow; i++)
	{
		OutFile_borrow.Filecout(borrow[i]);
	}
	OutFile_borrow.Closefile();
}

void Peroperate::OutReserveFile()
{
	int i;
	OutFile_reserve.open_out_reservefile();

	for (i = 0; i<Total_reserve; i++)
	{
		OutFile_reserve.Filecout(reserve[i]);
	}
	OutFile_reserve.Closefile();
}

int Peroperate::SwitchFunction(string sid, int op_num)
{
	string sname =sm.GetNameById(sid);

	if (op_num == 1)											//我的信息
	{
		int op=face.PersonalInfoFace();
		if(op == 0) 
		{ cout << "已退出."; getchar(); getchar(); return 0; }
		else if(op==1)
		{
			ShowMyCurBorrow(sid);
		}
		else if (op == 2)
		{
			ShowMyBorrow(sid);
		}
		else if (op == 3)
		{
			ShowMyReserve(sid);
		}
	} 
	else if (op_num == 2)										//图书信息
	{
		bm.AllBookShow();
	}
	else if (op_num == 3)										//借书
	{

	}
	else if (op_num == 4)										//还书
	{
		if (0==ShowMyCurBorrow(sid)) ;
		else
		{
			cout << "输入要归还的书籍序号： ";
			int index;
			cin >> index;
			borrow[index - 1].SetIsReturn();
			string bid = borrow[index - 1].GetBookId();
			bm.ReturnBook(bid);
			cout << "归还成功！！";
			ShowMyCurBorrow(sid);
		}
		
	}
	else if (op_num == 5)										//预约书籍
	{
		bm.AllBookShow();
		cout << "输入要预约的书籍序号： ";
		int no;
		cin >> no;
		int index = no - 1;
		string bid = bm.GetBookIdByIndex(index);
		string bname = bm.GetBookNameByIndex(index);

		for (int i = 0; i < Total_reserve; i++)
		{
			if (reserve[i].GetBookId()==bid)
			{
				cout << "你已经预约过该书，请选择其它操作！";
			}
		}

		cout << "输入预约时间：";
		string date;
		cin >> date;
		Reserve nr;
		nr.SetInfo(bid, bname, sid, sname, date);
		reserve[Total_reserve] = nr;
		Total_reserve++;
		cout << "预约成功";
	}
	return 1;
}

void Peroperate::ShowMyBorrow(string sid)
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "历史借阅";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_borrow; i++)
	{
		if (borrow[i].GetStuId() == sid)
			borrow[i].Show();
	}
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "按任意键继续...";
	getchar(); getchar();
}

void Peroperate::ShowMyReserve(string sid)
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "我的预约";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_reserve; i++)
	{
		if (reserve[i].GetStuId() == sid)
			reserve[i].Show();
	}
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "按任意键继续...";
	getchar(); getchar();
}

int Peroperate::ShowMyCurBorrow(string sid)
{
	int total = 0;
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "当前借阅";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_borrow; i++)
	{
		if (borrow[i].GetStuId() == sid && borrow[i].GetIsReturn() == 0)
		{borrow[i].Show(); total++;}
	}
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	getchar();
	return total;
}
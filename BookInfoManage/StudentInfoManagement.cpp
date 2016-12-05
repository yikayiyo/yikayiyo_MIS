#include "StudentInfoManagement.h"

const int Num_stu = 100; //最大书籍总数
Student student[Num_stu];	  //书对象数组
int No_stu = 1;		  //序号从1开始
int Total_stu = 0;       //当前书籍总数

void StudentInfoManagement::StuInfoManage()
{
	int op_num;         //操作序数
	char op_char;       //选择数
	char op_char2;      //是否保存
	Face_student.StuLoadface(); //加载界面

	int flag, nflag = 0;
	do {
		flag = 0;
		if (nflag)cout << "输入不合法，重新输入：";
		op_char = Face_student.StuInputcharface();
		if (op_char != 'Y'&&op_char != 'y'&&op_char != 'N'&&op_char != 'n')
		{
			flag = 1;
			nflag = 1;
		}
	} while (flag);

	if (op_char == 'Y' || op_char == 'y')				//读入文件
	{
		InStuFile();
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

		if (sub_op_char == 'Y' || sub_op_char == 'y') { AllStuShow();	Face_student.StuSubloadface(); }
	}
	else if (op_char == 'N' || op_char == 'n')
	{
		Face_student.StuSubloadface2();
	}

	while (1)				//程序执行过程
	{
		if (Total_stu != 0) op_num = Face_student.StuOperateface();		//书籍为不0时，加载主界面
		else op_num = Face_student.StuOperateface2();						//书籍为0时需要添加，加载子界面
		if (op_num == 6) break;
		SwitchFunction(op_num);
		cout << "任意键继续...";
		getchar();
		if (Total_stu != 0) Face_student.StuSubloadface();
		else
		{
			cout << endl;
			cout << "书籍数目为0！";
			Face_student.StuSubloadface2();
		}

	}
	cout << "要保存数据吗？(Y/N)";
	cin >> op_char2;

	if (op_char2 == 'Y' || op_char2 == 'y') { OutStuFile();	cout << "已保存！" << endl; }	//保存到文件
	system("pause");
}

void StudentInfoManagement::InStuFile()
{
	int i;
	Infile_student.open_in_bookfile();
	int total = 0;
	while (Infile_student.Filecinstudent())
	{
		student[total++] = Infile_student.Getstudent();
	}
	Total_stu = total - 1;
	for (i = 0; i < Total_stu; i++)
		student[i].SetIndex(1 + i);
	Infile_student.Closefile();
}

void StudentInfoManagement::OutStuFile()
{
	int i;
	OutFile_student.open_out_studentfile();

	for (i = 0; i<Total_stu; i++)
	{
		OutFile_student.Filecout(student[i]);
	}
	OutFile_student.Closefile();
}

void StudentInfoManagement::AllStuShow()
{
	int i;
	cout << endl;
	for (i = 0; i < 50; i++)	cout << "-";
	cout << "显示结果";
	for (i = 0; i < 50; i++)	cout << "-";
	cout << endl;
	for (i = 0; i < Total_stu; i++)
		student[i].Show();
	for (i = 0; i < 110; i++)cout << "-";
	cout << endl;
	cout << "按任意键继续...";
	getchar(); getchar();
}

int StudentInfoManagement::SwitchFunction(int)
{

	return 0;
}


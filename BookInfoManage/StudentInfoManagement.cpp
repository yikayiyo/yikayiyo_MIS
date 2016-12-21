#include "StudentInfoManagement.h"


void StudentInfoManagement::StuInfoManage()
{
	int op_num;         //操作序数
	char op_char;       //选择数
	char op_char2;      //是否保存
	Face_student.StuLoadFace(); //加载界面

	int flag, nflag = 0;
	do {
		flag = 0;
		if (nflag)cout << "输入不合法，重新输入：";
		op_char = Face_student.ReadFromFileFace();
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
			sub_op_char = Face_student.AfterReadFromFileFace();
			if (sub_op_char != 'Y'&&sub_op_char != 'y'&&sub_op_char != 'N'&&sub_op_char != 'n')
				flag = 1;
		} while (flag);

		if (sub_op_char == 'Y' || sub_op_char == 'y') { AllStuShow();	Face_student.StuSubLoadFace(); }
	}
	else if (op_char == 'N' || op_char == 'n')
	{
		Face_student.StuSubLoadFace2();
	}

	while (1)				//程序执行过程
	{
		if (Total_stu != 0) op_num = Face_student.OperateFace();			//不0时，加载主界面
		else op_num = Face_student.OperateFace2();							//为0时需要添加，加载子界面
		if (op_num == 6) break;
		SwitchFunction(op_num);
		cout << "任意键继续...";
		getchar();
		if (Total_stu != 0) Face_student.StuSubLoadFace();
		else
		{
			cout << endl;
			cout << "学生数目为0！";
			Face_student.StuSubLoadFace2();
		}

	}

	op_char2 = Face_student.WriteIntoFileFace();
	
	if (op_char2 == 'Y' || op_char2 == 'y') { OutStuFile();	cout << "已保存！" << endl; }	//保存到文件
	system("pause");
}

void StudentInfoManagement::InStuFile()
{
	int i;
	Infile_student.open_in_studentfile();
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

int StudentInfoManagement::SwitchFunction(int op_num)
{
	int i;
	string id;
	string name;
	string age;
	string cls;
	string major;
	string phone;

	if (op_num == 1)							//添加
	{
		int num = Face_student.AddFace();
		if (num == 0) { cout << "已退出."; getchar(); getchar(); return 0; }
		for (i = 0; i < num; i++)
		{
			cout << "输入第" << (i + 1) << "个学生的信息：" << endl;
			cout << "输入学生编号：";
			cin >> id;
			cout << "输入学生姓名：";
			cin >> name;
			cout << "输入学生年龄：";
			cin >> age;
			cout << "输入学生班级：";
			cin >> cls;
			cout << "输入学生专业：";
			cin >> major;
			cout << "输入学生联系方式：";
			cin >> phone;
			cout << endl;
			Total_stu++;
			student[Total_stu - 1].SetIndex(Total_stu);
			student[Total_stu - 1].SetInfo(id, name, age, cls, major, phone,0);
		}
		if (i == num)cout << "添加完成！" << endl;

	}
	else if(op_num==2)
	{
		int no;
		no = Face_student.DelFace();
		if (no == 0) { cout << "已退出."; getchar(); getchar(); return 0; }
		for (i = no; i < Total_stu; i++) { student[i].SetIndex(i); student[i - 1] = student[i]; }	//后面的元素覆盖前面的元素 
		cout << endl << "删除学生信息成功！" << endl;
		cout << "任意键继续...";
		getchar(); getchar();
		Total_stu--;
	}
	else if (op_num == 3)							//修改
	{
		int no;					//要修改的学生序号,为0时退出
		int item;				//要修改的项目
		int flag = 0;
		no = Face_student.StuSetFace();
		if (0 == no) { cout << "已退出."; getchar(); getchar(); return 0; }
		cin >> item;
		switch (item)
		{
		case 0:
			cout << "已退出"; getchar(); getchar(); return 0;
			break;
		case 1:
			cout << "输入学生编号：";
			student[no - 1].SetStuId();
			break;
		case 2:
			cout << "输入学生姓名：";
			student[no - 1].SetStuName();
			break;
		case 3:
			cout << "输入学生年龄：";
			student[no - 1].SetStuAge();
			break;
		case 4:
			cout << "输入学生班级：";
			student[no - 1].SetStuClass();
			break;
		case 5:
			cout << "输入学生专业：";
			student[no - 1].SetStuMajor();
			break;
		case 6:
			cout << "输入联系方式：";
			student[no - 1].SetStuPhone();
			break;
		case 7:
			cout << "输入学生编号：";
			cin >> id;
			cout << "输入学生姓名：";
			cin >> name;
			cout << "输入学生年龄：";
			cin >> age;
			cout << "输入学生班级：";
			cin >> cls;
			cout << "输入学生专业：";
			cin >> major;
			cout << "输入联系方式：";
			cin >> phone;
			cout << endl;
			student[no - 1].SetInfo(id, name, age, cls, major, phone,0);
			break;
		}

		cout << endl << endl << "已完成修改，结果为：" << endl;
		for (i = 0; i < 110; i++) cout << "-";
		cout << endl;
		student[no - 1].Show();
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

		no = Face_student.StuSearchFace();
		//if (0 == no) { cout << "已退出，任意键继续..."; getchar(); getchar(); return 0; }
		int flag = 0;
		switch (no)
		{
		case 0:
		{
			cout << "已退出，任意键继续..."; getchar(); getchar(); return 0;
		}
		case 1:																		//按学号搜索
		{
			cout << "请输入学号：";
			cin >> id;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuId();
				Begin = temp.find(id, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
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
		case 2:																		//按姓名搜索
			cout << "请输入姓名：";
			cin >> name;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuName();
				Begin = temp.find(name, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
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
		case 3:																		//按年龄搜索
			cout << "请输入年龄：";
			cin >> age;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuAge();
				Begin = temp.find(age, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
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
		case 4:																//按班级搜索
			cout << "请输入班级：";
			cin >> cls;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuClass();
				Begin = temp.find(cls, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
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
		case 5:																//按专业搜索
			cout << "请输入专业：";
			cin >> major;
			for (i = 0; i<Total_stu; i++)
			{
				temp = student[i].GetStuMajor();
				Begin = temp.find(major, 0);
				if (Begin != string::npos)
				{
					End = Begin + temp.length();
					flag++;
					if (flag == 1)Face_student.AfterSearchFace();
					student[i].Show();
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
		AllStuShow();
	}

	return 1;
}

string StudentInfoManagement::GetNameById(string sid)
{
	string name;
	int i = 0;
	for (;i<Total_stu;i++)
	{
		if (student[i].GetStuId() == sid)
			name = student[i].GetStuName();
	}
	return name;
}

int StudentInfoManagement::GetNumById(string sid)
{
	int res;
	int i = 0;
	for (; i<Total_stu; i++)
	{
		if (student[i].GetStuId() == sid)
			res = student[i].GetStuBrwAmt();
	}
	return res;
}

void StudentInfoManagement::AfterReturn(string sid)
{
	int i = 0;
	for (; i<Total_stu; i++)
	{
		if (student[i].GetStuId() == sid)
			student[i].UpdateBrwAmt();
	}
}


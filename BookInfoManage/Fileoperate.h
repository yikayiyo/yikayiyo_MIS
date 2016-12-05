#pragma once
#include<fstream>
#include<string>
#include "Book.h"
#include "Student.h"

const char book_filename[] = "Bookdata.txt";
const char student_filename[] = "Studentdata.txt";

class Fileoperate
{
public:
	int Filecinbook();							//写入文件
	int Filecinstudent();
	int Filecout(Book);							//读出文件
	int Filecout(Student);
	void Closefile();							//关闭文件流
	void open_in_bookfile();					//写入打开文件判断
	void open_in_studentfile();
	void open_out_bookfile();					//读出打开文件判断
	void open_out_studentfile();
	Book Getbook() { return book; }				//获取书对象
	Student Getstudent() { return student; }
private:
	fstream file;								//文件流
	Book book;
	Student student;
	int Judge();								//文件是否成功打开
};
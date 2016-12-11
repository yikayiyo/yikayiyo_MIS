#pragma once
#include<fstream>
#include<string>
#include "Book.h"
#include "Student.h"
#include"Borrow.h"
#include"Reserve.h"

const char book_filename[] = "Bookdata.txt";
const char student_filename[] = "Studentdata.txt";
const char login_filename[] = "Login.txt";
const char borrow_filename[] = "Borrowdata.txt";
const char reserve_filename[] = "Reservedata.txt";

class Fileoperate
{
public:
	int Filecinbook();							//读取文件
	int Filecinstudent();
	int Filecinborrow();
	int Filecinreserve();
	int Filecout(Book);							//写入文件
	int Filecout(Student);
	int Filecout(Borrow);
	int Filecout(Reserve);

	void Closefile();							//关闭文件流

	void open_in_bookfile();					//读取打开文件判断
	void open_in_studentfile();
	void open_in_borrowfile();
	void open_in_reservefile();

	void open_out_bookfile();					//写入打开文件判断
	void open_out_studentfile();
	void open_out_borrowfile();
	void open_out_reservefile();

	Book Getbook() { return book; }				//获取书对象
	Student Getstudent() { return student; }	//获取学生对象
	Borrow Getborrow() { return borrow; }
	Reserve Getreserve(){ return reserve; }
	int GetIdentity(string,string);				//获取用户标识0.登陆失败1.学生2.管理员
private:
	fstream file;								//文件流
	int Judge();								//文件是否成功打开
	
	Book book;
	Student student;
	Borrow borrow;
	Reserve reserve;
};
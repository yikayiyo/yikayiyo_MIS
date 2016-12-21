#include "Fileoperate.h"

int Fileoperate::Filecinbook()
{
	string id, name, author, publisher, pubdate;
	int num;
	if (file.eof()) { return 0; }
	file >> id >> name >> author >> publisher >> pubdate >> num;
	book.SetInfo(id, name, author, publisher, pubdate, num);
	return 1;
}

int Fileoperate::Filecinstudent()
{
	string id, name, age, cls, major, phone;
	int num;
	if (file.eof()) { return 0; }
	file >> id >> name >> age >> cls >> major >> phone>>num;
	student.SetInfo(id, name, age, cls, major, phone,num);
	return 1;
	
}

int Fileoperate::Filecinborrow()
{
	string bid, bname, sid, sname, bdate;
	int isret;
	if (file.eof()) { return 0; }
	file >> bid >> bname >> sid >> sname >> bdate >> isret;
	borrow.SetInfo(bid, bname, sid, sname, bdate, isret);
	return 1;
}

int Fileoperate::Filecinreserve()
{
	string bid, bname, sid, sname, rdate;
	if (file.eof()) { return 0; }
	file >> bid >> bname >> sid >> sname >> rdate;
	reserve.SetInfo(bid, bname, sid, sname, rdate);
	return 1;
}



int Fileoperate::Filecout(Book b)
{
	file << b.GetBookId() << "\t"
		<< b.GetBookName() << "\t"
		<< b.GetBookAuthor() << "\t"
		<< b.GetBookPub() << "\t"
		<< b.GetBookPubDate() << "\t"
		<< b.GetBookAmount() << endl;
	return 1;
}

int Fileoperate::Filecout(Student s)
{
	file << s.GetStuId() << "\t"
		<< s.GetStuName() << "\t"
		<< s.GetStuAge() << "\t"
		<< s.GetStuClass() << "\t"
		<< s.GetStuMajor() << "\t"
		<< s.GetStuPhone() <<"\t"
		<<s.GetStuBrwAmt()<<endl;
	return 1;
}

int Fileoperate::Filecout(Borrow bo)
{
	file << bo.GetBookId() << "\t"
		<< bo.GetBookName() << "\t"
		<< bo.GetStuId() << "\t"
		<< bo.GetStuName() << "\t"
		<< bo.GetBorrowDate() << "\t"
		<< bo.GetIsReturn() << endl;
	return 1;
}

int Fileoperate::Filecout(Reserve res)
{
	file << res.GetBookId() << "\t"
		<< res.GetBookName() << "\t"
		<< res.GetStuId() << "\t"
		<< res.GetStuName() <<"\t"
		<<res.GetReserveDate()<<endl;
	return 1;
}

void Fileoperate::Closefile()
{
	file.close();
}

void Fileoperate::open_in_bookfile()
{
	file.open(book_filename, ios::in);
	if (!Judge())	exit(1);
}

void Fileoperate::open_in_studentfile()
{
	file.open(student_filename, ios::in);
	if (!Judge())	exit(1);
}

void Fileoperate::open_in_borrowfile()
{
	file.open(borrow_filename, ios::in);
	if (!Judge())	exit(1);
}

void Fileoperate::open_in_reservefile()
{
	file.open(reserve_filename, ios::in);
	if (!Judge())	exit(1);
}

void Fileoperate::open_out_bookfile()
{
	file.open(book_filename, ios::out);
	if (!Judge())
		exit(1);
}

void Fileoperate::open_out_studentfile()
{
	file.open(student_filename, ios::out);
	if (!Judge())
		exit(1);
}

void Fileoperate::open_out_borrowfile()
{
	file.open(borrow_filename, ios::out);
	if (!Judge())
		exit(1);
}

void Fileoperate::open_out_reservefile()
{
	file.open(reserve_filename, ios::out);
	if (!Judge())
		exit(1);
}

int Fileoperate::GetIdentity(string acc, string pass)
{
	int res;
	file.open(login_filename, ios::in);
	while (!file.eof())
	{
		string account, password;
		int flag;
		file >> account >> password >> flag;
		if (acc == account&&pass == password)
		{
			res = flag;
		}
	}
	file.close();
	return res;
}

int Fileoperate::Judge()
{
	if (file.fail())
	{
		return 0;
	}
	return 1;
}

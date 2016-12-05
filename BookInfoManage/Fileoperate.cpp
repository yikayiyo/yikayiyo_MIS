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
	if (file.eof()) { return 0; }
	file >> id >> name >> age >> cls >> major >> phone;
	student.SetInfo(id, name, age, cls, major, phone);
	return 1;
	
}

int Fileoperate::Filecout(Book b)
{
	file << b.GetBookId() << endl
		<< b.GetBookName() << endl
		<< b.GetBookAuthor() << endl
		<< b.GetBookPub() << endl
		<< b.GetBookPubDate() << endl
		<< b.GetBookAmount() << endl << endl;
	return 1;
}

int Fileoperate::Filecout(Student s)
{
	file << s.GetStuId() << endl
		<< s.GetStuName() << endl
		<< s.GetStuAge() << endl
		<< s.GetStuClass() << endl
		<< s.GetStuMajor() << endl
		<< s.GetStuPhone() << endl << endl;
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

int Fileoperate::Judge()
{
	if (file.fail())
	{
		return 0;
	}
	return 1;
}

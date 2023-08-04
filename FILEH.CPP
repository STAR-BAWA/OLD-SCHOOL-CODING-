#include<iostream.h>
#include<conio.h>
#include<fstream.h>

//defining a class to store data of the students.
class student
{
   // int roll;
    char name[30];
    float marks;
    public: int roll;
	    student() {}
	    void getData();   //get student data from the users.
	    void putData();   //display data.
};

void student::getData()
{
    cout<<"Enter name:";
   // cin.getline(name, 30);
    cin>>name;
    cout<<"Enter roll no.:";
    cin>>roll;
    cin.ignore();   //ingnore new line character inserted when we press enter.
    cout<<"Enter marks:";
    cin>>marks;
}
void student::putData()
{
    cout<<"Name:"<<name<<endl;
    cout<<"Roll no.:"<<roll<<endl;
    cout<<"Marks:"<<marks<<endl;
}

int main()
{
    clrscr();
    student s[3];   //array of 3 students object.
    fstream file;
    int i;
    file.open("vikas.txt", ios::out);   //open file for writing.
    cout<<"Writing student information to the file:"<<endl;
    cout<<"Enter 3 students details to the file:"<<endl;
    for ( i = 0; i < 3; i++)
    {
	s[i].getData();
	file.write((char*)&s[i],sizeof(s[i]));  //write the object to a file.
    }
    file.close();  //close the file.
    file.open("vikas.txt", ios::in);   //open file for reading.
    cout<<"Reading student information to the file:"<<endl;
    for ( i = 0; i < 3; i++)
    {
	file.read((char*)&s[i],sizeof(s[i]));  //read the object to a file.
	s[i].putData();
    }
    file.close();  //close the file.
    file.open("vikas.txt", ios::in);   //open file for reading.
    int r;
    cout<<"Enter the roll no. to find:"<<endl;
    cin>>r;
    for ( i = 0; i < 3; i++)
    {
	file.read((char*)&s[i],sizeof(s[i]));  //read the object to a file.
	if(s[i].roll==r)
	{
	    s[i].putData();
	    break;
	}
    }
    file.close();  //close the file.
    getch();
    return 0;
}





















































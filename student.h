#include <iostream>
#include<cstring>

class student
{
    char admno[10];//admission no.
    char name[20];
    char stbno[6];// student book no
    int token;//total book of student
public:
    void createstudent()
    {

        cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The Admission No. ";
        cin>>admno;
        if(strlen(admno) < 8 || strlen(admno) > 10)
            throw '9';
        cout<<"Enter The Student Name "<<endl;
        cin.ignore();
        std::cin.getline(name, 10);
        token=0;
        stbno[0]='\0';
        cout<<"\n\nStudent Record Created...";
    }
    void showstudent()
    {
        cout<<"\nAdmission Number : "<<admno;
        cout<<"\nStudent Name : ";
        puts(name);
        cout<<"\nNo of Book Issued : "<<token;
        if(token==1)
        {
            cout<<"\nBook Number "<<stbno;
        }
    }
    void modifystudent()
    {
        cout<<"\nAdmission No. "<<admno;
        cout<<"\nModify Student Name : ";
        gets(name);
    }
    char* retadmno()
    {
        return admno;
    }
    char* retstbno()
    {
        return stbno;
    }
    int rettoken()
    {
        return token;
    }
    void addtoken()
    {
        token=1;
    }
    void resettoken()
    {
        token=0;
    }
    void getstbno(char t[])
    {
        strcpy(stbno,t);
    }
    void report()
    {
        cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl ;
    }
};//class ends here

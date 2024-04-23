#include <iostream>
#include<string>

using namespace std ;

class student
{
    char admno[10];//admission no.
    char name[20];
    char stbno[6];// student book no
    int token;//total book of student
public:
    void createstudent()
    {

        cout<<"\n\n\tNEW STUDENT ENTRY...\n";
        cout<<"\n\tEnter your 10 digit Admission No. :";
        cin>>admno;
        if(strlen(admno) < 10 || strlen(admno) > 10)
            throw '9';
        cout<<"\tEnter The Student Name :";
        cin.ignore();
        gets(name);
        token=0;
        stbno[0]='\0';
        cout<<"\n\n\tStudent Record Created...";
    }
    void showstudent()
    {
        cout<<"\n\tAdmission Number : "<<admno;
        cout<<"\n\tStudent Name : ";
        puts(name);
        cout<<"\n\tNo of Book Issued : "<<token;
        if(token==1)
        {
            cout<<"\nBook Number "<<stbno;
        }
    }
    void modifystudent()
    {
        cout<<"\n\tAdmission No. "<<admno;
        cout<<"\n\tModify Student Name : ";
        cin.ignore();
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
        cout<<"\t"<<admno<<setw(10)<<setw(10)<<token<<endl ;
    }
};//class ends here

#include <iostream>
#include<conio.h>
#include<iomanip>//input-output manipulator
#include<cstring>
#include<fstream>

#include "book.h"
#include "student.h"

using namespace std;

fstream fp,fp1;//object
book bk;
book* bookObj;
student st;//student class object

using namespace std;

void Rules()
{
    cout <<"\n\n\t                      RULES OF JIIT LRC           ";
    cout<<"\n\n\t  1) A student can borrow a Single book at a time\n"
            "\n\t  2)A valid student ID is required to issue a book\n"
            "\n\t  3) Issued book should be deposited back to library within 15 days, else fine of Rs10 will be imposed on the bearer "<<endl;
            getch();
}

void writestudent()
{
    char ch;
    fp.open("student.dat",ios::out|ios::app);//write and append data
    do{

        st.createstudent();
        fp.write((char*)&st,sizeof(student));//size of class
        cout<<"\n\n\tDo you want to add more record...(y/n?) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void displayspb(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;//book not found
    fp.open("book.dat",ios::in);//read data
    while(fp.read((char *)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbno(),n)==0)//not case sensitive
        {
            bk.showbook();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)//book not found
    {
        cout<<"\n\n\tBook does not exist";

    }
    getch();
}
void displaysps(char n[])
{
    cout<<"\nSTUDENT DETAILS\n";
    int flag=0;//student not found
    fp.open("student.dat", ios::in);//read data
    while(fp.read((char *)&st,sizeof(student)))
    {
        if(strcmpi(st.retadmno(),n)==0)//not case sensitive
        {
            st.showstudent();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)//student not found
    {
        cout<<"\n\n\tStudent does not exist";

    }
    getch();
}
void modifybook()
{
    char n[6];
    int found=0;//seach book of given data

    cout<<"\n\n\tMODIFY BOOK RECORD...";
    cout<<"\n\n\tEnter the book no. ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmpi(bk.retbno(),n)==0)
        {
            bk.showbook();
            cout<<"\n\tEnter the new details book";
            bk.modifybook();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);//back from current position
            fp.write((char *)&bk,sizeof(book));
            cout<<"\n\nRecord Updated";
            found=1;
        }

    }
    fp.close();
    if(found==0)
    {
        cout<<"\n\n\tRecord Not Found";

    }
    getch();//press key to get out
}
void modifystudent()
{
    char n[15];
    int found=0;//seach book of given data

    cout<<"\n\n\tMODIFY STUDENT RECORD...";
    cout<<"\n\n\tEnter the Enrollment no.(e.g  9923103033Hardik) ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.retadmno(),n)==0)
        {
            st.showstudent();
            cout<<"\nEnter the new details of student";
            st.modifystudent();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);//back from current position
            fp.write((char *)&st,sizeof(student));
            cout<<"\n\n\tRecord Updated";
            found=1;
        }

    }
    fp.close();
    if(found==0)
    {
        cout<<"\n\nRecord Not Found";

    }
    getch();//press key to get out
}

void deletestudent()
{
    char n[6];
    int flag=0;

    cout<<"\n\n\ttDELETE STUDENT...";
    cout<<"\n\n\tEnter the Enrollment no along with name (e.g 9923103042Priyansh) : ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmpi(st.retadmno(),n)!=0)
        {
            fp2.write((char*)&st,sizeof(student));
        }
        else{
            flag=1;//student found
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat","student.dat");//data after deletion moved to temp
    if(flag==1)
    {
        cout<<"\n\n\tRecord Deleted..";
    }
    else
    {
        cout<<"\n\nRecord not Found";
    }
    getch();
}

void writebook()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);//write and append data
    do{
        cout<<"\n\n\tEnter Book Type\n"
              "\t1)TextBook\n"
              "\t2)StoryBook\n"
              "\t3)General Book"<<endl;
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:
                bookObj = new Textbook;
                break;
            case 2:
                bookObj = new StoryBook;
                break;
            case 3:
                bookObj = new book;
                break;
            default:
                throw '5';
        }
        bk.createbook();
        fp.write((char*)&bk,sizeof(book));//size of class
        cout<<"\n\nDo you want to add more record...(y/n?) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void deletebook()
{
    char n[6];//book no.
    int flag=0;

    cout<<"\n\n\n\tDELETE BOOK...";
    cout<<"\n\n\tEnter the Book no : ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;//New onject
    fp2.open("Temp.dat",ios::out);//temp having data else than that to be deleted
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbno(),n)!=0)
        {
            fp2.write((char*)&st,sizeof(book));
        }
        else{
            flag=1;//student found
        }
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");//data after deletion moved to temp
    if(flag==1)
    {
        cout<<"\n\n\tRecord Deleted... ";
    }
    else
    {
        cout<<"\n\n\tRecord not Found";
    }
    getch();
}
void displayalls()
{

    fp.open("student.dat",ios::in);//read mode
    if(!fp)
    {
        cout<<"File Could Not Be Open";
        getch();
        return;//press any key and return
    }
    cout<<"\n\n\t\tStudent List\n\n";
    cout<<"==================================================================\n";
    cout<<"Enrollment No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";
    while(fp.read((char*)&st,sizeof(student)))
    {
        st.report();
    }
    fp.close();
    getch();
}
void displayallb()
{

    fp.open("book.dat",ios::in);//read mode
    if(!fp)
    {
        cout<<"File Could Not Be Open";
        getch();
        return;//press any key and return
    }
    cout<<"\n\n\t\tBook List\n\n";
    cout<<"==================================================================\n";
    cout<<"\tBook No."<<setw(20)<<"Book Name"<<setw(25)<<"Book Author\n";
    cout<<"==================================================================\n";
    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
    fp.close();
    getch();
}
void bookissue()
{
    char sn[15],bn[15];
    int found=0,flag=0;

    cout<<"\n\n\tBOOK ISSUE...";
    cout<<"\n\n\tEnter Enrollment no. "
          "With Name (E.g. 9923103033Hardik) ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&& found==0)
    {
        if(strcmpi(st.retadmno(),sn)==0)//compare admsn no.
        {
            found=1;
            if(st.rettoken()==0)//if book not issued
            {
                cout<<"\n\n\tEnter The Book No.";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.retbno(),bn)==0)//compare book no.
                    {
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());//pass book no.
                        int pos=-1*sizeof(st);
                        fp.seekg(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\tBook Issued Successfully\n\n "
                              "Please Note The Book Issue Date On Backside Of Your Book"
                              " And Return Book Within 15 Days, Otherwise Fine Of 10 Rs Per Day"<<endl;
                    }
                }
                if(flag==0)
                {
                    cout<<"\n\n\tBook No. Does Not Exists";
                }

            }

            else
            {

                cout<<"\n\n\tYou Have Not Returned The Last Book ";

            }



        }

    }
    if(found==0)
    {
        cout<<"\n\n\tStudent Record Not Exists... ";

    }
    getch();
    fp.close();
    fp1.close();
}

void bookdeposit()
{
    char sn[15],bn[15];
    int found=0,flag=0,day,fine;

    cout<<"\n\nBOOK DEPOSIT...";
    cout<<"\n\n\tEnter Enrollment no.With Name (E.g. 9923103033Hardik)  ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&& found==0)
    {
        if(strcmpi(st.retadmno(),sn)==0)//compare admsn no.
        {
            found=1;
            if(st.rettoken()==1)//if book issued
            {
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.retbno(),st.retstbno())==0)
                    {
                        flag=1;
                        bk.showbook();
                        cout<<"\n\n\t Book Deposited In No. Of Days : ";
                        cin>>day;
                        if(day>15)
                        {
                            fine=(day-15)*10;
                            cout<<"\n\tDue to late delivery of book fine will be imposed!!";
                            cout<<"\n\n\t The imposed fine is  = "<<fine<<"Rs";
                        }
                        st.resettoken();

                        int pos=-1*sizeof(st);
                        fp.seekg(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\tBook Deposited Successfully";


                    }
                }
                if(flag==0)
                {
                    cout<<"Book No. Does Not Exists";
                }

            }

            else
            {

                cout<<"No Book Issued";

            }



        }

    }
    if(found==0)
    {
        cout<<"Student Record Not Exists...";

    }
    getch();
    fp.close();
    fp1.close();
}


void start()
{
    cout<<"\t\t==================================================================\n";
    cout<<"\n\n\n\t\t\t\tLIBRARY MANAGEMENT SYSTEM\n\n"<<endl;
    cout<<"\t\t==================================================================\n";
    getch();
}
void adminmenu()
{

    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\n\t2.DISPLAY ALL STUDENT RECORD";
    cout<<"\n\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD";
    cout<<"\n\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\n\t6.CREATE BOOK";
    cout<<"\n\n\n\t7.DISPLAY ALL BOOKS";
    cout<<"\n\n\n\t8.DISPLAY SPECIFIC BOOK";
    cout<<"\n\n\n\t9.MODIFY BOOK RECORD";
    cout<<"\n\n\n\t10.DELETE BOOK RECORD";
    cout<<"\n\n\n\t11.BACK TO MAIN MENU";
    cout<<"\n\n\n\tPLEASE ENTER YOUR CHOICE(1-11)  ";
    cin>>ch2;
    switch(ch2)
    {
        case 1: writestudent();
            break;
        case 2: displayalls();
            break;
        case 3: char num[15];

            cout<<"\n\n\t Please Enter Enrollment no.With Name (e.g. 9923103033Hardik)  " ;
            cin>>num;
            displaysps(num);
            break;
        case 4: modifystudent();
            break;
        case 5:deletestudent();
            break;
        case 6:writebook();
            break;
        case 7:displayallb();
            break;
        case 8:
        {char num[6];

            cout<<"\n\n\tPlease enter book no. ";
            cin>>num;
            displayspb(num);
            break;
        }
        case 9:modifybook();
            break;
        case 10:deletebook();
            break;
        case 11:
            return;
        default:
            cout<<"\n\n\tInvalid choice";
    }
    adminmenu();
}

int main()

{
    char ch;
    start();
    do{
        cout<<"\n\n\n\t MAIN MENU";
        cout<<"\n\n\n\t1 BOOK ISSUE";
        cout<<"\n\n\n\t2 BOOK DEPOSIT";        
        cout<<"\n\n\n\t3 View All Available Books";
        cout<<"\n\n\n\t4 ADMINISTRATOR MENU";
        cout<<"\n\n\n\t5 View Rules and regulations of library ";
        cout<<"\n\n\n\t6 EXIT";
        cout<<"\n\n\n\t PLEASE SELECT YOUR OPTION(1-6) ";
        try {
            cin>>ch;
            if(ch >= 'A' && ch <= 'Z')
                throw "Error";
            else if(ch >= 'a' && ch <= 'z')
                throw "Error";
            switch(ch)
            {
                case '1': bookissue();
                    break;
                case '2': bookdeposit();
                    break;
                case '3':
                    displayallb(); 
                    break;   
                case '4':
                    adminmenu();
                    break;
                case '5':
                    Rules();
                    break;    
                case '6':
                cout<<"\n\n\t     Thank you for using our Library management system.  ";               

                    exit(0);
                default:
                    if(ch > '0' && ch < '9')
                        throw '0';
                    else
                        throw "Error";
            }
        }
        catch (char Error_Code)
        {
            if(Error_Code == '0')
            {
                cerr<<"\n\n\n\tInvalid choice "<<endl;
            }
            if(Error_Code == '1')
            {
                cerr<<"\n\n\n\tInvalid Book number"<<endl;
            }
            if(Error_Code == '5')
            {
                cerr<<"\n\n\n\tInvalid Book Type"<<endl;
            }
            if(Error_Code == '9')
            {
                cerr<<"\n\n\n\tInvalid Enrollment no"<<endl;
            }
        }
        catch (...)
        {
            cerr<<"\n\n\n\tOops look like something is not right\n"
                  "\t\tPlease try again"<<endl;
        }
    }while(ch!='6' );
    return 0;
}

#include <iostream>
#include<cstring>


using namespace std;
class book
{
    char bno[6];//bookno.
    char bname[50];//bookname
    char aname[20];//authorname
public:
    virtual void createbook()
    {
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nENTER BOOK NO.";
        cin>>bno;
        if(strlen(bno) > 6 || strlen(bno) < 2)
            throw '1';
        cout<<"\nENTER BOOK NAME"<<endl;
        cin.ignore();
        gets(bname);//enables enter with space
        cout<<"\nENTER AUTHOR NAME";
        gets(aname);
        cout<<"\n\n\nBook Created..";
    }
    virtual void showbook()
    {
        cout<<"\nBook Number: "<<bno;
        cout<<"\nBook Name: ";
        puts(bname);
        cout<<"\nBook Author Name: ";
        puts(aname);
    }
    virtual void modifybook()
    {
        cout<<"\nBook Number: "<<bno;
        cout<<"\nModify Book Name :"<<endl;
        cin.ignore();
        gets(bname);
        cout<<"\nModify Author's Name :";
        gets(aname);

    }

    char* retbno()//string return
    {
        return bno;

    }
    void report()
    {
        cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
    }
};

class Textbook : public book
{
private:
    string Academic_Level;
    int NoInStock;
    int NumberOfIssues;
public:
    void createbook() override
    {
        book::createbook();
        cout<<"\nAs it is a text following fields are also required"<<endl;
        cout<<"Enter Academic level i.e. UG , PG , PHD ..etc"<<endl;
        getline(cin,Academic_Level);
        cout<<"Enter Amount in stock"<<endl;
        cin>>NoInStock;
        cout<<"Enter No of issues"<<endl;
        cin>>NumberOfIssues;
    }
    void showbook() override
    {
        book::showbook();
        cout<<"Reccomended for "<<Academic_Level<<"Students"<<endl;
        cout<<"No of books in stock is "<<NoInStock<<endl;
        cout<<"Has "<<NumberOfIssues<<"Issues"<<endl;
    }
    void modifybook() override
    {
        book::modifybook();
        cout<<"\nModify Academic level i.e. UG , PG , PHD ..etc"<<endl;
        getline(cin,Academic_Level);
        cout<<"Modify Amount in stock"<<endl;
        cin>>NoInStock;
        cout<<"Modify No of issues"<<endl;
        cin>>NumberOfIssues;
    }
};


class StoryBook : public book
{
private:
    string Genre;
    string Type;//Novel , shortStory , Biography..etc
    bool IsIssueAllowed;
public:
    void createbook() override
    {
        book::createbook();
        cout<<"Enter Genre  i.e. Drama , Adventure , SelfHelp..etc"<<endl;
        getline(cin,Genre);
        cout<<"Enter Type  i.e. Novel , shortStory , Biography..etc"<<endl;
        getline(cin,Type);
        char choice;
        cout<<"Is Issue allowed y/n";
        cin>>choice;
        if(choice == 'y')
            IsIssueAllowed =true;
        else
            IsIssueAllowed = false;
    }
    void showbook() override
    {
        book::showbook();
        cout<<"Genre is  "<<Genre<<endl;
        cout<<"and is of type "<<Type<<endl;
        if (IsIssueAllowed)
            cout<<"Allowed to issue"<<endl;
        else
            cout<<"Not allowed to issue"<<endl;
    }
    void modifybook() override
    {
        book::modifybook();
        cout<<"Modify Genre  i.e. Drama , Adventure , SelfHelp..etc"<<endl;
        getline(cin,Genre);
        cout<<"Modify Type  i.e. Novel , shortStory , Biography..etc"<<endl;
        getline(cin,Type);
        char choice;
        cout<<"Is Issue allowed y/n";
        cin>>choice;
        if(choice == 'y')
            IsIssueAllowed =true;
        else
            IsIssueAllowed = false;
    }
};

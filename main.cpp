#include <iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>
using namespace std;
class contact
{
  public:
    long long int no;
    char mi[30]={'N','o','t',' ','A','v','a','i','l','a','b','l','e','\0'},name[10],no1[14]={'N','o','t',' ','A','v','a','i','l','a','b','l','e','\0'};
    void getDATa()
    {
    cout<<"\tFill the Following Detail's";
    cout<<"\nName of the Contact:";
    cin>>name;
    cout<<"Contact Number:";
    cin>>no;
    }
    void updtno()
    {
        cout<<"\n\tAlternate Contact No:";
        cin>>no1;
    }
    void updtmi()
    {
        cout<<"\n\tMail Id:";
        cin>>mi;
    }

    void showDATa()
    {
        cout<<"\n\t\tDetails of Required Contact";
          cout<<"\n\t\tName Of Contact:"<<name;
          cout<<"\n\t\tContact Number :"<<no;
          cout<<"\n\t\talternate Number:"<<no1;
          cout<<"\n\t\tMail Id        :"<<mi;
    }
void read(int pn)
{
   ifstream infile;
   infile.open("CONTACT.DAT", ios::binary);
   infile.seekg( pn*sizeof(contact) );
   infile.read( (char*)this, sizeof(*this) );
}
void cread(int cpn)
{
    ifstream infile;
    infile.open("CCONTACT.DAT", ios::binary);
    infile.seekg( cpn*sizeof(contact) );
    infile.read( (char*)this, sizeof(*this) );
}
void cwirte()
{
    ofstream outfile;
    outfile.open("CCONTACT.DAT", ios::app | ios::binary);
    outfile.write( (char*)this, sizeof(*this) );
}
void write()
{
    ofstream outfile;
    outfile.open("CONTACT.DAT", ios::app | ios::binary);
    outfile.write( (char*)this, sizeof(*this) );
}
int diskCount()
{
    ifstream infile;
    infile.open("CONTACT.DAT", ios::binary);
    infile.seekg(0, ios::end);
    return (int)infile.tellg() / sizeof(contact);
}
int cdiskCount()
{
    ifstream infile;
    infile.open("CCONTACT.DAT", ios::binary);
    infile.seekg(0, ios::end);
    return (int)infile.tellg() / sizeof(contact);
}
};

int main()
{
    //int flag=0,n,ea,dea,dsa;
    char ch,yn,optcon,optup;
     contact b;
    int opt,sno,n;
    system("CLS");
    cout<<"\n\n\n\n\t\t\t\t\t|-------------CONTACT'S----------|";
    cout<<"\n\t\t\t\t\t      1. View   Contact        ";
    cout<<"\n\t\t\t\t\t      2. add    Contact        ";
    cout<<"\n\t\t\t\t\t      3. Delete Contact        ";
    cout<<"\n\t\t\t\t\t      4. Existing Contact        ";
    cout<<"\n\t\t\t\t\t      5. Exit                    ";
    cout<<"\n\t\t\t\t\t|---------------------------------|";
    cout<<"\n\t\t\t\t\tEnter Your Choice:";
    cin>>opt;
    switch(opt)
    {
    case 1:
        system("CLS");
        n=b.diskCount();
        cout<<"\n\n\t\t---------------------------";
        cout<<"\n\t\t| S.No |  Contact Name     |";
        cout<<"\n\t\t----------------------------";
        for(int j=0;j<n;j++)
        {
           b.read(j);
           cout<<"\n\t\t   "<<j+1<<".   |     "<<b.name;
        }
         cout<<"\n\t\t----------------------------";
         cout<<"\n\n\t Enter the S.no that u want to View:";
         cin>>sno;
         if(sno<=n&&sno>0){
         b.read(sno-1);
         b.showDATa();}
         else
         {
             cout<<"There is No Contact on this S.no\n";
             cout<<"Do you Want to Add Contact(y/n):";
             cin>>yn;
             if(yn=='y')
             {
                 goto add;
             }
         }
         getch();
         main();
    case 2:
          system("CLS");
          add:
          do
          {
              b.getDATa();
              b.write();
              cout<<"\nDo u Want to add another Contact(y/n):";
              cin>>ch;
          }while(ch=='y');
          main();
    case 3:
       system("CLS");
       n=b.diskCount();
        cout<<"\n\n\t\t---------------------------";
        cout<<"\n\t\t| S.No |  Contact Name     |";
        cout<<"\n\t\t----------------------------";
        for(int j=0;j<n;j++)
        {
           b.read(j);
           cout<<"\n\t\t   "<<j+1<<".   |     "<<b.name;
        }
        int ps;
         cout<<"\n\t\t----------------------------";
         cout<<"\n\tEnter the S.no of Contact that u want to Delete:";
          cin>>ps;
        for(int j=0;j<n;j++)
        {
            if(j!=ps-1)
                {
                b.read(j);
                b.cwirte();
                }
                else
                {
                    b.read(ps-1);
                    cout<<b.name<<endl;
                    cout<<"\t\tDeleting File......";
                }
        }
        remove("CONTACT.DAT");
        n=b.cdiskCount();
       // cout<<"\nTotal :"<<n;
        for(int j=0;j<n;j++)
        {
            b.cread(j);
            b.write();
        }
        remove("CCONTACT.DAT");
        main();
    case 4:
        system("CLS");
        n=b.diskCount();
        cout<<"\n\n\t\t---------------------------";
        cout<<"\n\t\t| S.No |  Contact Name     |";
        cout<<"\n\t\t----------------------------";
        for(int j=0;j<n;j++)
        {
           b.read(j);
           cout<<"\n\t\t   "<<j+1<<".   |     "<<b.name;
        }
         cout<<"\n\t\t----------------------------";
         cout<<"\n\n\t Enter the S.no that u want to View:";
         cin>>sno;
         if(sno<=n&&sno>0)
        {
         b.read(sno-1);
         b.showDATa();
         cout<<"\nDo You Want to add Number and Mail id(y/n):";
         cin>>optup;
             if(optup=='y')
             {
             b.updtno();
             b.updtmi();
             b.write();
             n=b.diskCount();
              for(int j=0;j<n;j++)
              {
            if(j!=sno-1)
                {
                b.read(j);
                b.cwirte();
                }
                else
                {
                    b.read(sno-1);
                    cout<<b.name<<endl;
                    cout<<"\t\tDeleting File......";
                }
               }
        remove("CONTACT.DAT");
        n=b.cdiskCount();
       // cout<<"\nTotal :"<<n;
        for(int j=0;j<n;j++)
        {
            b.cread(j);
            b.write();
        }
        remove("CCONTACT.DAT");
         }
        }
         else
         {
             cout<<"There is No Contact on this S.no\n";
             cout<<"Do you Want to Add Contact(y/n):";
             cin>>yn;
             if(yn=='y')
             {
                 goto add;
             }
         }
         main();
    case 5:
        system("CLS");
        exit(0);
    default:
        cout<<"Invalid Oation";
        main();
    }
    return 0;
}

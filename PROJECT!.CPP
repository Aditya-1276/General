#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>

class mem                              //MEMBER CLASS
{int idno;
 char memname[50];
 int book1,book2,book3,nofbooks;
 public:
 class date
 {int dd,mm,yy;
  public:
  void indate();
  void outdate();
  void intdate()
  {dd=0;mm=0;yy=0;}
  date()
  {dd=0;mm=0;yy=0;}
  }D;
  void memin();
  void memout();
  int get_id();
  int retb1();
  int retb2();
  int retb3();
  mem()
  {book1=0;book2=0;book3=0;nofbooks=0;}
 //active
 void dispallm();
 void mem_search();
 void mem_append();
 void mem_Delete();
 void mem_modify();
 void Issue();
 void Return();
}M;

class book                             //BOOK CLASS
{int bkprice,bkno,bkstock;
 char bkname[100];
 public:
 void bkenter();
 void bkexit();
 void issue_update(int a);
 void return_update(int b);
 int bk_retno()
 {return bkno;}
 //active
 void dispallb();
 void bk_search();
 void bk_append();
 void bk_Delete();
 void bk_modify();
}B;

class stat                             //STATUS CLASS
{int a,b;
 public:
 void stat_out();
 void stat_read();
 void disp_stat();
}S;

int globul=0;                          //GLOBAL VARIABLE USED IN STATUS DISPLAY

void sthup()                           //FUNCTION TO RECOLOR THE OUTPUT
{clrscr();}

void Member()                          //DISPLAYS THE MEMBER MENU
{clrscr();

 int opt1;
 char ch1='y';

 do
 {
  cout<<"\t\t\t\t--MENU--\t\t"<<endl;
  cout<<"1.Display the details of all the members"<<endl;
  cout<<"2.Search for a members information"<<endl;
  cout<<"3.Add a member's data"<<endl;
  cout<<"4.Delete a member's data"<<endl;
  cout<<"5.Modify a member's data"<<endl;
  cout<<"6.Go back to the main menu"<<endl;
  cout<<"0.Exit from the program"<<endl<<endl;
  cout<<"Enter your option:";
  cin>>opt1;

  switch(opt1)
  {case 1:M.dispallm();
	  break;
   case 2:M.mem_search();
	  break;
   case 3:M.mem_append();
	  break;
   case 4:M.mem_Delete();
	  break;
   case 5:M.mem_modify();
	  break;
   case 6:textcolor(9);
	  sthup();
	  break;
   case 0:exit(0);
	  break;}
  cout<<"Enter y to to return to the member database:";
  cin>>ch1;
  clrscr();
}while(ch1=='Y'||ch1=='y');
}

void Book()                            //DISPLAYS THE BOOK MENU
{clrscr();
 int opt2;
 char ch2='y';
 do
 {cout<<"\t\t\t\t--MENU--\t\t"<<endl;
  cout<<"1.Display the details of all the books"<<endl;
  cout<<"2.Search for a book's information"<<endl;
  cout<<"3.Add more books into the database"<<endl;
  cout<<"4.Delete a book's record"<<endl;
  cout<<"5.Modify a books information"<<endl;
  cout<<"6.Go back to the main menu"<<endl;
  cout<<"0.Exit from the program"<<endl<<endl;
  cout<<"Enter your option:";
  cin>>opt2;

  switch(opt2)
  {case 1:B.dispallb();
	  break;
   case 2:B.bk_search();
	  break;
   case 3:B.bk_append();
	  break;
   case 4:B.bk_Delete();
	  break;
   case 5:B.bk_modify();
	  break;
   case 6:textcolor(9);
	  sthup();
	  break;
   case 0:exit(0);
	  break;}
  cout<<"Enter y to go back to the book database:";
  cin>>ch2;
  clrscr();
}while(ch2=='y'||ch2=='Y');
}


typedef mem::date mdate;               //TO ENTER THE RETURN DATE

void mdate::indate()
{cout<<"Enter return date(dd,mm,yy):";
 cin>>dd>>mm>>yy;}

void mdate::outdate()                  //TO DISPLAY THE RETURN DATE
{if(dd==0)
 cout<<"No books borrowed";
 else
 cout<<"Return date:"<<dd<<"/"<<mm<<"/"<<yy<<endl<<endl;}


void mem::memin()                      //TO ENTER THE MEMBER'S INFO
{cout<<"Enter member id:";
 cin>>idno;
 cout<<"Enter member's name:";
 gets(memname);
 mem();

}

void mem::memout()                     //TO DISPLAY THE MEMBER'S INFO
{cout<<endl;
 cout<<"Member ID:"<<idno<<endl;
 cout<<"Member name:"<<memname<<endl;
 cout<<"Number of books borrowed:"<<nofbooks<<endl;

 if(nofbooks==1)
 cout<<"ID number of book borrowed:"<<book1<<endl;
 else
 if(nofbooks==2)
 cout<<"ID numbers of books borrowed:"<<book1<<","<<book2<<endl;
 else
 if(nofbooks==3)
 cout<<"ID numbers of books borrowed:"<<book1<<","<<book2<<","<<book3<<endl;

 D.outdate();
 cout<<endl;
}



void mem::dispallm()                   //TO DISPLAY THE INFO OF ALL THE MEMBERS
{clrscr();
 ifstream disp;
 disp.open("MEMBER.DAT",ios::binary);
 while(disp.read((char*)&M,sizeof(M)))
 M.memout();
 disp.close();
 cout<<endl;
}

int mem::get_id()
{return idno;}

int mem::retb1()
{return book1;}

int mem::retb2()
{return book2;}

int mem::retb3()
{return book3;}

void mem::mem_search()                 //TO SEARCH FOR A MEMBER'S INFO
{clrscr();
 int a,flag=0;
 cout<<"Enter the id no of the member to be searched:";
 cin>>a;
 fstream f1;
 f1.open("MEMBER.DAT",ios::binary|ios::in);
 while(f1.read((char*)&M,sizeof(M)))
 {if(M.get_id()==a)
  {flag=1;
   cout<<"Required datails:";
   M.memout();}}
  f1.close();
  if(flag==0)
  {cout<<"Record not found"<<endl<<endl;}
}

void mem::mem_append()                 //TO ADD A NEW MEMBER'S INFO
{clrscr();
 char ch='y';
 fstream f2;
 f2.open("MEMBER.DAT",ios::out|ios::app|ios::binary);
 while(ch=='y'||ch=='Y')
 {M.memin();
  f2.write((char*)&M,sizeof(M));
  cout<<"Enter y or n:";

  cin>>ch;}
 f2.close();
 cout<<endl;
 S.stat_read();
}

void mem::mem_Delete()                 //TO DELETE AN EXISTING MEMBER'S INFO
{clrscr();
 fstream f3,g;
 int R,flag=0;
 f3.open("MEMBER.DAT",ios::binary|ios::in);
 g.open("M.DAT",ios::binary|ios::out);
 cout<<"Enter the id to be deleted:";
 cin>>R;
 while(f3.read((char*)&M,sizeof(M)))
 {if(M.get_id()!=R)
  g.write((char*)&M,sizeof(M));
  else
  if(M.get_id()==R)
  flag=1;}
 f3.close();
 g.close();
 remove("MEMBER.DAT");
 rename("M.DAT","MEMBER.DAT");
 if(flag==0)
 cout<<"Record not found"<<endl;
 else
 if(flag==1)
 cout<<"Record deleted"<<endl;
 cout<<endl;
 S.stat_read();
}

void mem::mem_modify()                 //TO ALTER THE INFORMATION OF AN EXISTING MEMBER
{clrscr();
 int Rno,pos;
 fstream f4;
 cout<<"Enter the ID of the record to be modified:";
 cin>>Rno;
 f4.open("MEMBER.DAT",ios::binary|ios::in|ios::out);
 while(f4.read((char*)&M,sizeof(M)))
 {pos=f4.tellg();
  if(M.get_id()==Rno)
  {f4.seekp(pos-sizeof(M));
   M.memin();
   f4.write((char*)&M,sizeof(M));}}
 f4.close();
 cout<<endl;
 S.stat_read();
}

void book::bkenter()                   //TO ENTER THE DETAILS OF A BOOK
{cout<<"Enter the id no of the book:";
 cin>>bkno;
 cout<<"Enter the name of the book:";
 gets(bkname);
 cout<<"Enter the price of the book:";
 cin>>bkprice;
 cout<<"Enter the stock of the books:";
 cin>>bkstock;
 cout<<endl;
}

void book::bkexit()                    //TO DISPLAY THE DETAILS OF A BOOK
{cout<<"Book number:"<<bkno<<endl;
 cout<<"Book name:"<<bkname<<endl;
 cout<<"Book price:"<<bkprice<<endl;
 cout<<"Book stock:"<<bkstock<<endl<<endl;
}

void book::dispallb()                  //TO DISPLAY THE INFORMATION OF ALL THE BOOKS
{clrscr();
 ifstream blam;
 blam.open("BOOKS.DAT",ios::binary);
 while(blam.read((char*)&B,sizeof(B)))
 B.bkexit();
 blam.close();
 cout<<endl;
}

void book::bk_search()                 //TO SEARCH FOR A SPECIFIC BOOK'S INFO
{clrscr();
 int v=0,p;
 cout<<"Enter the id number of the book whose data is needed:";
 cin>>p;
 fstream g1;
 g1.open("BOOKS.DAT",ios::binary|ios::in);
 while(g1.read((char*)&B,sizeof(B)))
 {if(B.bk_retno()==p)
  {B.bkexit();
   v=1;}}
 if(v==0)
 {cout<<"Record not found";}
 g1.close();
 cout<<endl;
}

void book::bk_append()                 //TO ENTER THE INFO OF A NEW BOOK
{clrscr();
 char ch='y';
 fstream g2;
 g2.open("BOOKS.DAT",ios::out|ios::app|ios::binary);
 while(ch=='y'||ch=='Y')
 {B.bkenter();
  g2.write((char*)&B,sizeof(B));
  cout<<"Enter y or n";
  cin>>ch;}
 g2.close();
 cout<<endl;
}

void book::bk_Delete()                 //TO DELETE THE INFO OF AN EXISTING BOOK
{clrscr();
 fstream g3,h;
 int R,flag=0;
 g3.open("BOOKS.DAT",ios::binary|ios::in);
 h.open("B.DAT",ios::binary|ios::out);
 cout<<"Enter the id to be deleted:";
 cin>>R;
 while(g3.read((char*)&B,sizeof(B)))
 {if(B.bk_retno()!=R)
  h.write((char*)&B,sizeof(B));
  else
  if(B.bk_retno()==R)
  flag=1;}
 g3.close();
 h.close();
 remove("BOOKS.DAT");
 rename("B.DAT","BOOKS.DAT");
 if(flag==0)
 cout<<"Record not found"<<endl;
 else
 if(flag==1)
 cout<<"Record deleted"<<endl;
 cout<<endl;
}

void book::bk_modify()                 //TO ALTER THE INFO OF AN EXISTING BOOK
{clrscr();
 int bno,pos;
 fstream g3;
 cout<<"Enter the ID of the record to be modified:";
 cin>>bno;
 g3.open("BOOKS.DAT",ios::binary|ios::in|ios::out);
 while(g3.read((char*)&B,sizeof(B)))
 {pos=g3.tellg();
  if(B.bk_retno()==bno)
  {g3.seekp(pos-sizeof(B));
   B.bkenter();
   g3.write((char*)&B,sizeof(B));}}
 g3.close();
 cout<<endl;
}

void stat::stat_out()                  //TO DISPLAY THE STATUS OF A BOOK
{cout<<"Member:"<<a<<" has the book:"<<b<<endl;}

void stat::stat_read()                 //TO ENTER OR UPDATE THE STATUS OF ALL THE BOOKS BORROWED
{int pos,num,y=0;
 fstream f1,f2;
 f1.open("STATUS.DAT",ios::binary|ios::out);
 f2.open("MEMBER.DAT",ios::binary|ios::in|ios::out);
 f2.seekp(0,ios::end);
 pos=f2.tellp();
 f2.seekp(0);
 num=pos/sizeof(M);

 while(f2.read((char*)&M,sizeof(M)))
 {a=M.get_id();

  if(M.retb1()!=0)
  {b=M.retb1();
   f1.write((char*)&S,sizeof(S));
   globul=0;
  }
  if(M.retb2()!=0)
  {b=M.retb2();
   f1.write((char*)&S,sizeof(S));
  }
  if(M.retb3()!=0)
  {b=M.retb3();
   f1.write((char*)&S,sizeof(S));
  }
  if(M.retb1()==0 && M.retb2()==0 && M.retb3()==0)
  {y++;}
  if(y==num)
  {globul=1;}
 }
 f1.close();
 f2.close();
}

void stat::disp_stat()                 //TO DISPLAY THE STATUS OF ALL BORROWED BOOKS
{clrscr();
 fstream f;
 f.open("STATUS.DAT",ios::binary|ios::in);
 while(f.read((char*)&S,sizeof(S)))
 {S.stat_out();}
 f.close();
 if(globul==1)
 cout<<"No books borrowed"<<endl;
 cout<<endl;
}


void book::issue_update(int a)         //TO UPDATE THE INFO OF THE BOOK(S) BORROWED USING THE ISSUE FUNCTION
{int pos;
 fstream f;
 f.open("BOOKS.DAT",ios::binary|ios::in|ios::out);
 while(f.read((char*)&B,sizeof(B)))
 {pos=f.tellg();
  if(B.bk_retno()==a)
  {bkstock--;
   f.seekp(pos-sizeof(B));
   f.write((char*)&B,sizeof(B));
  }
 }
 f.close();
}

void book::return_update(int b)        //TO UPDATE THE INFO OF THE BOOK(S) RETURNED USING THE RETURN FUNCTION
{int pos;
 fstream f;
 f.open("BOOKS.DAT",ios::binary|ios::in|ios::out);
 while(f.read((char*)&B,sizeof(B)))
 {pos=f.tellg();
  if(B.bk_retno()==b)
  {bkstock++;
   f.seekp(pos-sizeof(B));
   f.write((char*)&B,sizeof(B));
  }
 }
 f.close();
}


void mem::Issue()                      //TO ISSUE UPTO 3 BOOKS TO A MEMBER
{clrscr();
 int pos,rno,flag=0;
 fstream f;
 cout<<"Enter the ID number of the member:";
 cin>>rno;
 cout<<endl;
 f.open("MEMBER.DAT",ios::binary|ios::in|ios::out);
 while(f.read((char*)&M,sizeof(M)))
 {pos=f.tellg();
  if(M.get_id()==rno)
  {flag=1;
   cout<<"Enter the number of books to be borrowed:";
   cin>>nofbooks;
   if(nofbooks>3)
   {cout<<"MAXIMUM NUMBER OF BOOKS=3"<<endl;
    cout<<"Enter the number of books to be borrowed:";
    cin>>nofbooks;}
   if(nofbooks==1)
   {cout<<"Enter the id number of the book borrowed:";
    cin>>book1;
    B.issue_update(book1);}
   else
   if(nofbooks==2)
   {cout<<"Enter the id numbers of the books borrowed:";
    cin>>book1>>book2;
    B.issue_update(book1);
    B.issue_update(book2);}
   else
   if(nofbooks==3)
   {cout<<"Enter the id number of the books borrowed:";
    cin>>book1>>book2>>book3;
    B.issue_update(book1);
    B.issue_update(book2);
    B.issue_update(book3);}
   D.indate();
   f.seekp(pos-sizeof(M));
   f.write((char*)&M,sizeof(M));
  }
 }
 f.close();
 if(flag==0)
 {cout<<"Record not found"<<endl;}
 S.stat_read();
}

void mem::Return()                     //TO RETURN UPTO 3 BOOKS BACK TO THE LIBRARY
{clrscr();
 int ino,pos,flag=0;
 cout<<"Enter the ID number of the member returning the book:";
 cin>>ino;
 cout<<endl;
 fstream f;
 f.open("MEMBER.DAT",ios::binary|ios::in|ios::out);
 while(f.read((char*)&M,sizeof(M)))
 {pos=f.tellg();
  if(M.get_id()==ino)
  {flag=1;
   if(nofbooks==0)
   {cout<<"No books borrowed"<<endl;}
   else
   {if(book1!=0)
    B.return_update(book1);

    if(book2!=0)
    B.return_update(book2);

    if(book3!=0)
    B.return_update(book3);

    nofbooks=0;
    book1=0;
    book2=0;
    book3=0;
    D.intdate();
    f.seekp(pos-sizeof(M));
    f.write((char*)&M,sizeof(M));
   }
  }
 }
 f.close();
 if(flag==0)
 {cout<<"Record not found!"<<endl;}
 S.stat_read();
}

void Main_Menu()                       //USED TO DISPALY THE MAIN MENU
{int option;
 char ch='y';

/*
[TO RESET THE CONTENTS OF THE MEMBER AND BOOK FILE REMOVE THE COMMENTS OF THE
 LINES OF CODE BELOW THIS COMMENT BLOCK AND RUN THE PROGRAM. YOU WILL HAVE TO
 ENTER 5 RECORDS FOR EACH FILE. TO ALTER THE NUMBER OF INNITIAL RECORDS TO BE
 INTERED INTO THE FILES,CHANGE THE VALUE OF 'n' TO THE DESIRED VALUE. PUT THEM
  BACK IN COMMENTS AGAIN.]
*/

fstream l,o;
 int n=3;
 l.open("MEMBER.DAT",ios::binary|ios::out);
 o.open("BOOKS.DAT",ios::binary|ios::out);
 cout<<"Enter "<<n<<" records of members==>";
 cout<<endl<<endl;
 for(int k=0;k<n;k++)
 {M.memin();
  l.write((char*)&M,sizeof(M));
  cout<<endl;}
 l.close();
 clrscr();
 cout<<"Enter "<<n<<" records of books==>";
 cout<<endl<<endl;
 for(k=0;k<n;k++)
 {B.bkenter();
  o.write((char*)&B,sizeof(B));}
 o.close();
 clrscr();

 do
 {
  cout<<"\t\tWELCOME TO THE PUBLIC LIBRARY\t\t\t"<<endl;
  cout<<"\t\t-------------MENU-------------\t\t"<<endl;
  cout<<"1.Members"<<endl;
  cout<<"2.Books"<<endl;
  cout<<"3.Issue book"<<endl;
  cout<<"4.Return book"<<endl;
  cout<<"5.Status"<<endl;
  cout<<"0.Exit from the program"<<endl;
  cout<<"Enter your option:";
  cin>>option;

  switch(option)
  {case 1:textcolor(3);
	  Member();
	  break;
   case 2:textcolor(11);
	  Book();
	  break;
   case 3:textcolor(9);
	  M.Issue();
	  break;
   case 4:textcolor(9);
	  M.Return();
	  break;
   case 5:textcolor(9);
	  S.disp_stat();
	  break;
   case 0:textcolor(7);
	  exit(0);
	  break;
  }
  cout<<"Enter 'y' to go back to the main menu:";
  cin>>ch;
  clrscr();
 }
 while(ch=='Y'||ch=='y');
}

void main()
{clrscr();
 textcolor(9);

 int y=0;                              //PASSWORD BLOCK
 char password[50];
 for(int z=0;z<3;z++)
 {int w=3-z;
  if(y>0)
  cout<<"Incorrect password"<<endl;
  cout<<w<<" turns left"<<endl;
  cout<<"Enter the password:";
  gets(password);
  if(strcmp(password,"password")==0)
  {y=0;
  clrscr();
  Main_Menu();
 }
  else
  y++;}
 if(y==3)
 {clrscr();
  exit(0);}
}


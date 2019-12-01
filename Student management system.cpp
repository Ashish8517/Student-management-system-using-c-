#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;

void menu();

void faculty_menu();
void faculty_new();
void faculty_signin();
void faculty_signin_menu();
void faculty_create_task();
void faculty_delete_task();

void faculty_check_submission();

void faculty_show_complete_result();
void faculty_submit_marks();

void student_menu();
void student_new();
void student_signin();
void student_signin_menu(string);
void student_view_assignment(string);
void student_submit_assignment(string);
void student_view_result(string);

class Faculty
{
	char uid[10];
	char password[20];
	
	public:
		
		void create()
		{
			cout<<"Enter uid : ";
			fflush(stdin);
			gets(uid);
			cout<<"Enter password : ";
			gets(password);
		}
		
		char* get_uid()
		{
			return uid;
		}
		
	    char* get_password()
	    {
	    	return password;
		}
};

class Student
{
	char reg[10];
	char password[20];
	
	public:
		
		void create()
		{
			cout<<"Enter Regestration no. : ";
			fflush(stdin);
			gets(reg);
			cout<<"Enter password : ";
			gets(password);
		}
		
		char* get_reg()
		{
			return reg;
		}
		
	    char* get_password()
	    {
	    	return password;
		}
};

class Faculty_task
{	
	int task_no;
	char task[150];
	char date[15];
	
	public : 
	
	void set_task(int i)
	{
		task_no = i;
		cout<<"Enter the details of the task : ";
		fflush(stdin);
		gets(task);
		cout<<"Enter the last date of submission(dd-mm-yyyy) : ";
		gets(date);
	}
	
	void view()
	{
		cout<<"\nTASK No. : "<<task_no<<"\n";
		cout<<"DETAILS : "<<task<<"\n";
		cout<<"LAST DATE OF SUBMISSION : "<<date<<"\n\n\n";
	}
	
	int get_task_no()
	{
		return task_no;
	}
	
	char* get_date()
	{
		return date;
	}
};

class Submit
{
	int task_no;
	char reg[10];
	
	public:
		
	void set_data(int i,string s){
		task_no=i;
		strcpy(reg,s.c_str());
	}
	
	void show_data()
	{
		cout<<reg<<"\t\t\t  ";
		cout<<task_no<<"\n";
	}
	int get_task_no()
	{
		return task_no;
	}
	
	char* get_reg()
	{
		return reg;
	}
};

class Result
{
	int task_no;
	int marks;
	char reg[10];
	
	public:
		
	void set_data(){
		
		cout<<"\nEnter regestration number of student : ";
		fflush(stdin);
		gets(reg);
		cout<<"Enter the task number : ";
		cin>>task_no;
		cout<<"Enter the marks out of 100 : ";
		cin>>marks;
	}
	
	void show_data()
	{
		cout<<"\n"<<task_no<<"\t\t";
		cout<<marks<<"/100"<<"\n";
	}
	
	void show_data2()
	{   cout<<reg<<"\t\t";
		cout<<task_no<<"\t\t";
		cout<<marks<<"/100"<<"\n";
	}
	int get_task_no()
	{
		return task_no;
	}
	
	char* get_reg()
	{
		return reg;
	}
	
	int get_marks()
	{
		return marks;
	}
};


void faculty_menu()
{   system("cls");

    int choice;
	cout<<"=============<< Welcome >>=============\n";
	cout<<"1.ADD new account\n";
	cout<<"2.Sign in\n";
	cout<<"3.Go back\n";
	cout<<"4.Exit";
	cout<<"\n\nEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 :
			   faculty_new();
			   break;
		case 2 : 
		       faculty_signin();
		       break;
	    case 3 : 
	            menu();
	            break;
		case 4 : 
		        exit(0);
		        break;
	    default : 
	             cout<<"\nError 00000000(Wrong choice Entered)(PRESS ENTER TO CONTINUE)\n";
	             getch();
	            faculty_menu();
    }

}

void student_menu()
{   system("cls");

    int choice;
	cout<<"=========<< Welcome >>========\n";
	cout<<"1.ADD new account\n";
	cout<<"2.Sign in\n";
    cout<<"3.Go back\n";
	cout<<"4.Exit";
	cout<<"\n\nEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 :
			   student_new();
			   break;
		case 2 : 
		       student_signin();
		       break;
	    case 3 : 
	            menu();
	            break;
		case 4 : 
		        exit(0);
		        break;
	    default : 
	             cout<<"Error 00000000(Wrong choice Entered)(PRESS ENTER TO CONTINUE)\n";
	             getch();
	            student_menu();
	}
	
}

void faculty_new(){
system("cls");
ofstream file("faculty.txt",ios::app);
Faculty f;
f.create();
file.write((char*)&f,sizeof(f));
file.close();
cout<<"\nNew account created successfully....(PRESS ENTER TO CONTINUE)\n";
getch();
faculty_menu();
}

void student_new(){
system("cls");
ofstream file("student.txt",ios::app);
Student s;
s.create();
file.write((char*)&s,sizeof(s));
file.close();
cout<<"\nNew account created successfully....(PRESS ENTER TO CONTINUE)\n";
getch();
student_menu();
}

void faculty_signin()
{
system("cls");
ifstream file("faculty.txt");
int flag=1;
string uid1,uid2,pass1,pass2;
Faculty f;
cout<<"Enter Uid : ";
cin>>uid1;
cout<<"Enter password : ";
cin>>pass1;

while(file.read((char*)&f,sizeof(f)))
{
  uid2 = f.get_uid();
  pass2 = f.get_password();
  if(uid1.compare(uid2)==0 && pass1.compare(pass2)==0)
  {
  	flag=0;
  	faculty_signin_menu();
  }  
}
file.close();
if(flag==1)
{
	cout<<"Error 00000000(NO record found)(PRESS ENTER TO CONTINUE)\n";
	getch();
	faculty_menu();
}
}

void student_signin()
{
system("cls");
ifstream file("student.txt");
int flag=1;
string reg1,reg2,pass1,pass2;
Student s;
cout<<"Enter Registration no. : ";
cin>>reg1;
cout<<"Enter password : ";
cin>>pass1;

while(file.read((char*)&s,sizeof(s)))
{
  reg2=s.get_reg();
  pass2 = s.get_password();
  if(reg1.compare(reg2)==0 && pass1.compare(pass2)==0)
  {
  	flag=0;
  	student_signin_menu(reg1);
  }  
}
file.close();
if(flag==1)
{
	cout<<"\nError000000(No record found)(PRESS ENTER TO CONTINUE)\n";
	getch();
	student_menu();
}
	
}

void faculty_signin_menu()
{
	system("cls");

    int choice;
		cout<<"=========<< Welcome Sir >>========\n";
	cout<<"1.If You want to give an Assignment press... 1\n";
	cout<<"2.If you want to Update an Assignment press... 2\n";
	cout<<"3.If you want to Delete any Assignment press... 3\n";
	cout<<"4.If you want to Check submission press... 4\n";
	
	cout<<"6.If you want to see complete result of student's press...6\n";
	cout<<"7.If you want to give  marks to student press...7\n";
	cout<<"8.Back\n";
	cout<<"9.Exit";
	cout<<"\n\nChoose your number : ";
	cin>>choice;
	switch(choice)
	{
		case 1 :
			   faculty_create_task();
			   break;
		
	    case 3 : 
	            faculty_delete_task();
	            break;
		case 4 : 
		        faculty_check_submission();
		        break;
		
		case 6 :
			    faculty_show_complete_result();
			    break;
		case 7 : 
		        faculty_submit_marks();
		        break;
	    case 8 : 
	            faculty_menu();
	            break;
		case 9 : 
		        exit(0);
		        break;
		
	    default : 
	             cout<<"Wrong choice Entered..(PRESS ENTER TO CONTINUE)\n";
	             getch();
	            faculty_signin_menu();
    }
}

void faculty_create_task(){
	system("cls");
	Faculty_task f;
	int task_no; 
	ifstream file("task_no.txt");
	if(!file)
	{
		task_no=1;
	}
	else if(file)
	{
	file>>task_no;	
	file.close();
    }
	ofstream file2("task_no.txt");
	task_no++;
	file2<<task_no;
	file2.close();
	
	
	int choice;
	cout<<"Assigned task to....\n";
	cout<<"1.Individual\n";
	cout<<"2.All\n";
	cout<<"3.Go back\n";
	cout<<"\n\nEnter your choice : ";
	cin>>choice;
	if(choice==1)
	{   system("cls");
		string reg;
		Submit s;
		ofstream file5("reg__task_record.txt",ios::app);
		cout<<"Enter regestration of the student : ";
		cin>>reg;
        s.set_data(task_no,reg);
        file5.write((char*)&s,sizeof(s));
		file5.close();
		cout<<"------------Enter task details-----------\n\n";
		f.set_task(task_no);
		ofstream file4;
		file4.open(reg.c_str(),ios::app);
		file4.write((char*)&f,sizeof(f));
		file4.close();
		cout<<"\n\n Task added successfully to "<<reg<< " (PRESS ENTER TO CONTINUE)\n";
		getch();		
	}
	else if(choice==2){
	   f.set_task(task_no);
	   ofstream file3("Tasks.txt",ios::app);
	   file3.write((char*)&f,sizeof(f));
	   file3.close();
	   	cout<<"\n\n Task added successfully to All.(PRESS ENTER TO CONTINUE)\n";
		getch();
	   
     }
     else if(choice==3)
     {
     	faculty_signin_menu();
	 }
     else{
     	cout<<"\nwrong choice Entered..(PRESS ENTER TO CONTINUE)\n";
     	getch();
     	faculty_create_task();
	 }
	 faculty_signin_menu();
}
void faculty_delete_task(){
	system("cls");
	ifstream file1("Tasks.txt");
	Faculty_task f;
	string reg;
	int task_no,flag1=1,flag2=1;
	
	
	cout<<"Enter task no. to be deleted : ";
	cin>>task_no;
	while(file1.read((char*)&f,sizeof(f)))
	{
		if(f.get_task_no()==task_no)
		{
			flag1=0;
			break;
		}
	}
	if(flag1==0)
	{
		ofstream file2("Temp.txt",ios::app);
		file1.seekg(0,ios::beg);
		while(file1.read((char*)&f,sizeof(f)))
	    {
		   if(f.get_task_no()!=task_no)
		   {
			 file2.write((char*)&f,sizeof(f));
		   }
	    }
		file2.close();
		file1.close();
		remove("Tasks.txt");
		rename("Temp.txt","Tasks.txt");
		cout<<"\n General Task deleted successfully.(PRESS ENTER TO CONTINUE)\n";
		getch();
	}
	else if(flag1==1)
	{
		Submit s;
		ifstream file3("reg__task_record.txt");
		while(file3.read((char*)&s,sizeof(s))){
			if(s.get_task_no()==task_no){
				flag2=0;
				reg=s.get_reg();
				break;
			}
		}
		file3.close();
	}
	if(flag2==0)
	{	string s2="temp";
		Faculty_task f;
		ifstream file4(reg.c_str());
		ofstream file5(s2.c_str(),ios::app);
		while(file4.read((char*)&f,sizeof(f))){
			if(f.get_task_no()!=task_no)
			{
				file5.write((char*)&f,sizeof(f));
			}
		}
		file4.close();
		file5.close();
		remove(reg.c_str());
		rename(s2.c_str(),reg.c_str());
		cout<<"Task deleted from the account of "<<reg<<" (PRESS ENTER TO CONTINUE)\n";
		getch();
	}
	if(flag1==1 && flag2==1)
	{
		cout<<"No such record found.....(PRESS ENTER TO CONTINUE)\n";
		getch();
	}
	faculty_signin_menu();
	
}
void faculty_update_task(){
	system("cls");
	ifstream file1("Tasks.txt");
	Faculty_task f,f1;
	string reg;
	int task_no,flag1=1,flag2=1;
	
	
	cout<<"Enter task no. to be deleted : ";
	cin>>task_no;
	while(file1.read((char*)&f,sizeof(f)))
	{
		if(f.get_task_no()==task_no)
		{
			flag1=0;
			break;
		}
	}
	if(flag1==0)
	{
		ofstream file2("Temp.txt",ios::app);
		file1.seekg(0,ios::beg);
		while(file1.read((char*)&f,sizeof(f)))
	    {
		   if(f.get_task_no()!=task_no)
		   {
			 file2.write((char*)&f,sizeof(f));
		   }
		   else
		   if(f.get_task_no()==task_no)
		   {
		   	f1.set_task(task_no);
		    file2.write((char*)&f1,sizeof(f1));
		   }
	    }
		file2.close();
		file1.close();
		remove("Tasks.txt");
		rename("Temp.txt","Tasks.txt");
		cout<<"\n General Task number "<<task_no <<" Updated successfully. (PRESS ENTER)\n";
		getch();
	}
	else if(flag1==1)
	{
		Submit s;
		ifstream file3("reg__task_record.txt");
		while(file3.read((char*)&s,sizeof(s))){
			if(s.get_task_no()==task_no){
				flag2=0;
				reg=s.get_reg();
				break;
			}
		}
		file3.close();
	}
	if(flag2==0)
	{	string s2="temp";
		Faculty_task f,f1;
		ifstream file4(reg.c_str());
		ofstream file5(s2.c_str(),ios::app);
		while(file4.read((char*)&f,sizeof(f))){
			if(f.get_task_no()!=task_no)
			{
				file5.write((char*)&f,sizeof(f));
			}
			else if(f.get_task_no()==task_no)
			{
			f1.set_task(task_no);
		    file5.write((char*)&f1,sizeof(f1));
			}
		}
		file4.close();
		file5.close();
		remove(reg.c_str());
		rename(s2.c_str(),reg.c_str());
		cout<<"Task number " <<task_no <<" Updated of the account "<<reg<<" Successfully. (PRESS ENTER To continue)\n";
		getch();
	}
	if(flag1==1 && flag2==1)
	{
		cout<<"No such record found.....";
	}
	faculty_signin_menu();
	
}
void faculty_check_submission(){
	system("cls");
	ifstream file("Submission.txt");
	Submit s;
	int choice,i=0,count=0;
	cout<<"====menu====\n";
	cout<<"1.View whole list submission.\n";
	cout<<"2.View Top five submission.\n";
	cout<<"3.View Last five Submission.\n";
	cout<<"4.Go back.\n";
	cout<<"\n\n Enter your choice : ";
	cin>>choice;
	if(!file)
	{
		cout<<"NO record found....";
		getch();
		faculty_signin_menu();
   }
   system("cls");
   cout<<"REGESSTRAION NO . \t"<< "TASK NO\n";
   switch(choice)
   {
   	case 1: {
   			  while(file.read((char*)&s,sizeof(s)))
		      {
			    s.show_data();
		      }
		      break;
	        }
	case 2 : {
		       while(file.read((char*)&s,sizeof(s))&&i<5)
		       {
			     s.show_data();
			     i++;
		       }
		       break;
	         }
	case 3 :{
		      while(file.read((char*)&s,sizeof(s))&&i<5){
			     count++; }
			    
		          if(count<5){
		       	      while(file.read((char*)&s,sizeof(s))){
			             s.show_data();
			             i++;
						}
				    }
		         else{
		         	i=count-5;
		         	file.seekg(i*sizeof(s),ios::beg);
		         	while(file.read((char*)&s,sizeof(s))&&i<5){
			            s.show_data();
			            i++;
		               }
				   }
		      break;
	        } 
	case 4: faculty_signin_menu();
	         break;
	default : 
	       cout<<"Wrong choice Entered .....";
		   getch();
		   faculty_check_submission();  
   
   }	
   
   
   cout<<"\n\n============================================================\n\n";
   char ch;
   cout<<"Do you want to give marks to the students(y/n) : ";
   cin>>ch;
   if(ch=='y'|| ch=='Y')
   {
   	Result r;
   	r.set_data();
   	ofstream file("result.txt",ios::app);
   	file.write((char*)&r,sizeof(r));
   	cout<<"Marks submitted sucessfully. (PRESS ENTER To continue)\n";
   	getch();
   }
   faculty_signin_menu();
   
}
void faculty_announce_topper(){
	system("cls");
	Result r,topper;
	int count=0,i=0,max;
	ifstream file("result.txt");
	cout<<"========COMPLETE RESULT OF THE CLASS =======\n";
	cout<<"REGESTRATION NO.   TASK NO. \t\t  MARKS\n";
	while(file.read((char*)&r,sizeof(r))){
		r.show_data2();
		count++;
	}
	Result r1[count];
    file.close();
    
    ifstream file1("result.txt");
    
    while(file1.read((char*)&r,sizeof(r)))
    {   
        r1[i++]=r;
	}
	file1.close();
	
	max=r1[0].get_marks();
	topper = r1[0];
	for(int j=1;j<count;j++)
	{
		if(r1[j].get_marks()>max)
		{
			max=r1[j].get_marks();
			topper=r1[j];
		}
	}
	cout<<"\n\n\n==============TOPPER=====================\n";
	cout<<"Regestration no. : "<<topper.get_reg();
	cout<<"\nmarks obtained : "<<topper.get_marks()<<"/100";
	cout<<"\nTask number : "<<topper.get_task_no();    
	cout<<"\n\nPRESS ENTER TO CONTINUE.\n";
	getch();
	faculty_signin_menu();	
}

void faculty_show_complete_result(){
	system("cls");
	Result r;
	ifstream file("result.txt");
	cout<<"========COMPLETE RESULT OF THE CLASS =======\n";
	cout<<"REGESTRATION NO.   TASK NO. \t\t  MARKS\n";
	while(file.read((char*)&r,sizeof(r))){
		r.show_data2();
	}
	file.close();
	cout<<"\n\n\n==============================================";
	cout<<"\nPRESS ENTER TO CONTINUE.\n";
	getch();
	faculty_signin_menu();	
	
}
void faculty_submit_marks(){
	system("cls");
	Result r;
   	r.set_data();
   	ofstream file("result.txt",ios::app);
   	file.write((char*)&r,sizeof(r));
   	int option;
   	cout<<"Marks submitted sucessfully. Add more press 1 otherwise any : ";
   	cin>>option;
   	if(option==1)
   	{
   		faculty_submit_marks();
	}
	else{
	    faculty_signin_menu();	
	 }
   	}


void student_signin_menu(string reg1)
{   
    string reg=reg1;
	system("cls");

    int choice;
	cout<<"=========<< Welcome >>========\n";
	cout<<"1.View Assignment\n";
	cout<<"2.Submit Assignment\n";
	cout<<"3.View Result\n";
	cout<<"4.Go back\n";
	cout<<"5.Exit";
	cout<<"\n\nEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 :
			   student_view_assignment(reg);
			   break;
		case 2 : 
		       student_submit_assignment(reg);
		       break;
	    case 3 : 
	            student_view_result(reg);
	            break;
	    case 4 : 
	            student_menu();
	            break;
		case 5 : 
		        exit(0);
		        break;
		
	    default : 
	             cout<<"Wrong choice Entered..";
	            student_signin_menu(reg);
    }
}


void student_view_assignment(string reg1){
	string reg=reg1;
	int choice;
	system("cls");
	cout<<"=====menu=====\n";
	cout<<"1.View personal project.\n";
	cout<<"2.View General project.\n";
	cout<<"3.View All projects\n";
	cout<<"4.Go back.\n";
	cout<<"\n Enter your choice : ";
	cin>>choice;
	system("cls");
	int count1,count2;
	count1=count2=0;
	Faculty_task f;
	ifstream file1(reg.c_str());
	ifstream file2("Tasks.txt");
	if(choice==1 || choice==3){
			if(file1)
	         {
		       while(file1.read((char*)&f,sizeof(f)))
		       {
			    count1++;
			    f.view();
		       }
		     cout<<"\n You have "<<count1<<" personal projects.\n\n";
	         }	
	         else{
	         	cout<<"\n You have no personal projects.\n\n";
			 }
	}
	if(choice==2 || choice==3)
	{
	        if(file2)
	         {
		       while(file2.read((char*)&f,sizeof(f)))
		       {
			     count2++;
			     f.view();
		       }
		     cout<<"\n You have "<<count2<<" General projects.\n\n";
	         }	
	         else{
	         	cout<<"\n You have no General projects.\n\n";
			 }
	}
	if(choice==4){
		student_signin_menu(reg);
	}
   int choice2;
   cout<<"=======================================================================\n\n";
   cout<<"Do you want to submit your task press 1 otherwise any : ";
   cin>>choice2;
   if(choice2==1)
   {
   	student_submit_assignment(reg);
   }
   else{
   	 student_signin_menu(reg);
   }
}

void student_submit_assignment(string reg1){
    system("cls");
	string reg=reg1;
	Submit s;
	Faculty_task f;
	int task,flag1=1,flag2=1;
	ifstream file1(reg.c_str());
	ifstream file2("Tasks.txt");
	ofstream file3("Submission.txt",ios::app);
	cout<<"Enter unique task no. to submit the project if you want to check the task number then press 0 : ";
	cin>>task;
	if(task==0){
		student_view_assignment(reg);
	}
	else
	{
		
		while(file1.read((char*)&f,sizeof(f)))
		{
			if(f.get_task_no()==task)
			{
				flag1=0;
				break;
			}
		}
		if(flag1==1)
		{
			while(file2.read((char*)&f,sizeof(f))){
				
				if(f.get_task_no()==task)
				  {
				  	flag2=0;
				  	break;
				  }
			}
		}
		if(flag1==0|| flag2==0)
		{
		  s.set_data(task,reg);
		  file3.write((char*)&s,sizeof(s));
		  cout<<"Task number "<<task<<" Submitted successfully.(PRESS ENTER to continue)\n";
		  getch();
	    }
	    else
	    {
	    	cout<<"No such task number exixt....(PRESS ENTER to continue)\n";
	    	getch();
		}
	}
	file1.close();
	file2.close();
	file3.close();
    student_signin_menu(reg);
}

void student_view_result(string reg1){
	system("cls");
	string reg=reg1;
	string reg2;
	int flag=1;
	ifstream file("result.txt");
	Result r;
	cout<<"TASK NO. \t MARKS\n";
	while(file.read((char*)&r,sizeof(r))){
        reg2=r.get_reg();
        if(reg2==reg){
        	r.show_data();
        	flag=0;
		}
	}	
	if(flag==1)
	{
		cout<<"\n\nNO Record found...";
	}
	file.close();
	cout<<"\n\nPRESS ENTER TO CONINUE..";
	getch();
	student_signin_menu(reg);
	
}

void menu()
{   system("cls");

    int choice;
	cout<<"=========<< Welcome >>========\n";
	cout<<"1.Student\n";
	cout<<"2.Faculty\n";
	cout<<"3.Exit";
	cout<<"\n\nEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 :
			   faculty_menu();
			   break;
		case 2 : 
		       student_menu();
		       break;
		case 3 : 
		        exit(0);
		        break;
	    default : 
	             cout<<"Wrong choice Entered..(PRESS ENTER TO CONTINUE)\n";
	             getch();
	            menu();
	}
}

int main()
{
	menu();
	return 0;
}

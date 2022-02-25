/**********************************************************************************************************************************************
//HEADER FILES USED
**********************************************************************************************************************************************/
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define MAX 50
using namespace std;
int flag=0,num=0;


/**********************************************************************************************************************************************
//FUNCTION TO MOVE CURSOR POSITION
**********************************************************************************************************************************************/
void gotoXY(int X, int Y)
{
        COORD coordinates;
        coordinates.X = X;
        coordinates.Y = Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

/**********************************************************************************************************************************************
// CLASS FOR EMPLOYEE DETAILS
**********************************************************************************************************************************************/

class employee
{
    private:
        char name[20];
        char lname[20];
        char dept[20];
        char desig[20];
        int id,age;
        long int basicPay,medicalReimbursement=1500,otherAllowance,npay,TDS,EPF;
    public:
       friend void getdata(int i);
       friend void showdata(int i);
       friend void GetData();
       friend void PutData();
       friend void displayPayslip();
       friend void searchEmp();
       friend void Editname(int);
       friend void Editid(int);
       friend void Editdesg(int);
       friend void Editdept(int);
       friend void Editage(int);
       friend void Editsalary(int);
       friend void Edit();
       friend void deleteEmployee();
       friend void displaydata();
       friend bool checkid(int m);
};
employee ep[MAX],temp[MAX];

/**********************************************************************************************************************************************
//FUNCTION TO GET DATA FROM FILE
**********************************************************************************************************************************************/
void GetData()
{
        FILE *fp;
        fp = fopen("Employee.txt","r");
        int c=0;
    if(fp!=NULL)
    {
		while(feof(fp)==0)
		{
			fscanf(fp,"%s\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\n",&ep[c].name,&ep[c].lname,&ep[c].id,&ep[c].desig,&ep[c].dept,&ep[c].age,&ep[c].basicPay,&ep[c].otherAllowance,&ep[c].npay,&ep[c].TDS,&ep[c].EPF,&ep[c].medicalReimbursement);
			c++;
		}
		num=c;
	}
        fclose(fp);
}

/**********************************************************************************************************************************************
//FUNCTION TO PUT DATA INTO FILE
**********************************************************************************************************************************************/
void PutData()
{
	if(num==0)
	{
		system("del Employee.txt");
	}
	else
	{
		FILE *fp;
		fp = fopen("Employee.txt","w");
		for(int i=0;i<num;i++)
		{
			fprintf(fp,"%s\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\n",ep[i].name,&ep[i].lname,ep[i].id,ep[i].desig,ep[i].dept,ep[i].age,ep[i].basicPay,ep[i].otherAllowance,ep[i].npay,ep[i].TDS,ep[i].EPF,ep[i].medicalReimbursement);
		}
		fclose(fp);
	}
}

/**********************************************************************************************************************************************
//FUNCTION FOR MAKING BORDER
**********************************************************************************************************************************************/
void border(int left = 2, int top = 2,int right = 164, int bottom =42 )
{
        system("Color B");
        system("cls");
        gotoXY(left,top);printf("%c",201);
        gotoXY(left,bottom);printf("%c",200);

    for(int i=left+1;i<=right-1;i++)         //Top and Bottom Border line
        {
            Sleep(1);
        gotoXY(i,top);
            printf("%c",205);
        gotoXY(i,bottom);
            printf("%c",205);

        }
        gotoXY(right,top);printf("%c",187);
        gotoXY(right,bottom);printf("%c",188);

    for(int i=top+1;i<=bottom-1;i++)         //Left and Right Border Line
    {
            Sleep(1);
        gotoXY(left, i);
            printf("%c",186);
        gotoXY(right, i);
            printf("%c",186);
    }
}
/**********************************************************************************************************************************************
//FUNCTION FOR MAKING BORDER WITHOUT DELAY
**********************************************************************************************************************************************/
void Border(int left = 2, int top = 2,int right = 164, int bottom =42 )
{
        system("Color E");
        gotoXY(left,top);printf("%c",201);
        gotoXY(left,bottom);printf("%c",200);

    for(int i=left+1;i<=right-1;i++)         //Top and Bottom Border line
        {
        gotoXY(i,top);
            printf("%c",205);
        gotoXY(i,bottom);
            printf("%c",205);

        }
        gotoXY(right,top);printf("%c",187);
        gotoXY(right,bottom);printf("%c",188);

    for(int i=top+1;i<=bottom-1;i++)         //Left and Right Border Line
    {
        gotoXY(left, i);
            printf("%c",186);
        gotoXY(right, i);
            printf("%c",186);
    }
}
/**********************************************************************************************************************************************
//INTRODUCTION OF THE PROJECT
**********************************************************************************************************************************************/
void introduction()
{
        system("Color B");
        gotoXY(70,14);printf("PAYROLL MANAGEMENT SYSTEM");
        gotoXY(68,15);
        for(int i=0;i<29;i++)
        {
            Sleep(20);
            printf("%c",205); //196 is the ASCII code for '-'
        }
        gotoXY(69,19); printf("Designed and Programmed by:");
        gotoXY(69,20);
        for(int i=0;i<29;i++)
        {
            printf("%c",205);
            Sleep(20);
        }
        gotoXY(70,22); printf("AYUSH PETWAL");
        gotoXY(70,25); printf("SECTION A | ROLL NO. 35");
        gotoXY(70,28); printf("B.TECH CSE");
        gotoXY(70,32);printf("Press Any key to continue...");
        gotoXY(70,33);
        for(int i=0;i<29;i++)
        {
            printf("%c",205);
            Sleep(20);
        }
        getch();
}

/**********************************************************************************************************************************************
//FUNCTION TO IMITATE LOADING OF THE PROJECT
**********************************************************************************************************************************************/
void loading()
{
        system("cls");
        system("Color E");
        gotoXY(70,20);
        printf("Loading...");
        gotoXY(65,22);
    for(int i = 0; i<20; i++)
    {
        Sleep(200);
        printf("%c",219);
    }
}

/**********************************************************************************************************************************************
//FUNTION FOR MAKING LOGIN BORDER
**********************************************************************************************************************************************/
void loginborder(int left = 63, int top = 19, int right = 100, int bottom = 26)
{
        border(left,top,right,bottom);
}
/**********************************************************************************************************************************************
//FUNCTION FOR LOGIN INTO THE PAYROLL MANAGEMENT SYSTEM
**********************************************************************************************************************************************/
void login()
{
        system("Color D");
        char UserName[30],Password[30],ch;int i=0;
	gotoXY(65,21);
        printf("Enter UserName : ");
        cin>>UserName;
    gotoXY(65,23);
        cout<<"Enter Password : ";
    while(1)
    {
            ch = getch();
    	if(ch==13)                 //13 refers to the carriage return,it will stop the input after user presses "Enter"
    	break;
            if(ch==32||ch==9)
                continue;
            else
            {
                cout<<"*";
                Password[i]=ch;
                i++;
            }
	}
	Password[i] = '\0';
    if(strcmp(UserName,"Payroll")==0 && strcmp(Password,"1989")==0)
    {
            system("cls");
            loginborder();
    	gotoXY(72,21);
            cout<<"Login Success!!!";
    	gotoXY(66,23);
            cout<<"Will be redirected in 3 Seconds...";
            Sleep(1000);
    	gotoXY(89,23);
            cout<<"\b2";
            Sleep(1000);
    	gotoXY(89,23);
            cout<<"\b1";
            Sleep(1000);
    	gotoXY(89,23);
            cout<<"\b0";
            Sleep(1000);
	}
	else
	{
            flag++;
            system("cls");
        if(flag==3)
        {
            system("cls");
            loginborder();
        gotoXY(68,21);
            printf("!!!3 INCORRECT ATTEMPTS !!!\a");
        gotoXY(66,23);
            printf("    %d Attempts remaining!!",3-flag);
    	gotoXY(66,24);
            cout<<"System Will Close in 3 Seconds...";
            Sleep(1000);
    	gotoXY(88,24);
            cout<<"\b2";
            Sleep(1000);
    	gotoXY(88,24);
            cout<<"\b1";
            Sleep(1000);
        gotoXY(88,24);
            cout<<"\b0";
            Sleep(1000);
            exit(0);
        }
            loginborder();
    	gotoXY(72,21);
            printf("!!!Access Denied!!!\a");
    	gotoXY(66,23);
            printf("    %d Attempts remaining!!",3-flag);
        gotoXY(66,24);
            cout<<"Will be redirected in 3 Seconds...";
            Sleep(1000);
    	gotoXY(89,24);
            cout<<"\b2";
            Sleep(1000);
    	gotoXY(89,24);
            cout<<"\b1";
            Sleep(1000);
            cout<<"\b0";
            Sleep(1000);
            system("cls");
            loginborder();
            login();
	}
}
/**********************************************************************************************************************************************
//FUNCTION TO DISPLAY THE MENU
**********************************************************************************************************************************************/
void menu()
{
            system("cls");
            system("Color B");
            for(int i=0;i<=10;i++)
            {
            system("cls");
        gotoXY(64,5);
            printf("*****  Payroll Management System  ***** ");
            Sleep(2);
            }
            Border(2,2,164,40);
            system("Color B");
        gotoXY(64,5);
            printf("*****  Payroll Management System  ***** ");
            for(int i=62;i<=105;i++)
            {
        gotoXY(i,6);
            printf("%c",205);
            Sleep(20);
            }
        gotoXY(62,11);
            cout<<"Press  i ----> Insert New Employee";
        gotoXY(62,14);
            cout<<"Press  e ----> Edit an Employee Data";
        gotoXY(62,17);
            cout<<"Press  d ----> Delete an Employee Data";
        gotoXY(62,20);
            cout<<"Press  s ----> Search an Employee Data";
        gotoXY(62,23);
            cout<<"Press  l ----> List The Employee Table";
        gotoXY(62,26);
            cout<<"Press  p ----> Print Payslip for an Employee";
        gotoXY(62,29);
            cout<<"Press  q ----> Quit Program";
        gotoXY(66,34);
            cout<<"Select Your Option ====> ";
}
/**********************************************************************************************************************************************
//FUNCTION TO CHECK DUPLICATE IDs
**********************************************************************************************************************************************/
bool checkid(int m)
{
    for(int i=0;i<=num-1;i++)
	{
		if((ep[i].id)==m)
            return true;
	}
	return false;
}

/**********************************************************************************************************************************************
//FUNCTION TO GET EMPLOYEE DATA
**********************************************************************************************************************************************/

    void getdata(int i)
    {
        gotoXY(58,5);
            cout<<"Enter Details:-";
        gotoXY(56,7);
            cout<<"First Name: ";
            cin>>ep[i].name;
        gotoXY(56,9);
            cout<<"Last Name: ";
            cin>>ep[i].lname;
        gotoXY(56,11);
            cout<<"Id: ";
            cin>>ep[i].id;
            if(checkid(ep[i].id))
            {
                num--;
                system("cls");
                loginborder();
                gotoXY(67,22);
                cout<<"\aNo Duplicate ID's allowed!!!";
                Sleep(1000);
                return;
            }
        gotoXY(56,13);
            cout<<"Age: ";
            cin>>ep[i].age;
        gotoXY(56,15);
            cout<<"Department: ";
            cin>>ep[i].dept;
        gotoXY(56,17);
            cout<<"Designation: ";
            cin>>ep[i].desig;
        gotoXY(56,19);
            cout<<"Enter Pay Data:-";
        gotoXY(56,21);
            cout<<"Basic Pay: ";
            cin>>ep[i].basicPay;
        gotoXY(56,23);
            cout<<"House Rent Allowance(10% of basic pay): ";
            cout<<(ep[i].basicPay)/10;
        gotoXY(56,25);
            cout<<"Conveyance Allowance(50% of basic pay): ";
            cout<<(ep[i].basicPay)/2;
        gotoXY(56,27);
            cout<<"Medical Reimbursement: ";
            cout<<ep[i].medicalReimbursement;
        gotoXY(56,29);
            cout<<"Other Allownance: ";
            cin>>ep[i].otherAllowance;
        ep[i].TDS=(0.05)*(ep[i].basicPay);
        ep[i].EPF=(0.12)*(ep[i].basicPay);
        gotoXY(56,31);
            cout<<"Tax Reduced at Source(TDS-5% of basic pay) :"<<ep[i].TDS;
        gotoXY(56,33);
            cout<<"Employee Provident Fund(EPF-12% of basic pay) :"<<ep[i].EPF;
        ep[i].npay=((ep[i].basicPay)+(ep[i].basicPay)/2+(ep[i].basicPay)/10+ep[i].otherAllowance+ep[i].medicalReimbursement)-((0.05*(ep[i].basicPay))+((0.12)*(ep[i].basicPay)));
	    gotoXY(56,36);
	        cout<<"New Employee Added Into The System!!!";
	    getch();
    }

/**********************************************************************************************************************************************
//FUNCTION TO SHOW EMPLOYEE DATA
**********************************************************************************************************************************************/

    void showdata(int i)
    {
        gotoXY(56,7);
            cout<<"Id of the Employee : "<<ep[i].id;
        gotoXY(56,9);
            cout<<"Name of Employee : "<<ep[i].name<<" "<<ep[i].lname;
        gotoXY(56,11);
            cout<<"Age : "<<ep[i].age;
        gotoXY(56,13);
            cout<<"Department : "<<ep[i].dept;
        gotoXY(56,15);
            cout<<"Designation : "<<ep[i].desig;
        gotoXY(56,17);
            cout<<"Basic Pay : "<<ep[i].basicPay;
        gotoXY(56,19);
            cout<<"Conveyance Allowance :"<<(ep[i].basicPay)/2;
        gotoXY(56,21);
            cout<<"House Rent Allowance : "<<(ep[i].basicPay)/10;
        gotoXY(56,23);
            cout<<"Medical Reimbursement :"<<ep[i].medicalReimbursement;
        gotoXY(56,25);
            cout<<"Other Allownance:"<<ep[i].otherAllowance;
        gotoXY(56,27);
            cout<<"Tax Reduced at Source(TDS): "<<ep[i].TDS;
        gotoXY(56,29);
            cout<<"Employee Provident Fund(EPF) :"<<ep[i].EPF;
        gotoXY(56,31);
            cout<<"Net Pay: "<<ep[i].npay;
    }

/**********************************************************************************************************************************************
// FUNCTION TO STORE DATA OF EMPLOYEES
**********************************************************************************************************************************************/
void Add()
{

        system("cls");
        int i=num;
        getdata(i);
        num+=1;
}

/**********************************************************************************************************************************************
// FUNCTION TO GENERATE PAYSLIP OF AN EMPLOYEE
**********************************************************************************************************************************************/
void displayPayslip()
{
            system("cls");
            int found=0;
            Border();
            system("Color F");
        gotoXY(58,5);
            int code,i;
            cout<<"Enter Employee Job Code :";
            cin>>code;
    for(i=0;i<=num-1;i++)
	{
		if(ep[i].id==code)
		{
                system("cls");
                loginborder();
                gotoXY(71,22);
                cout<<"Generating Payslip";
                cout<<".";
                Sleep(1000);
                cout<<".";
                Sleep(1000);
                cout<<".";
                Sleep(1000);
                system("cls");
                border(45,2,132,42);
            gotoXY(78,5);
                cout<<"***  PAYSLIP   ***";
            gotoXY(78,6);
                cout<<"------------------";
			gotoXY(50,10);
                cout<<"Name : "<<ep[i].name<<" "<<ep[i].lname;
			gotoXY(93,10);
                cout<<"ID : "<<ep[i].id;
			gotoXY(50,13);
                cout<<"Age : "<<ep[i].age;
			gotoXY(65,13);
                cout<<"Department :"<<ep[i].dept;
			gotoXY(93,13);
                cout<<"Designation :"<<ep[i].desig;
			gotoXY(50,16);
                cout<<"Earnings :-";
			gotoXY(50,17);
                cout<<"-----------";
			gotoXY(50,19);
                cout<<"Basic Pay : "<<ep[i].basicPay<<endl;
			gotoXY(50,22);
                cout<<"HRA(10% of basic pay): "<<(ep[i].basicPay/10)<<endl;
			gotoXY(50,25);
                cout<<"Conveyance Allowance: "<<(ep[i].basicPay/2);
			gotoXY(50,26);
                cout<<"(50% of basic pay)";
			gotoXY(50,29);
                cout<<"Medical Reimbursement : "<<ep[i].medicalReimbursement<<endl;
			gotoXY(50,32);
                cout<<"Other Allowance:"<<ep[i].otherAllowance<<endl;
			gotoXY(93,16);
                cout<<"Deductions :-";
			gotoXY(93,17);
                cout<<"-----------";
			gotoXY(93,19);
                cout<<"Employee Provident Fund(EPF) :"<<ep[i].EPF<<endl;
			gotoXY(93,22);
                cout<<"TDS: "<<ep[i].TDS<<endl;
            gotoXY(46,38);
                cout<<"--------------------------------------------------------------------------------------";
			gotoXY(93,40);
                cout<<"***   Net Pay: Rs."<<ep[i].npay<<"/-   ***";
			found++;
		}
	}
		if(found==0)
        {
            gotoXY(70,20);
                cout<<"\a!!!Record Not Found!!!";
        }
            getch();
}


/**********************************************************************************************************************************************
// FUNCTION FOR SEARCHING RECORD FROM .TXT FILE
**********************************************************************************************************************************************/
void searchEmp()
{
            system("Color 3");
            system("cls");
            int flag=0,code;
            gotoXY(56,5);
            cout<<"Enter ID Of the Employee : ";
            cin>>jobcode;
        for(int i=0;i<=num-1;i++)
        {
            if(ep[i].id==code)
            {

                system("cls");
                showdata(i);
                Border(45,2,132,42);
                flag=1;
            }
        }
            if(flag==0)
            {
                gotoXY(70,20);
                    cout<<"\aRecord doesn't exist!!!";
            }
            getch();
}


/**********************************************************************************************************************************************
// FUNCTION FOR MODIFYING RECORDS
**********************************************************************************************************************************************/
void Editmenu()
{
            system("cls");
            Border();
            system("Color F");
        gotoXY(58,5);
            printf("Edit An Entry");
        gotoXY(59,7);
            cout<<"What Do You Want To edit";
        gotoXY(61,9);
            cout<<"n ---------> Name ";
        gotoXY(63,11);
            cout<<"i ---------> ID ";
        gotoXY(65,13);
            cout<<"d ---------> Designation";
        gotoXY(67,15);
            cout<<"D --------->Department ";
        gotoXY(69,17);
            cout<<"a ---------> Age";
        gotoXY(71,19);
            cout<<"s ---------> Salary";
        gotoXY(73,21);
            cout<<"q ---------> Quit";
        gotoXY(75,23);
            cout<<"Enter Choice ---->>>  ";
}

void Editname(int i)
{
            system("cls");
        gotoXY(61,9);
            cout<<"Enter New First Name----->  ";
            cin>>ep[i].name;
        gotoXY(61,11);
            cout<<"Enter New Last Name----->  ";
            cin>>ep[i].lname;
}

void Editid(int i)
{
            system("cls");
        gotoXY(61,9);
            cout<<"Enter New ID----->  ";
            cin>>ep[i].id;
}
void Editdesg(int i)
{
            system("cls");
        gotoXY(61,9);
            cout<<"enter new Designation----->  ";
            cin>>ep[i].desig;
}

void Editdept(int i)
{
            system("cls");
        gotoXY(61,9);
            cout<<"Enter new Department-----> ";
            cin>>ep[i].dept;
}
void Editage(int i)
{
            system("cls");
        gotoXY(61,9);
            cout<<"Enter new Age-----> ";
            cin>>ep[i].age;
}

void Editsalary(int i)
{
            system("cls");
        gotoXY(61,9);
            cout<<"Enter New Pay Data:----->";
        gotoXY(61,12);
            cout<<"Basic Pay: ";
            cin>>ep[i].basicPay;
        gotoXY(61,14);
            cout<<"House Rent Allowance(10% of basic pay): ";
            cout<<(ep[i].basicPay/2);
        gotoXY(61,16);
            cout<<"Conveyance Allowance(50% of basic pay): ";
            cout<<(ep[i].basicPay/10);
        gotoXY(61,18);
            cout<<"Medical Reimbursement: ";
            cout<<ep[i].medicalReimbursement;
        gotoXY(61,20);
            cout<<"Other Allowance: ";
            cin>>ep[i].otherAllowance;
            ep[i].TDS=(0.05)*ep[i].basicPay;
            ep[i].EPF=(0.12)*ep[i].basicPay;
        gotoXY(61,22);
            cout<<"Tax Reduced at Source(TDS-5% of basic pay) :"<<ep[i].TDS;
        gotoXY(61,24);
            cout<<"Employee Provident Fund(EPF-12% of basic pay) :"<<ep[i].EPF;
            ep[i].npay=(ep[i].basicPay+(ep[i].basicPay/2)+(ep[i].basicPay/10)+ep[i].otherAllowance+ep[i].medicalReimbursement)-(((0.05)*ep[i].basicPay)+((0.12)*ep[i].basicPay));
            getch();
}
void Edit()
{
            system("cls");
            Border();
            int jobcode,found=0;
        gotoXY(58,5);
            printf("Edit a Record");
            int i;
            char option;
        gotoXY(58,7);
            cout<<"Enter the jobcode To Edit : ";
            cin>>jobcode;

        for(i=0;i<=num-1;i++)
        {
          if(ep[i].id==jobcode)
		  {
                found=1;
			while((option=cin.get())!='q')
			{
			    Editmenu();
				switch(option)
				{
					case 'n':
						Editname(i);
						break;
					case 'i':
						Editid(i);
						break;
					case 'd':
						Editdesg(i);
						break;
					case 'D':
						Editdept(i);
						break;
					case 'a':
						Editage(i);
						break;
					case 's':
						Editsalary(i);
						break;
                    case 'q':
                        break;
                    default:
                        break;
				}

			}
		 }

	   }
            if(found==0)
            {
            gotoXY(70,20);
                cout<<"\a Record Not Found!!!";
            }
        if(option!= 'q')
                getch();
}



/**********************************************************************************************************************************************
// FUNCTION TO DELETE RECORD
**********************************************************************************************************************************************/

void deleteEmployee()
{
            system("Color F");
            int found=0;
            system("cls");
        for(int i=0;i<num;i++)
        {
            temp[i]=ep[i];
        }
        int code,check=-1,i,j;
        gotoXY(58,3);cout<<"Delete Record:- ";
        gotoXY(58,5);cout<<"Please Enter The Id of Employee : ";
            cin>>code;
        for(i=0;i<=num-1;i++)
        {
            if(ep[i].id==code)
            {
                check=i;
            }
        }
        if(check!=-1)
        {
            for(i=0,j=0;i<=num-1;i++,j++)
            {
                if(i==check)
                {
                    i++;
                }
			ep[j]=temp[i];
		}
		num--;
        gotoXY(70,20);
        cout<<"Record Deleted!!!";
        found=1;
	    }
        if(found==0)
        {
            gotoXY(70,20);
            cout<<"\a Record Not Found!!!";
        }
    getch();
}


/**********************************************************************************************************************************************
// FUNCTION TO DISPLAY ALL EMPLOYEE PAYDATA
**********************************************************************************************************************************************/

void  displaydata()
{
            system("cls");
            int i,j;
        gotoXY(64,5);
            printf("******** List of the Employees ********");
        gotoXY(36,6);
            cout<<"------------------------------------------------------------------------------------------------"<<endl;
        gotoXY(48,8);
            cout<<"Name\t\tID\t   Designation\t  Department\t  Age\t  Salary "<<endl;
        gotoXY(36,9);
            cout<<"------------------------------------------------------------------------------------------------"<<endl;
        for(i=0,j=10;i<=num-1;i++,j++)
        {
		gotoXY(44,j);
            cout<<ep[i].name<<" "<<ep[i].lname;
		gotoXY(61,j);
            cout<<ep[i].id;
		gotoXY(76,j);
            cout<<ep[i].desig;
		gotoXY(90,j);
            cout<<ep[i].dept;
		gotoXY(106,j);
            cout<<ep[i].age;
		gotoXY(114,j);
            cout<<ep[i].npay;
		j++;
        }
            Border(35,2,132,j);
            getch();
}


/**********************************************************************************************************************************************
// THE MAIN FUNCTION OF PROGRAM
**********************************************************************************************************************************************/


int main()
{
        border();
        introduction();
        loading();
        loginborder();
        login();
        menu();
        char option;
        GetData();
        while(1)
        {
            option=getch();
            switch(option)
            {
                case 'l':
                    displaydata();
                    break;
                case 'i':
                    Add();
                    break;
                case 'd':
                    deleteEmployee();
                    break;
                case 'e':
                    Edit();
                    break;
                case 's':
                    searchEmp();
                    break;
                case 'p':
                    displayPayslip();
                    break;
                case 'q':
                    PutData();
                    exit(0);
                default:
                    cout<<"\a";
		     }
            menu();
        }

        return 0;
}


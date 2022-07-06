#include<iostream>
using namespace std;
int i=0,no=2341;
struct binfo
{
	int  id;
	char type[10];
	int  cash;
	char fname[30];
	char lname[20];
	char dob[13];
	char phno[11];
	char date[10];
} s[20];
class bank
{
public:
bmain()
{
	cout<<"\tBANK MANAGMENT SYSTEM\n";
	cout<<"__________________________________________________\n";
	cout<<"BANK NAME:STATE BANK OF INDIA\n";
	cout<<"BRANCH   :DUBBA\n";
	cout<<"MANAGER  :VENUGOPAL\n";
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
};
class manager:public bank
{
	public:void update()
{
	int n, j, u,S=1;
	char ch;
	cout << "ENTER ACCOUNT NUMBER TO UPDATE:";
	cin >> n;
	for (j = 0; j <= i; j++)
		if (n == s[j].id)
		{
			cout << "1.CHANGE AC NO \n2.CHANGE FIRST NAME\n3.CHANGE LAST NAME\n4.CHANGE DATE OFBIRTH\n5.CHANGE ACCOUNT TYPE\n6.CHANGE PHONE NUMBER\n";
			cout<<"\n\tENTER YOUR CHOICE:";
			cin >> u;
			cout<<"-------------------------------------------\n";
			S=0;
			switch (u)
			{
			case 1:
				cout << "ENTER NEW ACCOUNT NUMBER\n";
				cin >> s[j].id;
				break;
			case 2:
				cout << "ENTER NEW FIRST NAME\n";
				cin >> s[j].fname;
				break;
			case 3:
				cout << "ENTER NEW LAST NAME\n";
				cin >> s[j].lname;
				break;
			case 4:
				cout << "ENTER NEW DATE OF BIRTH\n";
				cin >> s[j].dob;
				break;
			case 5:
				cout << "ENTER NEW ACCOUNT TYPE\n";
				cin >> s[j].type;
				break;
			case 6:
				cout << "ENTER NEW PHONE NUMBER\n";
				cin >> s[j].phno;
				break;
			}
		}
			if(S!=0)
			cout<<" !!INVALID ID!!\n";
			else
			cout << "UPDATED SUCCUESSFULLY\n";
		cout<<"------------------------------------------\n";
			}
	};
class coustmer:public bank
{
	public:
	void create()
	{
	cout<<"ENTER FOLLOWING DETAILS TO OPEN AN ACCOUNT\n";
	cout << "ENTER FIRST NAME:\n\t";
	cin >> s[i].fname;
	cout << "ENTER LAST NAME:\n\t";
	cin >> s[i].lname;
	cout << "ENYTER DATE OF BIRTH(DD-MM-YYYY):\n\t";
	cin >> s[i].dob;
	cout << "ENTER ACCOUNT TYPE:\n\t";
	cin >> s[i].type;
	cout << "ENTER PHONE NUMBER:\n\t";
	cin >> s[i].phno;
	cout<<"DEPOSIT MIN 500 RUPEES:\n\t";
	cin >> s[i].cash;
	cout<<"ENTER DATE OF ISSUE:\n\t";
	cin>>s[i].date;
	s[i].id=no+i;
	cout<<"YOUR ACCOUNT IS SUSCUFULLY CREATED\n";
	cout<<"YOUR ACCOUNT NUMBER IS:"<<s[i].id<<"\n";
	cout<<"------------------------------------------\n";
	i = i + 1;
	}
};
class trans:public coustmer
{
	public:int m,n,H=0,M=0,C;
	void withdraw()
	{
		cout<<"ENTER YOUR ACCOUNT NUMBER TO WITH DRAW MONEY:";
		cin>>n;
		for(int j=0;j<i;j++)
		{
			if(n==s[j].id)
			{
				H=1;
				if(s[j].cash!=0)
				{
					cout<<"ENTER MONEY TO WITH DRAW\n";
					cin>>m;
					if(s[j].cash>m)
					{
					s[j].cash=s[j].cash-m;	
					cout<<m<<" RUPEES SUSCESSFULLY WITHDRWAN\n";
		cout<<"YOUR BALANCE IS:"<<s[j].cash<<"\n";
		break;
		}
					else
					cout<<"!!THE AMOUNT WHICH YOU ENTER EXCEEDS YOUR ACCOUNT BALANCE!!\n";
					}
				else
				cout<<"!! YOUR ACCOUNT HAS ZERO BALANCE!!\n";	
			}
		}
		if(H==0)
		cout<<"!!INVALID ACCOUNT NUMBER!!\n";
			cout<<"------------------------------------------\n";
}
	void deposit()
	{
		cout<<"ENTER YOUR ACCOUNT NUMBER TO DEPOSIT MONEY:";
		cin>>n;
		for(int j=0;j<i;j++)
		{
			if(n==s[j].id)
			{
				M=1;
				cout<<"ENTER MONEY TO DEPOSIT:";
				cin>>m;
				s[j].cash+=m;
				C=s[j].cash;
					cout<<m<<" RUPEES SUSCESSFULLY DEPOSITED\n";
		cout<<"YOUR BALANCE IS:"<<C<<"\n";
				}
			}
			if(M==0)
		cout<<"!!INVALID ACCOUNT NUMBER!!\n";
			cout<<"------------------------------------------\n";
		}
	};
class display:public manager,public coustmer
{
	int d,C=0;
	public:
	void dism()
	{
		if(i==0)
		cout<<"LIST IS EMPTY\n";
		else
		{
		cout<<"ALL COUSTMER DETAILS\n";
		for(int j=0;j<i;j++)
		{
			cout<<"ACCOUNT TYPE  :"<<s[j].type<<"\t\t"<<" NAME :    "<<s[j].fname<<" "<<s[j].lname<<"\n";
			cout<<"ACCOUNT NUMBER:"<<s[j].id<<"\t\t"<< "DATE OF BIRTH:"<<s[j].dob<<"\n";
			cout<<"DATE OF ISSUE :"<<s[j].date<<"\t"<<"PHONE NUMBER:"<<s[j].phno<<"\n\n";
		    cout<<"\t\tBALANCE AMOUNT:"<<s[j].cash<<"\n";
		}
	}
	 cout<<"-----------------------------------------------------\n";
}
void disc()
	{
		cout<<"ENTER YOUR ACCOUNT NUMBER:";
		cin>>d;
			for(int j=0;j<i;j++)
		{
			if(s[j].id==d)
			{
				C=1;
			cout<<"ACCOUNT TYPE  :"<<s[j].type<<"\t\t"<<"NAME       :"<<s[j].fname<<" "<<s[j].lname<<"\n";
			cout<<"ACCOUNT NUMBER:"<<s[j].id<<"\t\t"<< "DATE OF BIRTH:"<<s[j].dob<<"\n";
			cout<<"DATE OF ISSUE :"<<s[j].date<<"\t"<<"PHONE NUMBER:"<<s[j].phno<<"\n\n";
		    cout<<"\t\tBALANCE AMOUNT:"<<s[j].cash<<"\n";
			}
		}
		if(C==0)
		cout<<"INVALID ACCOUNT NUMBER\n";
		 cout<<"----------------------------------------------------\n";
	}
};
class del:public coustmer
{
	public:
	int n;
	void block()
{
	cout << "ENTER YOUR ACCOUNT NUMBER TO BLOCK YOUR ACCOUNT:";
	cin >> n;
	int H=0;
	for (int j = 0; j < i; j++)
	{
		if (n == s[j].id)
		{
			H=1;
			for (int k = j; k < i; k++)
			{
				s[k].id = s[k + 1].id;
				strcpy(s[k].fname, s[k + 1].fname);
				strcpy(s[k].lname, s[k + 1].lname);
				strcpy(s[k].dob, s[k + 1].dob);
				strcpy(s[k].date, s[k + 1].date);
				strcpy(s[k].type, s[k + 1].type);
			    strcpy(s[k].phno,s[k+1].phno);
			    s[k].cash=s[k+1].cash;
			}
				}
	i = i - 1;
		}
		if(H==0)
			cout<<" !!INVALID ID!!\n";
			else
			cout << "YOUR ACCOUNT SUCSSFULLY BLOCKED\n";
			 cout<<"-------------------------------------------------\n";
}
};
int main()
{
	trans h;
	display M;
	del d;
	int n,c,m;
	h.bmain();
	while(1)
	{
		cout<<"1.MANAGER\n2.COUSTMER\n3.EXIT\n";
		cout<<"\n\tENTER YOUR CHOICE:";
		cin>>n;
		cout<<"---------------------------------------\n";
		switch(n)
		{
			case 1:
				{
					cout<<"1.ALL COUSTMER DETAILS\n2.UPDATE DETAILS\n3.EXIT\n";
	                cout<<"\n\tENTER YOUR CHOICE:";
	                cin>>m;
	                if(m==1)
	                M.dism();
	                else if(m==2)
	                M.update();
	                else
	                exit(0);
				}
			break;
			case 2:
				{
					cout<<"1.OPEN ACCOUNT\n2.WITHDRAW MONEY\n3.DEPOSIT\n4.KNOW YOUR BALANCE\n5.BLOCK ACCOUNT\n6.EXIT\n";
					cout<<"\n\tENTER YOUR CHOICE:";
					cin>>c;
					cout<<"--------------------------------------\n";
					if(c==1)
					{
						h.create();
					}
					else if(c==2)
						h.withdraw();
					else if(c==3)
					h.deposit();
					else if(c==4)
					M.disc();
					else if(c==5)
				    d.block();
				    else
					exit(0);	
				}
			break;
			case 3:exit(0);
		}
	}
}

	
 
	
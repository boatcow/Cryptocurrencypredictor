#include<fstream>
#include<vector>
#include<iostream>
#include <windows.h>
#include<string>
#include<deque>
using namespace std;
#define SIZE 3
float frnt,back;
void menu();
void develop();
void clrscr()
{
    for(int i=0;i<100;i++)
        cout<<"\n";
}

void plot()
{
ShellExecute(NULL, "open", "ugandan.html",NULL, NULL, SW_SHOWNORMAL);
}
void about()
{
    char a;
    clrscr();
    cout<<"              About                \n";
    cout<<"BITCOIN\nBitcoin is a cryptocurrency and worldwide payment system. It is the first decentralized digital currency, as the system works without a central bank or single administrator. ... Bitcoin was invented by an unknown person or group of people under the name Satoshi Nakamoto and released as open-source software in 2009.\n\n";
    cout<<"LITECOIN\nLitecoin (LTC) is a peer-to-peer cryptocurrency and open source software project released under the MIT/X11 license. Creation and transfer of coins is based on an open source cryptographic protocol and is not managed by any central authority. The coin was inspired by, and in technical details is nearly identical to, Bitcoin (BTC).\n\n";
    cout<<"DOGECOIN\nDogecoin is a cryptocurrency featuring a likeness of the Shiba Inu dog from the  Doge Internet meme as its logo. Introduced as a joke currency on 6 December 2013, Dogecoin quickly developed its own online community and reached a capitalization of US$60 million in January 2014. \n\n";
    cout<<"\n\nEnter any key......";
    cin>>a;
}
void login()
{
	clrscr();
    string a;
    int ch;
    clrscr();
    cout<<"Login";
    cout<<"\n[1]Login";
    cout<<"\n[2]Guest account";
    cout<<"\n[3]Developer options";
    cout<<"\nEnter choice: ";
    cin>>ch;
    if(ch==1)
    {
	
    cout<<"Enter username :";
    cin>>a;
    if(a=="trevsteals")
    {

        cout<<"\nENTER PASSWORD:  ";
        cin>>a;
        if(a=="jklol")
            {
                cout<<"\n\n Sucess .....";
                clrscr();
            }
        else
        cout<<"\nInvalid password";
    }
    else
       { cout<<"username not registered\n";
       exit(0);
   }
   }
   else if(ch==3)
   develop();

}

class database
{
    deque<float> dat;
    float returns(int i)
    {
        int n=0;
        double x[] = {1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        double y[30];
        for(deque<float>::reverse_iterator it=dat.rbegin();it<dat.rend() and n<i;n++,it++)
            y[n++]=*it;

        double b0 = 0;
        double b1 = 0;
        double alpha = 0.01;

        for (int i = 0; i < 20; i ++)
        {
            int idx = i %n;
            double p = b0 + b1 * x[idx];
            double err = p - y[idx];
            b0 = b0 - alpha * err;
            b1 = b1 - alpha * err * x[idx];
        }
		for(int i=1;i<4;i++)
        {int a=dat.back()+i*b1;
        dat.pop_back();
        dat.push_back(a);
        
    }
		return(float) b1;
        

    }
    void trim()
    {
        while(dat.size()>30)
            dat.pop_front();
    }
    void fread()
    {
        ifstream in(file.c_str(),ios::in);
        float a;
        
        in.seekg(0);
        while(in>>a)
        {
            dat.push_back(a);
        }
    }
    void fwrite()
    {
        ofstream out;
        string a="pred"+file;
        out.open(a.c_str(),ios::trunc);
        trim();
        int k=1;
       while(! dat.empty())
       {
       	if(k==1)
       	frnt=dat.front();
       	back=dat.front();
        out<<dat.front()<<" ";
        dat.pop_front();
      }
    }
    public:
    string file;
    double shortterm;
    double longterm;
    database(string a)
    {
        file=a;
        fread();
        shortterm=returns(3);
        longterm=returns(15);

    }
    void insert()
    {
        int n;
        float d;
        cout<<"enter how many values you want to enter:";
        cin>>n;
        cout<<"enter the values";
        for(int i=0;i<n;i++)
        {
            cin>>d;
            dat.push_back(d);
        }
    }
    ~database()
    {
        trim();
        fwrite();
    }
};
void chnge()
{
std::ofstream outfile;
char Data[3];
int k;
cout<<"enter data to add\n";
cin>>Data;
cout<<"\n\nAdd to\n[1]bit.txt\n[2]lite.txt\n[3]doge.txt\n";
cin>>k;
if(k==1)
outfile.open("bit.txt", std::ios_base::app);
if(k==2)
outfile.open("lite.txt", std::ios_base::app);
if(k==3)
outfile.open("doge.txt", std::ios_base::app);
outfile<<std::endl<<Data; 
login();
}
void develop()
{
    char a[10];
    clrscr();
    cout<<"Enter username :";
    cin>>a;
    if(strcmp(a,"secret")==0)
    {

        cout<<"\nENTER PASSWORD:  ";
        cin>>a;
        if(strcmp(a,"password")==0)
            {
                cout<<"\n\n Sucess .....";
                chnge();
            }
        else
        cout<<"\nInvalid password";
    }
    else
        cout<<"username not registered\n";



}    
int main()
{
    int o;
    char x,y;
	database currencies[]={database("lite.txt"),database("bit.txt"),database("doge.txt")};
    clrscr();
    login();
    xy:
    clrscr();
    cout<<"                     MENU                         \n\n";
    cout<<"[1]About\n";
    cout<<"[2]Longterm Investment\n";
    cout<<"[3]Shortterm Investment\n";
    cout<<"[4]View Graph";
    cout<<"\n[5]Exit";
    cin>>o;
    if(o==1)
    {
		about();
		goto xy;
	}
    else if(o==2)
    {
    	  cout<<"longterm best investment in decreasing order of preference: "<<endl;
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE-i-1;j++)
            if(currencies[j].longterm>currencies[j+1].longterm)
            {
                database temp=currencies[j];
                currencies[j]=currencies[j+1];
                currencies[j+1]=temp;
            }
  cout<<currencies[0].file<<endl<<currencies[1].file<<endl<<currencies[2].file<<endl;
  	cin>>x;
  	clrscr();
  goto xy;
	}
    else if(o==3)
    {
    	  cout<<endl<<"shortterm best investments in decreasing orderof preference : "<<endl;
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE-i-1;j++)
            if(currencies[j].shortterm>currencies[j+1].shortterm)
            {
                database temp=currencies[j];
                currencies[j]=currencies[j+1];
                currencies[j+1]=temp;
            }
  cout<<currencies[0].file<<endl<<currencies[1].file<<endl<<currencies[2].file<<endl;
  cin>>x;
	goto xy;
	}
    else if(o==4)
	plot();  
    return 0;
}

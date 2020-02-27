#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int count_d(int year, int month) //月份有幾天
{
	int days;
	if( (year%400==0||(year%4==0 && year%100!=0)) && month==2)
		days=29;
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		days = 31;
	else if(month==4||month==6||month==9||month==11)
		days = 30;
	else
		days = 28;
	return (days);
}

int count_t(int year1,int month1, int day1,int year2,int month2, int day2)
{
    int t,m1,m2,y,d,dd;
    d=0;
    y=0;
    m1=0;
    m2=0;
	if (year1==year2)
	{
		if(month1==month2)
			return day2-day1;
		else
		{
			for(int i=month1+1;i<month2;i++)
			{
				d=d+count_d(year1,i);
			}
			d=(d+count_d(year1,month1)-day1+day2);
			return d;
		}
	}
	else
	{
        if(month1==month2)
        {
        	for(int i=year1+1;i<=year2;i++)
                y=y+count_d(i,month1);
			return y+day2-day1;
		}

		else
		{
			for(int i=year1+1;i<year2;i++)
        	{
        		if( (i%400==0||(i%4==0 && i%100!=0)))
        			y=y+366;
        		else
        			y=y+365;
			}
			for(int i=month1+1;i<=12;i++)
        	{
        		m1=m1+count_d(year1,i);
			}
			for(int i=1;i<month2;i++)
			{
				m2=m2+count_d(year2,i);
			}
			d=y+m2+m1+day2+count_d(year1,month1)-day1;
			return d;
		}
	}
}

int main()
{
	int n,y1,m1,y2,d2,d1,m2,N,period;    //n 總天數
	double cp,w;
	float c,r,value=0,discount=1;
	float m,y,a;    //a accrued interest
	cout<<"bond maturity date yyyy/mm/dd:(輸入完月份請按enter 同理)";
	cin>>y2>>m2>>d2;
	cout<<"settlement date yyyy/mm/dd:(輸入完月份請按enter 同理)";
	cin>>y1>>m1>>d1;
	cout<<"bond yield:";
	cin>>r;
	cout<<"coupon rate:";
	cin>>y;

    c=(100*y)/2;
    n=count_t(y1,m1,d1,y2,m2,d2);

    if(m2>=6)
    {
        period=count_t(y2,m2-6,d1,y2,m2,d2);
    }
    else
    {
        period=count_t(y2-1,m2+12-6,d1,y2,m2,d2);
    }

    r=r/2;
    int k=n%period;    //k # of days to the next payment date
    w=double(k)/period;
    N=((n-k)/period)+1;  //總期數

    value=c*pow(1+r,-w);
    discount=pow(1+r,-w);

    for(int i=2;i<=N;i++)
    {
        discount=discount*pow(1+r,-1);
        value=value+c*discount;
    }

    value=value+100*discount;
    a=c*(1-w);
    cp=value-a;

    cout<<"Dirty price="<<value<<endl;
    cout<<"Clean price="<<cp<<endl;
	return 0;
}


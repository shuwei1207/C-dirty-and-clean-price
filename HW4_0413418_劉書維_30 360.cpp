#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int count_t(int year1,int month1, int day1,int year2,int month2, int day2)
{
    int t,m,y,d;
	if (year1==year2)
	{
		if(month1==month2)
			return day2-day1;
		else
		{
			m=(month2-month1)*30;
			d=day2-day1;
			t=m+d;
			return t;
		}
	}
	else
	{
        if(month1==month2)
			return day2-day1+(year2-year1)*360;
		else
		{
			y=(year2-year1)*360;
			m=(month2-month1)*30;
			d=day2-day1;
			t=y+m+d;
			return t;
		}
	}
}

int main()
{
	int n,y1,m1,y2,d2,d1,m2;
	double cp,w ;
	float c,r,value=0,discount;
	float m,y,a;    //a accrued interest
	
	cout<<"bond maturity date yyyy/mm/dd:(輸入完月份請按enter 同理)";
	cin>>y2>>m2>>d2;
	cout<<"settlement date yyyy/mm/dd:(輸入完月份請按enter 同理)";
	cin>>y1>>m1>>d1;
	cout<<"bond yield:(小數)";
	cin>>r;
	cout<<"coupon rate:(小數)";
	cin>>y;

    c=(100*y)/2;
    n=count_t(y1,m1,d1,y2,m2,d2);
    r=r/2;
    int k=n%180;    //k # of days to the next payment date
    w=double(k)/180;

    int N=((n-k)/180)+1;  //總期數
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

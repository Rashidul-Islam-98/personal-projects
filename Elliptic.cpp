#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"General formate: y^2=x^3+ax+b"<<endl;
    cout<<"Enter a and b:"<<endl;

    double a,b,x1,x2,x3,x4,y1,y2,y3,y4,temp;
    cin>>a>>b;
    cout<<"Enter the point P:"<<endl;
    cin>>x1>>y1;
    cout<<"Enter the point Q:"<<endl;
    cin>>x2>>y2;

    x3=((y2-y1)/(x2-x1))-x1-x2;
    y3=-y1+((y2-y1)/(x2-x1))*(x1-x3);
    cout<<"The value of P+Q: ("<<x3<<","<<y3<<")"<<endl;
    temp=(3*x1*x1+a)/(2*y1);
    x4=pow(temp,2)-2*x1;
    y4=-y1+temp*(x1-x4);
    cout<<"The value of 2P: ("<<x4<<","<<y4<<")"<<endl;
    return 0;
}

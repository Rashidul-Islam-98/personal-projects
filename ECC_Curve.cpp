#include<bits/stdc++.h>
using namespace std;
int a,b,p;
int inversmod1(int x,int y)
{
    int temp1,i,s;
    temp1=(3*x*x+a)%p;
    for(i=1;i<p;i++)
    {
        if(y==0)
        {
            s=INT_MAX;
            break;
        }
        else if(temp1%(2*y)==0)
        {
            s=(temp1/2*y);
            break;
        }
        else if((2*y*i)%p==1)
        {
            s=(temp1*i)%p;
            break;
        }
    }
    return s;
}
int inversmod2(int x1,int y1,int x2,int y2)
{
    int temp1,temp2,i,s;
    temp1=y2-y1;
    temp2=x2-x1;
    for(i=1;i<p;i++)
    {
        if(temp2==0)
        {
            s=INT_MAX;
            break;
        }
        else if(temp1%temp2==0)
        {
            s=temp1/temp2;
            break;
        }
        else if((temp2*i)%p==1)
        {
            s=(temp1*i)%p;
        }
    }
    return s;
}
int modulo(int v)
{
    int x;
    if(v<0)
    {
        for(int i=1;;i++)
        {
            x=v+i*p;
            if(x>0)
                break;
        }
    }
    else
        x=v%p;
    return x;
}
int main()
{
    cout<<"General formate: y^2=x^3+ax+b mod p"<<endl;
    cout<<"enter the value of a,b,p:"<<endl;
    int i,j;
    cin>>a>>b>>p;
    cout<<"Affine points of elliptic curve:"<<endl;
    int arr1[p],arr2[p];
    for(i=0;i<p;i++)
    {
        arr1[i]=(i*i*i+a*i+b)%p;
        arr2[i]=(i*i)%p;
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<p;j++)
        {
            if(arr1[i]==arr2[j])
            {
                cout<<"("<<i<<","<<j<<"),";
            }
        }
    }
    cout<<endl;
    cout<<"Enter the generator point:"<<endl;
    int x,y;
    cin>>x>>y;
    cout<<"subgroup of generator point:"<<endl;
    int sub1[100],sub2[100],t,temp,temp1,temp2;
    sub1[0]=x,sub2[0]=y;
    for(i=1;;i++)
    {
        if(i%2==1)
        {
            t=(i-1)/2;
            temp=inversmod1(sub1[t],sub2[t]);
            if(temp==INT_MAX)
            {
                sub1[i]=0;
                sub2[i]=0;
                break;
            }
            temp1=temp*temp-2*sub1[t];
            sub1[i]=modulo(temp1);
            temp2=temp*(sub1[t]-sub1[i])-sub2[t];
            sub2[i]=modulo(temp2);
        }
        else
        {
            t=i-1;
            temp=inversmod2(sub1[0],sub2[0],sub1[t],sub2[t]);
            if(temp==INT_MAX)
            {
                sub1[i]=0;
                sub2[i]=0;
                break;
            }
            temp1=temp*temp-sub1[0]-sub1[t];
            sub1[i]=modulo(temp1);
            temp2=temp*(sub1[0]-sub1[i])-sub2[0];
            sub2[i]=modulo(temp2);
        }
    }
    for(i=0;;i++)
    {
        cout<<(i+1)<<"G=("<<sub1[i]<<","<<sub2[i]<<") ";
        if(sub1[i]==0 && sub2[i]==0)
            break;
    }
    cout<<endl;
    cout<<"Value of n: "<<(i+1)<<endl;
    return 0;
}

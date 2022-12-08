#include<bits/stdc++.h>
using namespace std;
long long int n,phi;
long long int gcd(long long int a,long long int b)
{
    if(a%b==0)
    {
        return b;
    }
    else
    {
       return gcd(b,a%b);
    }
}
long long int euclidean(long long int x,long long int y)
{
    long long int a1,a2,a3,b1,b2,b3,t1,t2,t3,q;
    a1=1;
    a2=0;
    a3=x;
    b1=0;
    b2=1;
    b3=y;
    while(b3!=1)
    {
        q=a3/b3;
        t1=a1-q*b1;
        t2=a2-q*b2;
        t3=a3-q*b3;
        a1=b1;
        a2=b2;
        a3=b3;
        b1=t1;
        b2=t2;
        b3=t3;
    }
    if(b2<0)
        b2=b2+phi;
    return b2;
}
long long int mymod(long long int r,long long int e)
{
    long long int b,c,i;
    b=r%n;
    c=b;
    for(i=2;i<=e;i++)
    {
        c=c*b;
        c=c%n;
    }
    return c;
}
int main()
{
    long long int p,q,e,d,i,j;
    cout<<"Enter the first prime number:"<<endl;
    cin>>p;
    cout<<"Enter the second prime number:"<<endl;
    cin>>q;
    n=p*q;
    phi=(p-1)*(q-1);
    long long int temp;
    cout<<"Possible values of e:"<<endl;
    for(j=2;j<phi;j++)
    {
        temp=gcd(j,phi);
        if(temp==1)
            cout<<j<<" ";
    }
    cout<<endl;
    cout<<"Enter the value of e:"<<endl;
    cin>>e;
    d=euclidean(phi,e);
    cout<<n<<" "<<e<<" "<<d<<endl;
    string text;
    vector<int>cipher,decipher;
    cout<<"Enter the text:"<<endl;
    cin.ignore();
    getline(cin,text);
    long long int v,w;
    for(i=0;i<text.size();i++)
    {
        v=mymod(text[i],e);
        cipher.push_back(v);
    }
    cout<<"Encrypted mgs:"<<endl;
    for(i=0;i<cipher.size();i++)
    {
        if(cipher[i]>127)
            cout<<"'"<<(cipher[i])<<"'";
        else if(cipher[i]<47)
            cout<<"'"<<cipher[i]<<"'";
        else
            cout<<(char)(cipher[i]);
    }
    cout<<endl;
    for(i=0;i<cipher.size();i++)
    {
        w=mymod(cipher[i],d);
        decipher.push_back(w);
    }
    cout<<"Decrypted text:"<<endl;
    for(i=0;i<decipher.size();i++)
    {
        cout<<(char)(decipher[i]);
    }
    return 0;
}

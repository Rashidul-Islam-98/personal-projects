#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    fstream file("test.txt");
    string key,mgs,text;
    getline(file,key);
    getline(file,text);
    file<<"The key table:"<<endl;
    char mat[5][5];
    string table;
    table=key.append("abcdefghiklmnopqrstuvwxyz");
    int Size=table.size();
    int i,j,n=0,k;
    for(i=0;i<Size;i++)
    {
        if(table[i]=='j')
        {
            table[i]='i';
        }
        for(j=i+1;j<Size;j++)
        {
            if(table[i]==table[j])
            {
                for(k=j;k<Size;k++)
                {
                    table[k]=table[k+1];
                }
                Size--;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            mat[i][j]=table[n];
            n++;
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            file<<mat[i][j]<<"   ";
        }
        file<<endl;
    }
    j=0;
    for(i=0;text[i]!='\0';i++)
    {
        if(text[i]==' ')
            continue;
        if(text[i]==text[i+1] && j%2==0)
        {
            if(text[i]=='x')
           {
               mgs.push_back(tolower(text[i]));
               mgs.push_back('z');
               j+=2;
           }
            else
            {
              mgs.push_back(tolower(text[i]));
              mgs.push_back('x');
              j+=2;
            }
        }
        else
        {
            mgs.push_back(tolower(text[i]));
            j++;
        }
    }
    if(mgs.size()%2==1)
    {
        if(mgs[mgs.size()-1]=='x')
            mgs.push_back('z');
        else
            mgs.push_back('x');
    }
    file<<"Padded Text:"<<endl<<mgs<<endl;
    file<<"Encryted Text:"<<endl;
    int r1,r2,c1,c2;
    for(i=0;mgs[i]!='\0';i+=2)
    {
        j=i+1;
        for(k=0;k<5;k++)
        {
            for(n=0;n<5;n++)
            {
                if(mgs[i]==mat[k][n])
                {
                    r1=k;
                    c2=n;
                }
                if(mgs[j]==mat[k][n])
                {
                    r2=k;
                    c1=n;
                }
            }
        }
        if(r1==r2)
        {
            if(c1+1>4)
            {
                mgs[i]=mat[r1][c2+1];
                mgs[j]=mat[r2][0];
            }
            else if(c2+1>4)
            {
                mgs[i]=mat[r1][0];
                mgs[j]=mat[r2][c1+1];
            }
            else
            {
                mgs[i]=mat[r1][c2+1];
                mgs[j]=mat[r2][c1+1];
            }
        }
        else if(c1==c2)
        {
            if(r1+1>4)
            {
                mgs[i]=mat[0][c1];
                mgs[j]=mat[r2+1][c2];
            }
            else if(r2+1>4)
            {
                mgs[i]=mat[r1+1][c1];
                mgs[j]=mat[0][c2];
            }
            else
            {
                mgs[i]=mat[r1+1][c1];
                mgs[j]=mat[r2+1][c2];
            }
        }
        else
        {
            mgs[i]=mat[r1][c1];
            mgs[j]=mat[r2][c2];
        }
        file<<mgs[i]<<mgs[j];

    }
    file<<endl;
    file<<"Decryted Text:"<<endl;
    int r3,r4,c3,c4;
    for(i=0;mgs[i]!='\0';i+=2)
    {
        j=i+1;
        for(k=0;k<5;k++)
        {
            for(n=0;n<5;n++)
            {
                if(mgs[i]==mat[k][n])
                {
                    r3=k;
                    c4=n;
                }
                if(mgs[j]==mat[k][n])
                {
                    r4=k;
                    c3=n;
                }
            }
        }
        if(r3==r4)
        {
            if(c3-1<0)
            {
                mgs[i]=mat[r3][c4-1];
                mgs[j]=mat[r4][4];
            }
            else if(c4-1<0)
            {
                mgs[i]=mat[r3][4];
                mgs[j]=mat[r4][c3-1];
            }
            else
            {
                mgs[i]=mat[r3][c4-1];
                mgs[j]=mat[r4][c3-1];
            }
        }
        else if(c3==c4)
        {
            if(r3-1<0)
            {
                mgs[i]=mat[4][c3];
                mgs[j]=mat[r4-1][c4];
            }
            else if(r4-1<0)
            {
                mgs[i]=mat[r3-1][c3];
                mgs[j]=mat[4][c4];
            }
            else
            {
                mgs[i]=mat[r3-1][c3];
                mgs[j]=mat[r4-1][c4];
            }
        }
        else
        {
            mgs[i]=mat[r3][c3];
            mgs[j]=mat[r4][c4];
        }
        file<<mgs[i]<<mgs[j];

    }
    file.close();
    return 0;
}

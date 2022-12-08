#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream infile;
    infile.open("input.txt");
    string text,cipher;
    while(getline(infile,cipher))
    {
        text+=cipher;
    }
    infile.close();
    string key,letter;
    cout<<"Enter the key:"<<endl;
    cin>>key;
    letter=key.append("abcdefghiklmnopqrstuvwxyz");
    int i,j,k,n;
    char mat[5][5];
    int len=letter.size();
    for(i=0;i<len;i++)
    {
        if(letter[i]=='j')
        {
            letter[i]='i';
        }
        for(j=i+1;j<len;j++)
        {
            if(letter[i]==letter[j])
            {
                for(k=j;k<len;k++)
                {
                    letter[k]=letter[k+1];
                }
                len--;
            }
        }
    }
    k=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
          mat[i][j]=letter[k];
          k++;
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
          cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }
    string mgs;
    j=0;
    for(i=0;i<text.size();i++)
    {
        if(text[i]==' ')
            continue;
        if(text[i]=='j')
            text[i]=i;
        if(text[i]==text[i+1] && j%2==0)
        {
            if(text[i]=='x' || text[i]=='X')
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
    cout<<"Padded Text:"<<endl<<mgs<<endl;
    cout<<"Encryted Text:"<<endl;
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
                mgs[i]=mat[0][c2];
                mgs[j]=mat[r2+1][c1];
            }
            else if(r2+1>4)
            {
                mgs[i]=mat[r1+1][c1];
                mgs[j]=mat[0][c2];
            }
            else
            {
                mgs[i]=mat[r1+1][c2];
                mgs[j]=mat[r2+1][c1];
            }
        }
        else
        {
            mgs[i]=mat[r1][c1];
            mgs[j]=mat[r2][c2];
        }
        cout<<mgs[i]<<mgs[j];
    }
    cout<<"dexryted text:"<<endl;
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
            if(c1-1<0)
            {
                mgs[i]=mat[r1][c2-1];
                mgs[j]=mat[r2][4];
            }
            else if(c2-1<0)
            {
                mgs[i]=mat[r1][4];
                mgs[j]=mat[r2][c1-1];
            }
            else
            {
                mgs[i]=mat[r1][c2-1];
                mgs[j]=mat[r2][c1-1];
            }
        }
        else if(c1==c2)
        {
            if(r1-1<0)
            {
                mgs[i]=mat[4][c2];
                mgs[j]=mat[r2-1][c1];
            }
            else if(r2-1<0)
            {
                mgs[i]=mat[r1-1][c1];
                mgs[j]=mat[4][c2];
            }
            else
            {
                mgs[i]=mat[r1-1][c2];
                mgs[j]=mat[r2-1][c1];
            }
        }
        else
        {
            mgs[i]=mat[r1][c1];
            mgs[j]=mat[r2][c2];
        }
        cout<<mgs[i]<<mgs[j];
    }
}


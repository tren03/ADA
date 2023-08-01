include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("sample.txt",ios::in);
    fin.seekg(0,ios::beg);
    string text,pattern;
    while(fin)
    {
        getline(fin,text);
    }
    cout<<"enter pattern";
    getline(cin,pattern);
    int n=text.size();
    int m=pattern.size();
    int flag=0;
    for(int i=0;i<=n-m;i++)
    {
        int j=0;
        while(text[i+j]==pattern[j])
        {
            j++;
        }
        if(j==m)
        {
            cout<<"pattern found at index "<<i;
            flag++;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"not found ";
    }

}

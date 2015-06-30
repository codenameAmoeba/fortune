#include<iostream>
#include<time.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
//*************************************

int generate_call() //for generating unique pseudo-random number every time
{
time_t t;
srand((unsigned)time(&t));
return rand()%(2800);
}

//************************************

void extract(int arg=generate_call())
{
char a;
int update=0,flag=0;
fstream obj("fortune.ft",ios::in);
while(obj)
{
obj.get(a);
if(a=='%'){update++;}
if(update==arg)
{
while(obj){obj.get(a);if(a=='%'){flag=-1;break;}cout<<a;}
}
if(flag!=0) break;
}
}

//***********************************

int main()
{
extract();
return 0;
}

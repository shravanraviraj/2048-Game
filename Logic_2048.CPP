#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<DOS.h>
#include<stdlib.h>
unsigned int score=0;
int fwin=0;
const int o =5;

int checkendgame(int a[o][o])
{
int i,j;

//check for zeros
for(i=0;i<o;i++)
for(j=0;j<o;j++)
if(a[i][j]==0)
return 0;

//check for pairs
for(i=0;i<o;i++)
{
for(j=0;j<o;j++)
{
if(j==(o-1) && i<(o-1))
{
if(a[i][j]==a[i+1][j])
return 0;
}//if
else
if(i==(o-1) && j<(o-1))
{if(a[i][j]==a[i][j+1])
return 0;
} //elseif
else
if(a[i][j]==a[i][j+1] || a[i][j]==a[i+1][j])
return 0;

}//j
}//i
return 1;
}



//display the matrix
void disp(int a[o][o])
{int i,j;
for(i=0;i<o;i++)
{
for(j=0;j<o;j++)
{
if(a[i][j]!=0)
cout<<a[i][j]<<"     ";
else
cout<<"0     ";
}
cout<<"\n\n\n";
}
}

int up(int a[5][5])
{
int i,j,k,f=0,h=0;

for(j=0;j<o;j++)
{h=0;
for(i=1;i<o;i++)
{

k=i;

while(k>h)
{

if(a[k-1][j]==0)
{a[k-1][j]=a[k][j];
if(a[k][j]!=0)
f=1;
a[k][j]=0;}

else
if(a[k-1][j]==a[k][j])
{a[k-1][j]*=2;score+=a[k][j]*2;f=1;a[k][j]=0;h=k;}

else
break;

k--;
}//while
}//i
}//j
return f;
}





int down(int a[5][5])
{
int i,j,k,f=0,h=o-1;
for(j=0;j<o;j++)
{h=o-1;
for(i=o-2;i>=0;i--)
{
k=i;
while(k<h)
{

if(a[k+1][j]==0)
{a[k+1][j]=a[k][j];
if(a[k][j]!=0)
f=1;
a[k][j]=0;}

else
if(a[k+1][j]==a[k][j])
{a[k+1][j]*=2;score+=a[k][j]*2;a[k][j]=0;f=1;h=k;}
else
break;

k++;
}//while
}//i
}//j
return f;
}


int left(int a[5][5])
{
int i,j,k,f=0,h=0;
for(i=0;i<o;i++)
{h=0;
for(j=1;j<o;j++)
{
k=j;
while(k>h)
{
if(a[i][k-1]==0)
{a[i][k-1]=a[i][k];
if(a[i][k]!=0)
f=1;
a[i][k]=0;}
else
if(a[i][k-1]==a[i][k])
{a[i][k-1]*=2;score+=a[i][k]*2;a[i][k]=0;f=1;h=k;}
else
break;
k--;
}//while
}//j
}//i
return f;
}

int right(int a[5][5])
{
int i,j,k,f=0,h=o-1;
for(i=0;i<o;i++)
{ h=o-1;
for(j=o-2;j>=0;j--)
{
k=j;
while(k<h)
{
if(a[i][k+1]==0)
{a[i][k+1]=a[i][k];
if(a[i][k]!=0)
f=1;
a[i][k]=0;}
else
if(a[i][k+1]==a[i][k])
{a[i][k+1]*=2;score+=a[i][k]*2;a[i][k]=0;f=1;h=k;}
else
break;
k++;
}//while
}//j
}//i
return f;
}


int retind(int a[5][5])
{  int i;int index;
int n;
int j=0;
for(i=0;i<o*o;i++)
if(a[i/o][i%o]==0)
n++;

int * arr = new int[n];
j=0;

for(i=0;i<o*o;i++)
if(a[i/o][i%o]==0)
{arr[j]=i;j++;}
//randomize();
srand(5);
index = rand()%n;
return arr[index];

}



void main()
{ int index,addrand,x,y;
clrscr();
int a[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//randomize();
srand(25);
y=rand()%25;
x=rand()%25;
a[y/o][y%o]=2;
a[x/o][x%o]=2;

disp(a);
char key;
while(1)
{
addrand=0;
if(checkendgame(a))
{cout<<"\n\nGAME OVER !!"; break;}

//get character for movement
key=getch();
switch(key)
  {
   case 'w':addrand = up(a);
	     break;

   case 's': addrand = down(a);
	     break;

   case 'a':addrand = left(a);
	     break;

   case 'd':addrand = right(a);
	     break;

   case 'e': exit(0);
	     break;
  }

if(addrand)
{
index = retind(a);
a[index/o][index%o]=2;
}
clrscr();
disp(a);
cout<<"\n\n\nSCORE : "<<score;
if(fwin)
{cout<<"\n\nYOU WIN";break;}
}
getch();
}

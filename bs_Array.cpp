#include<iostream>
//#include"stdlib.h"
using namespace std;
char op;
int ar[21],msize;
int lb = 1;

int quit();
int array_in();
void array_print();
int array_insertion();
int array_deletion();
int l_search();

int main()
{

cout<<"Enter the size of the array(Max size 20) => ";
cin>>msize;
 
msize = array_in();
if( msize>=20){
	return 0;
}
 
array_print();
//cout<<"+++";
 
 cout<<"\n\n\t\tWhat operation do you want to perform => \n\t\t\t\t 1 = Insertion \n\t\t\t\t 2 = Deletion\n";
 cout<<"\t\t\t\t 3 = Linear search \n";
 cout<<"\t\t\t => ";
 cin>>op;
 
 int find;
	 switch (op)
	{
	
		case '1':
			msize = array_insertion();
			cout<<"\n\n";
			array_print();
			//cout<<"a{}"<<ar[5];
		break;
		
		case '2':
			msize = array_deletion();
			cout<<"\n\n";
			array_print();	
		break;
		
		case '3':
		
		 	find = l_search();
			cout<<"\n\n";
			if(find>0)
			{
				cout<<"\t\t Item found at[ "<<find<<" ]";
			}
			else
			{
			cout<<"\t\t Item could not be found :( \n";	
			}	
			
		break;
		default:
			cout<<"Something went wrong";
	};



return 0;
}

int array_in()
{
	char retry;
	while(msize>=20)
	{
		
		cout<<"incorrest";
		cout<<"Do you want to try again( y=yes ) => ";
		cin>>retry;
		
		if(retry == 'y')
		{
			cout<<"Enter the size of the array(Max size 20) => ";
			cin>>msize;

		}
		else
		{
			return msize;
		}
	}
	
	cout<<"\n\n\t\t Enter the elements of the array---\n";
	
	for(int i=1;i<=msize;i++)
	{
		
		cout<<"Enter value [ "<<i<<" ] => ";
		cin>>ar[i];
		
	}
	return msize;

}

void array_print()
{
	cout<<"\n\n\t\t\t The array is----";
	for(int i=1;i<=msize;i++)
	{
		cout<<"\n\t\t Element [ "<<i<<" ] => "<<ar[i] ;
		}
	
}

int array_insertion()
{
	int k,item;
	cout<<"Enter the new integer => ";
	cin>>item;
	cout<<"Where do you want to insert => ";
	cin>>k;
	
	if(k == msize + 1)
	{
		//cout<<msize;
		ar[msize + 1]=item;
		//cout<<msize;
	}	
	else
	{
		for(int i = msize;i>=k;--i)		// k position is now empty
		{
			ar[i+1]=ar[i];
		}
		ar[k]=item;
		
		
	}
return ++msize;
}

int array_deletion()
{
	int k;
	cout<<"Enter the position from where you want to delete =>";
	cin>>k;
	if(k != msize)
	{
		for(int i = k;i<=msize;++i)
		{
			ar[i]=ar[i+1];
		}	
	}

	
return --msize;
	
}

int l_search()
{
int key;
cout<<"\n\t\t What do you want to search => ";
cin>>key;

for(int i =1;i<=msize;++i)
{
	if(ar[i] == key)
	{
		return i;
	}
 	
}	
  return -1;	
}
//BUBBLE SORT
#include<iostream>
#include<conio.h>

using namespace std;
int main(){
	int i,n,key,j,arr[20],temp;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter elements: ";
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=0;i<=(n-2);i++)
	{
		for(j=0;j<=(n-i-2);j++)
		{
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}	
		}	
	}
	cout<<"The sorted data is: "<<endl;
	for(i=0;i<n;i++){
		cout<<arr[i];
	}
	getch();
	return 0;
}

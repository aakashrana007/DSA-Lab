//INSERTION SORT
#include<iostream>
#include<conio.h>

using namespace std;
int main(){
	int i,n,key,j,arr[20];
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter elements: ";
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=1;i<=(n-1);i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	cout<<"The sorted data is: ";
	for(i=0;i<n;i++){
	cout<<arr[i]<<endl;
}
	
	getch();
	return 0;
}

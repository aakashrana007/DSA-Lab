//SELECTION SORT
#include<iostream>
#include<conio.h>

using namespace std;
int main(){
	int i,n,k,key,in,arr[20],temp,min;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter elements: ";
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	
	for(k=0;k<n-1;k++){
		min=arr[k];
	for(i=k+1;i<n;i++)
	{	
		if(arr[k]>arr[i]){
			min=arr[i];
			in=i;
		}	
	}
	temp=arr[k];
	arr[k]=arr[in];
	arr[in]=temp;
	}
	
	cout<<"The sorted data is: "<<endl;
	for(i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	getch();
	return 0;
}

#include<iostream>
//By: Frankie Herbert
//Help from tutor: Alex P., Book assigned in class, Nigal, cplusplus
//Bag of "marbles"

using namespace std;

int main()
{
	int a[50],x,n,i,j,b[50];
	cout<<"How many marbles would you like to add to the bag: ";  //How many marbles to be added
	cin>>n;
	cout<<"\nWhat are the numbers on the " << n << " marbles: "; //defining the marbles added in the bag

	for(i=0;i<n;++i)
		cin>>a[i];

	cout<<"\nWhat number of marble would you like to remove?: "; //Removing marble 1 marble from the bag
	cin>>x;

	for(i=0,j=0;i<n;++i)
	{
		if(a[i]!=x)
			b[j++]=a[i];
	}

	if(j==n)
	{
		cout<<"\nSorry!!! This marble is not inside of the bag"; // Tells is the marble is in the bag
		exit(0);
	}
	else
	{
		cout<<"\nThis is what the bag has left: "; //Tells how many marbles are left in the bag
		for(i=0;i<j;i++)
			cout<<b[i]<<" ";
	}

	return 0;
}


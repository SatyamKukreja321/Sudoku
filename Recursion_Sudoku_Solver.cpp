#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int number)
{
	for(int x=0;x<n;x++)
	{
		if(mat[x][j]==number || mat[i][x]==number)
			return false;
	}
	
	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;
	
	for(int x=sx;x<sx+rn;x++)
	{
		for(int y=sy;y<sy+rn;y++)
		{
			if(mat[x][y]==number)
				return false;
		}
	}
	return true;
}


bool sudokuSolver(int mat[][9], int i, int j, int n)
{
	//Base case
	if(i==n)
	{
		//Print the matrix
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	
	// Case row end
	if(j==n)
		return sudokuSolver(mat,i+1,0,n);
	
	// Skip the pre filled cells
	if(mat[i][j]!=0)
		sudokuSolver(mat,i,j+1,n);
	
	// recursive case
	// fill the current cells with possible options
	for(int number=1;number<=n;number++)
	{
		if(canPlace(mat,i,j,n,number))
		{
			// Assume
			mat[i][j]=number;
			
			bool couldWeSolve = sudokuSolver(mat,i,j+1,n);
			if(couldWeSolve==true)
				return true;
		}
	}
	
	// backtracking
	mat[i][j]=0;
	return false;
}

int main()
{
	int mat[9][9] = {
		    {5,3,0,0,7,0,0,0,0},
		    {6,0,0,1,9,5,0,0,0},
		    {0,9,8,0,0,0,0,6,0},
		    {8,0,0,0,6,0,0,0,3},
		    {4,0,0,8,0,3,0,0,1},
		    {7,0,0,0,2,0,0,0,6},
		    {0,6,0,0,0,0,2,8,0},
		    {0,0,0,4,1,9,0,0,5},
		    {0,0,0,0,8,0,0,7,9},
	};
	
	cout<<endl;
	for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl<<endl;
	
	sudokuSolver(mat,0,0,9); // N=9;  N*N -> 9*9

	return 0;
}








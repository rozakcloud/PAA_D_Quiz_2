#include <bits/stdc++.h> 
using namespace std; 
#define N 3

struct Node {
	Node* parent; 
	int mat[N][N]; 
	int x, y;
	int level;
}; 

int main() { 
	int initial[N][N] = { 
		{1, 2, 3}, 
		{5, 7, 6}, 
		{4, 8, 0} 
	}; 

	int final[N][N] = { 
		{1, 2, 3}, 
		{5, 8, 6}, 
		{0, 7, 4} 
	}; 
	
	printf("Initial\n");
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++)
		{
			
			printf("%d ", initial[i][j]); 
		}
		printf("\n");
		
	}
	printf("------\n");
	
	printf("Target Final\n");
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++)
		{
			
			printf("%d ", final[i][j]); 
		}
		printf("\n");
		
	}
	printf("------\n");

	return 0; 
} 

#include<stdio.h>
#define SIZE 2
void MM(int A[SIZE][SIZE],int B[SIZE][SIZE],int C[SIZE][SIZE],int n)
{
 int P,Q,R,S,T,U,V;
// if(n<=2)
//  {
P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
Q=(A[1][0]+A[1][1])*B[0][0];
R=A[0][0]*(B[0][1]-B[1][1]);
S=(A[1][1])*(B[1][0]-B[0][0]);
T=(A[0][0]+A[0][1])*B[1][1];
U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
V=(A[0][1]-A[1][1])*(A[1][0]+B[1][1]);
}
// else
// {
//     MM(A,(*B)[0],(*C)[0],n/2) + MM(A,B,C,n/2);
//     MM(A,B,C,n/2) + MM(A,B,C,n/2);
//     MM(A,B,C,n/2) + MM(A,B,C,n/2);
// }
C[0][0]=(P+S-T+V);
C[0][1]=(R+T);
C[1][0]=(Q+S);
C[1][1]=(P+R-Q+U);
}
int main()
{
    int i,j,k;
    int a[SIZE][SIZE];
    int b[SIZE][SIZE];
    int c[SIZE][SIZE];

     printf("Enter the 4 elements of first matrix: ");
  for(i = 0;i < SIZE; i++)
      for(j = 0;j < SIZE; j++)
           scanf("%d", &a[i][j]);
 
  printf("Enter the 4 elements of second matrix: ");
  for(i = 0; i < SIZE; i++)
      for(j = 0;j < SIZE; j++)
           scanf("%d", &b[i][j]);
 
  printf("\nThe first matrix is\n");
  for(i = 0; i < SIZE; i++){
      printf("\n");
      for(j = 0; j < SIZE; j++)
           printf("%d\t", a[i][j]);
  }
 
  printf("\nThe second matrix is\n");
  for(i = 0;i < SIZE; i++){
      printf("\n");
      for(j = 0;j < SIZE; j++)
           printf("%d\t", b[i][j]);
  }
  MM(a,b,c,SIZE);

  printf("\n Multiplication \n");
  for(i = 0;i < SIZE; i++){
      printf("\n");
      for(j = 0;j < SIZE; j++)
           printf("%d\t", c[i][j]);
  }
return 0;
}
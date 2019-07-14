#include<stdio.h>
FILE *f;
void createvertice(int,int,int);
void createface(int,int,int,int);
void createcube(int,int,int);
int a[50][50][50],m,n,o;
int noofvertices=0;
int nooffaces=0;
int main()
{
	f=fopen("test.obj","w");
	int i,j,k;
	printf("enter size of matrix:-");
	scanf("%d%d%d",&m,&n,&o);
	printf("enter int should contain 0 or 1 values to matrix:-");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<o;k++)
			{
				scanf("%d",&a[i][j][k]);
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<o;k++)
			{
				if(a[i][j][k]==1)
				{
					createcube(i,j,k);
				}
			}
		}
	}
	fclose(f);
	return 0;
}
void createvertice(int a,int b,int c)
{
	fprintf(f,"v %d %d %d\n",a,b,c);
	noofvertices++;
}
void createface(int a,int b,int c,int d)
{
	fprintf(f,"f %d %d %d %d\n",a,b,c,d);
	nooffaces++;
}
void createcube(int x,int y,int z)
{
	createvertice(x,y,z);
	createvertice(x,y,z+1);
	createvertice(x,y+1,z);
	createvertice(x,y+1,z+1);
	createvertice(x+1,y,z);
	createvertice(x+1,y,z+1);
	createvertice(x+1,y+1,z);
	createvertice(x+1,y+1,z+1);
	createface(noofvertices-5,noofvertices-1,noofvertices-3,noofvertices-7);
	createface(noofvertices-3,noofvertices-2,noofvertices-6,noofvertices-7);
	createface(noofvertices-1,noofvertices-0,noofvertices-2,noofvertices-3);
	createface(noofvertices-5,noofvertices-4,noofvertices-0,noofvertices-1);
	createface(noofvertices-4,noofvertices-5,noofvertices-7,noofvertices-6);
	createface(noofvertices-0,noofvertices-4,noofvertices-6,noofvertices-2);
}

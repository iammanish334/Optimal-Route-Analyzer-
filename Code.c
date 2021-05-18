#include<stdio.h>

  int ary[10][10],completed[10],n,cost=0,data[100];
  int mn,temp,temp3,minimum;
  int p = 0,p1 = 0,c = 0,l = 0,count = 0,g = 1,n1=0,location = 0,c1 = 0;
  char city[1000000];

void takeInput()
{
	int i,j;


  printf("Enter the number of cities to visit : -- ");

  scanf("%d",&n);
  int q=n-1;
  for(int i = 0;i<n;i++)
  {
     printf("Enter the %dth city : -- ",i+1);
     scanf("%s",&city[i]);
  }

 printf("The cities are : -- \n");


 for(int i = 0;i<n;i++)
  {

     printf("%c \t",city[i]);

     }
     printf("\n The possible routes through all cities : -- \n");

        for(int j = 0;j<n;j++)
        {
             for(int i = 0;i<n;i++)
             {
             printf("%c ---- %c\n",city[j],city[i]);
             c++;
             }
        }
     printf("\n");

     printf("---> There are total %d combinations possible <---",c);


      printf("\n             --- Filtering the routes ---          \n");
       for(int j = 0;j<n;j++)
        {
             for(int i = 0;i<n;i++)
             {
                 if(i!=j)
                 {
                     printf("%c ---- %c\n",city[j],city[i]);
                      c1++;
                 }
             }
        }
        printf("\n");

     printf("--->Once filtered it comes out to be total %d combinations possible <---",c1);




     printf("\n                 Enter the weight or distance for each pair of nodes : --");
     printf("\n");

      for(int j = 0;j<n;j++)
        {
             for(int i = 0;i<n;i++)
             {
                 if(i!=j)
                 {
                     printf("Enter the data for node pair :- [%c - %c]   \n",city[j],city[i]);
                     scanf("%d",&data[p]);
                     p++;
                 }
             }
        }
 printf("\n");
 printf("\nInternally created a cost matrix. . . \n");
	for(i=0;i < n;i++)
	{


		for( j=0;j < n;j++)
		{
		if(i==j)
		{
			ary[i][j]=0;
		}
		else
		{
		    ary[i][j]=data[n1];
		    n1++;
		}
		}

		completed[i]=0;
	}



	printf("\n");

      printf(" ----NODE PAIR---- | UNIQUE ID |  DATA \n");

      for(int j = 0;j<n;j++)
        {
             for(int i = 0;i<n;i++)
             {
                 if(i!=j)
                 {
                     if(data[p1]!=0)
                     {
                        printf("    [%c -- %c]       |   %d       | %d  \n",city[j],city[i],p1,data[p1]);
                        p1++;
                     }

                 }
             }
        }
        printf("\n");

        printf("\n\nThe cost list is:");

	for( i=0;i < n;i++)
	{
		printf("\n");

		for(j=0;j < n;j++)
			printf("\t%d",ary[i][j]);
	}
	printf("\n\nThe selected weights/distance through using row wise minimization are : -- ");


     printf("\n");

   printf("                                  _____________________\n");
  printf("                                  |                                                             |\n");
  printf("                                  | **Note : -- If there are more than two node-pairs with same |\n");
  printf("                                  |              weights/distance then u can go for any of the  |\n");
  printf("                                  |              one and proceed further.                       |\n");
  printf("                                  |_____________________|\n");


}

void mincost(int city)
{
	int i,ncity;

	completed[city]=1;

	printf("%d--->",city+1);
	ncity=least(city);

	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);         
		cost+=ary[city][ncity];

		return;
	}

	mincost(ncity);
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;

	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}

	if(min!=999)
		cost+=kmin;

	return nc;
}

int main()
{
	takeInput();

	printf("\n\nThe Path is:\n");
	mincost(0); //passing 0 because starting vertex

	printf("\n\nMinimum cost is %d\n ",cost);

	return 0;
}
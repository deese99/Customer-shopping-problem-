#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#define MAX_CUSTOMERS 6
sem_t EnterShop;
sem_t ShopForAWhile;
sem_t LeaveShop;
sem_t wait;
int main()
{
    int i,num; 
    printf("----A solution to the shopping customer problem using semaphores----\n");
    printf("\n");
    printf("-->Please note that maximum pair of customers can only be 6 \n"); 
    printf("\t Enter total number of pairs of customers.\n");
    scanf("%d",&num);
    if(num>MAX_CUSTOMERS) 
    {
        printf("The maximum number of pair of customers entered is %d.\n",num);
        printf("Invalid Input\n");
        return 0;
    }
    else
   {   
        int cust[num];
        printf("\nPlease give the input in the form of 0 and 1\n");
        printf("\t --> 1 represents the pair with one person right handed and other person left handed i.e, RL or RL\n");
        printf("\t --> 0 represents the pair with any combination of right and left handed person except LR and RL\n");
        printf("\n");
        printf("Enter the pairs of customers as 0 and 1:\n");
        for(i=1;i<=num;i++)         
        {
           scanf("%d",&cust[i]);
        }
        for(i=1;i<=num;i++)
        {
           if(cust[i]==1)
           {
              printf("\n");
              printf("*****Welcome to the shop*****\n");
              printf("\n");
              printf("%d th pair is RL/LR pair of customer\n",i);
              sem_init(&EnterShop, 0, 1);
              sem_init(&ShopForAWhile, 0, 0);
              sem_init(&LeaveShop, 0, 1);
              printf("Customers processing...please wait\n\n");
              printf("\n");
              printf("Customers are entering in the shop.\n");
              sem_wait(&EnterShop);
              printf("Customers are doing shopping.\n");
              sem_post(&ShopForAWhile);
              sem_post(&wait);
              printf("Customers have finished shopping\n");
              int r=2; 
              for(int k=1;k<=r;k++)
              {
                 printf("Customers left the shop\n",k);
                 sem_wait(&LeaveShop);
             }
          }
  else
  {
   printf("\nSorry %d number pair is not allowed to enter the shop as they are not RL/LR pair \n",i);
  }
}
    }
}


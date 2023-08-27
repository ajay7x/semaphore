#include<stdio.h>
#include<stdlib.h>

int mutex=1;
int bookedticket=0;//full
int totalticket;//empty
int x=0;

void bookticket()
{
    --mutex;
    ++bookedticket;
    --totalticket;
    x++;
    printf("\n %d ticket booked successfully",x);
    printf("\n available ticket: %d",totalticket);
    ++mutex;
}

void cancelticket()
{
   
    --mutex;  
    --bookedticket;
    ++totalticket;
     printf("\n one ticket cancelled successfully");
    printf("\n available tickets: %d",totalticket);
    x--;
    ++mutex;
}

void remainingticket()
{
    printf("\n total remaining tickets: %d",totalticket);

}

int main()
{
    int i,n;

    printf("\n enter total number of tickets: ");
    scanf("%d",&totalticket);
    printf("\n 1.press 1 for ticket booking:"
        "\n 2.press 2 for ticket cancelling: "
         "\n 3.press 3 for display remaining ticket:"
         "\n 4.press 4 for exit:");

    for(i=1;i>0;i++)
    {
        printf("\n enter your choice:");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                    if((mutex==1)&&(totalticket!=0))
                    {
                        bookticket();
                    }
                    else
                    {
                        printf("no tickets available");

                    }
                    break;
            case 2:
                    if((mutex==1)&(bookedticket!=0))
                    {
                        cancelticket();
                    }
                    else
                    {
                        printf("no ticket for cancelling");
                    }
                    break;
            case 3:
                    {
                        remainingticket();
                    }
                    break;
            case 4:
                    exit(0);
                    break;

        }           
    }
}

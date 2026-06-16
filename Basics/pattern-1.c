#include<stdio.h>

int main()
{
    int start = 1 ;
    for ( int i =0 ; i < 7 ; i++)
    {
        if ( i % 2 ==0 )
            start = 0 ;
        else 
            start = 1;
        for ( int  j = 0 ; j < i ; j++)
        {
            printf(" %d",start);
            printf(" %d", 1-start );
        }
        printf("\n");
        


    }
}
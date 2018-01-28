#include <stdio.h>
#include <stdlib.h>


main()
{

    int *p = NULL,i,n,sum;
    printf("Please enter array numbers: ");
    scanf("%d",&n);

    p = (int*)malloc(sizeof(int)*n);

    if(p==NULL)
    {

        printf("No enough memory !\n");
        exit(0);
    }



    printf("Please input %d scores:",n);
    for (i=0;i<n;i++)
    {

        scanf("%d",p+i);

    }


    sum = 0;

    for (i =0;i<n;i++)
    {
        sum = sum + *(p+i);

    }

    printf("aver = %d\n",sum/n);
    free(p);

}

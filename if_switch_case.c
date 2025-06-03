#include <stdio.h>
int main()
{
   /**t b;
    printf("enter a value:");
    scanf("%d", &b);
    if (b < 0)
    {
        printf("The value is negative\n");
    }
    else if(b==0)
    {
        printf("The value is zero\n");
    }
    else 
    {
        printf("The value is positive\n");
    }
    int a = 2;
    switch (a)
    {
    case 1:
        printf("The value is 1\n");
        break;
    case 2:
        printf("The value is 2\n");
        break;
    case 3:
        printf("The value is 3\n");
        break;
    default:
        printf("The value is not 1, 2 or 3\n");
    }
    return 0; **/
   //Schleife mit while
int a = 0, b = 10;
while (a < b)
{
    printf("%d\n",a);
    ++a;
}

//Schleife mit do while
 a=0, b = 10;
 do 
{
    printf("%d\n",a);
    ++a;
}while (a < b);

//Schleife mit for
for (a = 0, b = 10; a < b; ++a)
{
    printf("%d\n",a);
}
}

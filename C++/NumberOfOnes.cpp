#include<bits/stdc++.h>

int main()
{
    int dv,r,c=0,NumberOfOnes=0;
    scanf("%d",&dv);
    while(dv > 0) 
    {
            r = dv %2;
            if(r == 1) 
            {
                c++;

            if(c > NumberOfOnes)
                NumberOfOnes = c;

            } 
            else 
            { 
                c = 0;
            }
            dv = dv/2;
    }
    printf("%d",NumberOfOnes);

}
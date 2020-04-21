#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{
    int a, b, k, i, n, N;
    float c, d;
    while(1)
    {
    	printf("请输入你想进行的操作，仅输入数字即可\n1.整数\n2.小数\n0.退出\n");//1整数2小数0退出 
        scanf("%d", &n);
        if(n==0)
        	break;
        else{
        	printf("请输入想生成等式的个数\n");
			scanf("%d",&N);
		    switch (n)
		    {
		    case 1:
		    {
		
		        for (i = 0; i < N; i++)
		        {
		            a = rand() % 100 + 1;
		            b = rand() % 100 + 1;
		            k = rand() % 4 + 1;
		            printf("%d", a);
		            switch (k)
		            {
		            case 1:
		                printf("+");
		                break;
		            case 2:
		                printf("-");
		                break;
		            case 3:
		                printf("*");
		                break;
		            case 4:
		                printf("/");
		                break;
		            }
		            printf("%d=\t\t", b);
		        }
		        break;
		    }
		    break;
		    case 2:
		    {
		        for (i = 0; i < N; i++)
		        {
		            c = rand() * 0.001 + 1;
		            d = rand() * 0.001 + 1;
		            k = rand() % 4 + 1;
		            printf("%0.2f", c);
		            switch (k)
		            {
		            case 1:
		                printf("+");
		                break;
		            case 2:
		                printf("-");
		                break;
		            case 3:
		                printf("*");
		                break;
		            case 4:
		                printf("/");
		                break;
		            }
		            printf("%0.2f=\t", d);
		        }
		        break;
		    }
		    break;
		    }
		}
    }
}

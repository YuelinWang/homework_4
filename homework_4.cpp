#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
double t[30005];
//个数 最大值 括号 输出 
int x,maxn,kh,outp;
//运算符 
int sizes[4];
//生成随机数 
//传入参数 整/小
void gen(int n)
{
	x*=3;
	srand((unsigned)time(NULL));
	if(n==1){
		for(int i=0;i<x;i++){
			t[i]=rand()%maxn;
			if(t[i]==0)
				i--;
		}
	}
	else{
		for(int i=0;i<x;i++){
			t[i]=rand()%(maxn*100)/100.0;
			if(int(t[i])==0)
				i--;
		}
	}
}
//为out函数提供输出的符号
int returnfh(int i)
{
	while(1){
		if(sizes[((int)t[i])%4]){
			return ((int)t[i])%4;
		}
		else{
			i++;
			if(i==x){
				i=0;
			}
		}
	}
}
//为out函数提供输出的符号 
void outfh(int fun_fh)
{
	if(fun_fh==0){
		printf(" + ");
	}
	else if(fun_fh==1){
		printf(" - ");
	}
	else if(fun_fh==2){
		printf(" * ");
	}
	else if(fun_fh==3){
		printf(" / ");
	}
}
//往文件中写入 
int outfh_file(int fun_fh,FILE *fp)
{
	if(fun_fh==0){
		fprintf(fp," + ");
	}
	else if(fun_fh==1){
		fprintf(fp," - ");
	}
	else if(fun_fh==2){
		fprintf(fp," * ");
	}
	else if(fun_fh==3){
		fprintf(fp," / ");
	}
}
//计算往txt输出的结果
//ab为数字c为符号 
double cal_out(double a,double b,int c)
{
	return c==0?(a+b):(c==1?(a-b):(c==2?(a*b):(a/b)));
} 
//计算往txt输出的结果
//abc为数字de为符号 
double cal_out_no(double a,double b,double c,int d,int e)
{
	if(d<2&&e>1){
		return cal_out(a,cal_out(b,c,e),d);
	}
	else{
		return cal_out(cal_out(a,b,d),c,e);
	}
} 
//按要求输出 
void out(int n)
{
	//标题 
	int id=1;
	FILE *fp1,*fp2;
	double x1,x2,x3;
	int fh1,fh2;
	system("cls");
	//有括号 
	if(kh){
		//直接打印 
		if(outp==0){
			for(int i=0;i<x;i++){
				//标题 
				printf("%d.",id++);
				x1=t[i++];
				x2=t[i++];
				x3=t[i];
				fh2=returnfh(i);
				//避免出现除以0的情况 
				if((x2-x3)==0&&fh2==1){
					int flagsize=sizes[3];
					sizes[3]=0;
					fh1=returnfh(i);
					sizes[3]=flagsize;
				}
				else{
					fh1=returnfh(i);
				}
				if(n==1){
					printf("%.0lf",x1);
					outfh(fh1);
					printf("(%.0lf",x2);
					outfh(fh2);
					printf("%.0lf) = \n",x3);
				}
				else{
					printf("%.2lf",x1);
					outfh(fh1);
					printf("(%.2lf",x2);
					outfh(fh2);
					printf("%.2lf) = \n",x3);
				}
			}
		}
		//输出txt 
		else{
			fp1=fopen("question.txt","w");
			fp2=fopen("answer.txt","w");
			for(int i=0;i<x;i++){
				//标题 
				fprintf(fp1,"%d.",id);
				fprintf(fp2,"%d.\t",id++);
				x1=t[i++];
				x2=t[i++];
				x3=t[i];
				fh2=returnfh(i);
				//避免出现除以0的情况 
				if((x2-x3)==0&&fh2==1){
					int flagsize=sizes[3];
					sizes[3]=0;
					fh1=returnfh(i);
					sizes[3]=flagsize;
				}
				else{
					fh1=returnfh(i);
				}
				if(n==1){
					fprintf(fp1,"%.0lf",x1);
					outfh_file(fh1,fp1);
					fprintf(fp1,"(%.0lf",x2);
					outfh_file(fh2,fp1);
					fprintf(fp1,"%.0lf) = \n",x3);
					fprintf(fp2,"%.2lf\n",cal_out(x1,cal_out(x2,x3,fh2),fh1));
				}
				else{
					fprintf(fp1,"%.2lf",x1);
					outfh_file(fh1,fp1);
					fprintf(fp1,"(%.2lf",x2);
					outfh_file(fh2,fp1);
					fprintf(fp1,"%.2lf) = \n",x3);
					fprintf(fp2,"%.2lf\n",cal_out(x1,cal_out(x2,x3,fh2),fh1));
				}
			}
			fclose(fp1);
			fclose(fp2);
		}
	}
	else{
		//直接打印 
		if(outp==0){
			for(int i=0;i<x;i++){
				//标题 
				printf("%d.",id++);
				x1=t[i++];
				x2=t[i++];
				x3=t[i];
				fh2=returnfh(i);
				//避免出现除以0的情况 
				if((x2-x3)==0&&fh2==1){
					int flagsize=sizes[3];
					sizes[3]=0;
					fh1=returnfh(i);
					sizes[3]=flagsize;
				}
				else{
					fh1=returnfh(i);
				}
				if(n==1){
					printf("%.0lf",x1);
					outfh(fh1);
					printf("%.0lf",x2);
					outfh(fh2);
					printf("%.0lf = \n",x3);
				}
				else{
					printf("%.2lf",x1);
					outfh(fh1);
					printf("%.2lf",x2);
					outfh(fh2);
					printf("%.2lf = \n",x3);
				}
			}
		}
		//输出txt 
		else{
			fp1=fopen("question.txt","w");
			fp2=fopen("answer.txt","w");
			for(int i=0;i<x;i++){
				//标题 
				fprintf(fp1,"%d.\t",id);
				fprintf(fp2,"%d.\t",id++);
				x1=t[i++];
				x2=t[i++];
				x3=t[i];
				fh2=returnfh(i);
				//避免出现除以0的情况 
				if((x2-x3)==0&&fh2==1){
					int flagsize=sizes[3];
					sizes[3]=0;
					fh1=returnfh(i);
					sizes[3]=flagsize;
				}
				else{
					fh1=returnfh(i);
				}
				if(n==1){
					fprintf(fp1,"%.0lf",x1);
					outfh_file(fh1,fp1);
					fprintf(fp1,"%.0lf",x2);
					outfh_file(fh2,fp1);
					fprintf(fp1,"%.0lf = \n",x3);
					fprintf(fp2,"%.2lf\n",cal_out_no(x1,x2,x3,fh1,fh2));
				}
				else{
					fprintf(fp1,"%.2lf",x1);
					outfh_file(fh1,fp1);
					fprintf(fp1,"%.2lf",x2);
					outfh_file(fh2,fp1);
					fprintf(fp1,"%.2lf = \n",x3);
					fprintf(fp2,"%.2lf\n",cal_out_no(x1,x2,x3,fh1,fh2));
				}
			}
			fclose(fp1);
			fclose(fp2);
		}
	}
	printf("打印成功，请按任意键继续\n");
	getchar();getchar();
	system("cls");
}
int main()
{
	//操作0退出1整数2小数 
	int n;
	while(1){
		memset(sizes,0,sizeof(sizes));
		memset(t,0,sizeof(t));
		printf("请输入你想进行的操作，仅输入数字即可\n1.整数\n2.小数\n0.退出\n");
		scanf("%d",&n);
		if(n==0||n==1||n==2){
			if(n==0){
				break;
			}
			else{
				while(1){
					printf("请输入想生成等式的个数\n取值范围为1-10000\n");
					scanf("%d",&x);
					if(x>=1&&x<=10000){
						printf("请输入最大值\n");
						scanf("%d",&maxn);
						gen(n);
						while(1){
							printf("请输入想要的四则运算符\n格式为四个0或1的数字，分别代表加减乘除\n0代表不用此运算符，1代表用，中间用空格隔开\n");
							for(int i=0;i<4;i++){
								scanf("%d",&sizes[i]);
							}
							int flagr=1;
							for(int i=0;i<4;i++){
								if(sizes[i]!=0&&sizes[i]!=1){
									flagr=0;
								}
							}
							if(flagr==1){
								while(1){
									printf("请输入是否带括号，0不带，1带\n");
									scanf("%d",&kh);
									if(kh==0||kh==1){
										while(1){
											printf("请选择输出方式，0直接打印，1以txt输出\n");
											scanf("%d",&outp);
											if(outp==0||outp==1){
												out(n);
												goto END;
											} 
											else{
												printf("输入有误请重新输入\n");
											}
										}
									}
									else
										printf("输入有误请重新输入\n");
								}
							}
							else
								printf("输入有误请重新输入\n");
						}
					}
					else
						printf("输入有误请重新输入\n");
				}
			}
		}
		else
			printf("输入有误请重新输入\n");
		END:;
	}
} 

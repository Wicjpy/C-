#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
#define CodeLength 6
typedef struct course
{
	int MT;/*数学*/
	int EN;/*英语*/
	int PH;/*物理*/


}COURSE;
typedef struct student
{
	long studentID;/*学号*/
	char studentName[10];/*姓名*/
	COURSE mark;/*成绩*/
	float aver;/*平均分*/
	int sum;/*总分*/
	int sort;/*排名*/
}STUDENT;

void Idsort(STUDENT stu[],int n); 
void InputScore(STUDENT stu[],int n);/*输入学生的信息*/
void AverforScore(STUDENT stu[],int sumCourse[],float aveCourse[],int n);/*计算每门课程的总分和平均分*/
void AverforStudent(STUDENT stu[],int n);/*计算学生的总分和平均分*/
void DatasortDescend(STUDENT stu[],int n);/*总分由高到低排出名次表*/
void DatasortAscend(STUDENT stu[],int n);/*总分由低到高排出名次表*/
void Idsort(STUDENT stu[],int n);/*按学号由小到大排序*/
void SortString(STUDENT stu[],int n);/*按姓名的字典顺序排出成绩表*/
void IDforSortandScore(STUDENT stu[],int n,long x,int score[], int sort[]);/*按学号查询排名和考试成绩*/
void NameforSortandScore(STUDENT stu[],int n,char Name[],int score[],int sort[]);/*按姓名查询排名和考试成绩*/
void Classify(STUDENT stu[],int n);/*统计各个级别的人数*/
void Listrecord(STUDENT stu[],int n,int sumCourse[4],float aveCourse[4]);/*输出每个学生的学号·姓名·各科考试成绩，以及每门课程的总分和平均分*/
void WritetoFile(STUDENT stu[],int n);/*将每个学生的记录信息写入文件*/
int ReadfromFile(STUDENT stu[]);/*从文件中读出每个学生的记录信息并显示*/ 
void Printfscore(STUDENT stu[],int n);/*输出从文件中读出的信息到屏幕上*/
void setnumber(char *Account_Number,char *Secret_Code);/*设定密码*/ 
void smile(void); 
int main()
{
	int sumCourse[4];/*单门课程总分*/
	float aveCourse[4];/*单门课程平均分*/
    int n;/*人数*/
	int sign,i;
	int score[4],sort[2];
	long ID;
	char Name[10];
    char Account_Number[CodeLength],Secret_Code[CodeLength],number[CodeLength],code[CodeLength];
	setnumber(Account_Number,Secret_Code);/*设定密码*/ 
    printf("您一共有3次输入用户名和密码的机会\n");
	printf("*（用户名和密码均为10位）*\n");
	for(i=1;i<=3;i++)
	{
		if(i==1)
			getchar(); 
		printf("请输入您的学号:");
		gets(number);
		printf("请输入您的密码:");
		gets(code);
		if(strcmp(number,Account_Number)==0&&strcmp(code,Secret_Code)==0)
			break;
		else
			printf("您的用户名或密码错误!请重新输入\n");
			continue;
	}
	if(i==4)
	{
		exit(1);
	}
	printf("\t\t\tW e l c o m e ！\t\t\t\t\n");
	printf("\t\t版    本\tv6.0\t\t\n");
	printf("\t\t更新时间\t2017.5.14\t\t\n");
	printf("\t\t学    院\t航天学院\t\t\n");
    printf("\t\t专业班级\t电子1621003班\t\t\n");
    printf("\t\t姓    名\t韩    枭\t\t\n");
    printf("\t\t学    号\t1162100330\t\t\n");
    printf("\t\t指导教师\t郭    萍\t\t\n");
	printf("\t\t\t--------\t\t\n");
    printf("\t\t\t使用说明\t\t\n");
    printf("\t\t\t--------\t\t\n");
	printf("\n");
    printf("\t ----------------------------------------------\n");
	printf("\t|| 本系统用于输入学生的个人信息（学号，姓名，成||\n");
	printf("\t|| 绩），可以得到学生的平均分，总分，排名等信息||\n");
    printf("\t ----------------------------------------------\n");
	printf("**********************************************************************\n");
	printf("请输入学生人数:");
	scanf("%d",&n);
	STUDENT stu[N];
	for(i=1;i<=20;i++)
	{
	printf("@-------------------------------------------------------------------------@");
	printf("\t\t1.输入学生的信息\t\t2.计算每门课程的总分和平均分\n");/*输入学生的信息*/
	printf("\n");
	
	printf("\t3.计算学生的总分和平均分\t4.总分由高到低排出名次表\n");/*计算学生的总分和平均分*/
printf("\n");
	
	printf("\t5.总分由低到高排出名次表\t6.按学号由小到大排序\n");/*总分由低到高排出名次表*/
printf("\n");
	
    printf("\t7.按姓名的字典顺序排出成绩表\t8.按学号查询排名和考试成绩\n");/*按姓名的字典顺序排出成绩表*/
printf("\n");
    
    printf("\t9.按姓名查询排名和考试成绩\t10.统计各级学生人数并画出柱状图\n");/*按姓名查询排名和考试成绩*/
printf("\n");
    
    printf("\t11.输出每个学生的学号·姓名·各科考试成绩，以及每门课程的总分和平均分\n");/*输出每个学生的学号·姓名·各科考试成绩，以及每门课程的总分和平均分*/
printf("\n");
    printf("\t12.将每个学生的记录信息写入文件\t13.从文件中读出每个学生的记录信息并显示\n");/*将每个学生的记录信息写入文件*/
printf("\n");
   
	printf("\t0.Exit\n");
	printf("@-------------------------------------------------------------------------@");
printf("\n");
	printf("请选择:");
	scanf("%d",&sign);
    switch(sign)
	{
		case 1:
	        InputScore(stu,n);/*输入学生的信息*/
		    smile();
			printf("\n");
			continue;
		case 2:
	        AverforScore(stu,sumCourse,aveCourse,n);/*计算每门课程的总分和平均分*/
			printf("数学总分=%d \t数学平均分=%6.1f\n",sumCourse[1],aveCourse[1]);
	        printf("英语总分=%d \t英语平均分=%6.1f\n",sumCourse[2],aveCourse[2]);
	        printf("物理总分=%d \t物理平均分=%6.1f\n",sumCourse[3],aveCourse[3]); 
			continue;
		case 3:
	        AverforStudent(stu,n);/*计算学生的总分和平均分*/
			for(i=1;i<=n;i++)
			{
				printf("学号:%ld 总分:%d 平均分:%6.1f\n",stu[i].studentID,stu[i].sum,stu[i].aver);
			
			}
			continue;
		case 4:
	        DatasortDescend(stu,n);/*总分由高到低排出名次表*/
	        printf("排名\t学号\t姓名\t数学\t物理\t英语\t总分\t均分\n");
			for(i=1;i<=n;i++)
			{
				printf("%d\t%ld\t%s\t%d\t%d\t%d\t%d\t%.1f\n",i,stu[i].studentID,stu[i].studentName,stu[i].mark.MT,stu[i].mark.PH,stu[i].mark.EN,stu[i].sum,stu[i].aver); 
			} 
			continue;
		case 5:
	        DatasortAscend(stu,n);/*总分由低到高排出名次表*/
	        for(i=1;i<=n;i++)
			{
				printf("%d\t%ld\t%s\t%d\t%d\t%d\t%d\t%.1f\n",i,stu[i].studentID,stu[i].studentName,stu[i].mark.MT,stu[i].mark.PH,stu[i].mark.EN,stu[i].sum,stu[i].aver); 
			} 
			continue;
		case 6:
	        Idsort(stu,n);/*按学号由小到大排序*/
	       	printf("排名\t学号\t姓名\t数学\t物理\t英语\n");
			for(i=1;i<=n;i++)
			{
				printf("%d\t%ld\t%s\t%d\t%d\t%d\n",i,stu[i].studentID,stu[i].studentName,stu[i].mark.MT,stu[i].mark.PH,stu[i].mark.EN); 
			} 
			continue;
		case 7:
	        SortString(stu,n);/*按姓名的字典顺序排出成绩表*/
	       	printf("排名\t学号\t姓名\t数学\t物理\t英语\n");
			for(i=1;i<=n;i++)
			{
				printf("%d\t%ld\t%s\t%d\t%d\t%d\n",i,stu[i].studentID,stu[i].studentName,stu[i].mark.MT,stu[i].mark.PH,stu[i].mark.EN); 
			} 
			continue;
		case 8:
			printf("请输入要查找的学生的学号:\n");/*按学号查询排名和考试成绩*/
		    scanf("%ld",&ID);
	        IDforSortandScore(stu,n,ID,score,sort);
			printf("名次: %d ,数学: %d ,英语: %d ,物理: %d\n",sort[1],score[1],score[2],score[3]);
	        AverforScore(stu,sumCourse,aveCourse,n);/*计算每门课程的总分和平均分*/
			if(score[1]<aveCourse[1])
			{
				printf("数学要加油\n");
			}
			if(score[2]<aveCourse[2])
			{
				printf("英语还不够好哦\n");
			}
	        if(score[3]<aveCourse[3])
			{
				printf("物理要努力\n");
			}
			continue;
		case 9:
	        printf("请输入要查找的学生的姓名:\n");/*按姓名查询排名和考试成绩*/
			scanf("%s",Name);
	        NameforSortandScore(stu,n,Name,score,sort);
		    printf("名次: %d ,数学: %d ,英语: %d ,物理: %d\n",sort[1],score[1],score[2],score[3]);
	        AverforScore(stu,sumCourse,aveCourse,n);/*计算每门课程的总分和平均分*/
	        if(score[1]<aveCourse[1])
			{
				printf("数学要加油\n");
			}
			if(score[2]<aveCourse[2])
			{
				printf("英语还不够好\n");
			}
	        if(score[3]<aveCourse[3])
			{
				printf("物理要努力\n");			
			}
			continue;
		case 10:
	        Classify(stu,n);/*统计各个级别的人数*/
			continue;
		case 11:
	        Listrecord(stu,n,sumCourse,aveCourse);/*输出每个学生的学号·姓名·各科考试成绩，以及每门课程的总分和平均分*/
	        continue;
		case 12:
	        WritetoFile(stu,n);/*将每个学生的记录信息写入文件*/
			continue;
		case 13:
	        n=ReadfromFile(stu);/*从文件中读出每个学生的记录信息并显示*/
			continue;
		case 0:
			return 0;
		default:
			exit(1);
		
		}
    }
    return 0;
}
void smile(void)//笑脸 
{
	printf("\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1");
}
void smile1(void)//笑脸 
{
	printf("\1");
}
void NameforSortandScore(STUDENT stu[],int n,char x[],int score[],int sort[])/*按姓名查询排名和考试成绩*/
{
	int low,high,mid;
    AverforStudent(stu,n);
    DatasortDescend(stu,n);
    SortString(stu,n);
	//printf("%ld",stu[1].studentID);
	low=1;
	high=n;
	while(low<=high)
	{
		mid=(high+low)/2;
		
		if(strcmp(x,stu[mid].studentName)>0)
		{
			low=mid+1;
		}
		else if(strcmp(x,stu[mid].studentName)<0)
		{
			high=mid-1;
		
		}
		else
		{
			score[1]=stu[mid].mark.MT;
			score[2]=stu[mid].mark.EN;
			score[3]=stu[mid].mark.PH;
			sort[1]=stu[mid].sort;
			//printf("%d",score[1]);
			break;
		}
	}
}
void InputScore(STUDENT stu[],int n)/*输入学生的信息*/
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		printf("输入第%d个学生的信息:\n",i);
		scanf("%ld",&stu[i].studentID);
	    scanf("%s",stu[i].studentName);
        scanf("%d",&stu[i].mark.MT);
        scanf("%d",&stu[i].mark.EN);
        scanf("%d",&stu[i].mark.PH);
	}
}
int ReadfromFile(STUDENT stu[])/*从文件中读出每个学生的记录信息并显示*/ 
{
    FILE *fp;
	int i,n;
	if((fp=fopen("student.txt","r"))==NULL)
	{
		printf("Failure to open student.txt!\n");
		exit(0);
	
	}
	for(i=0;!feof(fp);i++)
	{
		fread(&stu[i],sizeof(STUDENT),1,fp);
	}
	fclose(fp);
	printf("Total student is %d.\n",i-1);
	n=i-1;
    Printfscore(stu,n);/*输出从文件中读出的信息到屏幕上*/
	return i-1;
}
void AverforScore(STUDENT stu[],int sumCourse[],float averCourse[],int n)/*计算每门课程的总分和平均分*/
{
	int j;
	sumCourse[1]=0;sumCourse[2]=0;sumCourse[3]=0;
	averCourse[1]=0;averCourse[2]=0;averCourse[3]=0;
	for(j=1;j<=n;j++)
	{
		sumCourse[1]=sumCourse[1]+stu[j].mark.MT;
		sumCourse[2]=sumCourse[2]+stu[j].mark.EN;
        sumCourse[3]=sumCourse[3]+stu[j].mark.PH;
	
	}
	averCourse[1]=(float)sumCourse[1]/n;
    averCourse[2]=(float)sumCourse[2]/n;
    averCourse[3]=(float)sumCourse[3]/n; 
}
void IDforSortandScore(STUDENT stu[],int n,long x,int score[],int sort[])/*按学号查询排名和考试成绩*/
{
	int low,high,mid;
    AverforStudent(stu,n);
    DatasortDescend(stu,n);
    Idsort(stu,n);
	//printf("%ld",stu[1].studentID);
	low=1;
	high=n;
	while(low<=high)
	{
		mid=(high+low)/2;
		
		if(x>stu[mid].studentID)
		{
			low=mid+1;
		}
		else if(x<stu[mid].studentID)
		{
			high=mid-1;
		
		}
		else
		{
			score[1]=stu[mid].mark.MT;
			score[2]=stu[mid].mark.EN;
			score[3]=stu[mid].mark.PH;
			sort[1]=stu[mid].sort;
			//printf("%d",score[1]);
			break;
		}
	}
}

void SortString(STUDENT stu[],int n)/*按姓名的字典顺序排出成绩表*/
{
	int i,j,k;
	STUDENT temp;
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			if(strcmp(stu[j].studentName,stu[k].studentName)<0)
			{
				k=j;
			}
		}
		if(k!=i)
		{
				temp=stu[k];stu[k]=stu[i];stu[i]=temp;
		}
	}
}
void AverforStudent(STUDENT stu[],int n)/*计算学生的总分和平均分*/
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		stu[i].sum=stu[i].mark.MT+stu[i].mark.EN+stu[i].mark.PH;
		stu[i].aver=(float)stu[i].sum/3;
	}
}
void WritetoFile(STUDENT stu[],int n)/*将每个学生的记录信息写入文件*/
{
    
    AverforStudent(stu,n);
	DatasortDescend(stu,n);
	FILE *fp;
	if((fp=fopen("student.txt","w"))==NULL)
	{
		printf("Failure to open student.txt!\n");
		exit(0);
	}
	fwrite(stu,sizeof(STUDENT),n,fp);
	fclose(fp);
	printf("成功储存于当前文件夹的student.txt中，您可以打开查看\n"); 
}
void Printfscore(STUDENT stu[],int n)/*输出从文件中读出的信息到屏幕上*/
{
	int i;
	printf("学号\t姓名\t数学\t英语\t物理\t平均分\t总分\t排名\n");
	for(i=1;i<=n;i++)
	{
		printf("%ld\t%s\t%d\t%d\t%d\t%.1f\t%d\t%d\n",stu[i].studentID,stu[i].studentName,stu[i].mark.MT,stu[i].mark.EN,stu[i].mark.PH,stu[i].aver,stu[i].sum,stu[i].sort);
	}
}
void Listrecord(STUDENT stu[],int n,int sumCourse[4],float aveCourse[4])/*输出每个学生的学号·姓名·各科考试成绩，以及每门课程的总分和平均分*/
{
   int i;
   AverforScore(stu,sumCourse,aveCourse,n);
   printf("学号\t姓名\t数学\t英语\t物理\n");
   for(i=1;i<=n;i++)
   {
       printf("%ld\t%s\t%d\t%d\t%d\n",stu[i].studentID,stu[i].studentName,stu[i].mark.MT,stu[i].mark.EN,stu[i].mark.PH);
   }
        printf("数学总分=%d\t数学平均分=%6.1f\n",sumCourse[1],aveCourse[1]);
        printf("英语总分=%d\t英语平均分=%6.1f\n",sumCourse[2],aveCourse[2]);
        printf("物理总分=%d\t物理平均分=%6.1f\n",sumCourse[3],aveCourse[3]); 
}
void Classify(STUDENT stu[],int n)/*统计各个级别的人数*/
{
	int a=0,b=0,c=0,d=0,e=0,i,mark,a1,b1,c1,d1,e1;
	for(i=1;i<=n;i++)
	{
		mark=stu[i].mark.MT/10;
		//printf("%d",mark);
		switch(mark)
		{
		case 10:
		case 9:
			a++;
			break;
		case 8:
			b++;
			break;
		case 7:
			c++;
			break;
		case 6:
			d++;
			break;
		case 5:
        case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			e++;
			break;
		}
	}
	a1=(float)a/n*100;b1=(float)b/n*100;c1=(float)c/n*100;d1=(float)d/n*100;e1=(float)e/n*100;
	printf("数学成绩柱状图\n");
	for(i=1;i<=a;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("优秀:共%d人,%d%%\n",a,a1);
    for(i=1;i<=b;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("良好:共%d人,%d%%\n",b,b1);
    for(i=1;i<=c;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("中等:共%d人,%d%%\n",c,c1);
    for(i=1;i<=d;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("及格:共%d人,%d%%\n",d,d1);
    for(i=1;i<=e;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("及格:共%d人,%d%%\n",e,e1);
	//printf("优秀:%d,%d 良好:%d,%d 中等:%d,%d 及格:%d,%d 不及格:%d,%d",a,a1,b,b1,c,c1,d,d1,e,e1);
    a=0;b=0;c=0;d=0;e=0;a1=0;b1=0;c1=0;d1=0;e1=0;
	for(i=1;i<=n;i++)
	{
		mark=stu[i].mark.EN/10;
		//printf("%d",mark);
		switch(mark)
		{
		case 10:
		case 9:
			a++;
			break;
		case 8:
			b++;
			break;
		case 7:
			c++;
			break;
		case 6:
			d++;
			break;
		case 5:
        case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			e++;
			break;
		}
	}
	a1=(float)a/n*100;b1=(float)b/n*100;c1=(float)c/n*100;d1=(float)d/n*100;e1=(float)e/n*100;
	printf("物理成绩柱状图\n");
	for(i=1;i<=a;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("优秀:共%d人,%d%%\n",a,a1);
    for(i=1;i<=b;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("良好:共%d人,%d%%\n",b,b1);
    for(i=1;i<=c;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("中等:共%d人,%d%%\n",c,c1);
    for(i=1;i<=d;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("及格:共%d人,%d%%\n",d,d1);
    for(i=1;i<=e;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("不及格:共%d人,%d%%\n",e,e1);
    a=0;b=0;c=0;d=0;e=0;a1=0;b1=0;c1=0;d1=0;e1=0;
	for(i=1;i<=n;i++)
	{
		mark=stu[i].mark.PH/10;
		//printf("%d",mark);
		switch(mark)
		{
		case 10:
		case 9:
			a++;
			break;
		case 8:
			b++;
			break;
		case 7:
			c++;
			break;
		case 6:
			d++;
			break;
		case 5:
        case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			e++;
			break;
		}
	}
	a1=(float)a/n*100;b1=(float)b/n*100;c1=(float)c/n*100;d1=(float)d/n*100;e1=(float)e/n*100;
	printf("英语成绩柱状图\n");
	for(i=1;i<=a;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("优秀:共%d人,%d%%\n",a,a1);
    for(i=1;i<=b;i++)
	{
		smile1();	
	}
	printf("\t\t\t");
	printf("良好:共%d人,%d%%\n",b,b1);
    for(i=1;i<=c;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("中等:共%d人,%d%%\n",c,c1);
    for(i=1;i<=d;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("及格:共%d人,%d%%\n",d,d1);
    for(i=1;i<=e;i++)
	{
		smile1();
	}
	printf("\t\t\t");
	printf("不及格:共%d人,%d%%\n",e,e1);
}
void DatasortAscend(STUDENT stu[],int n)/*总分由低到高排出名次表*/
{
    int i,j,k;
	STUDENT temp;
	AverforStudent(stu,n);
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			if(stu[j].sum<stu[k].sum)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=stu[k];stu[k]=stu[i];stu[i]=temp;
			
		}
	}
}
void DatasortDescend(STUDENT stu[],int n)/*总分由高到低排出名次表*/
{
    int i,j,k;
	STUDENT temp;
	AverforStudent(stu,n);
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			if(stu[j].sum>stu[k].sum)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=stu[k];stu[k]=stu[i];stu[i]=temp;
		}
	}
	for(i=1;i<=n;i++)
	{
		stu[i].sort=i;
	}
	//printf("第名是%d\n",stu[2].sort);
}
void Idsort(STUDENT stu[],int n)/*按学号由小到大排序*/
{
	int i,j,k;
	STUDENT temp;
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			if(stu[j].studentID<stu[k].studentID)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=stu[k];stu[k]=stu[i];stu[i]=temp;
		}
	}
}
void setnumber(char *Account_Number,char *Secret_Code)
{
	char set,HistoryAccount[CodeLength],HistorySecret[CodeLength],ScanAccount[CodeLength],ScanSecret[CodeLength]; 
	FILE *fp;
	while(1)
	{
		printf("\n----------------不华丽的分界线--------------\n\n"); 
		printf("是否重新设定用户学号和密码？（输入Y/y代表是,N/n代表否）\n");
		printf("如果你的电脑是第一次运行此程序，则初始化数据为:学号：1162100330 密码：6666666666");
		fp=fopen("Account.txt","r");
		if(fp==NULL)
		{
			fp=fopen("Account.txt","w");
			fprintf(fp,"%s\n%s","1162100330","6666666666");	
		}
		fclose(fp);
		scanf("%c",&set);  
		if(set=='Y'||set=='y')
		{ 
			fp=fopen("Account.txt","r");
			if(fp==NULL)
			{
				printf("\t打开用户信息文件失败，请重试");
				return; 
			}
			printf("为确定是本人操作，请输入最近一次设定的学号和用户名，记得用回车或空格隔开哟:\n");
			fscanf(fp,"%s%s",HistoryAccount,HistorySecret);
			scanf("%s",ScanAccount); 
			scanf("%s",ScanSecret);
			if(strcmp(HistoryAccount,ScanAccount)==0&&strcmp(HistorySecret,ScanSecret)==0)
			{ 
				printf("请输入您新的10位学号：");
				scanf("%s",Account_Number); 
				printf("请输入您新的10位密码：");
				scanf("%s",Secret_Code); 
				fp=fopen("Account.txt","w");
				fprintf(fp,"%s\n%s",Account_Number,Secret_Code);
				fclose(fp);
				printf("用户信息设定成功！"); 
			}
			else
			{
				printf("只有用户本人才可以修改用户信息哟\1\n\n");
				exit(0);
			}
			break;
		}
		//如果没有重新输入则打开先前写入的文件或系统文件 
		else if(set=='N'||set=='n')
		{
			fp=fopen("Account.txt","r");
			if(fp==NULL)
			{
				printf("打开用户信息文件失败，请重试");
				return; 
			}
			printf("读取最近一次的用户信息"); 
			fscanf(fp,"%s%s",Account_Number,Secret_Code);
			fclose(fp);
			break;
		}
		else
		{
			printf("输错东西了额……");
			exit(0);
		}
	}
	printf("\n----------------不华丽的分界线--------------\n\n");
} 





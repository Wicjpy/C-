#include<stdio.h>#include<stdlib.h>#include<string.h>#define N 30#define CodeLength 6typedef struct course{ int MT;/*数学*/ int EN;/*英语*/ int PH;/*物理*/
}COURSE;typedef struct student{ long studentID;/*学号*/ char studentName[10];/*姓名*/ COURSE mark;/*成绩*/ float aver;/*平均分*/ int sum;/*总分*/ int sort;/*排名*/}STUDENT;

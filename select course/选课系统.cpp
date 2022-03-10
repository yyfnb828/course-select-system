#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_STU 10
#define SIZE_COU 10
#define SIZE_SEL 10
#define SIZE_GRA 10 
//函数声明部分
void home(void);//主函数部分 
void stu_operate(void);//学生操作部分菜单
void cou_operate(void);//课程操作部分菜单 
void statistic(void);//统计函数 
void choose(void);//选课函数 
void delete_sel(int);//删除选课函数 
//--学生信息部分：
void input_stu(void);//增加学生信息 
void search_stu(void);//搜索学生信息 
void search_stu_id(void);//通过id搜索学生信息 
void search_stu_name(void);//通过姓名查找学生信息 
void show_stu(void);//将系统中学生信息展示 
void edit_stu(void);//编辑学生信息 
void renew_stu(void);//更新学生信息保存到文件 
void delete_stu(void);//删除学生信息 
void readfile_student(void);//从文件导入学生信息 
//--课程信息部分：
void input_cou(void);//增加课程信息 
void search_cou(void);//搜索课程信息 
void search_cou_id(void);//通过id搜索课程 
void search_cou_name(void);//通过课程名搜索课程 
void show_cou(void);//展示所有课程 
void edit_cou(void);//编辑课程信息 
void renew_cou(void);//更新课程信息保存到文件 
void delete_cou(void);//删除课程信息 
void readfile_course(void);//从文件导入课程信息 
//--选课信息部分：
void readfile_select(void);//从文件导入选课信息 
void input_grade(void);//录入学生成绩
void show_grade(void); //查询学生成绩 
void renew_select(void);//更新选课信息到文件 
//--成绩信息部分：
void input_grade(void);//课程打分
void renew_grade(void);//保存成绩到文件 
void readfile_grade(void);//从文件导入成绩信息
void out_grade(void);//学生查询自己成绩 
/*学生信息结构体*/
struct student_info {
    char stu_ID[9];//学生ID 
    char stu_name[10];//学生姓名 
    char sex[9];//学生性别 
}stu[SIZE_STU];

/*课程信息结构体*/
struct course_info {
    char course_ID[9];//课程ID 
    char course_name[9];//课程名称 
    char credit[9];//课程学分 
}cou[SIZE_COU];

/*选课记录结构体*/
struct select_info {
    int s;//存放学生信息的数组下标
    int c;//存放课程信息的数组下标
}sel[SIZE_SEL];
/*储存成绩结构体*/ 
struct grade_info{
	int student;//存放学生信息数组下标 
	int course;//存放课程信息数组下标 
	int number;//存放成绩 
}gra[SIZE_GRA];

//全局变量i,j,x分别是学生,课程,选课信息数组下标
int i = -1;
int j = -1;
int x = -1;
int y = 0;
int main(void){
    //进入欢迎界面
    system("cls");
        readfile_course();
	    readfile_student();
	    readfile_select();
	    readfile_grade();
    home();
    return 0;
}
void readfile_course(void) 
{
	int a=0;
	    FILE * fp;
	    fp = fopen("D:\\dev_c\\xuanke.txt","r+");
	    
	    //--打开课程文件 
	    while(!feof(fp))
	    {
			 fscanf(fp,"%s %s %s",&cou[a].course_ID,&cou[a].course_name,&cou[a].credit);
			 a++;
			 j++;//全局变量++ 
		}
		j--;
	    fclose(fp);
}
void readfile_student(void)
{
	int a=0;
	    FILE * fp;
	    fp = fopen("D:\\dev_c\\student.txt","r+");

	    while(!feof(fp))
		{
			fscanf(fp,"%s %s %s",&stu[a].stu_ID,&stu[a].stu_name,&stu[a].sex);
			a++;
			i++;
		}
		i--;
	    fp = fopen("D:\\dev_c\\student.txt","a+");
fclose(fp);
}

void readfile_select(void)
{
	int a=0;
	FILE * fp;
	fp = fopen("D:\\dev_c\\chengji.txt","r+");
	while(!feof(fp))
	{
		fscanf(fp,"%d %d",&sel[a].s,&sel[a].c);
		a++;
		x++;
	}
	x--;
	fp = fopen("D:\\dev_c\\chengji.txt","a+");
	fclose(fp);
}
void readfile_grade(void)
{
		int a=0;
		FILE * fp;
		fp = fopen("D:\\dev_c\\number.txt","r+");
		while(!feof(fp))
		{
			fscanf(fp,"%d %d %d",&gra[a].student,&gra[a].course,&gra[a].number);
			a++;
			y++;
		}
		y--;
		fp = fopen("D:\\dev_c\\chengji.txt","a+");
		fclose(fp);
} 
//欢迎界面
void home(void) {
    printf("\n-------------------------欢迎进入选课系统！----------------------");
    int h;
    printf("\n\n                        请选择你要进行的操作：");
    printf("\n\n                             1.学生操作");
    printf("\n                             2.课程操作");
    printf("\n                             3.开始选课");
    printf("\n                             4.选课统计");
    printf("\n                             5.退出系统");
    printf("\n                                                      ");
    printf("\n                        请输入：");
    scanf("%d",&h);
    system("cls");
    switch(h){
        case 1:
            stu_operate();
            break;
        case 2:
            cou_operate();
            break;
        case 3:
            choose();
            break;
        case 4:
            statistic();
            break;
        default:
            system("cls");
            printf("BYE!");
            break;
    }
}
/*开始选课*/
void choose(void){
	char flag;
	FILE * fp;
	    //--判断文件是否为空
	    fp = fopen("D:\\dev_c\\chengji.txt","r+");
	    flag = fgetc(fp);
	    if(fp == NULL)
		{
	        printf("打开文件失败！");
	        system("cls");
	        home;
	    }
    char stu_id[10],cou_id[10];
    printf("\n-------------------------欢迎进入选课系统！----------------------");
    //输入选课学生信息
    printf("\n\n                 请输入选课人学号：");
    fflush(stdin);//清空输入缓冲区 
    scanf("%s",stu_id);
    int h = 0;
    flag=0;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_ID,stu_id)==0){
            flag = 0;
            break;
        } else {
            flag = 1;
        }
    }
    if(flag||i==-1){
        printf("\n                 不存在此学号\n");
        system("pause");
        system("cls");
        home();
    }
    //录入姓名信息
    x++;
    sel[x].s = h;
    //输入课程信息
    printf("\n\n                 请输入选修课程号：");
    fflush(stdin);
    scanf("%s",cou_id);
    flag = 0;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_ID,cou_id)==0){
            flag = 0;
            break;
        } else {
            flag = 1;
        }
    }
    if(flag||j==-1){
        printf("\n                 不存在此课程号\n");
        x--;
        system("pause");
        system("cls");
        home();
    }
    //录入课程信息
        sel[x].c = h;
        fp = fopen("D:\\dev_c\\chengji.txt","a");
            fprintf(fp,"%d\t%d",sel[x].s,sel[x].c);
	        fflush(stdin);
    printf("\n                 录入成功!\n");
    renew_select();
    system("pause");
    system("cls");
    
    
    home();
}
/*删除选课记录*/
void delete_sel(int q){
    int h;
    for(h = q;q < x;h++){
        q++;
        sel[h].c = sel[q].c;
        sel[h].s = sel[q].s;
    }

}
//对学生记录进行操作
void stu_operate(void) {
    printf("\n-------------------------欢迎进入选课系统！----------------------");
    printf("\n\n                 请选择你要对学生记录进行的操作：");
    printf("\n\n                             1.添加");
    printf("\n                             2.查询");
    printf("\n                             3.显示");
    printf("\n                             4.成绩查询");
    printf("\n                             5.返回主页面");
    printf("\n                                                      ");
    printf("\n                        请输入：");
    int i;
    scanf("%d",&i);
    system("cls");
    switch(i){
        case 1://添加学生信息
            input_stu();
            break;
        case 2://查询学生信息
            search_stu();
            break;
        case 3://显示所有学生信息
            show_stu();
            break;
        case 4:
            out_grade();
	        break;
        case 5:
            home();
            break;
    }
}
//对课程记录进行操作
void cou_operate(void) {
    printf("\n-------------------------欢迎进入选课系统！----------------------");
    printf("\n\n                 请选择你要对课程记录进行的操作：");
    printf("\n\n                             1.添加课程");
    printf("\n                             2.查询课程");
    printf("\n                             3.显示全部课程");
    printf("\n                             4.录入成绩");
    printf("\n                             5.返回主页面");
    printf("\n                                                      ");
    printf("\n                        请输入：");
    int i;
    scanf("%d",&i);
    system("cls");
    switch(i){
        case 1:
            input_cou();
            break;
        case 2:
            search_cou();
            break;
        case 3:
            show_cou();
        case 4:
			input_grade(); 
        case 5:
            home();
            break;
    }
}
//选课信息统计记录
void statistic(void){
    printf("\n-------------------------欢迎进入选课系统！----------------------");
    printf("\n\n                     共有学生信息：%d 条",i+1);
    printf("\n                     共有课程信息：%d 条",j+1);
    if(x == -1){
        printf("\n                       选课记录：0 条");
        printf("\n\n                     ");
        system("pause");
        system("cls");
        home();
    } else {
        printf("\n\n                        选课记录 %d 条：",x+1);
        int m;
        for(m = 0;m <= x;m++){
            printf("\n                     ================");
            printf("\n                     第%d条",m+1);
            printf("\n                     学生学号：%s",stu[sel[m].s].stu_ID);
            printf("\n                     学生姓名：%s",stu[sel[m].s].stu_name);
            printf("\n                     课程号：%s",cou[sel[m].c].course_ID);
            printf("\n                     课程名：%s",cou[sel[m].c].course_name);
        }
        printf("\n\n            ");
        system("pause");
        system("cls");
        home();
    }

}


//--------------------------------------学生信息插入--------------------------------------
void input_stu(void){
    char flag;
    FILE * fp;
    //--判断文件是否为空
    fp = fopen("D:\\dev_c\\student.txt","r+");
    flag = fgetc(fp);
    if(flag==EOF){
        printf("学号\t姓名\t性别\n");
    }
    fclose(fp);
    fp = fopen("D:\\dev_c\\student.txt","r+");
    if(fp == NULL){
        printf("打开文件失败！");
        system("cls");
        stu_operate();
    }
    printf("学号\t姓名\t性别\n");
    while(1){
        i++;
        scanf("%s %s %s",&stu[i].stu_ID,&stu[i].stu_name,&stu[i].sex);
        //--数据查重
        int h;
        for(h = 0;h < i;h++){
            if(i == 0) break;//第一条数据不需要查重
            if (strcmp(stu[h].stu_ID,stu[i].stu_ID)==0) {
                printf("该学号已存在，请重新输入！\n");
                scanf("\n%s %s %s\n",&stu[i].stu_ID,&stu[i].stu_name,&stu[i].sex);
                h = -1;
            }
        }
        //--
        fprintf(fp,"%s\t%s\t%s",stu[i].stu_ID,stu[i].stu_name,stu[i].sex);
        printf("\n录入成功，继续录入输入y，返回上一级请按任意键：");
        fflush(stdin);
        scanf("%c",&flag);
        fclose(fp);
        if(flag!='y'&&'Y') break;
        fp = fopen("D:\\dev_c\\student.txt","a");
    }
    renew_stu();
    system("cls");
    stu_operate();
}
/*查询学生信息*/
void search_stu(void){
    system("cls");
    printf("\n请选择查询方式：");
    printf("\n  1.学号查询");
    printf("\n  2.姓名查询");
    printf("\n请选择：");
    int h;
    scanf(" %d",&h);
    switch(h){
        case 1:
            search_stu_id();
            break;
        case 2:
            search_stu_name();
            break;

    }
}
/*学号查询*/
void search_stu_id(void){
    system("cls");
    char id[9];
    printf("\n输入学生的学号:");
    fflush(stdin);
    scanf("%s",id);
    int h;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_ID,id)==0){
            system("cls");
            printf("查找成功!");
            printf("\n\n\t学号\t姓名\t性别");
            printf("\n\t-----------------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
            system("pause");
            system("cls");
            stu_operate();
        }
    }
    system("cls");
    printf("没有此学号！\n");
    system("pause");
    system("cls");
    stu_operate();
}
/*姓名查询*/
void search_stu_name(void){
    system("cls");
    char name[9];
    printf("\n输入学生的姓名:");
    fflush(stdin);
    scanf("%s",name);
    int h;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_name,name)==0){
            system("cls");
            printf("查找成功!");
            printf("\n\n\t学号\t姓名\t性别");
            printf("\n\t---------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
            system("pause");
            system("cls");
            stu_operate();
        }
    }
    system("cls");
    printf("没有此姓名！");
    system("pause");
    system("cls");
    stu_operate();
}
/*显示所有学生信息*/
void show_stu(void){
    int h;
    if(i == -1){
        printf("\n还没有录入信息！\n");
        system("pause");
        system("cls");
        stu_operate();
    }
    system("cls");
    printf("\n\n\t学号\t姓名\t性别");
    printf("\n\t---------------------------------------------------------");
    for(h = 0;h <= i;h++){
        printf("\n\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
    }
    //
    fflush(stdin);
    printf("\n\t1.修改");
    printf("\n\t2.删除");
    printf("\n\t3.返回");
    printf("\n\n  选择要进行的操作：");
    int flag;
    fflush(stdin);
    scanf("%d",&flag);
    switch(flag){
        case 1:
            edit_stu();
            break;
        case 2:
            delete_stu();
            break;
        default:
            system("cls");
            stu_operate();
            break;

    }
}
/*编辑学生信息*/
void edit_stu(void){
    printf("\n输入需要编辑的学生的学号：");
    char id[10];
    getchar();
    scanf("%s",id);
    int h;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_ID,id)==0){//找到需要编辑的行
            system("cls");
            printf("\n\n\t学号\t姓名\t性别");
            printf("\n\t---------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
            printf("\n这是修改前的数据，请依次输入修改值：\n\t");
            fflush(stdin);
            scanf("%s %s %s",&stu[h].stu_ID,&stu[h].stu_name,&stu[h].sex);
            int k;
            for(k = 0;k <= i;k++){
                if(strcmp(stu[k].stu_ID,stu[h].stu_ID)==0){
                    if(k==h){
                        continue;
                    } else {//学号不唯一
                        printf("\n此学号已存在！重新输入学号：");
                        fflush(stdin);
                        scanf("%s",&stu[h].stu_ID);
                        k = -1;
                    }
                }
            }
            /*将修改信息写入文件*/
            //思想：将原文件重新写入一遍
            renew_stu();
            system("cls");
            printf("修改成功！\n");
            system("pause");
            system("cls");
            stu_operate();
        }
    }
    printf("\n此学号不存在！\n");
    system("pause");
    system("cls");
    stu_operate();
}
/*删除学生信息*/
void delete_stu(void){
    printf("\n输入需要编辑的学生的学号：");
    char id[10];
    getchar();
    scanf("%s",id);
    int h;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_ID,id)==0){//找到需要编辑的行
            system("cls");
            //检查他/她是否选课了
            int a;
            for(a = 0;a <= x;a++){
                if(h==sel[a].s){//选课了则将对应课程记录减1,以及选课数组减1
                    delete_sel(a);
                    a = -1;
                    x--;
                    continue;
                }
            }
            //如果只有一条记录
            if(i==0){
                i = -1;
                renew_stu();
                printf("修改成功！\n");
                system("pause");
                system("cls");
                stu_operate();
            }

            int k;
            for(k = h+1;k <= i;k++,h++){//将数组直接向前移动
                strcpy(stu[h].stu_ID,stu[k].stu_ID);
                strcpy(stu[h].stu_name,stu[k].stu_name);
                strcpy(stu[h].sex,stu[k].sex);
            }
            /*将修改信息写入文件*/
            //思想：将原文件重新写入一遍
            renew_stu();
            i--;
            system("cls");
            printf("修改成功！\n");
            system("pause");
            system("cls");
            stu_operate();
        }
    }
    printf("\n此学号不存在！\n");
    system("pause");
    system("cls");
    stu_operate();
}
//--------------------------------------课程信息插入--------------------------------------
void input_cou(void){
    char flag;
    FILE * fp;
    //--判断文件是否为空
    fp = fopen("D:\\dev_c\\xuanke.txt","r+");
    flag = fgetc(fp);
    if(flag==EOF){
        printf("代码\t名称\t学分\n");
    }
    fclose(fp);
    //--
    fp = fopen("D:\\dev_c\\xuanke.txt","a+");
    if(fp == NULL){
        printf("打开文件失败！");
        system("cls");
        cou_operate();
    }
    printf("代码\t名称\t学分\n");
    while(1){
        j++;
        scanf("%s %s %s",&cou[j].course_ID,&cou[j].course_name,&cou[j].credit);
        //--数据查重
        int h;
        for(h = 0;h < j;h++){
            if(j == 0) break;//第一条数据不需要查重
            if (strcmp(cou[h].course_ID,cou[j].course_ID)==0) {
                printf("该课程号已存在，请重新输入！\n");
                scanf("\n%s %s %s",&cou[j].course_ID,&cou[j].course_name,&cou[j].credit);
                h = -1;
            }
        }
        //--
        fprintf(fp,"%s\t%s\t%s\t\t\n",cou[j].course_ID,cou[j].course_name,cou[j].credit);
        printf("\n录入成功，继续录入输入y，返回上一级请按任意键：");
        fflush(stdin);
        scanf("%c",&flag);
        fclose(fp);
        if(flag!='y'&&'Y') break;
        fp = fopen("D:\\dev_c\\xuanke.txt","a");
    }
    renew_cou();
    system("cls");
    cou_operate();
}
/*查询课程信息*/
void search_cou(void){
    system("cls");
    printf("\n请选择查询方式：");
    printf("\n  1.课程号查询");
    printf("\n  2.课程名查询");
    printf("\n请选择：");
    int h;
    scanf(" %d",&h);
    switch(h){
        case 1:
            search_cou_id();
            break;
        case 2:
            search_cou_name();
            break;

    }
}
/*课程号查询*/
void search_cou_id(void){
    system("cls");
    char id[9];
    printf("\n输入课程号:");
    fflush(stdin);
    scanf("%s",id);
    int h;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_ID,id)==0){
            system("cls");
            printf("查找成功!");
            printf("\n\n\t代码\t名称\t学分");
            printf("\n\t-----------------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\t\t\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);
            system("pause");
            system("cls");
            cou_operate();
        }
    }
    system("cls");
    printf("没有此课程号！\n");
    system("pause");
    system("cls");
    cou_operate();
}
/*课程名查询*/
void search_cou_name(void){
    system("cls");
    char name[9];
    printf("\n输入课程名:");
    fflush(stdin);
    scanf("%s",name);
    int h;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_name,name)==0){
            system("cls");
            printf("查找成功!");
            printf("\n\n\t代码\t名称\t学分");
            printf("\n\t---------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\t\t\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);
            system("pause");
            system("cls");
            cou_operate();
        }
    }
    system("cls");
    printf("没有此课程名！");
    system("pause");
    system("cls");
    cou_operate();
}
/*显示所有课程信息*/
void show_cou(void){
    int h;
    if(j == -1){
        printf("\n还没有录入信息！\n");
        system("pause");
        system("cls");
        cou_operate();
    }
    system("cls");
    printf("\n\n\t代码\t名称\t学分");
    printf("\n\t-------------------------------------------------------------");
    for(h = 0;h <= j;h++){
        printf("\n\t%s\t%s\t%s\t\t\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);
    }
    //
    fflush(stdin);
    printf("\n\t1.修改");
    printf("\n\t2.删除");
    printf("\n\t3.返回");
    printf("\n\n  选择要进行的操作：");
    int flag;
    fflush(stdin);
    scanf("%d",&flag);
    switch(flag){
        case 1:
            edit_cou();
            break;
        case 2:
            delete_cou();
            break;
        default:
            system("cls");
            cou_operate();
            break;

    }
}
/*编辑课程信息*/
void edit_cou(void){
    printf("\n输入需要编辑的课程号：");
    char id[10];
    getchar();
    scanf("%s",id);
    int h;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_ID,id)==0){//找到需要编辑的行
            system("cls");
            printf("\n\n\t代码\t名称\t学分");
            printf("\n\t-------------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);
            printf("\n这是修改前的数据，请依次输入修改值：\n\t");
            fflush(stdin);
            scanf("%s %s %s",&cou[h].course_ID,&cou[h].course_name,&cou[h].credit);
            int k;
            for(k = 0;k <= j;k++){
                if(strcmp(cou[k].course_ID,cou[h].course_ID)==0){
                    if(k==h){
                        continue;
                    } else {//课程号不唯一
                        printf("\n此课程号已存在，重新输入：");
                        fflush(stdin);
                        scanf("%s",&cou[h].course_ID);
                        k = -1;
                    }
                }
            }
            /*将修改信息写入文件*/
            //思想：将原文件重新写入一遍
            renew_cou();
            system("cls");
            printf("修改成功！\n");
            system("pause");
            system("cls");
            cou_operate();
        }
    }
    printf("\n此课程号不存在！\n");
    system("pause");
    system("cls");
    cou_operate();
}
/*删除课程信息*/
void delete_cou(void){
    printf("\n输入需要编辑的课程号：");
    char id[10];
    getchar();
    scanf("%s",id);
    int h;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_ID,id)==0){//找到需要编辑的行
            system("cls");
            //如果只有一条记录
            if(j==0){
                j = -1;
                renew_cou();
                printf("修改成功！\n");
                system("pause");
                system("cls");
                cou_operate();
            }
            int k;
            for(k = h+1;k <= j;k++,h++){//将数组直接向前移动
                strcpy(cou[h].course_ID,cou[k].course_ID);
                strcpy(cou[h].course_name,cou[k].course_name);
                strcpy(cou[h].credit,cou[k].credit);
            }
            /*将修改信息写入文件*/
            //思想：将原文件重新写入一遍
            renew_cou();
            j--;
            system("cls");
            printf("修改成功！\n");
            system("pause");
            system("cls");
            cou_operate();
        }
    }
    printf("\n此课程号不存在！\n");
    system("pause");
    system("cls");
    cou_operate();
}
void input_grade(void){
		char fla;
		FILE * fp;
		    //--判断文件是否为空
		    fp = fopen("D:\\dev_c\\chengji.txt","r+");
		    fla = fgetc(fp);
		    if(fp == NULL)
			{
		        printf("打开文件失败！");
		        system("cls");
		        home;
		    }
	char cou_id[10];
	int flag,h,g,m = 0;
	    printf("\n-------------------------欢迎进入选课系统！----------------------");
	    //输入课程信息
		    printf("\n\n                 请输入录入成绩课程号：\n");
		    fflush(stdin);
		    scanf("%s",cou_id);
		    flag = 0;
		    for(h = 0;h <= j;h++){
		        if(strcmp(cou[h].course_ID,cou_id)==0){
		            flag = 0;
		            break;
		        } else {
		            flag = 1;
		        }
		    }
		    if(flag||j==-1){
		        printf("\n                 不存在此课程号\n");
		        x--;
		        system("pause");
		        system("cls");
		        home();
		    }
		    for(int l=0; l<=x; l++)
		    {
				if(strcmp(cou[sel[l].c].course_ID,cou_id)==0)
				{
					m++;
				}
			}
			if(m == 0)
			{
				printf("\n                本课程还没有人选课\n");
				system("pause");
				system("cls");
				home();
			} 
				for(int j=0; j<=x; j++)
				{
					if(strcmp(cou[sel[j].c].course_ID,cou_id)==0)
					{
						gra[y].student = sel[j].s;
						gra[y].course = sel[j].c;
						printf("%s同学的%s课成绩为：",stu[sel[j].s].stu_name,cou[sel[j].c].course_name); 
						scanf("%d",&gra[y].number);
						        fp = fopen("D:\\dev_c\\number.txt","r+");
						            fprintf(fp,"%d\t%d\t%d\t\t\n",gra[y].student,gra[y].course,gra[y].number);
						            y++;
						    printf("\n                 录入成功!\n");
						    renew_grade();
					        fflush(stdin);
					}
				}
}
void out_grade(void)
{
	char flag;
		FILE * fp;
		    //--判断文件是否为空
		    fp = fopen("D:\\dev_c\\number.txt","r+");
		    flag = fgetc(fp);
		    if(fp == NULL)
			{
		        printf("打开文件失败！");
		        system("cls");
		        home;
		    }
		    char stu_id[10];
			    printf("\n-------------------------欢迎进入选课系统！----------------------");
			    //输入选课学生信息
			    printf("\n\n                 请输入选课人学号：");
			    fflush(stdin);//清空输入缓冲区 
			    scanf("%s",stu_id);
			    int h = 0;
			    flag=0;
			    for(h = 0;h <= i;h++){
			        if(strcmp(stu[h].stu_ID,stu_id)==0){
			            flag = 0;
			            break;
			        } else {
			            flag = 1;
			        }
			    }
			    if(flag||i==-1){
			        printf("\n                 不存在此学号\n");
			        system("pause");
			        system("cls");
			        home();
			    }
			    for(h=0; h<= y; h++)
			    {
					if(strcmp(stu[gra[h].student].stu_ID,stu_id)==0){
						if(gra[h].number!=0)
						{
							printf("%s : %d\n",cou[gra[h].course].course_name,gra[h].number);
						}
					}
				}
		    
}
//--功能函数
/*更新系统数据至文件*/
void renew_stu(void){
    FILE * fp;
    fp = fopen("D:\\dev_c\\student.txt","w+");
    if(fp == NULL){
        printf("\n打开文件失败,无法保存至文件。\n");
        fclose(fp);
        return ;
    }
    if(i == -1){
        fclose(fp);
        return;
    }
    int h;
    for(h = 0;h <= i;h++){
        fprintf(fp,"%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
    }
    fclose(fp);

}
void renew_cou(void){
    FILE * fp;
    fp = fopen("D:\\dev_c\\xuanke.txt","w+");
    if(fp == NULL){
        printf("\n打开文件失败,无法保存至文件。\n");
        fclose(fp);
        return ;
    }
    if(j == -1){
        fclose(fp);
        return;
    }
    int h;
    for(h = 0;h <= j;h++){
        fprintf(fp,"%s\t%s\t%s\t\t\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);    }
    fclose(fp);

}
void renew_select(void){
	FILE * fp;
	fp = fopen("D:\\dev_c\\chengji.txt","w+");
	if(fp == NULL){
		printf("\n打开文件失败，无法保存至文件。\n");
		fclose(fp);
		return ;
	}
	if(x == -1){
		fclose(fp);
		return ;
	}
	int h;
	for(h=0; h <=x; h++){
		fprintf(fp,"%d\t%d\t\t\n",sel[h].s,sel[h].c);
	}
	fclose(fp);
}
void renew_grade(void){
		FILE * fp;
		fp = fopen("D:\\dev_c\\number.txt","w+");
		if(fp == NULL){
			printf("\n打开文件失败，无法保存至文件。\n");
			fclose(fp);
			return ;
		}
		if(x == -1){
			fclose(fp);
			return ;
		}
		int h;
		for(h=0; h <=x; h++){
			fprintf(fp,"%d\t%d\t%d\t\t\n",gra[h].student,gra[h].course,gra[h].number);
		}
		fclose(fp);
}

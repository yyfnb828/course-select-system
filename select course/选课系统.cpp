#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_STU 10
#define SIZE_COU 10
#define SIZE_SEL 10
#define SIZE_GRA 10 
//������������
void home(void);//���������� 
void stu_operate(void);//ѧ���������ֲ˵�
void cou_operate(void);//�γ̲������ֲ˵� 
void statistic(void);//ͳ�ƺ��� 
void choose(void);//ѡ�κ��� 
void delete_sel(int);//ɾ��ѡ�κ��� 
//--ѧ����Ϣ���֣�
void input_stu(void);//����ѧ����Ϣ 
void search_stu(void);//����ѧ����Ϣ 
void search_stu_id(void);//ͨ��id����ѧ����Ϣ 
void search_stu_name(void);//ͨ����������ѧ����Ϣ 
void show_stu(void);//��ϵͳ��ѧ����Ϣչʾ 
void edit_stu(void);//�༭ѧ����Ϣ 
void renew_stu(void);//����ѧ����Ϣ���浽�ļ� 
void delete_stu(void);//ɾ��ѧ����Ϣ 
void readfile_student(void);//���ļ�����ѧ����Ϣ 
//--�γ���Ϣ���֣�
void input_cou(void);//���ӿγ���Ϣ 
void search_cou(void);//�����γ���Ϣ 
void search_cou_id(void);//ͨ��id�����γ� 
void search_cou_name(void);//ͨ���γ��������γ� 
void show_cou(void);//չʾ���пγ� 
void edit_cou(void);//�༭�γ���Ϣ 
void renew_cou(void);//���¿γ���Ϣ���浽�ļ� 
void delete_cou(void);//ɾ���γ���Ϣ 
void readfile_course(void);//���ļ�����γ���Ϣ 
//--ѡ����Ϣ���֣�
void readfile_select(void);//���ļ�����ѡ����Ϣ 
void input_grade(void);//¼��ѧ���ɼ�
void show_grade(void); //��ѯѧ���ɼ� 
void renew_select(void);//����ѡ����Ϣ���ļ� 
//--�ɼ���Ϣ���֣�
void input_grade(void);//�γ̴��
void renew_grade(void);//����ɼ����ļ� 
void readfile_grade(void);//���ļ�����ɼ���Ϣ
void out_grade(void);//ѧ����ѯ�Լ��ɼ� 
/*ѧ����Ϣ�ṹ��*/
struct student_info {
    char stu_ID[9];//ѧ��ID 
    char stu_name[10];//ѧ������ 
    char sex[9];//ѧ���Ա� 
}stu[SIZE_STU];

/*�γ���Ϣ�ṹ��*/
struct course_info {
    char course_ID[9];//�γ�ID 
    char course_name[9];//�γ����� 
    char credit[9];//�γ�ѧ�� 
}cou[SIZE_COU];

/*ѡ�μ�¼�ṹ��*/
struct select_info {
    int s;//���ѧ����Ϣ�������±�
    int c;//��ſγ���Ϣ�������±�
}sel[SIZE_SEL];
/*����ɼ��ṹ��*/ 
struct grade_info{
	int student;//���ѧ����Ϣ�����±� 
	int course;//��ſγ���Ϣ�����±� 
	int number;//��ųɼ� 
}gra[SIZE_GRA];

//ȫ�ֱ���i,j,x�ֱ���ѧ��,�γ�,ѡ����Ϣ�����±�
int i = -1;
int j = -1;
int x = -1;
int y = 0;
int main(void){
    //���뻶ӭ����
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
	    
	    //--�򿪿γ��ļ� 
	    while(!feof(fp))
	    {
			 fscanf(fp,"%s %s %s",&cou[a].course_ID,&cou[a].course_name,&cou[a].credit);
			 a++;
			 j++;//ȫ�ֱ���++ 
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
//��ӭ����
void home(void) {
    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
    int h;
    printf("\n\n                        ��ѡ����Ҫ���еĲ�����");
    printf("\n\n                             1.ѧ������");
    printf("\n                             2.�γ̲���");
    printf("\n                             3.��ʼѡ��");
    printf("\n                             4.ѡ��ͳ��");
    printf("\n                             5.�˳�ϵͳ");
    printf("\n                                                      ");
    printf("\n                        �����룺");
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
/*��ʼѡ��*/
void choose(void){
	char flag;
	FILE * fp;
	    //--�ж��ļ��Ƿ�Ϊ��
	    fp = fopen("D:\\dev_c\\chengji.txt","r+");
	    flag = fgetc(fp);
	    if(fp == NULL)
		{
	        printf("���ļ�ʧ�ܣ�");
	        system("cls");
	        home;
	    }
    char stu_id[10],cou_id[10];
    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
    //����ѡ��ѧ����Ϣ
    printf("\n\n                 ������ѡ����ѧ�ţ�");
    fflush(stdin);//������뻺���� 
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
        printf("\n                 �����ڴ�ѧ��\n");
        system("pause");
        system("cls");
        home();
    }
    //¼��������Ϣ
    x++;
    sel[x].s = h;
    //����γ���Ϣ
    printf("\n\n                 ������ѡ�޿γ̺ţ�");
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
        printf("\n                 �����ڴ˿γ̺�\n");
        x--;
        system("pause");
        system("cls");
        home();
    }
    //¼��γ���Ϣ
        sel[x].c = h;
        fp = fopen("D:\\dev_c\\chengji.txt","a");
            fprintf(fp,"%d\t%d",sel[x].s,sel[x].c);
	        fflush(stdin);
    printf("\n                 ¼��ɹ�!\n");
    renew_select();
    system("pause");
    system("cls");
    
    
    home();
}
/*ɾ��ѡ�μ�¼*/
void delete_sel(int q){
    int h;
    for(h = q;q < x;h++){
        q++;
        sel[h].c = sel[q].c;
        sel[h].s = sel[q].s;
    }

}
//��ѧ����¼���в���
void stu_operate(void) {
    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
    printf("\n\n                 ��ѡ����Ҫ��ѧ����¼���еĲ�����");
    printf("\n\n                             1.���");
    printf("\n                             2.��ѯ");
    printf("\n                             3.��ʾ");
    printf("\n                             4.�ɼ���ѯ");
    printf("\n                             5.������ҳ��");
    printf("\n                                                      ");
    printf("\n                        �����룺");
    int i;
    scanf("%d",&i);
    system("cls");
    switch(i){
        case 1://���ѧ����Ϣ
            input_stu();
            break;
        case 2://��ѯѧ����Ϣ
            search_stu();
            break;
        case 3://��ʾ����ѧ����Ϣ
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
//�Կγ̼�¼���в���
void cou_operate(void) {
    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
    printf("\n\n                 ��ѡ����Ҫ�Կγ̼�¼���еĲ�����");
    printf("\n\n                             1.��ӿγ�");
    printf("\n                             2.��ѯ�γ�");
    printf("\n                             3.��ʾȫ���γ�");
    printf("\n                             4.¼��ɼ�");
    printf("\n                             5.������ҳ��");
    printf("\n                                                      ");
    printf("\n                        �����룺");
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
//ѡ����Ϣͳ�Ƽ�¼
void statistic(void){
    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
    printf("\n\n                     ����ѧ����Ϣ��%d ��",i+1);
    printf("\n                     ���пγ���Ϣ��%d ��",j+1);
    if(x == -1){
        printf("\n                       ѡ�μ�¼��0 ��");
        printf("\n\n                     ");
        system("pause");
        system("cls");
        home();
    } else {
        printf("\n\n                        ѡ�μ�¼ %d ����",x+1);
        int m;
        for(m = 0;m <= x;m++){
            printf("\n                     ================");
            printf("\n                     ��%d��",m+1);
            printf("\n                     ѧ��ѧ�ţ�%s",stu[sel[m].s].stu_ID);
            printf("\n                     ѧ��������%s",stu[sel[m].s].stu_name);
            printf("\n                     �γ̺ţ�%s",cou[sel[m].c].course_ID);
            printf("\n                     �γ�����%s",cou[sel[m].c].course_name);
        }
        printf("\n\n            ");
        system("pause");
        system("cls");
        home();
    }

}


//--------------------------------------ѧ����Ϣ����--------------------------------------
void input_stu(void){
    char flag;
    FILE * fp;
    //--�ж��ļ��Ƿ�Ϊ��
    fp = fopen("D:\\dev_c\\student.txt","r+");
    flag = fgetc(fp);
    if(flag==EOF){
        printf("ѧ��\t����\t�Ա�\n");
    }
    fclose(fp);
    fp = fopen("D:\\dev_c\\student.txt","r+");
    if(fp == NULL){
        printf("���ļ�ʧ�ܣ�");
        system("cls");
        stu_operate();
    }
    printf("ѧ��\t����\t�Ա�\n");
    while(1){
        i++;
        scanf("%s %s %s",&stu[i].stu_ID,&stu[i].stu_name,&stu[i].sex);
        //--���ݲ���
        int h;
        for(h = 0;h < i;h++){
            if(i == 0) break;//��һ�����ݲ���Ҫ����
            if (strcmp(stu[h].stu_ID,stu[i].stu_ID)==0) {
                printf("��ѧ���Ѵ��ڣ����������룡\n");
                scanf("\n%s %s %s\n",&stu[i].stu_ID,&stu[i].stu_name,&stu[i].sex);
                h = -1;
            }
        }
        //--
        fprintf(fp,"%s\t%s\t%s",stu[i].stu_ID,stu[i].stu_name,stu[i].sex);
        printf("\n¼��ɹ�������¼������y��������һ���밴�������");
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
/*��ѯѧ����Ϣ*/
void search_stu(void){
    system("cls");
    printf("\n��ѡ���ѯ��ʽ��");
    printf("\n  1.ѧ�Ų�ѯ");
    printf("\n  2.������ѯ");
    printf("\n��ѡ��");
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
/*ѧ�Ų�ѯ*/
void search_stu_id(void){
    system("cls");
    char id[9];
    printf("\n����ѧ����ѧ��:");
    fflush(stdin);
    scanf("%s",id);
    int h;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_ID,id)==0){
            system("cls");
            printf("���ҳɹ�!");
            printf("\n\n\tѧ��\t����\t�Ա�");
            printf("\n\t-----------------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
            system("pause");
            system("cls");
            stu_operate();
        }
    }
    system("cls");
    printf("û�д�ѧ�ţ�\n");
    system("pause");
    system("cls");
    stu_operate();
}
/*������ѯ*/
void search_stu_name(void){
    system("cls");
    char name[9];
    printf("\n����ѧ��������:");
    fflush(stdin);
    scanf("%s",name);
    int h;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_name,name)==0){
            system("cls");
            printf("���ҳɹ�!");
            printf("\n\n\tѧ��\t����\t�Ա�");
            printf("\n\t---------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
            system("pause");
            system("cls");
            stu_operate();
        }
    }
    system("cls");
    printf("û�д�������");
    system("pause");
    system("cls");
    stu_operate();
}
/*��ʾ����ѧ����Ϣ*/
void show_stu(void){
    int h;
    if(i == -1){
        printf("\n��û��¼����Ϣ��\n");
        system("pause");
        system("cls");
        stu_operate();
    }
    system("cls");
    printf("\n\n\tѧ��\t����\t�Ա�");
    printf("\n\t---------------------------------------------------------");
    for(h = 0;h <= i;h++){
        printf("\n\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
    }
    //
    fflush(stdin);
    printf("\n\t1.�޸�");
    printf("\n\t2.ɾ��");
    printf("\n\t3.����");
    printf("\n\n  ѡ��Ҫ���еĲ�����");
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
/*�༭ѧ����Ϣ*/
void edit_stu(void){
    printf("\n������Ҫ�༭��ѧ����ѧ�ţ�");
    char id[10];
    getchar();
    scanf("%s",id);
    int h;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_ID,id)==0){//�ҵ���Ҫ�༭����
            system("cls");
            printf("\n\n\tѧ��\t����\t�Ա�");
            printf("\n\t---------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n",stu[h].stu_ID,stu[h].stu_name,stu[h].sex);
            printf("\n�����޸�ǰ�����ݣ������������޸�ֵ��\n\t");
            fflush(stdin);
            scanf("%s %s %s",&stu[h].stu_ID,&stu[h].stu_name,&stu[h].sex);
            int k;
            for(k = 0;k <= i;k++){
                if(strcmp(stu[k].stu_ID,stu[h].stu_ID)==0){
                    if(k==h){
                        continue;
                    } else {//ѧ�Ų�Ψһ
                        printf("\n��ѧ���Ѵ��ڣ���������ѧ�ţ�");
                        fflush(stdin);
                        scanf("%s",&stu[h].stu_ID);
                        k = -1;
                    }
                }
            }
            /*���޸���Ϣд���ļ�*/
            //˼�룺��ԭ�ļ�����д��һ��
            renew_stu();
            system("cls");
            printf("�޸ĳɹ���\n");
            system("pause");
            system("cls");
            stu_operate();
        }
    }
    printf("\n��ѧ�Ų����ڣ�\n");
    system("pause");
    system("cls");
    stu_operate();
}
/*ɾ��ѧ����Ϣ*/
void delete_stu(void){
    printf("\n������Ҫ�༭��ѧ����ѧ�ţ�");
    char id[10];
    getchar();
    scanf("%s",id);
    int h;
    for(h = 0;h <= i;h++){
        if(strcmp(stu[h].stu_ID,id)==0){//�ҵ���Ҫ�༭����
            system("cls");
            //�����/���Ƿ�ѡ����
            int a;
            for(a = 0;a <= x;a++){
                if(h==sel[a].s){//ѡ�����򽫶�Ӧ�γ̼�¼��1,�Լ�ѡ�������1
                    delete_sel(a);
                    a = -1;
                    x--;
                    continue;
                }
            }
            //���ֻ��һ����¼
            if(i==0){
                i = -1;
                renew_stu();
                printf("�޸ĳɹ���\n");
                system("pause");
                system("cls");
                stu_operate();
            }

            int k;
            for(k = h+1;k <= i;k++,h++){//������ֱ����ǰ�ƶ�
                strcpy(stu[h].stu_ID,stu[k].stu_ID);
                strcpy(stu[h].stu_name,stu[k].stu_name);
                strcpy(stu[h].sex,stu[k].sex);
            }
            /*���޸���Ϣд���ļ�*/
            //˼�룺��ԭ�ļ�����д��һ��
            renew_stu();
            i--;
            system("cls");
            printf("�޸ĳɹ���\n");
            system("pause");
            system("cls");
            stu_operate();
        }
    }
    printf("\n��ѧ�Ų����ڣ�\n");
    system("pause");
    system("cls");
    stu_operate();
}
//--------------------------------------�γ���Ϣ����--------------------------------------
void input_cou(void){
    char flag;
    FILE * fp;
    //--�ж��ļ��Ƿ�Ϊ��
    fp = fopen("D:\\dev_c\\xuanke.txt","r+");
    flag = fgetc(fp);
    if(flag==EOF){
        printf("����\t����\tѧ��\n");
    }
    fclose(fp);
    //--
    fp = fopen("D:\\dev_c\\xuanke.txt","a+");
    if(fp == NULL){
        printf("���ļ�ʧ�ܣ�");
        system("cls");
        cou_operate();
    }
    printf("����\t����\tѧ��\n");
    while(1){
        j++;
        scanf("%s %s %s",&cou[j].course_ID,&cou[j].course_name,&cou[j].credit);
        //--���ݲ���
        int h;
        for(h = 0;h < j;h++){
            if(j == 0) break;//��һ�����ݲ���Ҫ����
            if (strcmp(cou[h].course_ID,cou[j].course_ID)==0) {
                printf("�ÿγ̺��Ѵ��ڣ����������룡\n");
                scanf("\n%s %s %s",&cou[j].course_ID,&cou[j].course_name,&cou[j].credit);
                h = -1;
            }
        }
        //--
        fprintf(fp,"%s\t%s\t%s\t\t\n",cou[j].course_ID,cou[j].course_name,cou[j].credit);
        printf("\n¼��ɹ�������¼������y��������һ���밴�������");
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
/*��ѯ�γ���Ϣ*/
void search_cou(void){
    system("cls");
    printf("\n��ѡ���ѯ��ʽ��");
    printf("\n  1.�γ̺Ų�ѯ");
    printf("\n  2.�γ�����ѯ");
    printf("\n��ѡ��");
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
/*�γ̺Ų�ѯ*/
void search_cou_id(void){
    system("cls");
    char id[9];
    printf("\n����γ̺�:");
    fflush(stdin);
    scanf("%s",id);
    int h;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_ID,id)==0){
            system("cls");
            printf("���ҳɹ�!");
            printf("\n\n\t����\t����\tѧ��");
            printf("\n\t-----------------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\t\t\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);
            system("pause");
            system("cls");
            cou_operate();
        }
    }
    system("cls");
    printf("û�д˿γ̺ţ�\n");
    system("pause");
    system("cls");
    cou_operate();
}
/*�γ�����ѯ*/
void search_cou_name(void){
    system("cls");
    char name[9];
    printf("\n����γ���:");
    fflush(stdin);
    scanf("%s",name);
    int h;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_name,name)==0){
            system("cls");
            printf("���ҳɹ�!");
            printf("\n\n\t����\t����\tѧ��");
            printf("\n\t---------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\t\t\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);
            system("pause");
            system("cls");
            cou_operate();
        }
    }
    system("cls");
    printf("û�д˿γ�����");
    system("pause");
    system("cls");
    cou_operate();
}
/*��ʾ���пγ���Ϣ*/
void show_cou(void){
    int h;
    if(j == -1){
        printf("\n��û��¼����Ϣ��\n");
        system("pause");
        system("cls");
        cou_operate();
    }
    system("cls");
    printf("\n\n\t����\t����\tѧ��");
    printf("\n\t-------------------------------------------------------------");
    for(h = 0;h <= j;h++){
        printf("\n\t%s\t%s\t%s\t\t\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);
    }
    //
    fflush(stdin);
    printf("\n\t1.�޸�");
    printf("\n\t2.ɾ��");
    printf("\n\t3.����");
    printf("\n\n  ѡ��Ҫ���еĲ�����");
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
/*�༭�γ���Ϣ*/
void edit_cou(void){
    printf("\n������Ҫ�༭�Ŀγ̺ţ�");
    char id[10];
    getchar();
    scanf("%s",id);
    int h;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_ID,id)==0){//�ҵ���Ҫ�༭����
            system("cls");
            printf("\n\n\t����\t����\tѧ��");
            printf("\n\t-------------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n",cou[h].course_ID,cou[h].course_name,cou[h].credit);
            printf("\n�����޸�ǰ�����ݣ������������޸�ֵ��\n\t");
            fflush(stdin);
            scanf("%s %s %s",&cou[h].course_ID,&cou[h].course_name,&cou[h].credit);
            int k;
            for(k = 0;k <= j;k++){
                if(strcmp(cou[k].course_ID,cou[h].course_ID)==0){
                    if(k==h){
                        continue;
                    } else {//�γ̺Ų�Ψһ
                        printf("\n�˿γ̺��Ѵ��ڣ��������룺");
                        fflush(stdin);
                        scanf("%s",&cou[h].course_ID);
                        k = -1;
                    }
                }
            }
            /*���޸���Ϣд���ļ�*/
            //˼�룺��ԭ�ļ�����д��һ��
            renew_cou();
            system("cls");
            printf("�޸ĳɹ���\n");
            system("pause");
            system("cls");
            cou_operate();
        }
    }
    printf("\n�˿γ̺Ų����ڣ�\n");
    system("pause");
    system("cls");
    cou_operate();
}
/*ɾ���γ���Ϣ*/
void delete_cou(void){
    printf("\n������Ҫ�༭�Ŀγ̺ţ�");
    char id[10];
    getchar();
    scanf("%s",id);
    int h;
    for(h = 0;h <= j;h++){
        if(strcmp(cou[h].course_ID,id)==0){//�ҵ���Ҫ�༭����
            system("cls");
            //���ֻ��һ����¼
            if(j==0){
                j = -1;
                renew_cou();
                printf("�޸ĳɹ���\n");
                system("pause");
                system("cls");
                cou_operate();
            }
            int k;
            for(k = h+1;k <= j;k++,h++){//������ֱ����ǰ�ƶ�
                strcpy(cou[h].course_ID,cou[k].course_ID);
                strcpy(cou[h].course_name,cou[k].course_name);
                strcpy(cou[h].credit,cou[k].credit);
            }
            /*���޸���Ϣд���ļ�*/
            //˼�룺��ԭ�ļ�����д��һ��
            renew_cou();
            j--;
            system("cls");
            printf("�޸ĳɹ���\n");
            system("pause");
            system("cls");
            cou_operate();
        }
    }
    printf("\n�˿γ̺Ų����ڣ�\n");
    system("pause");
    system("cls");
    cou_operate();
}
void input_grade(void){
		char fla;
		FILE * fp;
		    //--�ж��ļ��Ƿ�Ϊ��
		    fp = fopen("D:\\dev_c\\chengji.txt","r+");
		    fla = fgetc(fp);
		    if(fp == NULL)
			{
		        printf("���ļ�ʧ�ܣ�");
		        system("cls");
		        home;
		    }
	char cou_id[10];
	int flag,h,g,m = 0;
	    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
	    //����γ���Ϣ
		    printf("\n\n                 ������¼��ɼ��γ̺ţ�\n");
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
		        printf("\n                 �����ڴ˿γ̺�\n");
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
				printf("\n                ���γ̻�û����ѡ��\n");
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
						printf("%sͬѧ��%s�γɼ�Ϊ��",stu[sel[j].s].stu_name,cou[sel[j].c].course_name); 
						scanf("%d",&gra[y].number);
						        fp = fopen("D:\\dev_c\\number.txt","r+");
						            fprintf(fp,"%d\t%d\t%d\t\t\n",gra[y].student,gra[y].course,gra[y].number);
						            y++;
						    printf("\n                 ¼��ɹ�!\n");
						    renew_grade();
					        fflush(stdin);
					}
				}
}
void out_grade(void)
{
	char flag;
		FILE * fp;
		    //--�ж��ļ��Ƿ�Ϊ��
		    fp = fopen("D:\\dev_c\\number.txt","r+");
		    flag = fgetc(fp);
		    if(fp == NULL)
			{
		        printf("���ļ�ʧ�ܣ�");
		        system("cls");
		        home;
		    }
		    char stu_id[10];
			    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
			    //����ѡ��ѧ����Ϣ
			    printf("\n\n                 ������ѡ����ѧ�ţ�");
			    fflush(stdin);//������뻺���� 
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
			        printf("\n                 �����ڴ�ѧ��\n");
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
//--���ܺ���
/*����ϵͳ�������ļ�*/
void renew_stu(void){
    FILE * fp;
    fp = fopen("D:\\dev_c\\student.txt","w+");
    if(fp == NULL){
        printf("\n���ļ�ʧ��,�޷��������ļ���\n");
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
        printf("\n���ļ�ʧ��,�޷��������ļ���\n");
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
		printf("\n���ļ�ʧ�ܣ��޷��������ļ���\n");
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
			printf("\n���ļ�ʧ�ܣ��޷��������ļ���\n");
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

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define M 100

struct record
{
    char name[20];
    int age;
    char tele[15];
    char city[20];
    char units[30];
    char note[20];
};

void create();
void append(); //�������ݺ���
void display(); //��ʾͨѶ¼�ļ�����
void locate(); //��ѯͨѶ¼����
void modify(); //�޸�ͨѶ¼����
void dele(); //ɾ��ͨѶ¼����
void disp_arr(struct record *,int ); //��ʾ���麯��
void disp_row(struct record ); //��ʾһ�м�¼����
void disp_table(); //��ʾ��ͷ����
void disp_str(char ,int); //��ʾn���ַ�����
void modi_sep(struct record[],int ); //�޸ļ�¼����
void sort_name(struct record[],int );//������������
void sort_city(struct record[],int );//������������
void del_name(struct record[],int *);//������ɾ������
void del_sequ(struct record[],int *);//�����ɾ������
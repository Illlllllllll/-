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
void append(); //输人数据函数
void display(); //显示通讯录文件函数
void locate(); //查询通讯录函数
void modify(); //修改通讯录函数
void dele(); //删除通讯录函数
void disp_arr(struct record *,int ); //显示数组函数
void disp_row(struct record ); //显示一行记录函数
void disp_table(); //显示表头函数
void disp_str(char ,int); //显示n个字符函数
void modi_sep(struct record[],int ); //修改记录函数
void sort_name(struct record[],int );//按姓名排序函数
void sort_city(struct record[],int );//按城市排序函数
void del_name(struct record[],int *);//按姓名删除函数
void del_sequ(struct record[],int *);//按序号删除函数
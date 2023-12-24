#include <iostream>
#include "address.h"
using namespace std;

void dele()
{
    struct record temp,info[M];
    char ask;
    int i=0,flag=0;
    FILE * fp;
    if((fp=fopen("address.txt","rb"))==NULL)
    {
        cout<<"打开文件失败！"<<endl;
        exit(1);
    }
    while (fread(&temp,sizeof(struct record),1,fp)==1)
        info[i++]=temp;
    fclose(fp);
    while(1)
    {
        cout<<"\n\n";
        disp_str(' ',16);
        cout<<"删除通讯录信息"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"1.按姓名删除"<<endl;
        disp_str(' ',16);
        cout<<"2.按序号删除"<<endl;
        disp_str(' ',16);
        cout<<"3.返回主菜单"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"请选择(1-3)：";
        cin>>ask;
        if(ask=='3')
            break;
        else if(ask=='2')
        {
            del_sequ(info,&i);
            flag=1;
        }
        else if(ask=='1')
        {    
            del_name(info,&i);
            flag=1;
        }    
        
    }
    if(flag)
    {
        fp=fopen("address.txt","wb");
        fwrite(info,sizeof(struct record),i,fp);
        fclose(fp);
    }
}
void del_name(struct record info[],int * p)
{
    char d_name[20],sure;
    int i;
    cout<<"请输入姓名：";
    cin>>d_name;
    for(i=0;i< *p;i++)
        if(strcmp(info[i].name,d_name)==0)
            break;
    if(i!= *p)
    {
        cout<<"您要删除的记录是："<<endl;
        disp_table();
        disp_row(info[i]);
        cout<<"您确定要删除吗？(Y/N)";
        cin>>sure;
        if(sure=='Y'||sure=='y')
        {
            for(;i<*p-1;i++)
                info[i]=info[i+1];
            (*p)--;
            cout<<"删除成功！"<<endl;
            system("pause");
        }
    }
    else
    {
        cout<<"要删除的没找到";
        system("pause");
    }
}

void del_sequ(struct record info[],int *p)
{
    int del_sequence,i;
    char sure;
    cout<<"请输入序号：";
    cin>>del_sequence;
    if(del_sequence<1||del_sequence> *p)
    {
        cout<<"序号超出范围！按任意键返回..."<<endl;
        system("pause");
    }
    else
    {
        cout<<"您要删除的记录是："<<endl;
        disp_table();
        disp_row(info[del_sequence-1]);
        cout<<"您确定要删除吗？(Y/N)";
        cin>>sure;
        if(sure=='Y'||sure=='y')
        {
            for(i=del_sequence-1;i<*p-1;i++)
                info[i]=info[i+1];
            (*p)--;
            cout<<"删除成功！"<<endl;
        }
    }
}
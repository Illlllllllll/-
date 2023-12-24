#include <iostream>
#include "address.h"
using namespace std;

void append()//输人数据函数
{
    struct record info;
    FILE * fp;
    char ask;
    if((fp=fopen("address.txt","ab"))==NULL)
    {
        cout<<"can't open file！"<<endl;
        exit(1);
    }
    while (1)
    {
        cout<<"\n\n";
        fflush(stdin);
        cout<<"输入通讯录记录："<<endl;
        cout<<"姓名：";
        cin>>info.name;
        cout<<"年龄：";
        cin>>info.age;
        cout<<"电话：";
        cin>>info.tele;
        cout<<"所在城市：";
        cin>>info.city;
        cout<<"所在单位：";
        cin>>info.units;
        cout<<"备注：";
        cin>>info.note;
        fwrite(&info,sizeof(struct record),1,fp);
        cout<<"是否继续输入(Y/N)？";
        cin>>ask;
        if(ask!='Y'&&ask!='y')
            break;
    }
    fclose(fp);
    cout<<"\n\n通讯录记录输入完毕！按任意键继续....";
}
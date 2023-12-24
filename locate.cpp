#include <iostream>
#include "address.h"
using namespace std;


void locate()
{
    struct record temp,info[M];
    char ask,name[20],city[20];
    int n=0,i,flag;
    FILE * fp;
    if((fp=fopen("address.txt","rb"))==NULL)
    {
        cout<<"打开文件失败！"<<endl;
        exit(1);
    }
    while (fread(&temp,sizeof(struct record),1,fp)==1)
        info[n++]=temp;
    while (1)
    {
        flag=0;
        disp_str(' ',16);
        cout<<"查询通讯录信息"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"1.按姓名查询"<<endl;
        disp_str(' ',16);
        cout<<"2.按城市查询"<<endl;
        disp_str(' ',16);
        cout<<"3.返回上一层"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"请选择(1-3)：";
        fflush(stdin);
        cin>>ask;
        switch (ask)
        {
            case '1':
                cout<<"请输入姓名：";
                cin>>name;
                disp_table();
                for(i=0;i<n;i++)
                    if(strcmp(name,info[i].name)==0)
                    {
                        flag=1;
                        disp_row(info[i]);
                    }
                if(!flag)
                    cout<<"没有找到相关信息！"<<endl;
                system("pause");
                break;
            case '2':
                cout<<"请输入城市：";
                cin>>city;
                disp_table();
                for(i=0;i<n;i++)
                    if(strcmp(city,info[i].city)==0)
                    {
                        flag=1;
                        disp_row(info[i]);
                    }
                if(!flag)
                    cout<<"没有找到相关信息！"<<endl;
                system("pause");
                break;
            default:
                return ;
        }
    }
    fclose(fp);
}
    

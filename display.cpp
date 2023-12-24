#include <iostream>
#include "address.h"
using namespace std;

void display()
{
    struct record temp,info[M];
    FILE * fp;
    char ask;
    int i;
    if((fp=fopen("address.txt","rb"))==NULL)
    {
        cout<<"打开文件失败！"<<endl;
        exit(1);
    }
    while(fread(&temp,sizeof(struct record),1,fp)==1)  
        info[i++]=temp;
    while (1)
    {
        cout<<"\n\n";
        disp_str(' ',10);
        cout<<"显示通讯录信息（共有"<<i<<"条记录）"<<endl;
        disp_str('*',40);
        putchar('\n');
        disp_str(' ',17);
        cout<<"1.按自然顺序显示\n";
        disp_str(' ',17);
        cout<<"2.按姓名排序显示\n";
        disp_str(' ',17);
        cout<<"3.按城市排序显示\n";
        disp_str(' ',17);
        cout<<"4.返回主菜单\n";
        disp_str('*',40);
        cout<<endl;
        disp_str(' ',17);
        cout<<"请选择操作(1-4): ";
        cin>>ask;
        switch (ask)
        {
            case '1':
                disp_arr(info,i);
                break;
            case '2':
                sort_name(info,i);
                break;
            case '3':
                sort_city(info,i);
                break;
            default:
                return ;
        }
    }
    fclose(fp);
}
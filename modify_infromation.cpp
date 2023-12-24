#include <iostream>
#include "address.h"
using namespace std;

void modify()
{
    char ask;
    struct record temp,info[M];
    FILE * fp;
    int i=0,flag=0;
    if((fp=fopen("address.txt","rb"))==NULL)
    {
        cout<<"打开文件失败！"<<endl;
        exit(1);
    }
    while(fread(&temp,sizeof(struct record),1,fp)==1)
    {    
        info[i++]=temp;
    }
    fclose(fp);
    while(1)
    {
        cout<<"\n\n";
        disp_str(' ',16);
        cout<<"通讯录管理系统"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"1.浏览显示通讯录"<<endl;
        disp_str(' ',16);
        cout<<"2.编辑显示通讯录"<<endl;
        disp_str(' ',16);
        cout<<"3.返回上一层"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"请选择(1-3)：";
        cin>>ask;
        /*switch(ask)
        {
            case '1':
                disp_arr(info,i);
                break;
            case '2':
                flag=1;
                modi_sep(info,i);
                break;
            default:
                return ;
        }*/
        if(ask=='1')
            disp_arr(info,i);
        else if(ask=='2')
        {
            flag=1;
            modi_sep(info,i);
        }
        else if(ask=='3')
            break;
    }
    if(flag) //如果修改了通讯录信息，则将修改后的信息写入文件
    {    
        fp=fopen("address.txt","wb");
        fwrite(info,sizeof(struct record),i,fp);
        fclose(fp);
    }
}
void modi_sep(struct record info[],int n)
{
    int sequence;
    char ask;
    while (1)
    {
        cout<<"请输入序号：";
        cin>>sequence;
        if(sequence<1||sequence>n)
        {
            cout<<"序号超出范围！请重新输入！"<<endl;
            getchar();
            continue;
        }
        cout<<"您要修改的记录是："<<endl;
        disp_table();
        disp_row(info[sequence-1]);
        cout<<"重新输入以下信息："<<endl;
        cout<<"姓名：";
        cin>>info[sequence-1].name;
        cout<<"年龄：";
        cin>>info[sequence-1].age;
        cout<<"电话：";
        cin>>info[sequence-1].tele;
        cout<<"城市：";
        cin>>info[sequence-1].city;
        cout<<"单位：";
        cin>>info[sequence-1].units;
        cout<<"备注：";
        cin>>info[sequence-1].note;
        cout<<"是否继续修改？(Y/N)";
        cin>>ask;
        if(ask!='Y'&&ask!='y')
            break;
    }
    
}
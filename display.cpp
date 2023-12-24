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
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        exit(1);
    }
    while(fread(&temp,sizeof(struct record),1,fp)==1)  
        info[i++]=temp;
    while (1)
    {
        cout<<"\n\n";
        disp_str(' ',10);
        cout<<"��ʾͨѶ¼��Ϣ������"<<i<<"����¼��"<<endl;
        disp_str('*',40);
        putchar('\n');
        disp_str(' ',17);
        cout<<"1.����Ȼ˳����ʾ\n";
        disp_str(' ',17);
        cout<<"2.������������ʾ\n";
        disp_str(' ',17);
        cout<<"3.������������ʾ\n";
        disp_str(' ',17);
        cout<<"4.�������˵�\n";
        disp_str('*',40);
        cout<<endl;
        disp_str(' ',17);
        cout<<"��ѡ�����(1-4): ";
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
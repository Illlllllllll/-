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
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        exit(1);
    }
    while (fread(&temp,sizeof(struct record),1,fp)==1)
        info[n++]=temp;
    while (1)
    {
        flag=0;
        disp_str(' ',16);
        cout<<"��ѯͨѶ¼��Ϣ"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"1.��������ѯ"<<endl;
        disp_str(' ',16);
        cout<<"2.�����в�ѯ"<<endl;
        disp_str(' ',16);
        cout<<"3.������һ��"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"��ѡ��(1-3)��";
        fflush(stdin);
        cin>>ask;
        switch (ask)
        {
            case '1':
                cout<<"������������";
                cin>>name;
                disp_table();
                for(i=0;i<n;i++)
                    if(strcmp(name,info[i].name)==0)
                    {
                        flag=1;
                        disp_row(info[i]);
                    }
                if(!flag)
                    cout<<"û���ҵ������Ϣ��"<<endl;
                system("pause");
                break;
            case '2':
                cout<<"��������У�";
                cin>>city;
                disp_table();
                for(i=0;i<n;i++)
                    if(strcmp(city,info[i].city)==0)
                    {
                        flag=1;
                        disp_row(info[i]);
                    }
                if(!flag)
                    cout<<"û���ҵ������Ϣ��"<<endl;
                system("pause");
                break;
            default:
                return ;
        }
    }
    fclose(fp);
}
    

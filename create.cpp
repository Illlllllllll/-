#include <iostream>
#include "address.h"


void create()
{
    char ask;
    int flag=1;
    FILE * fp;
    if((fp=fopen("address.txt","rb"))!=NULL)
    {
        fclose(fp);
        cout<<"\n\nͨѶ¼�ļ��Ѿ����ڣ��Ƿ񸲸�(Y/N)��";
        cin>>ask;
        if(ask!='Y'&&ask!='y')
            flag=0;
    }
    if (flag)
    {
        fp=fopen("address.txt","wb");
        if(fp==NULL)
        {
            cout<<"can't open file��"<<endl;
            exit(1);
        }
        fclose(fp);
        cout<<"\n\n ͨѶ¼�ļ������ɹ��������������....";
        getchar();
    }
    
}
#include <iostream>
#include "address.h"
using namespace std;

void append()//�������ݺ���
{
    struct record info;
    FILE * fp;
    char ask;
    if((fp=fopen("address.txt","ab"))==NULL)
    {
        cout<<"can't open file��"<<endl;
        exit(1);
    }
    while (1)
    {
        cout<<"\n\n";
        fflush(stdin);
        cout<<"����ͨѶ¼��¼��"<<endl;
        cout<<"������";
        cin>>info.name;
        cout<<"���䣺";
        cin>>info.age;
        cout<<"�绰��";
        cin>>info.tele;
        cout<<"���ڳ��У�";
        cin>>info.city;
        cout<<"���ڵ�λ��";
        cin>>info.units;
        cout<<"��ע��";
        cin>>info.note;
        fwrite(&info,sizeof(struct record),1,fp);
        cout<<"�Ƿ��������(Y/N)��";
        cin>>ask;
        if(ask!='Y'&&ask!='y')
            break;
    }
    fclose(fp);
    cout<<"\n\nͨѶ¼��¼������ϣ������������....";
}
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
        cout<<"���ļ�ʧ�ܣ�"<<endl;
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
        cout<<"ͨѶ¼����ϵͳ"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"1.�����ʾͨѶ¼"<<endl;
        disp_str(' ',16);
        cout<<"2.�༭��ʾͨѶ¼"<<endl;
        disp_str(' ',16);
        cout<<"3.������һ��"<<endl;
        disp_str('*',50);
        cout<<endl;
        disp_str(' ',16);
        cout<<"��ѡ��(1-3)��";
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
    if(flag) //����޸���ͨѶ¼��Ϣ�����޸ĺ����Ϣд���ļ�
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
        cout<<"��������ţ�";
        cin>>sequence;
        if(sequence<1||sequence>n)
        {
            cout<<"��ų�����Χ�����������룡"<<endl;
            getchar();
            continue;
        }
        cout<<"��Ҫ�޸ĵļ�¼�ǣ�"<<endl;
        disp_table();
        disp_row(info[sequence-1]);
        cout<<"��������������Ϣ��"<<endl;
        cout<<"������";
        cin>>info[sequence-1].name;
        cout<<"���䣺";
        cin>>info[sequence-1].age;
        cout<<"�绰��";
        cin>>info[sequence-1].tele;
        cout<<"���У�";
        cin>>info[sequence-1].city;
        cout<<"��λ��";
        cin>>info[sequence-1].units;
        cout<<"��ע��";
        cin>>info[sequence-1].note;
        cout<<"�Ƿ�����޸ģ�(Y/N)";
        cin>>ask;
        if(ask!='Y'&&ask!='y')
            break;
    }
    
}
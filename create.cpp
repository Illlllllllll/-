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
        cout<<"\n\n通讯录文件已经存在，是否覆盖(Y/N)？";
        cin>>ask;
        if(ask!='Y'&&ask!='y')
            flag=0;
    }
    if (flag)
    {
        fp=fopen("address.txt","wb");
        if(fp==NULL)
        {
            cout<<"can't open file！"<<endl;
            exit(1);
        }
        fclose(fp);
        cout<<"\n\n 通讯录文件建立成功！按任意键继续....";
        getchar();
    }
    
}
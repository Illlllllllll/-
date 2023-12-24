#include <iostream>
#include "address.h"
#include <iomanip>
using namespace std;

void disp_str(char ch,int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<" "<<ch;
}
void disp_arr(struct record info[],int n)
{
    char press;
    int i;
    for(i=0;i<n;i++)
    {
        if(i%20==0)
        {
            cout<<"\n\n";
            disp_str(' ',12);
            cout<<"我的通信录（共有"<<n<<"条记录）"<<endl;
            disp_str('*',40);
            cout<<endl;
            cout<<"序号    ";
            disp_table();
        }
        cout<<setw(5)<<i+1;
        disp_row(info[i]);
        if((i+1)%20==0)
        {
            disp_str('*',40);
            cout<<endl;
            disp_str(' ',12);
            cout<<"按回车键继续，按其他键结束显示：";
            cin>>press;
            if(press=='\n')
                break;
        }
    }
    disp_str('*',40);
    cout<<endl;
    system("pause");
}
void disp_table()
{
    cout<<"姓名";
    disp_str(' ',7);
    cout<<"年龄";
    disp_str(' ',2);
    cout<<"电话";
    disp_str(' ',7);
    cout<<"城市";
    disp_str(' ',8);
    cout<<"单位";
    disp_str(' ',8);
    cout<<"备注"<<endl;
}
void disp_row(struct record row)
{
    cout<<setw(12)<<row.name<<"   ";
    cout<<setw(7)<<row.age<<"   ";
    cout<<setw(12)<<row.tele<<"   ";
    cout<<setw(15)<<row.city<<"   ";
    cout<<setw(15)<<row.units<<"   ";
    cout<<setw(20)<<row.note<<endl;
}
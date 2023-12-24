#include <iostream>
#include "address.h"
using namespace std;

int main() {

    char choice;
    while(1)
    {
        cout<<"\n\n";
        disp_str(' ',12);
        cout << "通讯录管理系统" << endl;
        disp_str('*',35);cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "1. 输入通讯录信息";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "2. 显示通讯录信息";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "3. 查询通讯录信息";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "4. 修改通讯录信息";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "5. 删除通讯录信息";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "6. 建立通讯录信息";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "7. 退出通讯录信息";
        disp_str(' ',12);cout<<"*";cout<<endl;
        disp_str('*',35);cout<<endl;
        disp_str(' ',12);
        cout << "请选择操作(1-7): ";
        cin >> choice;

        switch (choice) 
        {
            case '1':
                append();
                break;
            case '2':
                display();
                break;
            case '3':
                locate();
                break;
            case '4':
                modify();
                break;
            case '5':
                dele();
                break;
            case '6':
                create();
                break;
            case '7':
                return 0;
            default:
                continue;
        }
    }
    return 0;
}

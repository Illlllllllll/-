#include <iostream>
#include "address.h"
using namespace std;

int main() {

    char choice;
    while(1)
    {
        cout<<"\n\n";
        disp_str(' ',12);
        cout << "ͨѶ¼����ϵͳ" << endl;
        disp_str('*',35);cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "1. ����ͨѶ¼��Ϣ";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "2. ��ʾͨѶ¼��Ϣ";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "3. ��ѯͨѶ¼��Ϣ";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "4. �޸�ͨѶ¼��Ϣ";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "5. ɾ��ͨѶ¼��Ϣ";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "6. ����ͨѶ¼��Ϣ";
        disp_str(' ',12);cout<<"*";cout<<endl;
        cout<<"*";disp_str(' ',12);
        cout << "7. �˳�ͨѶ¼��Ϣ";
        disp_str(' ',12);cout<<"*";cout<<endl;
        disp_str('*',35);cout<<endl;
        disp_str(' ',12);
        cout << "��ѡ�����(1-7): ";
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

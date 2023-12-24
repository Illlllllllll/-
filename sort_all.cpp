#include <iostream>
#include "address.h"
using namespace std;


void sort_city(struct record info[],int n)
{
    int i,j;
    struct record info_t[M],temp;
    for(i=0;i<n;i++)
        info_t[i]=info[i];
    for(i=1;i<n;i++)
        for(j=0;j<n-i;j++)
        {   if(strcmp(info_t[j].city,info_t[j+1].city)>0)
            {
                temp=info_t[j];
                info_t[j]=info_t[j+1];
                info_t[j+1]=temp;
            }
        }
    disp_arr(info_t,n);
}
void sort_name(struct record info[],int n)
{
    int i,j;
    struct record info_t[M],temp;
    for(i=0;i<n;i++)
        info_t[i]=info[i];
    for(i=1;i<n;i++)
        for(j=0;j<n-i;j++)
        {   if(strcmp(info_t[j].name,info_t[j+1].name)>0)
            {
                temp=info_t[j];
                info_t[j]=info_t[j+1];
                info_t[j+1]=temp;
            }
        }
    disp_arr(info_t,n);

}
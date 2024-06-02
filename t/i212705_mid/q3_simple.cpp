#include<iostream>
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
#include"sys/wait.h"
#include"sys/stat.h"
#include"pthread.h"
#include<string>


using namespace std;
pthread_t t1,t2,t3,t4,t5;
int C_total=0;
struct donor
{
    string name;
    string ID;
    float amount;
    int Cg;

};
void *T1(void * args)
{   
    donor *p=(donor *)args;
    if(p->Cg==1)
    {

            int temp=0;
            temp=p->amount;
            C_total+=temp;

    }
    pthread_exit(0);
}
void *T2(void * args)
{
    donor *p=(donor *)args;
    if(p->Cg==2)
    {
        
            int temp=0;
            temp=p->amount;
            C_total+=temp;
        
    }
    pthread_exit(0);
}
void *T3(void * args)
{
    donor *p=(donor *)args;
    if(p->Cg==3)
    {
        
            int temp=0;
            temp=p->amount;
            C_total+=temp;
       
    }
    pthread_exit(0);
}
void *T4(void * args)
{
    donor *p=(donor *)args;
    if(p->Cg==4)
    {
        
            int temp=0;
            temp=p->amount;
            C_total+=temp;
        
    }
    pthread_exit(0);
}
void *T5(void * args)
{
   donor *p=(donor *)args;
    if(p->Cg==5)
    {
        
            int temp=0;
            temp=p->amount;
            C_total+=temp;
        
    }
    pthread_exit(0);
}

int main()
{
    donor p;
    cout<<"enter your name : "<<endl;
    cin>>p.name;
    cout<<"ID card number"<<endl;
    cin>>p.ID;
    cout<<"enter donation amount"<<endl;
    cin>>p.amount;
    cout<<"enter contributing group any group between from 1 to 5"<<endl;
    cin>>p.Cg;

   

    pthread_create(&t1,NULL,&T1,&p);
                
    pthread_create(&t2,NULL,&T1,&p);
    
    pthread_create(&t3,NULL,&T1,&p);
    
    pthread_create(&t4,NULL,&T1,&p);
        
    pthread_create(&t5,NULL,&T1,&p);
    
    int option;
    cout<<"would you like to donatwe more . ? press 0 for exti else press 1 "<<endl;
    cin>>option;
    if(option==1)
    {
        while(true)
            {
                cout<<"enter your name : "<<endl;
                cin>>p.name;
                cout<<"ID card number"<<endl;
                cin>>p.ID;
                cout<<"enter donation amount"<<endl;
                cin>>p.amount;
                cout<<"enter contributing group any group between from 1 to 5"<<endl;
                cin>>p.Cg; 

                pthread_join(t1,NULL);
                pthread_join(t2,NULL);
                pthread_join(t3,NULL);
                pthread_join(t4,NULL);
                pthread_join(t5,NULL);      pthread_join(t1,NULL);
                cout<<"would you like to donatwe more . ? press 0 for exti else press 1 "<<endl;
                cin>>option;
                if(option==0)
                {
                    break;
                }
            } 
    }

    cout<<"the total amonun of donations is : "<<C_total<<endl;

    return 0;
}
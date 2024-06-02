#include<iostream>
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
#include"sys/wait.h"
#include"sys/stat.h"
#include"pthread.h"
#include<string>
using namespace std;
int v,m;
int length;
void *add(void *args)
{
    char* a =(char*)args;
    a=a+2;
    pthread_exit((void*)a);
}
int main()
{
    char array[10];
    char reverse[10];
    char R[10];
    char first[10];
    char final[10];
    int fd[2];
    int fd1[2];
    pipe(fd);
    pipe(fd1);
    cout<<"enter a string "<<endl;
    
    cin>>array;
    cout<<endl;
    write(fd[1],array,sizeof(array));
    close(fd[1]);
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        int temp=0;
        read(fd[0],reverse,sizeof(array));
        close(fd[0]);
        for(int i=0;i<10;i++)
        {
            if (reverse[i]>='a' && reverse[i]<='z')
                {
                   
                   temp=temp+1;
                }
        }
        int j=0;
        for(int i=temp-1;i>=0;i--)
        {
            R[j]=reverse[i];
      
            j=j+1;
        }
        
        cout<<endl;
        write(fd1[1],R,sizeof(R));
        close(fd1[1]);
        exit(0);
    }
    else if (pid>0)
    {
        
        int z=wait(&v);
        read(fd1[0],first,sizeof(first));
       
        // for(int i=0;i<10;i++)
        // {   if(first[i]>='a' && first[i]<='z')
        //     {
        //         cout<<first[i]<<endl;
        //     }
        // }
    }
    cout<<"task 2 "<<endl;
    pid_t p2;
    p2=fork();
    if(p2==0)
    {
        int temp=0;
        for(int i=0;i<10;i++)
        {
            if (first[i]>='a' && first[i]<='z')
                {
                   
                    temp=temp+1;
                }
        }
        length=temp;
        
        exit(0);
    }
    else if (p2>0)
    {
        int oo=wait(&m);
        
    }
    pthread_t t1,t2,t3,t4,t5,t6;
    pthread_create(&t1,NULL,add,&first[0]);
    void *ans;
    pthread_join(t1,&ans);
    char *a=(char *)ans;
    final[0]=*a;

    pthread_create(&t2,NULL,add,&first[1]);
    pthread_join(t2,&ans);
    
    a=(char *)ans;
    final[1]=*a;

    pthread_create(&t3,NULL,add,&first[2]);

    pthread_join(t3,&ans);
    
    a=(char *)ans;
    final[2]=*a;

    pthread_create(&t4,NULL,add,&first[3]);
    
    pthread_join(t4,&ans);
     a=(char *)ans;
    final[3]=*a;

    pthread_create(&t5,NULL,add,&first[4]);
    
    ans;
    pthread_join(t5,&ans);
    a=(char *)ans;
    final[4]=*a;

    cout<<final<<endl;
    return 0;

}
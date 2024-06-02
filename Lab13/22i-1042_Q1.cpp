#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h> 

using namespace std;

pthread_mutex_t process_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t kernel_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t main_mutex = PTHREAD_MUTEX_INITIALIZER;

string arr[9] = {"Google", "Word", "Excel", "Zoom", "Notepad", "VsCode", "Settings", "Oracle", "Camera"};
int timeslice[9] = {6, 7, 5, 3, 8, 3, 6, 4, 9}; // timeslices for each task
int time_count = 0, no_processes = 9, current_count = 0;

void *process(void *arg)
{
    int index = (intptr_t)arg;
    if (index == 0)
    {
        pthread_mutex_lock(&kernel_mutex);
        //cout<<"locking kernal "<<pthread_mutex_trylock(&kernel_mutex);
        cout << "\n##### Kernel is Starting #####\n";
        while (pthread_mutex_trylock(&kernel_mutex) != 0)
        {
            // Kernel is locked for processing

        }
        cout << "\n##### Kernel is Terminating #####\n";
        pthread_mutex_unlock(&main_mutex);
    }
    else
    {
        while (pthread_mutex_trylock(&process_mutex) != 0)
        {
            // Busy waiting
        }
        pthread_mutex_trylock(&process_mutex);

        cout << endl<< arr[index - 1] << " is running.\n";
        time_count += timeslice[index - 1];
        current_count++;
        pthread_mutex_unlock(&process_mutex);
        if (current_count == no_processes )
        {
            pthread_mutex_unlock(&kernel_mutex);
        }
    }
    return NULL;
}

int main()
{
    cout << "\n********** Applications are going to start **********\n";
    pthread_t thrs[10];
    pthread_mutex_unlock(&process_mutex);
    pthread_mutex_unlock(&kernel_mutex);

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&thrs[i], NULL, process, (void *)(intptr_t)i); 
        if (i==0)
        {
            usleep(100000); 
        }
        
    }
    for (int i = 0; i < 10; i++)
    {
        pthread_join(thrs[i], NULL); 
    }
    while (pthread_mutex_trylock(&main_mutex) != 0)
    {
        // Main is locked untill processing
    }
    cout << "\n***** Your total running time is: " << time_count << " seconds. ******";
    cout << "\n***** Finally, your mini-OS is Shutting Down. *****." << endl;
    return 0;
}
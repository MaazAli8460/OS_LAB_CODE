#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h> 
using namespace std;

int usr[3];
string currentop[3];
string logtable;
pthread_mutex_t usr_write_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t main_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t input_mutex = PTHREAD_MUTEX_INITIALIZER;

int count = 0;

void *process(void *arg)
{
    int index = (intptr_t)arg;
    int choice = 0;
    while (true)
    {
        pthread_mutex_lock(&input_mutex); 
        cout << "\nUser " << index << ": Press 1 to read file, press 2 to write to file, press 3 to quit writing mode, press 4 to quit: ";
        cin >> choice;
        pthread_mutex_unlock(&input_mutex); 

        if (choice == 1)
        {
            cout << "\nUser " << index << " reading file";
            currentop[index] = "read";
        }
        else if (choice == 2)
        {
            if (pthread_mutex_trylock(&usr_write_mutex) != 0)
            {
                cout << "\nUser " << index << " cannot write to file. Another user is writing.";
            }
            else
            {
                cout << "\nUser " << index << " writing to file";
            }
        }
        else if (choice == 3)
        {

            cout << "\nUser " << index << " Quits writing to file";
            pthread_mutex_unlock(&usr_write_mutex);

            
        }
        else if(choice==4)
        {
            count++;
            break;
        }
    }
    if (count == 3)
    {
        pthread_mutex_unlock(&main_mutex);
    }

    return NULL;
}

int main()
{
    pthread_t thrs[3];
    pthread_mutex_unlock(&usr_write_mutex);
    pthread_mutex_unlock(&input_mutex);
    pthread_mutex_trylock(&main_mutex);

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&thrs[i], NULL, process, (void *)(intptr_t)i);
    }
    while (pthread_mutex_trylock(&main_mutex) != 0)
    {
        // Main is locked until processing completes
    }
    cout << "\nMain exiting" << endl;
    return 0;
}
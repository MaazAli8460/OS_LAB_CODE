#include <iostream>
#include <vector>
#include <pthread.h>
#include <fstream>

using namespace std;
vector<int> arr;
int te = 0;

void *Take_input(void *arg)
{
    int oldstate, var;
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate);

    char temp1;
    while (1)
    {
        cout << "\nDo you want to enter value(y/n):";
        cin >> temp1;
        if (temp1 == 'n')
        {
            break;
        }
        cout << "\nEnter value:";
        cin >> var;
        arr.push_back(var);
    }
    cout << "\nArray you entered:\n";
    for (int j = 0; j < arr.size(); j++)
    {
        cout<<"  "<<arr[j];
    }
    te = 1;

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    return NULL;
}
void *Process_arr(void *arg)
{
    while (te != 1)
    {
    }
    int oldstate, var;
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    ofstream outFile("Sorted.txt");

    if (!outFile)
    {
        cerr << "Error opening file." << endl;
        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
        return NULL;
    }

    
    for (int i = 0; i < arr.size(); ++i)
    {
        outFile << arr[i] << " ";
    }

    outFile.close();
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

    return NULL;
}
int main()
{
    pthread_t tid1, tid2;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&tid1, &attr, Take_input, NULL);
    pthread_create(&tid2, &attr, Process_arr, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_attr_destroy(&attr);
    pthread_exit(NULL);

    return 0;
}
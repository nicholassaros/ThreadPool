#include "ThreadPool.h"

#include <iostream>
#include <unistd.h>
#include <atomic>

using namespace std;

void thread_pool_test(){
    sleep(1);
    cout << "Hello from a thread pool" << endl;
}

void testEmptyPool() {
    cout << "Test: Empty Pool\n";
    {
        ThreadPool pool(4);  // Create thread pool with 4 threads
        // No tasks enqueued, just wait for a bit
    }  // Thread pool will be destroyed here

    // Add a small delay to confirm the pool shutdown
    //sleep(1);
    cout << "ThreadPool destroyed with no tasks\n";
}

int main(){


    ThreadPool th(4);

    int taskId = 0;

    while(true){
        th.TaskQueuePush([taskId]() {
            cout << "Executing task " << taskId << "\n";
            sleep(5);
            cout << "Finished executing task " << taskId << "\n";
        });
        taskId++;
        sleep(2);
    }
    return 0;

}
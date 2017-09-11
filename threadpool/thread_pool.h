/**
*Author: Sun Bo
*Date: 2017-09-11
*/

#ifndef OPEN_THREAD_POOL_H
#define OPEN_THREAD_POOL_H

#include<iostream>
#include<list>
#include<functional>
#include<mutex>

namespace open{
    class ThreadPool{
    public:
        ThreadPool();
        ThreadPool(int threadNumber,int minthreadNumber = 5, int maxthreadNumber = 80);
        int addTask(std::funcation<void ()> task);
        int getthreadNumber();
    private:
        std::list<std::funcation<void ()>> taskQueue;
        std::mutex taskQuMtx;
        std::mutex threadRunMtx;
        std::vector<std::thread> threadVec;
        int minthreadNumber;
        int maxthreadNumber;
    }
}
#endif
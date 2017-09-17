/**
*Author: Sun Bo
*Date: 2017-09-11
*/
#ifndef OPEN_THREAD_TASK_H
#define OPEN_THREAD_TASK_H

#include<condition_variable>
#include"event/event_object.h"
#include"event/Event_driver.h"

namespace open{
    class Task{
    public:
        void operator()();
        void setObject(std::shared_ptr<EventObject> object);
        void notify();
        void setIsRun();
    private:
        std::mutex taskMtx;
        std::condition_variable cv;
        bool isRun = true;
        std::shared_ptr<EventDirver> eventDirverPtr;
        std::shared_ptr<EventObject> objectPtr;
        std::list<std::shared_ptr<EventObject>> objectList;
    };

    class EventParameter : EventParameter{

    }
}
#endif
#ifndef OPEN_EVENT_DIRVER_H
#define OPEN_EVENT_DIRVER_H

#include<memory>
#include<utility>
#include<unordered_map>
#include"event_object.h"
namespace open{
    typedef std::funcation<std::pair<int,std::shared_ptr<EventParameter>>(EventParameter)> EventFuncation
    class EventDirver{
    public:
        void pushEventFunc(std::shared_ptr<Event>,EventFuncation,
                                const std::list<std::shared_ptr<Event>>);
        void pushEventObj(std::shared_ptr<Event>,std::shared_ptr<EventObject>,
                            const std::list<std::shared_ptr<Event>>);
        void pushCircularEventFunc(std::shared_ptr<Event>,EventFuncation,
                            const std::list<std::shared_ptr<Event>>,std::funcation<bool()>);
        void pushCircularEventObj(std::shared_ptr<Event>,std::shared_ptr<EventObject>,
                            const std::list<std::shared_ptr<Event>>,std::funcation<bool()>);
        void removeEvent(std::shared_ptr<Event>);

        void removeEventObj(std::shared_ptr<Event>,std::shared_ptr<EventObject>);

        void removeEventFunc(std::shared_ptr<Event>, EventFuncation);
    private:
        std::unordered_map<std::shared_ptr<Event>,EventObjToObjs> eventObjMap;
        std::unordered_map<EventFuncation,std::shared_ptr<EventObject>> funcToObj;
        std::vector<std::funcation<void()>> task;
        std::vector<std::funcation<void()>> prepareTask;
    };
}
#endif
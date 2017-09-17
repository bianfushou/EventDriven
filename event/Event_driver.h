#ifndef OPEN_EVENT_DIRVER_H
#define OPEN_EVENT_DIRVER_H

#include<memory>
#include<utility>
#include<unordered_map>
#include"event_object.h"
namespace open{
    typedef std::shared_ptr<std::function<EventExParameter>(EventParameter)>> Eventfunction
    class EventDirver{
    public:
        void pushEventFunc(std::shared_ptr<Event>,Eventfunction,
                                const std::list<std::shared_ptr<Event>>);
        void pushEventObj(std::shared_ptr<Event>,std::shared_ptr<EventObject>,
                            const std::list<std::shared_ptr<Event>>);
        void pushCircularEventFunc(std::shared_ptr<Event>,Eventfunction,
                            const std::list<std::shared_ptr<Event>>,std::function<bool()>);
        void pushCircularEventObj(std::shared_ptr<Event>,std::shared_ptr<EventObject>,
                            const std::list<std::shared_ptr<Event>>,std::function<bool()>);
        void removeEvent(std::shared_ptr<Event>);

        void removeEventObj(std::shared_ptr<Event>,std::shared_ptr<EventObject>);

        void removeEventFunc(std::shared_ptr<Event>, Eventfunction);
    private:
        std::unordered_map<std::shared_ptr<Event>,EventObjToObjs> eventObjMap;
        std::unordered_map<Eventfunction,std::shared_ptr<EventObject>> funcToObj;
        std::vector<std::shared_ptr<Event>> events;
        std::vector<std::shared_ptr<Event>> prepareEvents;
    };
}
#endif
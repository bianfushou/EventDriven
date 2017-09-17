#ifndef OPEN_EVENT_OBJ_TO_OBJS_H
#define OPEN_EVENT_OBJ_TO_OBJS_H

namespace open{
    class EventObjToObjs{
    public:
    private:
        std::shared_ptr<EventObject> orgObj;
        std::set<shared_ptr<EventObject>> objSet;
    };
}

#endif
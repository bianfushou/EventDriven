#ifndef OPEN_EVENT_H
#define OPEN_EVENT_H
#include <memory>
#include"event_object.h"

namespace open{
    class Event{
    public:
        void setEventParameterPtr(std::shared_ptr<EventParameter>);
        std::shared_ptr<EventParameter> getEventParameterPtr();
    private:
        int code;
        std::shared_ptr<EventParameter> eventParameterPtr;
    }
}
#endif
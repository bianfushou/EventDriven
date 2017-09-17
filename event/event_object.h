#ifndef OPEN_EVENT_OBJECT_H
#define OPEN_EVENT_OBJECT_H

namespace open{

    class EventParameter{
    }

    class EventExParameter{
    public:
        EventExParameter(int status, int eventCode, std::shared_ptr<EventParameter> parameter);
        int getEventCode();
        int getStatus();
        std::shared_ptr<EventParameter> getEventParameter();
    private:
        int status;
        int eventCode;
        std::shared_ptr<EventParameter> parameter;
    }

    class EventObject{
    public:
        virtual EventExParameter operator(EventParameter imParam)=0;
        virtual int getId(){return 0;}
    };
}

#endif
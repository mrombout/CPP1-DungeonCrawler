#ifndef ACTION_H
#define ACTION_H

namespace dc {
namespace game {

    class Action
    {
    public:
        Action() { }
        virtual ~Action() { };

        virtual void execute() const = 0;
    };

}
}

#endif // ACTION_H

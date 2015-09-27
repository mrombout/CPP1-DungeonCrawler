#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <string>
#include <QObject>
#include <QCoreApplication>
#include "command.h"
#include "statemanager.h"

namespace dc {
namespace engine {

    class Game : public QObject,
                 public StateManager<Game> {
        Q_OBJECT
    public:
        explicit Game(QObject *parent = 0);
        ~Game();

        void start();
        void stop();

        void quit();

    signals:
        void finished();

    public slots:
        void run();
        void aboutToQuitApp();

    private:
        QCoreApplication *mApp;

        bool mLoop;
    };

}
}

#endif // GAMELOOP_H

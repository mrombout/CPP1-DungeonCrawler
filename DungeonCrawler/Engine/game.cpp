#include <iostream>
#include <QDebug>
#include "game.h"

namespace dc {
namespace engine {

    Game::Game(QObject *parent) :
        QObject(parent),
        StateManager<Game>(this)
    {
        mApp = QCoreApplication::instance();
    }

    Game::~Game()
    {

    }

    void Game::run()
    {
        qDebug() << "START - Game";

        if(currentState())
            mLoop = true;

        do {
            Command *command;
            do {
                std::string input = read();
                command = eval(input);
            } while(!command);

            print(command);
        } while(mLoop);
    }

    void Game::stop()
    {
        qDebug() << "STOP - Game";

        mLoop = false;
        quit();
    }

    void Game::quit()
    {
        emit finished();
    }

    void Game::aboutToQuitApp()
    {

    }

}
}

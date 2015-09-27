#include <QCoreApplication>
#include <QTimer>
#include "Engine/game.h"
#include "Engine/statemanager.h"
#include "Game/State/welcomestate.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // create main
    dc::engine::Game game;
    game.setState(new dc::game::WelcomeState());

    // connect signals
    QObject::connect(&game, SIGNAL(finished()), &app, SLOT(quit()));
    QObject::connect(&app, SIGNAL(aboutToQuit()), &game, SLOT(aboutToQuitApp()));

    // start application
    QTimer::singleShot(10, &game, SLOT(run()));
    return app.exec();
}

#include <iostream>
#include <fstream>
#include <string>
#include <QIODevice>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include "welcomestate.h"

namespace dc {
namespace game {

    WelcomeState::WelcomeState()
    {

    }

    void WelcomeState::onInitialize(engine::Game *game)
    {
        QFile file("E:/Programming/CPP/CPP1-DungeonCrawler/DungeonCrawler/Assets/intro.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Error: Could not load intro file.";
        }

        QTextStream in(&file);
        while(!in.atEnd()) {
            mWelcomeMsg.append(in.readLine() + "\n");
        }
    }

    void WelcomeState::onEnter(engine::Game *game)
    {
        QTextStream cout(stdout, QIODevice::WriteOnly);
        cout << mWelcomeMsg;
    }

    std::string WelcomeState::onRead()
    {
        QTextStream cout(stdout, QIODevice::WriteOnly);
        cout << "\t(N)ew Game \n\t(L)oad Game \n\t(E)xit" << endl;

        std::string input;
        std::cin >> input;

        return input;
    }

    engine::Command *WelcomeState::onEval(std::string input)
    {
        return 0;
    }

}
}

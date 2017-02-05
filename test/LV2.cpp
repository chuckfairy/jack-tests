/**
 * LADPSA plugin tests
 *
 */
#include <stdio.h>
#include <iostream>

#include <Jack/Server.h>
#include <Audio/Search.h>
#include <LV2/Plugin.h>
#include <LV2/Search.h>
#include <QApplication>
#include <QMainWindow>

using namespace std;

int main( int argc, char ** argv ) {

    QApplication app(argc, argv);

    QMainWindow * win = new QMainWindow();

    Jack::Server * server = new Jack::Server();

    server->start();

    //server->connectDefault();

    LV2::Host * host = new LV2::Host( server->getJackClient() );

    //host->updatePlugins();

    vector<Audio::Plugin*> plugins = host->findAllInstruments();

    host->setServer( server );

    host->setServerCallbacks();

    Audio::Plugin * p = plugins[34];

    host->addPlugin( p );

    //win->setCentralWidget( ((LV2::Plugin*)plugins[10])->getUIWidget() );

    //win->show();

    ((LV2::Plugin*)p)->run();

    int exe = app.exec();



    ///sleep(50);

    return 0;

};

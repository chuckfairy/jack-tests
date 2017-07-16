/**
 * Test
 */
#pragma once

#include <QtCore>
#include <QWidget>

#include <Audio/Plugin.h>
#include <Util/Dispatcher.h>

#include <ui_PatchBayItem.h>


/**
 * Forwarding
 */

class MainWindow;

namespace LV2 {

    class Plugin;

};


namespace Orza { namespace App { namespace Widget {

/**
 * Main class
 */

class PatchbayPlugin : public QWidget, public Util::Dispatcher {

    Q_OBJECT;

    public:

        explicit PatchbayPlugin( Audio::Plugin * const );
        explicit PatchbayPlugin();

        ~PatchbayPlugin();


        /**
         * Getters
         */

        QWidget * getWidget() {

            return _WidgetContent;

        };

        static const char * REMOVE_EVENT;

    public slots:

        void handleViewClick();

        void handleRemoveClick();


        /**
         * Getters
         */

        Ui_PatchBayItem * getUI() {

            return &_UI;

        };

        Audio::Plugin * getPlugin() {

            return _Plugin;

        };


    private:

        Audio::Plugin * _Plugin;

        QWidget * _WidgetContent;

        Ui_PatchBayItem _UI;

};

} } };

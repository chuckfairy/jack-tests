/**
 * Host audio mod
 *
 */
#pragma once

#include <vector>

#include <jack/jack.h>

#include <Audio/Host.h>
#include <Audio/Plugin.h>
#include <Audio/Port.h>


using std::vector;


/**
 * Midi Alsa extended class
 *
 */

namespace Jack {

class Host : public Audio::Host {

    private:

        const char * _name = "gabrielo-audio";


        /**
         * Host output ports
         */

        jack_port_t * _outputLeft;

        jack_port_t * _outputRight;

        const char * _outputLeftName = "output-L";

        const char * _outputRightName = "output-R";


        /**
         * Host input port
         */

        jack_port_t * _inputLeft;

        jack_port_t * _inputRight;

        const char * _inputLeftName = "input-L";

        const char * _inputRightName = "input-R";


        /**
         * Host client pointer
         */

        jack_client_t * _jackClient;


    public:

        /**
         * Constructs
         *
         */

        Host();

        Host( jack_client_t * j );


        /**
         * Default start
         *
         */

        void start();


        /**
         * main jack client from server
         */

        void setHostClient( jack_client_t * j ) {

            _jackClient = j;

        };


        /**
         * Get specific ports
         */

        vector<Port> getPortsByType( enum HostPortFlags );


        /**
         * Get specific ports
         */

        vector<Port> getInputPorts();


        /**
         * Get specific ports
         */

        vector<Port> getOutputPorts();


        /**
         * Get port name
         */

        const char * getPortFullName( const char * name ) {

            char * c = (char*) malloc(80);

            sprintf( c, "gabrielo-client:%s", name );

            return c;

        };


        /**
         * Default ports
         *
         */

        void createPorts();


        /**
         * Abstract jack port connection method
         *
         */

        int connectHostPort( const char *, const char * );


        /**
         * Host Connection port methods
         *
         */

        void connectRedirect();

        bool connectInputTo( const char * );

        bool connectInputTo( const char *, const char * );

        bool connectOutputTo( const char * );

        bool connectOutputTo( const char *, const char * );

};

};

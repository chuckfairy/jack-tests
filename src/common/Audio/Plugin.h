/**
 * Plugin abstract
 *
 */
#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <inttypes.h>

#include "Port.h"

using std::vector;
using std::map;
using std::string;


namespace Audio {


/**
 * Base plugin class
 *
 */

class Plugin {

    protected:

        bool ACTIVE = false;

        char TYPE[10];

        uint32_t _portsNum;

        map<long, Port*> _ports;

        vector<long> _audioPorts;

        vector<long> _inputs;

        vector<long> _outputs;

        vector<long> _controlPorts;

        char name[255];

        int long _numPorts;


    public:

        Plugin() {};

        ~Plugin() {};


        /**
         * Get type
         *
         */

        const char * getType() {

            return TYPE;

        };


        /**
         * Inputs grabbed from ports
         *
         */

        vector<long> * getInputs() {

            return &_inputs;

        };


        /**
         * Get output long ports
         *
         */

        vector<long> * getOutputs() {

            return &_outputs;

        };


        /**
         * Get name of plugin
         * From _descriptor
         *
         */

        char * getName() {

            return name;

        };


        /**
         * Is on / connected
         *
         */

        bool isActive() {

            return ACTIVE;

        };


        /**
         * Set name copy str
         */

        void setName( const char * s ) {

            strcpy( name, s );

        };


        /**
         * Set ports from Descriptor
         *
         */

        virtual void setPorts() {};


        /**
         * Map and set port
         *
         */

        void setPort( long index, Port * port ) {

            _ports[ index ] = port;

        };


        /**
         *  Port getter
         */

        Port * getPort( long index ) {

            return _ports[ index ];

        };


        /**
         * Create a port
         *
         */

        virtual Port * createPort( long portNum ) {

            Port * p = new Port;

            return p;

        };


        /**
         * Start up for lv2
         */

        virtual void start() { std::cout << "TESTERES"; };

};

};

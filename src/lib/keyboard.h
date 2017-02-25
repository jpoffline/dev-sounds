#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>


#include "Interactions.h"
#include "fundamental_tones.h"
#include "sound_engines.h"
#include "Envelopes.h"

class KEYBOARD
{
    typedef std::vector<sf::Int16> SAMPLES;
    typedef sf::Keyboard SFk;
    private:
        FUNDAMENTAL_TONES ftones;
        std::map<SFk::Key, int> _keys;
        void _gen_key_mappings();
        std::vector<SAMPLES> _keyboard_samples;
        void _gen_keyboard_samples();

        double _key_length_seconds;
        int _nsamples_per_second;

    public:
        
        KEYBOARD();
        void play();
        
        SAMPLES gen_samples();


};
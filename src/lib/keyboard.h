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
        std::vector<SAMPLES> _keyboard_samples;
        const int nsamples = 44100;
        const int _window_height = 800;
        const int _window_width = 600;
        void _gen_key_mappings();
        void _gen_keyboard_samples();

        bool _is_mouse_in_window(const sf::Vector2i loc);
        sf::Vector2f _get_mouse_loc_frac(const sf::Vector2i loc);

        
    public:
        
        KEYBOARD();
        void play();
        


};
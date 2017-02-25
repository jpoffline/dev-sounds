//
//  sound.h
//  TestApp
//
//  Created by Jonathan Pearson on 15/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

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



class SOUND
{
    typedef std::vector<sf::Int16> SAMPLES;
    
    private:
        FUNDAMENTAL_TONES ftones;

    public:
        
        SOUND()
        {
            
        }
    
    
        void youtube();
        void keyboard();
        std::vector<sf::Sound> gen_simple_tone(double freq);
        std::vector<SAMPLES> gen_keyboard_notes();
        SAMPLES gen_samples();
    
};





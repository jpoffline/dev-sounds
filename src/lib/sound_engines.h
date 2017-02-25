//
//  sound_engines.h
//  TestApp
//
//  Created by Jonathan Pearson on 19/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <cmath>
#include <stdlib.h>
#include "Envelopes.h"

const double TWO_PI = 6.28318;

namespace JP_sound
{
    struct Mode;
    short SineWave(double time, double freq, double amp);
    short SquareWave(double time, double freq, double amp);
    short Noise(double amp);
    short Wub(double i);
    short PianoTone(double time, double freq);
    short PadTone(double time, double freq);
    short SquarePianoTone(double time, double freq);

    
}

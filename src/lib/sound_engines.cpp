//
//  sound_engines.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 19/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#include "sound_engines.h"


namespace JP_sound {

// Wave form generators
    
const int MAXAMP = 32767;
const int SAMPRATE = 44100;

struct Mode{
    double freq;
    double amp;
};

short PianoTone(double i, double freq)
{
    return JP_sound::SineWave(i,freq,       0.2 );
    return JP_sound::SineWave(i,freq,       0.2 )
         + JP_sound::SineWave(i,freq *   4, 0.2 )
         + JP_sound::SineWave(i,freq *   8, 0.2 )
         + JP_sound::SineWave(i,freq * 1.3, 0.2 )
         + SineWave(i, freq / 8, 0.2 );
}

short PadTone(double time, double freq)
{
    return(SquarePianoTone(time, freq));
    return JP_sound::SineWave(time,freq,       0.25 )
         + JP_sound::SineWave(time,freq*1.1,   0.25 )
         + JP_sound::SineWave(time,freq*1.9,   0.25 )
         + JP_sound::SineWave(time,freq*5,     0.1  );
}
    
short SquarePianoTone(double i, double freq)
{
    return JP_sound::SquareWave(i,freq,       0.25 )
    + JP_sound::SquareWave(i,freq * 2,   0.25 )
    + JP_sound::SquareWave(i,freq * 0.1, 0.25 )
    + JP_sound::SquareWave(i,freq * 0.2, 0.25 );
}

short SineWave(double time, double freq, double amp)
{
    short result;
    double tpc = SAMPRATE / freq;
    double cycles = time / tpc;
    double rad = TWO_PI * cycles;
    short amplitude = MAXAMP * amp;
    result = amplitude * sin(rad);
    return result;
}

short SquareWave(double time, double freq, double amp)
{
    short result = 0;
    int tpc = SAMPRATE / freq;
    int cyclepart = (int)time % tpc;
    int halfcycle = tpc / 2;
    short amplitude = MAXAMP * amp;
    if(cyclepart < halfcycle)
    {
        result = amplitude;
    }
    return result;
}

short Noise(double amp)
{
    short result = 0;
    short amplitude = MAXAMP * amp;
    result = rand() % amplitude;
    return result;
}

short Wub(double i)
{
    return SineWave(i, 40, 0.3 ) + SineWave(i, 43, 0.3 ) + SineWave(i, 48, 0.3 );
}
    
    
} // namespace-JP_sound
//
//  fundamental_tones.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 19/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#include "fundamental_tones.h"


FUNDAMENTAL_TONES::FUNDAMENTAL_TONES()
{
    
    notes["C"]  = 16.35;
    notes["Cs"] = 17.32;
    notes["D"]  = 18.35;
    notes["Eb"] = 19.45;
    notes["E"]  = 20.60;
    notes["F"]  = 21.83;
    notes["Fs"] = 23.12;
    notes["G"]  = 24.50;
    notes["Gs"] = 25.96;
    notes["A"]  = 27.50;
    notes["Bb"] = 29.14;
    notes["B"]  = 30.87;
    
}

double
FUNDAMENTAL_TONES::get(std::string key)
{
    return notes[key];
}


double
FUNDAMENTAL_TONES::get(std::string key , double oct)
{

    return get(key) * (oct) * 4;
}

double
FUNDAMENTAL_TONES::get_middle_C()
{
    return get("C", 4.0);
}

double
FUNDAMENTAL_TONES::get_middle(std::string key)
{
    return get(key, 4.0);
}

std::vector<double>
FUNDAMENTAL_TONES::get_octave(double oct)
{
    return std::vector<double>{
        get("C", oct),
        get("Cs", oct),
        get("D", oct),
        get("Eb", oct),
        get("E", oct),
        get("F", oct),
        get("Fs", oct),
        get("G", oct),
        get("Gs", oct),
        get("A", oct),
        get("Bb", oct),
        get("B", oct)
    };
    
}

std::vector<double> FUNDAMENTAL_TONES::get_octave_middle()
{
    return get_octave(4.0);
}

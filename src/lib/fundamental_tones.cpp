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

double FUNDAMENTAL_TONES::keyn_to_freq(int keyn)
{
    return std::pow(2, ((double)keyn - 49) / 12) * 440;
}

int FUNDAMENTAL_TONES::freq_to_keyn(double freq)
{
    return 49 + 12 * std::log2(freq / 440);
}

std::vector<std::string> 
FUNDAMENTAL_TONES::getNoteNames()
{
    return note_names;
}

std::string 
FUNDAMENTAL_TONES::getNoteName(int noteN)
{
    // Get the name of the key for the given
    // key-number.
    return note_names[noteN - 1];
}

double 
FUNDAMENTAL_TONES::get(int octave, int keynumber)
{
    // Get the frequency for a given octave
    // and key-number in that octave.
    return keyn_to_freq(12 * octave + keynumber);
}

double
FUNDAMENTAL_TONES::get(std::string key)
{
    return notes[key];
}

int 
FUNDAMENTAL_TONES::get_nnotes_per_octave()
{
    return notes.size();
}

double
FUNDAMENTAL_TONES::get(std::string key , double oct)
{

    return get(key) * oct * 4;
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

std::vector<double> 
FUNDAMENTAL_TONES::get_octave_middle()
{
    return get_octave(4.0);
}

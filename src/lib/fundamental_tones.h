//
//  fundamental_tones.h
//  TestApp
//
//  Created by Jonathan Pearson on 19/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <string>
#include <map>
#include <vector>
#include <cmath>
class FUNDAMENTAL_TONES{
    private:
        std::map<std::string, double> notes;
        std::vector<std::string> note_names{
            "A", "Bb", "B", "C", "Db",
            "D", "Eb", "E", "F", "Fs",
            "G", "Gs"
        };
    public:
        FUNDAMENTAL_TONES();
        double get(std::string);
        double get(std::string, double);
        double get_middle_C();
        double get_middle(std::string);
        std::vector<double> get_octave(double);
        std::vector<double> get_octave_middle();
        int get_nnotes_per_octave();
        double keyn_to_freq(int);
        int freq_to_keyn(double);
        double get(int, int);
        std::vector<std::string> getNoteNames();
        std::string getNoteName(int);

};
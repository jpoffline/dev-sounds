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

class FUNDAMENTAL_TONES{
    private:
        std::map<std::string, double> notes;
    public:
        FUNDAMENTAL_TONES();
        double get(std::string);
        double get(std::string, double);
        double get_middle_C();
        double get_middle(std::string);
        std::vector<double> get_octave(double);
        std::vector<double> get_octave_middle();
};
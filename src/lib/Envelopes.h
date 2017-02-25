//
//  Envelopes.h
//  TestApp
//
//  Created by Jonathan Pearson on 20/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <cmath>
namespace JP_sound
{
    
struct EnvelopeParams
{
    double attackDuration = 0.1;
    double decayDuration = 0.2;
    double sustainLevel = 0.7;
    double releaseTime = 0.7;
    double releaseRate = 0.1;
    
    void set_scale(double scale);
    void set_total_duration(double scale);
    
    EnvelopeParams();
    EnvelopeParams(double scale);
};

    
class Envelopes
{
    EnvelopeParams ep;
    double decay_end_time;
public:
    Envelopes(EnvelopeParams);
    double get(double time);
    double get_attack(double t);
    double get_decay(double t);
    double get_sustain(double t);
    double get_release(double t);
};
    


} // namespace-JP_sound
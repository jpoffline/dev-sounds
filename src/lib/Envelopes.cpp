//
//  Envelopes.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 20/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#include "Envelopes.h"

namespace JP_sound{

    
void EnvelopeParams::set_scale(double scale)
{
    attackDuration *= scale;
    decayDuration  *= scale;
    releaseTime    *= scale;
    releaseRate    *= scale;
}
    
void EnvelopeParams::set_total_duration(double scale)
{
    set_scale(scale);
}
    
    
EnvelopeParams::EnvelopeParams()
{
    
}
    
EnvelopeParams::EnvelopeParams(double scale)
{
    set_total_duration(scale);
}
    
Envelopes::Envelopes(EnvelopeParams e)
: ep(e)
{
    decay_end_time = ep.attackDuration + ep.decayDuration;
}
    
double Envelopes::get_attack(double t)
{
    return t / ep.attackDuration;
}
    
double Envelopes::Envelopes::get_decay(double t)
{
    double sus_grad = -(1.0 - ep.sustainLevel) / ep.decayDuration;
    double sus_c = 1.0 - sus_grad * ep.attackDuration;
    return t * sus_grad + sus_c;
}
    
double Envelopes::get_sustain(double t)
{
    return ep.sustainLevel;
}
    
double Envelopes::get_release(double t)
{
    return ep.sustainLevel * std::exp((ep.releaseTime - t) / ep.releaseRate);
}
    
double Envelopes::get(double time)
{

    if(time < ep.attackDuration)
    {
        return get_attack(time);
    }
    else if(time >= ep.attackDuration && time < decay_end_time)
    {
        return get_decay(time);
    }
    else if(time >= decay_end_time && time < ep.releaseTime)
    {
        return get_sustain(time);
    }
    else
    {
        return get_release(time);
    }
    return 1.0;
}
    
}
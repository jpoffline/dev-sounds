//
//  test_Envelopes.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 20/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#include "tests.h"

namespace tests
{

const std::string scratch_loc = "/Users/jap/scratch/dev/dump-sfml-dev/";
 
    
void run()
{
    std::cout << "Running test suite" << std::endl;
    dump_envelope();
    test_samples();
    test_samples_with_envelope();
}
    

void dump_envelope()
{
    JP_sound::EnvelopeParams eps(10.0);

    auto envelope = JP_sound::Envelopes(eps);
    std::ofstream out(scratch_loc + "test_envelope.txt");
    for(double t = 0; t < 10; t += 0.01)
    {
        out << t << " " << envelope.get(t) << "\n";
    }
    out.close();
}


void test_samples()
{
    SOUND sound;
    
    auto samples = sound.gen_samples();

    std::ofstream out(scratch_loc + "test_samples.txt");
    for(int s = 0; s < samples.size(); s ++)
    {
        out << s << " " << samples[s] << "\n";
    }
    out.close();
}
    

void test_samples_with_envelope()
{
    SOUND sound;
    
    auto samples = sound.gen_samples();
    
    JP_sound::EnvelopeParams eps(samples.size());
    auto envelope = JP_sound::Envelopes(eps);
    std::ofstream out(scratch_loc + "test_samples.txt");
    for(int s = 0; s < samples.size(); s ++)
    {
        out << s << " " << envelope.get(s) * samples[s] << "\n";
    }
    out.close();
}


} // namespace-tests
//
//  test_Envelopes.h
//  TestApp
//
//  Created by Jonathan Pearson on 20/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#pragma once
#include "Envelopes.h"
#include "keyboard.h"
#include "sound.h"
#include <iostream>
#include <fstream>
#include <string>
#include "types.h"

namespace tests
{
    
void dump_envelope();
void test_samples();
void test_samples_with_envelope();
void dump_samples_loop(JP_SOUND::SAMPLES&);
void run();
    
}
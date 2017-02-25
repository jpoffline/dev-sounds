//
//  sound.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 15/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#include "sound.h"


SOUND::SAMPLES
SOUND::gen_samples()
{
    SAMPLES samples;
    int nsamples_per_second = 4410;
    int nseconds = 10;
    int nsamples = nseconds * nsamples_per_second;
    int frac = nsamples / 5;
    int which = 0;
    for(int i = 0; i < nsamples; i++)
    {
        samples.push_back(
                          JP_sound::SineWave(i,ftones.get("Fs"),  0.1)
                          + JP_sound::SineWave(i,ftones.get("F"),  0.1)
                          );
    }
    return samples;
    
}

void SOUND::youtube()
{
    
    sf::RenderWindow window(sf::VideoMode(800,600),"sound");
    
    
    SAMPLES samples;


    
    int nsamples_per_second = 4410;
    int nseconds = 10;
    int nsamples = nseconds * nsamples_per_second;
    int frac = nsamples / 5;
    int which = 0;
    for(int i = 0; i < nsamples; i++)
    {
        //samples.push_back(JP_sound::Wub(i));
       // samples.push_back(JP_sound::SquareWave(i,440,0.9 ));
        
        samples.push_back(
                          JP_sound::SineWave(i,ftones.get("Fs"),  0.1)
                          +JP_sound::SineWave(i,ftones.get("B"),  0.1)
                          +JP_sound::SineWave(i,ftones.get("D"),  0.1)
                          +JP_sound::SineWave(i,ftones.get("Fs", 1),  0.1)
                          +JP_sound::SineWave(i,ftones.get("B", 2),  0.1)
                          +JP_sound::SineWave(i,ftones.get("D", 1),  0.1)
                          );
       /* if(i > frac)    {which = 1;}
        if(i > 2 * frac){which = 2;}
        if(i > 3 * frac){which = 3;}
        if(i > 4 * frac){which = 4;}
        if(which == 0)samples.push_back(JP_sound::SineWave(i,ftones.get("Fs"), 0.1));
        if(which == 1)samples.push_back(JP_sound::PianoTone(i,ftones.get_middle("G")));
        //if(which == 2)samples.push_back(JP_sound::PianoTone(i,ftones.get_middle("D")));
        //if(which == 3)samples.push_back(JP_sound::PianoTone(i,ftones.get_middle("C")));
        //if(which == 4)samples.push_back(JP_sound::PianoTone(i,ftones.get_middle("E")));*/
//        samples.push_back(JP_sound::Noise(0.9));
    }
    
    sf::SoundBuffer buffer;
    buffer.loadFromSamples(&samples[0], samples.size(),1,44100);
    sf::Sound sound;

    sound.setBuffer(buffer);

    
    
    bool playing = false;
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) )
        {
            sound.play();
            sf::sleep(sf::milliseconds(100));
        }
        
    }
    
    
}

void
SOUND::keyboard()
{
    
    
    
    sf::RenderWindow window(sf::VideoMode(800,600),"sound");
    const int wait = 210;
    
    auto samples_vec = gen_keyboard_notes();
    
    std::vector<sf::SoundBuffer> buffers(samples_vec.size());
    std::vector<sf::Sound> sounds(buffers.size());
    for(int i = 0; i < samples_vec.size(); i++)
    {
        buffers[i].loadFromSamples(&samples_vec[i][0], samples_vec[i].size(), 1, 44100);
        sounds[i].setBuffer(buffers[i]);
    }

    

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            sounds[0].play();
            sf::sleep(sf::milliseconds(wait));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            sounds[1].play();
            sf::sleep(sf::milliseconds(wait));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            sounds[2].play();
            sf::sleep(sf::milliseconds(wait));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            sounds[3].play();
            sf::sleep(sf::milliseconds(wait));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
        {
            sounds[4].play();
            sf::sleep(sf::milliseconds(wait));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G))
        {
            sounds[5].play();
            sf::sleep(sf::milliseconds(wait));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H))
        {
            sounds[6].play();
            sf::sleep(sf::milliseconds(wait));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
        {
            sounds[7].play();
            sf::sleep(sf::milliseconds(wait));
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
        {
            sounds[7].play();
            sf::sleep(sf::milliseconds(wait));
            sounds[4].play();
            sf::sleep(sf::milliseconds(wait));
            sounds[1].play();
            sf::sleep(sf::milliseconds(wait));
            sounds[7].play();
            sf::sleep(sf::milliseconds(wait));
        }
        
    }
}

std::vector<SOUND::SAMPLES>
SOUND::gen_keyboard_notes()
{

    std::vector<double> frequencies = ftones.get_octave_middle();
    std::vector<SAMPLES> samples_vec(frequencies.size());
    
    int nsamples_per_second = 44100;
    int nseconds = 1;
    int nsamples = nseconds * nsamples_per_second;
    
    JP_sound::EnvelopeParams eps(nsamples);
    eps.sustainLevel = 0.3;
    auto envelope = JP_sound::Envelopes(eps);

    for(int i = 0; i < nsamples; i++)
    {
        for(int f = 0; f < frequencies.size(); f++)
        {
            samples_vec[f].push_back(envelope.get(i) * JP_sound::PianoTone(i,frequencies[f]));
        }
    }
    
    return samples_vec;
    
}








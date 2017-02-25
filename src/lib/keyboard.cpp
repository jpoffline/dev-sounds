#include "keyboard.h"

KEYBOARD::KEYBOARD()
{
    _gen_key_mappings();
    _gen_keyboard_samples();
    _key_length_seconds = 0.1;
    _nsamples_per_second = 44100;
    std::cout << "init called\n";
}

void
KEYBOARD::play()
{
    const int wait = 210;
    std::vector<sf::SoundBuffer> buffers(_keyboard_samples.size());
    std::vector<sf::Sound> sounds(buffers.size());
    for(int i = 0; i < _keyboard_samples.size(); i++)
    {
        buffers[i].loadFromSamples(&_keyboard_samples[i][0], _keyboard_samples[i].size(), 1, 44100);
        sounds[i].setBuffer(buffers[i]);
    }
    
    while(true)
    {
        if(SFk::isKeyPressed(SFk::Key::Escape))
        {
            break;
        }
        for(auto& k : _keys)
        {
            if(SFk::isKeyPressed(k.first))
            {
                sounds[k.second].play();
                sf::sleep(sf::milliseconds(wait));
            }
        }
    }
}


void
KEYBOARD::_gen_keyboard_samples()
{
   
    auto frequencies = ftones.get_octave_middle();
    _keyboard_samples.resize(frequencies.size());
    
    int nsamples = 44100;
    JP_sound::EnvelopeParams eps(nsamples);
    eps.sustainLevel = 0.3;
    eps.releaseRate = 0.01;
    eps.releaseTime = 0.1;
    auto envelope = JP_sound::Envelopes(eps);

    for(int i = 0; i < nsamples; i++)
    {
        for(int f = 0; f < frequencies.size(); f++)
        {
            _keyboard_samples[f].push_back(
                envelope.get(i) * JP_sound::PianoTone(i,frequencies[f])
            );
            
        }
    }
    

    
}


void KEYBOARD::_gen_key_mappings()
{
    _keys[SFk::Key::A] = 0;
    _keys[SFk::Key::S] = 1;
    _keys[SFk::Key::D] = 2;
    _keys[SFk::Key::F] = 3;
    _keys[SFk::Key::G] = 4;
    _keys[SFk::Key::H] = 5;
    _keys[SFk::Key::J] = 6;
    _keys[SFk::Key::K] = 7;
    _keys[SFk::Key::L] = 8;
    _keys[SFk::Key::Z] = 9;
    _keys[SFk::Key::X] = 10;
    _keys[SFk::Key::C] = 11;
    
    
}





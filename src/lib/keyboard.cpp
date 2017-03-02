#include "keyboard.h"

KEYBOARD::KEYBOARD()
{
    _gen_key_mappings();
    _gen_keyboard_samples();
    
}

void 
KEYBOARD::play_pad()
{
    play_via_key = false;
}



void
KEYBOARD::play()
{

    std::vector<sf::Sound> sounds;
    std::vector<sf::SoundBuffer> buffers(_keyboard_samples.size());
    sounds.resize(buffers.size());
    auto nsounds = _keyboard_samples.size();
    for(int i = 0; i < nsounds; i++)
    {
        sf::SoundBuffer buffer;
        //buffer.loadFromSamples(&_keyboard_samples[i][0], _keyboard_samples[i].size(), 1, 44100);
        buffers[i].loadFromSamples(&_keyboard_samples[i][0], _keyboard_samples[i].size(), 1, 44100);
        sounds[i].setBuffer(buffers[i]);
        //sounds[i].setBuffer(buffer);
    }


    sf::Window window(sf::VideoMode(_window_width, _window_height), "My window");
    while(!SFk::isKeyPressed(SFk::Key::Escape))
    {
        if(play_via_key)
        {
            for(auto& k : _keys)
            {
                if(SFk::isKeyPressed(k.first))
                {
                    if(sounds[k.second].getStatus() != sf::Sound::Status::Playing)
                    {
                        sounds[k.second].play();
                    }
                }
            }
        }
        else
        {
            auto loc = sf::Mouse::getPosition(window);
            if(_is_mouse_in_window(loc))
            {
                int idx = (int)(nsounds * loc.x / (float)_window_width);
                for(auto& k : _keys)
                {
                    if(idx == k.second)
                    {
                        if(sounds[idx].getStatus() != sf::Sound::Status::Playing)
                        {
                            std::cout << idx << std::endl;
                            sounds[idx].play();
                        }
                    }

                }
                
            }
        }
    }
    
}

sf::Vector2f 
KEYBOARD::_get_mouse_loc_frac(const sf::Vector2i loc)
{
    sf::Vector2f result;
    result.x = loc.y / (float)_window_width;
    result.y = loc.x / (float)_window_height;
    return result;
}



bool 
KEYBOARD::_is_mouse_in_window(const sf::Vector2i loc)
{
    if(
        loc.x < 0 
        | loc.y < 0
        | loc.x > _window_height
        | loc.y > _window_width
    ){
        return false;
    }

    return true;


}

void
KEYBOARD::_gen_keyboard_samples()
{
   
    auto frequencies = ftones.get_octave_middle();
    _keyboard_samples.resize(frequencies.size());
    
    
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
                envelope.get(i) 
                * JP_sound::PianoTone(i,frequencies[f])
            );
            
        }
    }
    

    
}


void KEYBOARD::_gen_key_mappings()
{
    // Map the key-pressed to indices of the frequencies.
    //  TODO: map to note names.
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





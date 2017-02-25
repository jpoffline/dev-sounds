//
//  Interactions.h
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>


namespace game {
    namespace control {
        
        bool is_key_pressed_up();
        bool is_key_pressed_right();
        bool is_key_pressed_left();
        bool is_key_pressed_down();
    }
    
    /*
    namespace move{
        
        float speed;
        
        void move(sf::RectangleShape &obj, float x, float y);
        
        
        void move_up(sf::RectangleShape &obj);
        void move_down(sf::RectangleShape &obj);
        void move_left(sf::RectangleShape &obj);
        void move_right(sf::RectangleShape &obj);
       
     
    }
     */
    
}

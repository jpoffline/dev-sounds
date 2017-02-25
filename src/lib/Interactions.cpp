//
//  Interactions.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Interactions.h"




namespace game {
    namespace control {
        
        bool is_key_pressed_up(){
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
        }
        bool is_key_pressed_right(){
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
        }
        bool is_key_pressed_left(){
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
        }
        bool is_key_pressed_down(){
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
        }
    }
    /*
    namespace move{
        
        
        
        void move(sf::RectangleShape &obj, float x, float y)
        {
            obj.move(x,y);
        }
        
        
        void move_up(sf::RectangleShape &obj)
        {
            move(obj, 0.0f, - speed);
        }
        void move_down(sf::RectangleShape &obj)
        {
            move(obj, 0.0f, speed );
        }
        void move_left(sf::RectangleShape &obj)
        {
            move(obj, - speed, 0.0f);
        }
        void move_right(sf::RectangleShape &obj)
        {
            move(obj, speed, 0.0f);
        }
        
    }*/
    
}
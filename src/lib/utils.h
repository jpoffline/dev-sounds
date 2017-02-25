//
//  utils.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <sstream>

namespace UTILS {
    template <typename T> std::string tostr(const T& t) {
        std::ostringstream os;
        os<<t;
        return os.str();
    }
    
    template<typename T>
    class GETSET
    {
    private:
        T value;
    public:
        void set(T v){value = v;}
        T get(){return value;}
        GETSET(T v): value(v){}
        GETSET() : value(T(0)){}
        void inc(T v){value = value + v;}
    };
    
}

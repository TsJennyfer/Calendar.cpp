//
//  Event.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 20/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Event
{
public:
    Event () { }
    Event (string category, time_t date, int len, string activity) :
        category(category),
        date (date),
        len (len),
        activity (activity) { }
    string category;
    time_t date;
    int len;
    string activity;
};

#endif /* Event_hpp */

//
//  Filtr.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 17/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef Filtr_hpp
#define Filtr_hpp

#include "Event.hpp"

class Filtr
{
public:
    virtual bool doFiltr(Event *rec);
};

#endif

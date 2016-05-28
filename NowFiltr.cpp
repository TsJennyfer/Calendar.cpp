//
//  NowFiltr.cpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 22/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#include "NowFiltr.hpp"

bool NowFiltr::doFiltr( Event *rec )
{
    if(rec->date>(time(NULL)) && rec->date<(time(NULL) + (8*60*60)))
        return true;
    
    else
        return false;
}

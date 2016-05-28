//
//  OutdateFiltr.cpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 22/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#include "OutdateFiltr.hpp"
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

bool OutdateFiltr::doFiltr( Event *rec )
{
    if(rec->date<(time(NULL)))
    {
        return true;
    }
    else
        return false;
}
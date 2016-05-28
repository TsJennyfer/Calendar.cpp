//
//  DateFiltr.cpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 22/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#include "DateFiltr.hpp"
#include <string.h>
 #include <iostream>
 #include <stdio.h>
using namespace std;
 
DateFiltr::DateFiltr( time_t searchDate )
{
    search = searchDate;
}
bool DateFiltr::doFiltr(Event *rec)
{
    if(rec->date>(search) && rec->date<(search + (24*60*60)))
    {
        return true;
    }
    else
        return false;
}

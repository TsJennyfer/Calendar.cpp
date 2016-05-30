//
//  DateTimeFiltr.cpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 24/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#include "DateTimeFiltr.hpp"

using namespace std;

DateTimeFiltr::DateTimeFiltr( time_t searchDate )
{
    search = searchDate;
}
bool DateTimeFiltr::doFiltr(Event *rec)
{
    if( rec->date == search )
    {
        return true;
    }
    else
        return false;
}

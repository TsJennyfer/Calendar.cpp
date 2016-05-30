//
//  CategoryFiltr.cpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 20/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//
#include "CategoryFiltr.hpp"

using namespace std;

CategoryFiltr::CategoryFiltr( string searchCategory )
{
    search = searchCategory;
}
bool CategoryFiltr::doFiltr(Event *rec)
{
    if(strcmp( search.c_str(), rec->category.c_str() ) == 0)
        return true;
    else
        return false;
}

//
//  DateFiltr.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 22/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef DateFiltr_hpp
#define DateFiltr_hpp

#include <stdio.h>
#include "Filtr.hpp"
using namespace std;

class DateFiltr : public Filtr
{
private:
    time_t search;
public:
    DateFiltr ( time_t searchTime );
    bool doFiltr( Event *rec );
};

#endif /* DateFiltr_hpp */
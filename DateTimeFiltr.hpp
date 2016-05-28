//
//  DateTimeFiltr.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 24/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef DateTimeFiltr_hpp
#define DateTimeFiltr_hpp

#include <stdio.h>
#include "Filtr.hpp"
using namespace std;

class DateTimeFiltr : public Filtr
{
private:
    time_t search;
public:
    DateTimeFiltr ( time_t searchTime );
    bool doFiltr( Event *rec ) override;
};


#endif /* DateTimeFiltr_hpp */

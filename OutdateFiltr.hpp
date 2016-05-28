//
//  OutdateFiltr.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 22/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef OutdateFiltr_hpp
#define OutdateFiltr_hpp

#include <stdio.h>
#include "Filtr.hpp"
using namespace std;

class OutdateFiltr : public Filtr
{
public:
    bool doFiltr( Event *rec ) override;
};

#endif /* OutdateFiltr_hpp */

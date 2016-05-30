//
//  AllFiltr.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 21/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef AllFiltr_hpp
#define AllFiltr_hpp

#include "Filtr.hpp"

using namespace std;

class AllFiltr : public Filtr
{
public:
    bool doFiltr(Event *rec);
};

#endif /* AllFiltr_hpp */

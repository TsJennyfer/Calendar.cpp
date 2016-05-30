//
//  NowFiltr.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 22/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef NowFiltr_hpp
#define NowFiltr_hpp

#include "Filtr.hpp"

using namespace std;

class NowFiltr : public Filtr
{
public:
    bool doFiltr( Event *rec );
};

#endif /* NowFiltr_hpp */

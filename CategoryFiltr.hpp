//
//  CategoryFiltr.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 20/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef CategoryFiltr_hpp
#define CategoryFiltr_hpp

#include <stdio.h>
#include <string>
#include "Filtr.hpp"
using namespace std;

class CategoryFiltr : public Filtr
{
private:
    string search;
public:
    CategoryFiltr ( string searchCategory );
    bool doFiltr(Event *rec) override;
};

#endif /* CategoryFiltr_hpp */

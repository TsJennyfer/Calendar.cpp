//
//  OrganaizerLib.hpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 20/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#ifndef OrganaizerLib_hpp
#define OrganaizerLib_hpp

#include <map>
#include <fstream>
#include <vector>
#include <string>

#include "Event.hpp"
#include "Filtr.hpp"
#include "AllFiltr.hpp"
#include "CategoryFiltr.hpp"
#include "OutdateFiltr.hpp"
#include "NowFiltr.hpp"
#include "DateFiltr.hpp"
#include "DateTimeFiltr.hpp"

using namespace std;

class OrganizerLib
{
private:
    map <time_t, Event> mymap;
    bool modifiedCalendar;
public:
    OrganizerLib();
    void loadCalendarMap();
    int printMap( Filtr *filtr );
    void printAll();
    void addEvent();
    void searchByDate();
    void deleteByTime();
    void searchByCategory();
    void saveFile();
    void checkChanges();
    void workWithOutdate();
    void nowEvents();
    int deleteMap( Filtr *filtr );
};
#endif /* OrganaizerLib_hpp */

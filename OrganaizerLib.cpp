//
//  OrganaizerLib.cpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 20/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#include "OrganaizerLib.hpp"

const string filename = "/Users/jn/Documents/projects/Calendar.cpp/timetable.txt";
//const string filename = "timetable.txt";

OrganizerLib::OrganizerLib()
{
    modifiedCalendar = false;
}

//help function for work with base
void OrganizerLib::loadCalendarMap()
{
    ifstream n_file;
    string buff;
    n_file.open( filename );
    if( !n_file.good() )
        cout<<"ERROR. Can not find \"timetable.txt\" ";
    while(n_file.good())
    {
        Event rec;
        tm date;
        char buffCategory[1000];
        char buffActivity[1000];
        int buffLen;
        memset(&date, 0, sizeof(tm));
        getline(n_file, buff);
        if (buff != "")
        {
            sscanf(
                   buff.c_str(),
                   "%[^'|']|%d/%d/%d %d:%d|%d|%[^'\n']",
                   (char*)&buffCategory,
                   &date.tm_mday,
                   &date.tm_mon,
                   &date.tm_year,
                   &date.tm_hour,
                   &date.tm_min,
                   &buffLen,
                   (char*)&buffActivity
            );
            
            date.tm_mon = date.tm_mon - 1 ;
            date.tm_year = date.tm_year - 1900;
            date.tm_isdst = 1;
            time_t dateAll = mktime(&date);
            
            mymap.insert(map<time_t, Event> :: value_type(dateAll,
                                                       Event(string(buffCategory),
                                                             dateAll,
                                                             buffLen,
                                                             string(buffActivity) ) ) );
        }
    }
    n_file.close();
}

//main function for printing
int OrganizerLib::printMap( Filtr *filtr )
{
    int result=0;
    
    for(map<time_t, Event>::iterator it=mymap.begin(); it!= mymap.end(); it++)
    {
        if( filtr->doFiltr( &it->second ) )
        {
            if(result == 0)
                cout<<"Your events: \n";
            
            char s[100];
            struct tm * d1;
            d1 = localtime(&it->first);
            
            strftime(s, 100, "%a, %d/%m/%Y %H:%M", d1);
            cout<<s;
            
            cout<<" - "<<it->second.len<<" min. -> "
                <<it->second.category<<" -> "
                <<it->second.activity<<'\n';
            result++;
        }
    }
    return result;
}

//main function for deleting
int OrganizerLib::deleteMap( Filtr *filtr )
{
    int result = 0;
    for(map<time_t, Event>::iterator it=mymap.begin(); it!= mymap.end();)
    {
        if( filtr->doFiltr( &it->second ) )
        {
            mymap.erase(it++);
           
            result++;
            modifiedCalendar = true;
        }
        else
        {
            ++it;
        }
    }
    return result;
}

void OrganizerLib::searchByTime()
{
    time_t dateSearch;
    tm dateInput;
    memset(&dateInput, 0, sizeof(tm));
    
    cout<<"Put date and time of searching event(dd/mm/yyyy hh:mm): ";
    string puts;
    getline(cin, puts);
    
    if("c" == puts)
    return;
    
    sscanf(puts.c_str(), "%d/%d/%d  %d:%d",
           &dateInput.tm_mday,
           &dateInput.tm_mon,
           &dateInput.tm_year,
           &dateInput.tm_hour,
           &dateInput.tm_min
    );
    dateInput.tm_mon = dateInput.tm_mon - 1 ;
    dateInput.tm_year = dateInput.tm_year - 1900;
    dateInput.tm_isdst = 1;
    dateSearch = mktime(&dateInput);
    int res = 0;
    for(map<time_t, Event>::iterator it=mymap.begin(); it!= mymap.end(); ++it)
    {
        if(it->first == dateSearch)
        {
            DateTimeFiltr df = DateTimeFiltr(dateSearch);
            res = printMap( &df );
            return;
        }
        else if(it->first < dateSearch && dateSearch <= (it->first+(it->second.len*60)))
        {
            DateTimeFiltr df = DateTimeFiltr(it->first);
            res = printMap( &df );
            return;
        }
    }
    if( res == 0 )
        cout<<"You have not got any event in this time. \n";
}

void OrganizerLib::deleteByTime()
{
    time_t dateDelete;
    tm dateInput;
    memset(&dateInput, 0, sizeof(tm));
    
    cout<<"Put date of deleting event(dd/mm/yyyy hh:mm): ";
    string puts;
    getline(cin, puts);
    
    if("c" == puts)
        return;

    sscanf(puts.c_str(), "%d/%d/%d  %d:%d",
        &dateInput.tm_mday,
        &dateInput.tm_mon,
        &dateInput.tm_year,
        &dateInput.tm_hour,
        &dateInput.tm_min
    );
    dateInput.tm_mon = dateInput.tm_mon - 1 ;
    dateInput.tm_year = dateInput.tm_year - 1900;
    dateInput.tm_isdst = 1;
    dateDelete = mktime(&dateInput);
   
    DateTimeFiltr df = DateTimeFiltr(dateDelete);
    int res = deleteMap( &df );
    if( res == 0 )
        cout<<"You have not got any event in this time. \n";
    else
        cout<<"Your event deleted. \n";
}

void OrganizerLib::printAll()
{
    AllFiltr af = AllFiltr();
    int res = printMap( &af );
    if( res == 0 )
        cout<<"You have not got any event. \n";
}

void OrganizerLib::workWithOutdate()
{
    OutdateFiltr af = OutdateFiltr();
    int res = printMap( &af );
    int countMenu = (-1);
    if( res != 0 )
    {
        cout<<"This is your outdated events :( \n";
        cout<<"Would you delete it? \n";
        cout<<"Press 1 to delete. \n";
        cout<<"Press 2 to go on. \n";
    
        while(countMenu != 2 && countMenu != 1)
        {
            countMenu = (-1);
            string puts;
            cout<<"Put your number: ";
            getline(cin, puts);
            sscanf(puts.c_str(), "%d", &countMenu);
            switch(countMenu)
            {
                case 1:
                {
                    OutdateFiltr of = OutdateFiltr();
                    res = deleteMap( &of );
                    cout<<"Your "<<res<<" outdate events deleted. \n";
                    break;
                }
                case 2:
                    break;
            }
        }
    }
}

void OrganizerLib::searchByCategory()
{
    string searchCategory;
    
    cout<<"Put your searching category: ";
    getline(cin, searchCategory);
    CategoryFiltr cf = CategoryFiltr(searchCategory);
    int res = printMap( &cf );
    
    if(res == 0)
        cout<<"You haven't got any events in this category :( \n";
}


void OrganizerLib::searchByDate()
{
    time_t dateSearch;
    tm dateInput;
    memset(&dateInput, 0, sizeof(tm));
    
    cout<<"Put date of searching event(dd/mm/yyyy): ";
    string puts;
    getline(cin, puts);
    
    if("c" == puts)
        return;
    
    sscanf(puts.c_str(), "%d/%d/%d",
           &dateInput.tm_mday,
           &dateInput.tm_mon,
           &dateInput.tm_year
    );
    dateInput.tm_mon = dateInput.tm_mon - 1 ;
    dateInput.tm_year = dateInput.tm_year - 1900;
    dateSearch = mktime(&dateInput);
    
    DateFiltr df = DateFiltr(dateSearch);
    int res = printMap( &df );
    if( res == 0 )
        cout<<"You have not got any event on this date. \n";
}

void OrganizerLib::nowEvents()
{
    NowFiltr nf = NowFiltr();
    int res = printMap( &nf );
    
    if(res == 0)
        cout<<"You haven't got any events for now. \n";
}

void OrganizerLib::checkChanges()
{
    if(modifiedCalendar)
    {
        cout<<"You have changes in your calendar. Do you want to save it? \n";
        cout<<"Press 1 to save \n";
        cout<<"Press 2 to discard changes \n";
        string puts;
        int n;
        getline(cin, puts);
        sscanf(puts.c_str(), "%d", &n);
        switch(n)
        {
            case 1:
            {
                saveFile();
                cout<<"See you later. \n";
                break;
            }
            case 2:
            {
                cout<<"Ok. This is the end :( See you later. \n";
                break;
            }
        }
    }
}

void OrganizerLib::addEvent()
{
    Event rec;
    tm date;
    memset(&date, 0, sizeof(tm));
    
    cout<<"Put date of your event(dd/mm/yyyy hh:mm): ";
    string putsDate;
    getline(cin, putsDate);
    if("c" == putsDate)
        return;
    sscanf(putsDate.c_str(), "%d/%d/%d %d:%d", &date.tm_mday, &date.tm_mon, &date.tm_year, &date.tm_hour, &date.tm_min);
    
    date.tm_mon = date.tm_mon - 1 ;
    date.tm_year = date.tm_year - 1900;
    time_t dateBuff =  mktime(&date);
    
    if(dateBuff < time(NULL))
    {
        cout<<"It's not allowed to create event in this time. \n";
        return;
    }
    
    for(map<time_t, Event>::iterator it=mymap.begin(); it!= mymap.end(); ++it)
    {
        if(it->first == dateBuff)
        {
            cout<<"You can't add event to this time. \n";
            cout<<"You already have event to this time. \n";
            return;
        }
        else if(it->first < dateBuff && dateBuff <= (it->first+(it->second.len*60)))
        {
            cout<<"You alredy have event to this time. \n";
            return;
        }
    }
    
    cout<<"Put length of your activity: ";
    string putsLen;
    int lenBuff;
    getline(cin, putsLen);
    if("c" == putsLen)
        return;
    sscanf(putsLen.c_str(), "%d", &lenBuff);
    if(lenBuff == 0)
    {
        cout<<"It is not allowed lenght of your event. \n";
        return;
    }
    
    cout<<"Put category of your event: ";
    string putsCategory;
    getline(cin, putsCategory);
    if("c" == putsCategory)
        return;
    
    cout<<"Put your activity: ";
    string putsActivity;
    getline(cin, putsActivity);
    if("c" == putsActivity)
        return;

    mymap.insert(map<time_t, Event> :: value_type(dateBuff,
                                                  Event(putsCategory.c_str(),
                                                        dateBuff,
                                                        lenBuff,
                                                        putsActivity.c_str() ) ) );
    
    modifiedCalendar = true;
    
    cout<<"Your event added. \n";
}

void OrganizerLib::saveFile()
{
    ofstream n_file;
    string buff;
    n_file.open( filename );
    for(map<time_t, Event>::iterator it=mymap.begin(); it!= mymap.end(); ++it)
    {
        char s[100];
        struct tm * d1;
        d1 = localtime(&it->first);
        strftime(s, 100, "%d/%m/%Y %H:%M", d1);
        
        n_file<<it->second.category<<"|"
        <<s<<"|"
        <<it->second.len<<"|"
        <<it->second.activity<<"\n";
    }
    n_file.close();
    cout<<"Your file saved. \n";
}

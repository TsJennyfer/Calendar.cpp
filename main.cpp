//
//  main.cpp
//  OrganizerCpp
//
//  Created by Yevheniia Tsapkova on 17/05/16.
//  Copyright © 2016 Yevheniia Tsapkova. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "OrganaizerLib.hpp"
using namespace std;

//const string filename = "/Users/jn/Documents/projects/Calendar.cpp/menu.txt";
//const string filename = "menu.txt";

OrganizerLib app = *new OrganizerLib();

void showTime()
{
    cout<<"\n";
    cout<<"Hello! This is your new organizer. \n";
    char time_now[100];
    time_t now = time(NULL);
    tm * ptm = localtime(&now);
    strftime(time_now, 100, "%a, %d/%m/%Y %H:%M", ptm);
    cout<<"Today is "<<time_now<<". \n \n";
}

void printMenu()
{
    string buff;
    ifstream new_file;
    new_file.open( filename );
    if( !new_file.good() )
        cout<<"ERROR. Can not find \"menu.txt\" ";
    while(new_file.good())
    {
        getline(new_file, buff);
        cout<<buff<<"\n";
    }
    new_file.close();
}

void doFunc(int countMenu)
{
    switch(countMenu)
    {
        case 1:
            printMenu();
            break;
            
        case 2:
            app.nowEvents();
            break;
            
        case 3:
            app.addEvent();
            break;
            
        case 4:
            app.searchByDate();
            break;
            
        case 5:
            app.deleteByTime();
            break;
            
        case 6:
            app.searchByCategory();
            break;
            
        case 7:
            app.saveFile();
            break;
            
        case 8:
            app.printAll();
            break;
        case 0:
            app.checkChanges();
            break;
    }
}

void putNumber()
{
    int countMenu = (-1);
    while(countMenu != 0)
    {
        countMenu = (-1);
        cout<<"Put your number: ";
        string puts;
        getline(cin, puts);
        sscanf(puts.c_str(), "%d", &countMenu);
        doFunc(countMenu);
    }
}

int main(int argc, const char * argv[])
{
    app.loadCalendarMap();
    showTime();
    app.workWithOutdate();
    printMenu();
    putNumber();
    
    return 0;
}

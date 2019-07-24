/*
    Name: Adileah Smith, Melanie Moore, Jacob Binzer, Garrett Grey, Luke Taylor
    Date:9/11/18
    Desc: 
    
    Class to measure and time an algorithm's performance
    and save the results to a csv file.
    
    setN should be called with a value, and the subsequent
    tic/toc and increment calls will be logged until another setN
    is called, or a saveResults.
    
    saveResults saves a csv file in the current directory provided
    by a string.  The columns should be n, time, A count, B count, C count.
    The file is overwritten if one already exists.
    
    //code is finished
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>
#include <ctime>


#include "timer.h"

using namespace std;

Timer::Timer() {
    incA = 0;
    incB = 0;
    incC = 0;
}

double getTimeAsDoubleSeconds(){
    struct timeval now;
    gettimeofday(&now, NULL);
    return (double)now.tv_sec + (double)now.tv_usec / 1000000.0;
}

void Timer::saveResults(string x){
    ofstream save_file;
    save_file.open(x.c_str());
    save_file << "n,time,a,b,c\n";
    
    for(unsigned int i = 0; i < all_Time.size(); i++) {
        save_file << all_Time[i].n << ",";
        save_file << all_Time[i].time_num << ",";
        save_file << all_Time[i].a << ",";
        save_file << all_Time[i].b << ",";
        save_file << all_Time[i].c << "," << endl;
    }
    
    save_file.close();
}

void Timer::setN(unsigned len){
    n_size = len;
}

void Timer::tic(){
    incA = 0;
    incB = 0;
    incC = 0;
   start_time = getTimeAsDoubleSeconds();
}

void Timer::toc(){
    time_length = (getTimeAsDoubleSeconds() - start_time);
    
    log_row_t temp_log;
    
    temp_log.n = n_size;
    temp_log.time_num = time_length;
    temp_log.a = incA;
    temp_log.b = incB;
    temp_log.c = incC;
    
    all_Time.push_back(temp_log);
    
}

void Timer::incrementA() {
    incA++;
}

void Timer::incrementB() {
    incB++;
}

void Timer::incrementC() {
    incC++;
}
#ifndef TIMER_H
#define TIMER_H
/*
    Class to measure and time an algorithm's performance
    and save the results to a csv file.
    
    setN should be called with a value, and the subsequent
    tic/toc and increment calls will be logged until another setN
    is called, or a saveResults.
    
    saveResults saves a csv file in the current directory provided
    by a string.  The columns should be n, time, A count, B count, C count.
    The file is overwritten if one already exists.
*/
#include <string>
#include <vector>

using namespace std;

struct log_row_t{
  unsigned n;
  double time_num;
  unsigned a;
  unsigned b;
  unsigned c;
};

class Timer{
    public:
    Timer();
    
    void setN(unsigned); // Sets the current n
    void tic(); // Start a timer
    void toc(); // Stops the timer
    
    void incrementA();  // Increment an a variable
    void incrementB();  // Increment a b variable
    void incrementC();  // Increment a c variable
    
    void saveResults(string);  // Saves the full data to the given
                               // filename.
    
    private:
    vector<log_row_t> all_Time;
    int n_size;
    double time_length;
    double start_time;
    int incA;
    int incB; // for increment variables all this does is count how
    int incC; // many times loops loop in an interation
    
};

#endif
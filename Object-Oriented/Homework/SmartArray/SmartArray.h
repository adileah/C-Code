#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H  

/*    @file SmartArray.cpp   
      @author < Adileah Smith >
      @date < 6/20 >

			@description Implements a class for an array with bounds checking.
      Implementatoin is below the declaration in this same file.
*/

#include <string>
#include <sstream>
#include <stdexcept>


using namespace std;

template <typename T>
class SmartArray{
  public:
  
  SmartArray(); 
  SmartArray(T);   //Defines a different default value.
  SmartArray(const SmartArray<T> &); 
  ~SmartArray(); 
  SmartArray& operator=(const SmartArray<T> &other);  
  void sort(SmartArray<T> num, int i, int j, int k);
  T& operator[](int);       // Set data in array, NO negatives
  void MergeSort(SmartArray<T> num, int i, int k);
  int size() const;     
  
  SmartArray<T> operator+(const SmartArray<T> &) const;
  bool operator==(const SmartArray<T> &) const; 
  int count(T) const; 
  
  string getAsString() const; 
  
  private:
  
  T* data;
  unsigned array_size;
  T default_value;
  //unsigned current_capacity;
};
/*                   Implementation       */
template <class T>
ostream& operator<<(ostream &o, const SmartArray<T> &r){
  o << r.getAsString();
  return o;
}

template <class T>
SmartArray<T>::SmartArray(){
  array_size = 0;
  data = NULL;
  default_value = T();
}

template <class T>
SmartArray<T>::~SmartArray(){
  if(data){
    delete[] data;
    data = NULL;
  }
}

template <class T>
SmartArray<T>::SmartArray(T value){
  array_size = 0;
  data = NULL;
  default_value = value;
}

template <class T>
T& SmartArray<T>::operator[](int location){
  if(location < 0){
    throw logic_error("Negative not allowed");
  }
  if(data == NULL){
    data = new T[location + 1];
    array_size = location + 1;
    for(unsigned i = 0; i < array_size; i++){
      data[i] = default_value;
    }
    return data[location];
  }else{
    if(location >= array_size){
      T* temp = new T[location + 1];
      for(unsigned i = 0; i < location + 1; i++){
        temp[i] = default_value;
      }
      for(unsigned i = 0; i < array_size; i++){
        temp[i] = data[i];
      }
      delete[] data;
      data = temp;
      array_size = location + 1;
    }
    
    return data[location];
  }
  
}

template <class T>
string SmartArray<T>::getAsString() const{
  stringstream s;
  s << "[";
  for(unsigned i = 0; i < array_size; i++){
    s << data[i];
    if(i != array_size - 1){
      s << ", ";
    }
  }
  s << "]";
  return s.str();
}


template <class T>
int SmartArray<T>::size() const{
  return array_size;
}


template <class T>
SmartArray<T> SmartArray<T>::operator+(const SmartArray<T> &other) const{
  SmartArray<T> bagpipe = other;
  for(unsigned i = 0; i < other.array_size; i++){
    bagpipe.data[i+array_size] = other.data[i];
  }
}

template <class T>
bool SmartArray<T>::operator==(const SmartArray<T> &other) const{
  if (array_size == other.array_size){
    for(unsigned i = 0; i < array_size; i++){
      if(data[i] != other.data[i]){return false;}
    }
    return true;
  }else{return false;}
}

template<class T>
int SmartArray<T>::count(T thing)const{
  int count = 0;
  for (unsigned i = 0; i < size(); i++){
    if (data[i] == thing){
      count++;
    }
  }
  return count;
}

template<class T>
SmartArray<T> :: SmartArray(const SmartArray<T> &other){
  for (unsigned i = 0; i < array_size; i++){
    other.data[i] = data[i];
  }
}

template<class T>
SmartArray<T>& SmartArray<T>::operator=(const SmartArray<T> &other){
  for (unsigned i = 0; i < array_size; i++){
    data[i] = other.data[i];
  }
}

template<class T>
void SmartArray<T>::sort(SmartArray<T> numbers, int i, int j, int k){
  int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   int* mergedNumbers = NULL; 

   mergePos = 0;
   mergedSize = k - i + 1;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
                                              // for merged numbers
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
}

template <class T>
void SmartArray<T>::MergeSort(SmartArray<T> numbers, int i, int k) {
   int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j);
      MergeSort(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      sort(numbers, i, j, k);
   }
}


#endif
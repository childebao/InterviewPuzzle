/*
 Question:
 As you know, two operations of Stack are push and pop. Now give you two integer arrays, one is the original array before push and pop operations, the other one is the result array after a series of push and pop operations to the first array. Please give the push and pop operation sequence.
 For example:
 If the original array is a[] = {1,2,3}, and the result array is b[] = {1,3,2}.
 Then, the operation sequence is “push1|pop1|push2|push3|pop3|pop2”(operations are split by ‘|’ and no space).
 Rules:
 •	The push and pop operations deal with the original int array from left to right.
 •	The input is two integer array. They are the original array and the result array. These interger array is split by space.
 •	The output is the operation sequence.
 •	If the original array cannot make to the result array with stack push and pop, The output should be 'None'.
 •	The operation "push1" means push the first element of the original array to the stack.
 •	The operation "pop1" means pop the first element of the original array from the stack, and add this element to the tail of the result array.
 •	Please don't include any space in the output string.
 Sample1:   Input:  1 2 3 4
 1 2 3 4  Output:  push1|pop1|push2|pop2|push3|pop3|push4|pop4
 Sample2: 
 Input:
 1 2 3 4
 4 3 2 1  Output:  push1|push2|push3|push4|pop4|pop3|pop2|pop1
 */


#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

char* calculateOperationSequence(int *originalArray, int *resultArray, int length);

inline bool isSpace(char x){
  return x == ' ' || x == '\r' || x == '\n' || x == '\r' || x == '\b' || x == '\t';
}

char * rightTrim(char *str){
  int len = strlen(str);
  while(--len>=0){
    if(isSpace(str[len])){
      str[len] = '\0';
    }else{
      break;
    }
  }
  return str;
}

char * getInputLine(char *buffer, int length){
  if(fgets(buffer,length, stdin)==NULL){
    return NULL;
  }
  rightTrim(buffer);
  if(strlen(buffer)<=0){
    return NULL;
  }
  return buffer;
}

int splitAndConvert(char* strings,int *array){
  char*tokenPtr = strtok(strings,",");
  int i=0;
  while(tokenPtr!=NULL){
    array[i] = atoi(tokenPtr);
    i++;
    tokenPtr=strtok(NULL,",");
  }
  return i;
}

int main(){
  char line[1000] = {0} ;
  while(getInputLine(line,1000)){
    int originalArray[30] = {0};
    int originalArrayLength = splitAndConvert(line,originalArray);
    if(originalArrayLength==0){
      break;
    }
    
    getInputLine(line, 1000);
    int resultArray[30] = {0};
    int resultArrayLength = splitAndConvert(line,resultArray);
    if(resultArrayLength==0){
      break;
    }
    
    char* operationSequence = calculateOperationSequence(originalArray, resultArray, resultArrayLength);
    cout<<operationSequence<<endl;
  }
  return 0; 
} 

//your code is here

string int2String(int num)
{
  string numString;
  ostringstream convert;
  convert << num;
  numString = convert.str();
  return numString;
}

string answer = ""; 

bool search(int pushedIndex, int poppedNumbers, string operations, int * originalArray, int * resultArray, int length)
{
  int idxa = 1  , idxb = 0 , top = 0;
  int stack[ length+1 ] , sd[ length+1 ];
  
  if( length <= 0 ) { 
    return true;// for no number
  }   
  operations = "push1";
  stack[0] = originalArray[0];
  sd[0] = 1;
  while( idxb < length ){
    if( top >= 0 && stack[top] == resultArray[idxb] ){
      operations =operations + "|pop" + int2String(sd[top--]);
      idxb++;
    }else if(idxa < length){
      stack[++top] = originalArray[idxa++];
      sd[top] = idxa;
      operations =operations + "|push" + int2String(sd[top]);
    }else{
      return false;
    }   
  }   
  cout << operations << endl;
  return true; 
}

char* calculateOperationSequence(int * originalArray, int * resultArray, int length)
{
  string operations;                                                                                                                                         
  
  bool result = search(0, 0, operations, originalArray, resultArray, length);
  
  cout << operations << endl;
  if (!result) {
    answer = "None";
  }
  
  char * operationArray = new char[answer.length() + 1]; 
  strcpy(operationArray, answer.c_str());
  return operationArray;
}

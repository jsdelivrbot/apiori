#ifndef APRIORI
#define APRIORI

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

#define blankSpace 32
#define newLine 10

using namespace std;

class Apriori
{
    private:
        LinkedList<int> startingData;
		LinkedList<int> oldList;
		LinkedList<int> newList;
        int getDataFileCount(ifstream& inputFile);
    public:
        //void findMinFrequ();
        template <typename T>
        void cFirstCandList(); //create first candidate list

        void fillStartingData(string file);
		Apriori();
};

Apriori::Apriori()
{

}


void Apriori::fillStartingData(string file)
{
    ifstream inputFile;
    inputFile.open("testdata.txt");
    int hello;
    int startingPosition;
    do
    {

        startingPosition = inputFile.tellg(); //tellg get the position of the file input

        hello = getDataFileCount(inputFile);
        cout << hello << "\n";
		if(hello == -1){
			cout << "hello \n";
		  break;
		}
		else{
		  inputFile.seekg(startingPosition,inputFile.beg);
		  startingData.createArray(hello);
		  string input;
		  char random;
		  for(int i = 0; i <= hello; i++){
			inputFile >> input;
			cout << endl << input << " " << i << "  \n";
			startingData.setArrayData(i,stoi(input));
			random  = inputFile.get(); // get the black space and new line characters
		  }
		}//end of else statment
	
    }while(hello != -1 && !inputFile.eof());

    inputFile.close();
}

/*
pre:
post: return the number of items per line
1 item = return of 0
purpose: is to get the total amount of items so we can make a static array
 */

int Apriori::getDataFileCount(ifstream& inputFile)
{
    int count;
    char check = 0;
    string junk;
    if(inputFile.eof())
    {
        count = -1;
    }
    else
    {
        for(count = 0 ;check != newLine && !inputFile.eof();)
        {
            inputFile >> junk;
            check = inputFile.get();
            if(check == blankSpace)
            {
                count++;
            }
			if((int)check == -1){
			  count = -1;
			  break;
			}
        }
    }
    return count;
}



/*
void Apriori::findMinFrequ()
{
    
    
}
*/
template <typename T>
void Apriori::cFirstCandList()
{
    
    startingData.clearIterator();
    do{
        T* data = startingData.getIteratorValue();
        for(int i = 0; i < startingData.getIteratorSize()+ 1; i++)
        {
            if(!startingData.search(data[i])) //not found
            {
                Node<T>* newNode = new Node<T>(0, data);
                startingData.appendToTheEnd(newNode);
            }
        }
    }while(startingData++);
}


#endif
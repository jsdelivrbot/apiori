{"changed":true,"filter":false,"title":"Apriori.h","tooltip":"/header_files/Apriori.h","value":"/*\nError log\ngood\n*/\n\n#ifndef APRIORI\n#define APRIORI\n\n#include <iostream>\n#include <fstream>\n#include <string>\n#include \"LinkedList.h\"\n\n#define blankSpace 32\n#define newLine 10\n\nusing namespace std;\n\ntemplate <typename T>\nclass Apriori\n{\n    private:\n    //members\n        LinkedList<T> startingData;\n\t\tLinkedList<T> oldList;\n\t\tLinkedList<T> newList;\n        int mFrequencyThreshold;  //s on the paper\n        int mCountTransactions;\n    //end of members   \n        int getDataFileCount(ifstream& inputFile);\n    //makes new item sets\n        \n        Node<T>* makeNewNode(Node<T>* temp1, Node<T>* temp2);\n        bool isSame(Node<T>* temp1, Node<T>* temp2);\n    //end of make new Sets??????!??!!?!?!?!?!?!?!?!\n    public:\n    //for the first time\n        void cFirstCandList(); //create first candidate list\n        void fillStartingData(string file);\n        \n    //magic\n        void purge();\n        int getCount(){return newList.getCount();};\n        \n        \n        \n    //setters\n        void setFrequencyThreshold(float percentage);\n        void setCountTransactions(int count);\n        \n    //utilites\n        void prune();\n\t\tbool checkForItemsFrequency(Node<T>* set);// if it's larger than frequency threshold it's good\n\t\tvoid displayEverthing();\n\t\tvoid print();\n\t\tvoid makeSets();\n\t//constructors\n\t\tApriori();\n\t\tApriori(int frequencyThreshold);\n\t\t~Apriori();\n};\ntemplate <typename T>\nApriori<T>::Apriori()\n{\n    mFrequencyThreshold = 5;\n}\ntemplate <typename T>\nApriori<T>::~Apriori()\n{\n    startingData.clear();\n    oldList.clear();\n    newList.clear();\n}\ntemplate <typename T>\nApriori<T>::Apriori(int frequencyThreshold)\n{\n    mFrequencyThreshold = frequencyThreshold;\n}\n\n/*\nit shoots one to many\n*/\ntemplate <typename T>\nvoid Apriori<T>::fillStartingData(string file)\n{\n    ifstream inputFile;\n    inputFile.open(\"testdata.txt\");\n    int itemsInTransactions = 0; //number of items bought per transaction\n    int startingPosition;\n    int numberOfTransactions = 0; //total amount of transactions\n  \n    while(numberOfTransactions <= mCountTransactions && !inputFile.eof() && itemsInTransactions != -1)\n    {\n        startingPosition = inputFile.tellg(); //tellg get the position of the file input\n        itemsInTransactions = getDataFileCount(inputFile);\n        if(itemsInTransactions == - 1){ // error saying didn't take in any numbers\n    \t\tcout << \"error error \\n\"\n    \t\t     << \"broke with less then wanted number of transaction \\n\" \n    \t\t     << \"endded with \"  << numberOfTransactions << \"\\n\\n\\n\"  ;\n    \t\tbreak;\n        }\n    \telse\n    \t{\n            inputFile.seekg(startingPosition,inputFile.beg);\n            startingData.createArray(itemsInTransactions);\n            string junk;\n            string input;\n            for(int i = 0; i < itemsInTransactions; i++)\n            {\n    \t\t\tinputFile >> junk; //gettint the transactional number\n    \t\t\tinputFile.get(); //getting the space\n    \t\t\tinputFile >> input; //gets the input number\n\t\t\t    inputFile.get();// gets the newline character\n    \t\t\tstartingData.setArrayData(i,stoi(input));\n\t        }\n    \t}\n    numberOfTransactions++;\n    }\n    inputFile.close();\n}\n\n/*\npre:\npost: return the number of items per line\n1 item = return of 1\npurpose: is to get the total amount of items so we can make a static array\n */\ntemplate <typename T>\nint Apriori<T>::getDataFileCount(ifstream& inputFile)\n{\n    int count = 0;\n    \n    if(inputFile.eof())\n    {\n        count = -1;\n    }\n    else\n    {\n        string getLineString;\n        getline(inputFile, getLineString);\n        char transactionNumber = getLineString[0];\n        do\n        {\n            count++; // it add plus plus for the item before this\n            getline(inputFile, getLineString);\n        }while(transactionNumber == getLineString[0]); //so ifthe transaction number don't match\n    }\n    return count;\n}\n\n\n/*\nhave not tested with search works\n*/\ntemplate <typename T>\nvoid Apriori<T>::cFirstCandList()\n{\n    \n    startingData.clearIterator();\n    do{\n        T* data = startingData.getIteratorValue();\n        for(int i = 0; i < startingData.getIteratorSize(); i++)\n        {\n            if(!newList.search(data[i])) //not found\n            {\n                Node<T>* newNode = new Node<T>(1, data[i]);\n                newList.appendToTheEnd(newNode);\n            }\n        }\n    }while(startingData++);\n}\ntemplate <typename T>\nvoid Apriori<T>::displayEverthing()\n{\n    //startingData.display();\n    //oldList.display();\n    newList.display();\n}\n\n\n\n//adds new nodes to new list\n/*\ndoesn't check for doub's but i don't think it needs to\n*/\ntemplate <class T>\nvoid Apriori<T>::makeSets() //uses the new and old linked list\n{\n    oldList.operatorEquals(newList);\n    newList.setHead(NULL);\n    newList.clear(); //mcount = 0;\n\n    int setCount; // one after the node your on\n    int nodeCount = 0; //keeps track of node your on\n    Node<T>* temp1 = oldList.getHead();\n    Node<T>* temp2 = temp1;\n    \n   //sets starting node and proceeding node to start traversal\n   while(temp1->mNext != NULL)\n   {\n        temp2 = temp1;\n        setCount = nodeCount + 1;\n        //compares one node with all other nodes\n        while(setCount < oldList.getCount()) \n        {\n            temp2 = temp2->mNext;\n            if(isSame(temp1, temp2))  //check to see if compatible\n            {\n                newList.appendToTheEnd(makeNewNode(temp1, temp2));\n            }\n            setCount++;\n        }\n        nodeCount++;\n        temp1 = temp1->mNext;\n   }\n}\n\n//adds data to the new node\ntemplate <class T>\nNode<T>* Apriori<T>::makeNewNode(Node<T>* temp1, Node<T>* temp2)\n{\n   Node<T>* newNode = new Node<T>(temp1->mSize + 1);\n\n   for(int i = 0; i < temp1->mSize; i++)\n   {\n      newNode->mData[i] = temp1->mData[i];\n   }\n   newNode->mData[newNode->mSize - 1] = temp2->mData[temp2->mSize - 1];\n   return newNode; //just added\n}\n\n//checks to see if all elements in sets are the same except for last element\ntemplate <class T>\nbool Apriori<T>::isSame(Node<T>* temp1, Node<T>* temp2)\n{\n   bool theSame = true;\n   \n   for(int i = 0; i < temp1->mSize; i++)\n   {\n      if(temp1->mData[i] != temp2->mData[i] && i < temp1->mSize - 1)\n         theSame = false;\n   }\n   \n   return theSame;\n}\n\n//makes threshold frequency\ntemplate <class T>\nvoid Apriori<T>::setFrequencyThreshold(float percentage)\n{\n    mFrequencyThreshold = (mCountTransactions * percentage) / 100;\n}\n\n//sets transaction count\ntemplate <class T>\nvoid Apriori<T>::setCountTransactions(int count)\n{\n    mCountTransactions = count;\n}\n\n//check if subsets in set exist \ntemplate <class T>\nvoid Apriori<T>::prune()\n{\n\tNode<T>* currNode = newList.getHead();\n\tNode<T>* lastNode = NULL;  //previous node\n\twhile(currNode != NULL)\n\t{\n    \tfor(int i = 0; i < oldList.getCount(); i++)\n    \t{\n    \t\tfor(int j = 0; j < currNode->mSize; j++)// this bunch of code create all possible combinations.\n    \t\t{\n\t\t\t\tT* subset = new T[currNode->mSize - 1];  //one less than current node's size\n\t\t\t\tfor(int k = 0; k < currNode->mSize; k++)\n\t\t\t\t{\n\t\t\t\t\tif(k < j)\n\t\t\t\t\t{\n\t\t\t\t\t\tsubset[k] = currNode->mData[k];\n\t\t\t\t\t}\t\t\t\t\n                    if(k > j)\n\t\t\t\t\t{\n\t\t\t\t\t\tsubset[k-1] = currNode->mData[k];\n\t\t\t\t\t}\n\t\t\t\t} //end of for K < currNode->size\n\t\t\t\tNode<T>* subsetNode = new Node<T>(currNode->mSize - 1,subset, 0);\n\t\t\t\tif(!oldList.searchForNode(subsetNode)) //checkListForNode?\n\t\t\t\t{\n\t\t\t\t    if(i != 0)\n\t\t\t\t    {\n    \t\t\t\t\tcurrNode = lastNode;\n\t\t\t\t    }\n\t\t\t\t    else\n\t\t\t\t    {\n\t\t\t\t        currNode = NULL;\n\t\t\t\t    }\n                    newList.deleteByIndex(i);\n    \t\t\t    i--;\n\t\t\t    }\n\t\t\t    delete subsetNode;\n    \t\t} // end of for J < CurrNode->mSize\n    \t} //end of I < old.mCount\n    \tif(currNode == NULL)\n    \t{\n    \t    currNode = newList.getHead();\n    \t}\n    \telse\n    \t{\n            lastNode = currNode;\n    \t    currNode = currNode->mNext;\n    \t}\n\t}//end of the while(cNode != NULL)\n}\n\n//takes out non frequent sets\ntemplate <class T>\nvoid Apriori<T>::purge()\n{\n    Node<T>* currNode = newList.getHead();\n    for(int i = 0; currNode != NULL; i++ )\n    {\n        if(!checkForItemsFrequency(currNode)) // if it doesn't meet the minume frequency then delete\n        {\n            newList.deleteByIndex(i);\n            i--;\n        }\n        currNode = currNode->mNext;\n    }\n}\n\n/*\npre:linked list must have data\npost: its going to return true if it passes the min frequency threshold else false\npurpose: check the frequency and delete it if its to low.\n*/\ntemplate <class T>\nbool Apriori<T>::checkForItemsFrequency(Node<T>* set)\n{\n    startingData.clearIterator();\n    bool found;\n    int count = 0;\n    do\n    {\n        T* iterData = startingData.getIteratorValue();\n        for(int i = 0; i < set->mSize; i++) //checking set\n        {\n            found = false;\n            for(int j = 0; j < startingData.getIteratorSize(); j++) //overall data\n            {\n                if(set->mData[i] == iterData[j])\n                {\n                    found = true;\n                    break;\n                }\n            }\n            if(!found) break;\n            if(i == set->mSize - 1) count++; //so if it found it for all of mSize then all the values been found\n        }\n    }while(startingData++);\n    \n    if(count >= mFrequencyThreshold)\n    {\n        return true;\n    }\n    else\n    {\n        return false;\n    }\n}\ntemplate <class T>\nvoid Apriori<T>::print()\n{\n    newList.print();\n}\n#endif\n","undoManager":{"mark":97,"position":100,"stack":[[{"group":"doc","deltas":[{"start":{"row":261,"column":22},"end":{"row":261,"column":23},"action":"remove","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":22},"end":{"row":261,"column":23},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":23},"end":{"row":261,"column":24},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":24},"end":{"row":261,"column":25},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":25},"end":{"row":261,"column":26},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":26},"end":{"row":261,"column":27},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":27},"end":{"row":261,"column":28},"action":"insert","lines":["x"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":28},"end":{"row":261,"column":29},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":29},"end":{"row":261,"column":30},"action":"insert","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":30},"end":{"row":261,"column":31},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":31},"end":{"row":261,"column":32},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":32},"end":{"row":261,"column":33},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":32},"end":{"row":261,"column":33},"action":"remove","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":28},"end":{"row":261,"column":29},"action":"remove","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":28},"end":{"row":261,"column":29},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":261,"column":28},"end":{"row":261,"column":29},"action":"remove","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":2},"end":{"row":254,"column":3},"action":"insert","lines":["f"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":3},"end":{"row":254,"column":4},"action":"insert","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":4},"end":{"row":254,"column":5},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":5},"end":{"row":254,"column":6},"action":"insert","lines":["d"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":6},"end":{"row":254,"column":7},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":7},"end":{"row":254,"column":8},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":8},"end":{"row":254,"column":9},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":9},"end":{"row":254,"column":10},"action":"insert","lines":["u"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":9},"end":{"row":254,"column":10},"action":"remove","lines":["u"]}]}],[{"group":"doc","deltas":[{"start":{"row":254,"column":8},"end":{"row":254,"column":9},"action":"remove","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":3,"column":0},"end":{"row":4,"column":0},"action":"remove","lines":["So currently there a problem with getDataFileCount it doens't get the last line of data.  It someithng with testing for the -1 part",""]}]}],[{"group":"doc","deltas":[{"start":{"row":253,"column":7},"end":{"row":253,"column":8},"action":"remove","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":253,"column":6},"end":{"row":253,"column":7},"action":"remove","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":253,"column":5},"end":{"row":253,"column":6},"action":"remove","lines":["d"]}]}],[{"group":"doc","deltas":[{"start":{"row":253,"column":4},"end":{"row":253,"column":5},"action":"remove","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":1,"column":9},"end":{"row":3,"column":0},"action":"remove","lines":["","",""]}]}],[{"group":"doc","deltas":[{"start":{"row":251,"column":3},"end":{"row":251,"column":4},"action":"remove","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":251,"column":2},"end":{"row":251,"column":3},"action":"remove","lines":["f"]}]}],[{"group":"doc","deltas":[{"start":{"row":1,"column":9},"end":{"row":2,"column":0},"action":"insert","lines":["",""]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":2},"end":{"row":252,"column":3},"action":"insert","lines":["g"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":3},"end":{"row":252,"column":4},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":4},"end":{"row":252,"column":5},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":5},"end":{"row":252,"column":6},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":2,"column":0},"end":{"row":2,"column":4},"action":"insert","lines":["good"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":6},"end":{"row":252,"column":7},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":7},"end":{"row":252,"column":8},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":8},"end":{"row":252,"column":9},"action":"insert","lines":["r"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":9},"end":{"row":252,"column":10},"action":"insert","lines":["a"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":10},"end":{"row":252,"column":11},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":11},"end":{"row":252,"column":12},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":12},"end":{"row":252,"column":13},"action":"insert","lines":["a"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":13},"end":{"row":252,"column":14},"action":"insert","lines":["c"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":14},"end":{"row":252,"column":15},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":15},"end":{"row":252,"column":16},"action":"insert","lines":["i"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":16},"end":{"row":252,"column":17},"action":"insert","lines":["o"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":17},"end":{"row":252,"column":18},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":18},"end":{"row":252,"column":19},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":19},"end":{"row":252,"column":20},"action":"insert","lines":["c"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":20},"end":{"row":252,"column":21},"action":"insert","lines":["o"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":21},"end":{"row":252,"column":22},"action":"insert","lines":["u"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":22},"end":{"row":252,"column":23},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":23},"end":{"row":252,"column":24},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":34,"column":23},"end":{"row":34,"column":25},"action":"remove","lines":["te"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":2},"end":{"row":252,"column":6},"action":"remove","lines":["gets"]},{"start":{"row":252,"column":2},"end":{"row":252,"column":3},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":34,"column":23},"end":{"row":34,"column":24},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":3},"end":{"row":252,"column":4},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":4},"end":{"row":252,"column":5},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":252,"column":5},"end":{"row":252,"column":6},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":34,"column":24},"end":{"row":34,"column":27},"action":"insert","lines":["ts?"]}]}],[{"group":"doc","deltas":[{"start":{"row":34,"column":27},"end":{"row":34,"column":36},"action":"insert","lines":["?????!??!"]}]}],[{"group":"doc","deltas":[{"start":{"row":34,"column":36},"end":{"row":34,"column":51},"action":"insert","lines":["!?!?!?!?!?!?!?!"]}]}],[{"group":"doc","deltas":[{"start":{"row":311,"column":0},"end":{"row":312,"column":0},"action":"insert","lines":["",""]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":0},"end":{"row":312,"column":1},"action":"insert","lines":["/"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":1},"end":{"row":312,"column":2},"action":"insert","lines":["/"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":2},"end":{"row":312,"column":3},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":3},"end":{"row":312,"column":4},"action":"insert","lines":["a"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":4},"end":{"row":312,"column":5},"action":"insert","lines":["k"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":5},"end":{"row":312,"column":6},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":6},"end":{"row":312,"column":7},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":7},"end":{"row":312,"column":8},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":8},"end":{"row":312,"column":9},"action":"insert","lines":["o"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":9},"end":{"row":312,"column":10},"action":"insert","lines":["u"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":10},"end":{"row":312,"column":11},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":11},"end":{"row":312,"column":12},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":12},"end":{"row":312,"column":13},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":13},"end":{"row":312,"column":14},"action":"insert","lines":["o"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":14},"end":{"row":312,"column":15},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":15},"end":{"row":312,"column":16},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":16},"end":{"row":312,"column":17},"action":"insert","lines":["f"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":17},"end":{"row":312,"column":18},"action":"insert","lines":["r"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":18},"end":{"row":312,"column":19},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":19},"end":{"row":312,"column":20},"action":"insert","lines":["q"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":20},"end":{"row":312,"column":21},"action":"insert","lines":["u"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":21},"end":{"row":312,"column":22},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":22},"end":{"row":312,"column":23},"action":"insert","lines":["n"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":23},"end":{"row":312,"column":24},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":24},"end":{"row":312,"column":25},"action":"insert","lines":[" "]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":25},"end":{"row":312,"column":26},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":26},"end":{"row":312,"column":27},"action":"insert","lines":["e"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":27},"end":{"row":312,"column":28},"action":"insert","lines":["t"]}]}],[{"group":"doc","deltas":[{"start":{"row":312,"column":28},"end":{"row":312,"column":29},"action":"insert","lines":["s"]}]}],[{"group":"doc","deltas":[{"start":{"row":38,"column":43},"end":{"row":39,"column":8},"action":"insert","lines":["","        "]}]}],[{"group":"doc","deltas":[{"start":{"row":52,"column":63},"end":{"row":52,"column":64},"action":"remove","lines":["e"]},{"start":{"row":52,"column":63},"end":{"row":52,"column":64},"action":"insert","lines":["a"]}]}],[{"group":"doc","deltas":[{"start":{"row":52,"column":88},"end":{"row":52,"column":89},"action":"insert","lines":["'"]}]}],[{"group":"doc","deltas":[{"start":{"row":52,"column":52},"end":{"row":52,"column":53},"action":"insert","lines":["'"]}]}]]},"ace":{"folds":[],"scrolltop":5224,"scrollleft":0,"selection":{"start":{"row":332,"column":57},"end":{"row":332,"column":57},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":20,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1417749463770}
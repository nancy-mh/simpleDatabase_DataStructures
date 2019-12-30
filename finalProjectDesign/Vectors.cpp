//Nancy Moreno Huizar

#include "Vectors.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

//function is called by searcRecord function, defined in main, it intakes a a number that matches to a field or record and a vector that has a copy of all tree nodes. Indexes of this vector are search for the information entered by user and if a match, it is added to a vector that is returned
vector<ActorActress> ActorActress::exactSearch(int field, vector<ActorActress>& vectorToBeSearched)
{
   ActorActress actorActressObj;
    vector<ActorActress> resultVector;
    int index=0;
   
    
    if (field == 1)
    {
        string year;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore(INT32_MAX, '\n');
    
        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getYear() == stoi(year))
            {
                actorActressObj = vectorToBeSearched[index];
                resultVector.push_back(actorActressObj);
                
            }
            index++;
        }
    }
    
   else if (field == 2)
    {
        string award;
        cout << "Enter award: ";
        getline (cin, award);

        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getAward() == award)
            {
                actorActressObj = vectorToBeSearched[index];
                resultVector.push_back(actorActressObj);
            }
            index++;
        }
    }
   else if (field == 3)
   {
       string name;
       cout << "Enter name: ";
       getline (cin, name);
       
       while (index < vectorToBeSearched.size())
       {
           if (vectorToBeSearched[index].getName() == name)
           {
               actorActressObj = vectorToBeSearched[index];
               resultVector.push_back(actorActressObj);
           }
           index++;
       }
   }

   else if (field == 4)
    {
        string film;
        cout << "Enter film: ";
        getline (cin, film);
        
        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getFilm() == film)
            {
                actorActressObj = vectorToBeSearched[index];
                resultVector.push_back(actorActressObj);
            }
            index++;
        }
    }

    return resultVector;
}
    

vector<Pictures> Pictures::exactSearch(int field, vector<Pictures>& vectorToBeSearched)
{
    Pictures picturesObj;
    vector<Pictures> resultVector;
    int loopCounter =0;
 
    int index=0;
    
    if (field == 2)
    {
        string year;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore(INT32_MAX, '\n');
        
        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getYear() == stoi(year))
            {
                picturesObj = vectorToBeSearched[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            index++;
        }
        if (loopCounter == vectorToBeSearched.size())
        {
            cout << "No matching records were found.\n";
        }
    }
    else if (field == 1)
    {
        string name;
        cout << "Enter name: ";
        getline (cin, name);
        
        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getName() == name)
            {
                picturesObj = vectorToBeSearched[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            index++;
        }
        if (loopCounter == vectorToBeSearched.size())
        {
            cout << "No matching records were found.\n";
        }
    }
    else if (field == 3)
    {
        string genre1;
        cout << "Enter genre1: ";
        getline (cin, genre1);
        
        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getGenre1() == genre1)
            {
                picturesObj = vectorToBeSearched[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            index++;
        }
        if (loopCounter == vectorToBeSearched.size())
        {
            cout << "No matching records were found.\n";
        }
    }
    else if (field == 4)
    {
        string genre2;
        cout << "Enter genre2: ";
        getline (cin, genre2);
        
        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getGenre2() == genre2)
            {
                picturesObj = vectorToBeSearched[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            index++;
        }
        if (loopCounter == vectorToBeSearched.size())
        {
            cout << "No matching records were found.\n";
        }
    }
    else if (field == 5)
    {
        string release;
        cout << "Enter release: ";
        getline (cin, release);
        
        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getRelease() == release)
            {
                picturesObj = vectorToBeSearched[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            index++;
        }
        if (loopCounter == vectorToBeSearched.size())
        {
            cout << "No matching records were found.\n";
        }
    }
    else if (field == 6)
    {
        string synopsis;
        cout << "Enter synopsis: ";
        getline (cin, synopsis);
        
        while (index < vectorToBeSearched.size())
        {
            if (vectorToBeSearched[index].getSynopsis() == synopsis)
            {
                picturesObj = vectorToBeSearched[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            index++;
        }
        if (loopCounter == vectorToBeSearched.size())
        {
            cout << "No matching records were found.\n";
        }
    }
    
    else
    {
        cout << "You have chosen an invalid field.\n";
    }
    
    return resultVector;
}


// referance http://www.cplusplus.com/reference/string/string/find/
// to understand how the find function in strings work
vector<ActorActress> ActorActress:: containsSearch (int field, vector<ActorActress>& inputVector)
{
    ActorActress actorActressObj;
    vector<ActorActress> resultVector;
    int index=0;
    int loopCounter =0;
    
    if (field == 1)
    {
        string year;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore(INT32_MAX, '\n');
        
        while (index < inputVector.size())
        {
            string temp = to_string(inputVector[index].getYear());
            unsigned long foundFlag =0;
        
            foundFlag = temp.find(year);   // if the input is not found foundFlag will be assigned a giant number
            if (!(foundFlag > temp.length())) // this it can be compared to the length the string being searched
            {
               actorActressObj = inputVector[index];
                 resultVector.push_back(actorActressObj);
                
            }
            else
            {
                loopCounter++;
            }
        
            index++;
        }
    
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
    }
    if (field == 2)
    {
        string award;
        cout << "Enter award: ";
        getline (cin, award);
        
        while (index < inputVector.size())
        {
            string temp = inputVector[index].getAward();
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(award);
            if (!(foundFlag > temp.length()))
            {
                actorActressObj = inputVector[index];
                resultVector.push_back(actorActressObj);
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }

    }
    if (field == 4)
    {
        string film;
        cout << "Enter film: ";
        getline (cin, film);
        
        while (index < inputVector.size())
        {
            string temp = inputVector[index].getFilm();
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(film);
            if (!(foundFlag > temp.length()))
            {
                actorActressObj = inputVector[index];
                resultVector.push_back(actorActressObj);
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
        
    }
    if (field == 3)
    {
        string name;
        cout << "Enter name: ";
        getline (cin, name);
        
        while (index < inputVector.size())
        {
            string temp = inputVector[index].getName();
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(name);
            if (!(foundFlag > temp.length()))
            {
                actorActressObj = inputVector[index];
                resultVector.push_back(actorActressObj);
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
        
    }
    
     return resultVector;
}

vector<Pictures> Pictures:: containsSearch (int field, vector<Pictures>& inputVector)
{
    Pictures picturesObj;
    vector<Pictures> resultVector;
    int index=0;
    int loopCounter =0;
    
    if (field == 2)
    {
        string year;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore(INT32_MAX, '\n');
        
        while (index < inputVector.size())
        {
            string temp = to_string(inputVector[index].getYear());
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(year);
            if (!(foundFlag > temp.length()))
            {
                picturesObj = inputVector[index];
                resultVector.push_back(picturesObj);
                
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
    }
    if (field == 2)
    {
        string name;
        cout << "Enter name: ";
        getline (cin, name);
        
        while (index < inputVector.size())
        {
            string temp = inputVector[index].getName();
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(name);
            if (!(foundFlag > temp.length()))
            {
                picturesObj = inputVector[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
        
    }
    if (field == 3)
    {
        string genre1;
        cout << "Enter genre1: ";
        getline (cin, genre1);
        
        while (index < inputVector.size())
        {
            string temp = inputVector[index].getGenre1();
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(genre1);
            if (!(foundFlag > temp.length()))
            {
                picturesObj = inputVector[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
        
    }
    if (field == 4)
    {
        string genre2;
        cout << "Enter genre2: ";
        getline (cin, genre2);
        
        while (index < inputVector.size() )
        {
            string temp = inputVector[index].getGenre2();
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(genre2);
            if (!(foundFlag > temp.length()))
            {
                picturesObj = inputVector[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
        
    }
    if (field == 5)
    {
        string release;
        cout << "Enter release: ";
        getline (cin, release);
        
        while (index < inputVector.size())
        {
            string temp = inputVector[index].getRelease();
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(release);
            if (!(foundFlag > temp.length()))
            {
                picturesObj = inputVector[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
        
    }
    if (field == 6)
    {
        string synopsis;
        cout << "Enter synopsis: ";
        getline (cin, synopsis);
        
        while (index < inputVector.size())
        {
            string temp = inputVector[index].getSynopsis();
            unsigned long foundFlag =0;
            
            foundFlag = temp.find(synopsis);
            if (!(foundFlag > temp.length()))
            {
                picturesObj = inputVector[index];
                resultVector.push_back(picturesObj);
            }
            else
            {
                loopCounter++;
            }
            
            index++;
        }
        
        if (loopCounter == inputVector.size())
        {
            cout << "No matching records were found.\n";
        }
        
    }
    return resultVector;
}

// function does a selection sort on input vector by the field chosen by user and returned this same vector
// a merge sort implmentation would yield better preformance for a larger database
vector<ActorActress> ActorActress:: sort(vector<ActorActress>& inputVector, int sortCategory)
{
    
    
    ActorActress actorActressObj;
    
    if (sortCategory == 4)
    {
      
        
        for (int row=0;row<inputVector.size();row++)   // will walk through the rows of the vector, theres only one row
        {
            for (int index=0;index<inputVector.size()-1;++index)  // will walk through objects of vector
            {
                if (inputVector[index].getFilm() > inputVector[index+1].getFilm())  //compares the film of first object to the
                    // film of the second object
                {
                    actorActressObj=inputVector[index];  //object with film of greater ACSII value is held in object
                    
                    inputVector[index]=inputVector[index+1]; // places object with film of higher ASCII value into the second
                    // index
                    
                    inputVector[index+1]=actorActressObj;   // object now has object with greater ASCII value

                }
            }
        }
        
    }
    
    if (sortCategory == 3 )
        
    {
        for (int row=0;row<inputVector.size();row++)
        {
            for (int index=0;index<inputVector.size()-1;index++)
            {
                
                if (inputVector[index].getName() > inputVector[index+1].getName())
                    
                {
                    actorActressObj=inputVector[index];
                    
                    inputVector[index]=inputVector[index+1];
                  
                    
                    inputVector[index+1]=actorActressObj;
                    
                }
            }
            
       }
    }
    
    if (sortCategory == 2)
    {
        for (int row=0;row<inputVector.size();row++)
        {
            for (int index=0;index<inputVector.size()-1;index++)
            {
                if (inputVector[index].getAward() > inputVector[index+1].getAward())
                    
                {
                    actorActressObj=inputVector[index];
                    
                    inputVector[index]=inputVector[index+1];
                    
                    
                    inputVector[index+1]=actorActressObj;
                    
                }
            }
            
        }
    
    }
    
    if (sortCategory == 1)
    {
        
        for (int row=0;row<inputVector.size();row++)
        {
            for (int index=0;index<inputVector.size()-1;index++)
            {
                if (inputVector[index].getYear() > inputVector[index+1].getYear())
                    
                {
                    actorActressObj=inputVector[index];
                    
                    inputVector[index]=inputVector[index+1];
                   
                    
                    inputVector[index+1]=actorActressObj;
                   
                }
            }
        }
        for (int row=0;row<inputVector.size();row++)
        {
            for (int index=0;index<inputVector.size()-1;index++)
            {
                if (inputVector[index].getYear() > inputVector[index+1].getYear())
                    
                {
                    actorActressObj=inputVector[index];
                    
                    inputVector[index]=inputVector[index+1];
                   
                    
                    inputVector[index+1]=actorActressObj;
                  
                }
            }
        }
    }
    
    
    return   inputVector;
}

vector<Pictures> Pictures:: sort(vector<Pictures>& inputVector, int sortCategory)
{
    Pictures picturesObj;
    
            if (sortCategory == 3)
            {
                for (int row=0;row<inputVector.size();row++)
                {
                    for (int index=0;index<inputVector.size()-1;index++)
                    {
                        
                if (inputVector[index].getGenre1() > inputVector[index+1].getGenre1())
                    
                {
                    picturesObj=inputVector[index];
                    
                   inputVector[index]=inputVector[index+1];
                    
                    
                    inputVector[index+1]=picturesObj;
                }
            }
                }
            }
           else if (sortCategory == 4)
            {
                
                for (int row=0;row<inputVector.size();row++)
                {
                    for (int index=0;index<inputVector.size()-1;index++)
                    {
                        
                if (inputVector[index].getGenre2() > inputVector[index+1].getGenre2())
                    
                {
                    picturesObj=inputVector[index];
                    
                    inputVector[index]=inputVector[index+1];
                   
                    
                    inputVector[index+1]=picturesObj;
                }
            }
                }
            }
    
           else if (sortCategory == 2)
           {
               for (int row=0;row<inputVector.size();row++)
               {
                   for (int index=0;index<inputVector.size()-1;index++)
                   {
               
               if (inputVector[index].getYear() > inputVector[index+1].getYear())
                   
               {
                   picturesObj=inputVector[index];
                   
                   inputVector[index]=inputVector[index+1];
                   
                   
                   inputVector[index+1]=picturesObj;
               }
           }
               }
           }
    
            else if (sortCategory == 1)
            {
                for (int row=0;row<inputVector.size();row++)
                {
                    for (int index=0;index<inputVector.size()-1;index++)
                    {
                
                if (inputVector[index].getName() > inputVector[index+1].getName())
                    
                {
                    picturesObj=inputVector[index];
                    
                    inputVector[index]=inputVector[index+1];
                   
                    
                    inputVector[index+1]=picturesObj;
                }
            }
                }
            }
           else if (sortCategory == 5)
            {
                
                for (int row=0;row<inputVector.size();row++)
                {
                    for (int index=0;index<inputVector.size()-1;index++)
                    {
                        
                if (inputVector[index].getRelease() > inputVector[index+1].getRelease())
                {
                    picturesObj=inputVector[index];
                    
                    inputVector[index]=inputVector[index+1];
                    
                    inputVector[index+1]=picturesObj;
                }
            }
                }
            }

            else if (sortCategory == 6)
            {
                for (int row=0;row<inputVector.size();row++)
                {
                    for (int index=0;index<inputVector.size()-1;index++)
                    {
                
                if (inputVector[index].getSynopsis() > inputVector[index+1].getSynopsis())
                {
                    picturesObj=inputVector[index];
                    
                    inputVector[index]=inputVector[index+1];
                    
                    inputVector[index+1]=picturesObj;   
                }
            }
                }
            }
    
    return inputVector;
}

//function writes search and sort reports to file
void ActorActress:: writeToFile (string fileName,vector<int>& printVector, vector<ActorActress>& inputVector)
{
    string matrix [inputVector.size()][printVector.size()];
    vector<string> temp;
    ofstream outFile;
    outFile.open(fileName);
    
    for (int i = 0; i <printVector.size(); i++)
    {
        if(printVector[i] == 1)
        {
            temp.push_back("Year");
        }
        if(printVector[i] == 2)
        {
            temp.push_back("Award");
        }
        if(printVector[i] == 3)
        {
            temp.push_back("Name");
        }
        if(printVector[i] == 4)
        {
            temp.push_back("Film");
        }
        
        outFile << setw(30) << temp[i];
    }
    outFile << endl;
    


    if (outFile)
    {
            for (int j = 0; j <printVector.size(); j++)
            {

                    if(printVector[j] == 1)
                    {

                        for (int i= 0; i <inputVector.size(); i++)
                        {
                            matrix [i][j] = to_string(inputVector[i].getYear());
                        }
                    }
                    else if(printVector[j] == 2)
                    {

                        for (int i= 0; i <inputVector.size(); i++)
                        {
                            matrix [i][j] = inputVector[i].getAward();
                        }
                    }
                    else if(printVector[j] == 3)
                    {

                        for (int i= 0; i <inputVector.size(); i++)
                        {
                            matrix [i][j] = inputVector[i].getName();
                        }
                    }
                    else if(printVector[j] == 4)
                    {
                        
                        for (int i= 0; i <inputVector.size(); i++)
                        {
                            matrix [i][j] = inputVector[i].getFilm();
                        }
                    }
            }
        
        for (int row = 0; row < inputVector.size(); row++)
        {
            for (int col = 0; col < printVector.size(); col++)
            {
                outFile << setw(30) << matrix [row][col];
            }

            outFile << endl;
        }
       
    }
    outFile.close();

}

void Pictures:: writeToFile (string fileName, vector<int>& printVector, vector<Pictures>& inputVector)
{
    string matrix [inputVector.size()][printVector.size()];
    vector<string> temp;
    ofstream outFile;
    outFile.open(fileName);
    
    for (int i = 0; i <printVector.size(); i++)
    {
        if(printVector[i] == 1)
        {
            temp.push_back("Name");
        }
        if(printVector[i] == 2)
        {
            temp.push_back("Year");
        }
        if(printVector[i] == 3)
        {
            temp.push_back("Genre1");
        }
        if(printVector[i] == 4)
        {
            temp.push_back("Genre2");
        }
        if(printVector[i] == 5)
        {
            temp.push_back("Release");
        }
        if(printVector[i] == 6)
        {
            temp.push_back("Synopsis");
        }
        
        outFile << setw(60) << temp[i];
    }
    outFile << endl;
    
    if (outFile)
    {
        for (int j = 0; j <printVector.size(); j++)
        {
            
            if(printVector[j] == 1)
            {
                
                for (int i= 0; i <inputVector.size(); i++)
                {
                    matrix [i][j] = inputVector[i].getName();
                }
            }
            else if(printVector[j] == 2)
            {
                
                for (int i= 0; i <inputVector.size(); i++)
                {
                    matrix [i][j] = to_string(inputVector[i].getYear());
                }
            }
            else if(printVector[j] == 3)
            {
                
                for (int i= 0; i <inputVector.size(); i++)
                {
                    matrix [i][j] = inputVector[i].getGenre1();
                }
            }
            else if(printVector[j] == 4)
            {
                
                for (int i= 0; i <inputVector.size(); i++)
                {
                    matrix [i][j] = inputVector[i].getGenre2();
                }
            }
            else if(printVector[j] == 5)
            {
                
                for (int i= 0; i <inputVector.size(); i++)
                {
                    matrix [i][j] = inputVector[i].getRelease();
                }
            }
            else if(printVector[j] == 6)
            {
                
                for (int i= 0; i <inputVector.size(); i++)
                {
                    matrix [i][j] = inputVector[i].getSynopsis();
                }
            }
        }
        
        for (int row = 0; row < inputVector.size(); row++)
        {
            for (int col = 0; col < printVector.size(); col++)
            {
                outFile << setw(60) << matrix [row][col];
            }
            
            outFile << endl;
        }
        
    }
    
    outFile.close();

}

void ActorActress:: writeCSV (string fileName, vector<ActorActress>& inputVector)
{
    ofstream outFile;
    outFile.open(fileName);
    
    if (outFile)
    {
        outFile << "Year"<<','
            <<"Award"<<','
            <<"Winner"<<','
            <<"Name"<<','
            <<"Film"<<'\n';
        
            for (int i= 0; i <inputVector.size(); i++)
            {
                outFile << inputVector[i].getYear() << ','
                        <<inputVector[i].getAward() <<','
                        << inputVector[i].getWinner()<< ','
                        << inputVector[i].getName()<<','
                        <<inputVector[i].getFilm()<<'\n';
            }
        
    }
    
    outFile.close();
}

void Pictures:: writeCSV (string fileName, vector<Pictures>& inputVector)
{
    ofstream outFile;
    outFile.open(fileName);
    
    if (outFile)
    {
        outFile << "Name"<< ','
        <<"Year"<< ','
        <<"Nominations"<<','
        <<"Rating"<<','
        <<"Duration"<<","
        <<"Genre1"<<','
        <<"Genre2"<<','
        <<"Release"<<','
        <<"Metacritic"<<','
        <<"Synopsis"<<'\n';
        
        for (int i= 0; i <inputVector.size(); i++)
        {
            outFile << inputVector[i].getName() << ','
                    <<inputVector[i].getYear() <<','
                    <<inputVector[i].getNominations()<< ','
                    <<inputVector[i].getRating()<<','
                    <<inputVector[i].getDuration()<<','
                    <<inputVector[i].getGenre1()<<','
                    <<inputVector[i].getGenre2()<<','
                    <<inputVector[i].getRelease()<<','
                    <<inputVector[i].getMetacritic()<<','
                    <<inputVector[i].getSynopsis()<<'\n';
        }
        
    }
    
    outFile.close();
}

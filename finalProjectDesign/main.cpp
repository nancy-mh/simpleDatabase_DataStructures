//Nancy Moreno Huizar

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "BinarySearchTrees.h"
#include "Vectors.h"
#include <sstream>
#include <iomanip>
using namespace std;

//function protoypes
void mainMenu ();  // driver of database assigment
string subMenu (int); // allows user to pick record

// actor-actresses database function prototypes
void readInActorActresses(string, ActorActressBSTree *);
void addRecord (ActorActressBSTree*);
void modifyExistingRecord(ActorActressBSTree*);
void deleteRecord(ActorActressBSTree*);
void sortRecords(ActorActressBSTree *);
void searchRecords(ActorActressBSTree *);
void writeModifiedRecordsToFile (ActorActressBSTree*);

// pictures database function prototypes
void readInPictures(string, PicturesBSTree *);
void addRecord (PicturesBSTree*);
void modifyExistingRecord(PicturesBSTree*);
void deleteRecord(PicturesBSTree*);
void sortRecords(PicturesBSTree*);
void searchRecords(PicturesBSTree*);
void writeModifiedRecordsToFile (PicturesBSTree*);


int main ()
{

    mainMenu();
 
    return 0;
}

// calls actor-actresses and pictures database functions
void mainMenu ()
{
    ActorActressBSTree* BSTreeA = new ActorActressBSTree; // level one node
    PicturesBSTree* BSTreeP = new PicturesBSTree; //level one node

    string actorActresses = "actor-actress.csv";
    string pictures = "pictures.csv";
    
    string record; // will hold record chosen by user

    int option; // will hold main menu option
    bool repeat = true; // terminates loop if false
    
    
    do
    {
        cout << "Enter number of the desired option" << endl;
        cout << " 1. Read in Actor-Actresses file" << endl;
        cout << " 2. Read in Pictures file" << endl;
        cout << " 3. Add a record" << endl;
        cout << " 4. Modify existing record" << endl;
        cout << " 5. Delete a record" << endl;
        cout << " 6. Sort records" << endl;
        cout << " 7. Search records" << endl;
        cout << " 8. Write modified records to file and exit" << endl;
        
        cout << " -- Your choice is: ";
        cin >> option;
        cin.ignore(INT32_MAX, '\n'); // skips 4611686018427387903 char or until '\n' from cin bugger allowing for next entry.
    
        
        switch (option)
        {
            case 1:
                readInActorActresses(actorActresses, BSTreeA);
                break;
                
            case 2:
                readInPictures(pictures, BSTreeP);
                break;
                
            case 3:
                record = subMenu(option);
                if(record == "actor-actress")
                {
                    addRecord(BSTreeA);
                }
                else if(record == "pictures")
                {
                    addRecord(BSTreeP);
                }
                else
                    cout << "Invalid entry.\n";
                
                cout <<endl;

                break;
               
                
            case 4:
                record = subMenu(option);
                if(record == "actor-actress")
                {
                   modifyExistingRecord(BSTreeA);
                }
                else if(record == "pictures")
                {
                    modifyExistingRecord(BSTreeP);
                }
                else
                    cout << "Invalid entry.\n";
                
                cout <<endl;
                
                break;
                
            case 5:
                record = subMenu(option);
                if(record == "actor-actress")
                {
                    deleteRecord(BSTreeA);
                }
                else if(record == "pictures")
                {
                    deleteRecord(BSTreeP);
                }
                else
                    cout << "Invalid entry.\n";
  
                cout <<endl;
                
                break;
                
            case 6:
                record = subMenu(option);
                if(record == "actor-actress")
                {
                    sortRecords(BSTreeA);
                }
                else if(record == "pictures")
                {
                    sortRecords(BSTreeP);
                }
                else
                    cout << "Invalid entry.\n";
                
                cout <<endl;

                break;
                
            case 7:
                record = subMenu(option);
                if(record == "actor-actress")
                {
                    searchRecords(BSTreeA);
                }
                else if(record == "pictures")
                {
                    searchRecords(BSTreeP);
                }
                else
                    cout << "Invalid entry.\n";

                cout <<endl;
                
                break;
                
            case 8:
                record = subMenu(option);
                if(record == "actor-actress")
                {
                    writeModifiedRecordsToFile(BSTreeA);
                    repeat = false;
                }
                else if(record == "pictures")
                {
                    writeModifiedRecordsToFile(BSTreeP);
                     repeat = false;
                }
                else
                    cout << "Invalid entry.\n";

                cout <<endl;
                
                break;

          default:
                 if (option != (1-8))
                  { cout << "invalid input." << endl<<endl;}
        }
        
    } while (repeat);
        
}


/*
 input: an integer
 output: string
 This function is called in every case of main menu function to allow user to choose between actor-actress and pictures database
 the string returned informs each case which functions to call
 */
string subMenu (int mainMenuOption)
{
    string record;
    cout << "Entry must be actor-actress or pictures" <<  endl;
    
    if (mainMenuOption == 3)
    {
        cout << "Would you like to add a record to actor-actress records or pictures records?\n";
        getline (cin, record);
        
    }
    else if (mainMenuOption == 4)
    {
        cout << "Would you like to modify a record from actor-actress records or pictures records?\n";
        getline (cin, record);
    }
    else if (mainMenuOption == 5)
    {
        cout << "Would you like to delete a record to actor-actress records or pictures records?\n";
        getline (cin, record);
    }
    else if (mainMenuOption == 6)
    {
        cout << "Would you like to sort actor-actress records or pictures records?\n";
        getline (cin, record);
    }
    else if (mainMenuOption == 7)
    {
        cout << "Would you like search actor-actress records or pictures records?\n";
        getline (cin, record);
    }
    else if (mainMenuOption == 8)
    {
        cout << "Would you like a report of actor-actress records or pictures records?\n";
        getline (cin, record);
    }

    return record;
}


/*
 
 input: string and a pointer to an object of ActorActressBSTree class
 output: none
 This function reads in data from actor-actress.csv  file, one line at a time into node and adds this node to tree by calling addNode function
 */
void readInActorActresses(string actorActresses, ActorActressBSTree* BSTreeA)
{
    fstream infile;
    infile.open(actorActresses);
    if (infile)
    {
        string columnNames;
        getline(infile, columnNames, '\n'); // reads in column names to prevent them from being added to tree
        
        NodeActorActress*  tree = new NodeActorActress;
        string line;
        while (!infile.eof())
        {
            getline(infile, line, ',');
            tree->setYear(stoi(line));
            getline(infile, line, ',');
            tree->setAward(line);
            getline(infile, line, ',');
            tree->setWinner(stoi(line));
            getline(infile, line, ',');
            tree->setName(line);
            getline(infile, line, '\n'); // '\n' delimiter stops reading in at the end of each line
            tree->setFilm(line);
            BSTreeA->addNode(*tree);  // must dereference pointer to pass a NodeActorActress object to addNode function

        }
        
        delete tree;
        
        cout <<" -- Records have been successfully read in.\n\n";
    }
    else
        cout <<"Could not open file.\n";
    
    infile.close();
}

/*
 
 input: string and a pointer to an object of PicturesBSTree class
 output: none
 This function reads in data from pictures.csv file, one line at a time into node and adds this node to tree by calling addNode function. This function also handles records with empty fields by replacing field with -1 for integer fields and "no data" for string fields.
 */
void readInPictures(string pictures, PicturesBSTree* BSTreeP)
{
    Pictures picturesObj;
    fstream infile;
    infile.open(pictures);
    if (infile)
    {
        string columnNames;
        getline(infile, columnNames, '\n');
        NodePictures* tree = new NodePictures;
        
        string line;
        while (!infile.eof())
        {
            getline(infile, line, ',');
            if (line.length() ==0)     // if current line being read in does not have data, line length = 0 so set name to default name
            {
                tree->setName(picturesObj.getName());
            }
            else
                tree->setName(line);
                
            getline(infile, line, ',');
            if (line.length() == 0)   // check if line is empty
            {
                tree->setYear(picturesObj.getYear());
            }
            for (int i =0; i <line.length(); i++)
            {
                if(!isdigit(line[i])) // checks if line is a digit, if not set year to default year
                                        // this check is needed for stoi to function properly
                {
                    tree->setYear(picturesObj.getYear());
                }
                else
                    tree->setYear(stoi(line));
            }
            
            getline(infile, line, ',');
            if (line.length() == 0)
            {
                tree->setNominations(picturesObj.getNominations());
            }
            else
            {
                for (int i =0; i<line.length(); i++)
                {
                    if (!isdigit(line[i]))
                    {
                        tree->setNominations(picturesObj.getNominations());
                    }
                    else
                        tree->setNominations(stoi(line));
                }
            }
            
            getline(infile, line, ',');
            if (line.length() == 0)
            {
                tree->setRating(picturesObj.getRating());
            }
            else
            {
                    for(int i =0; i<line.length(); i++)
                    {
                        if (!isdigit(line[i]))
                        {
                            tree->setRating(picturesObj.getRating());
                        }
                        else
                            tree->setRating(stof(line));
                    }
            }

            getline(infile, line, ',');
            if (line.length() == 0)
            {
                tree->setDuration(picturesObj.getDuration());
            }
            else
            {
            for (int i =0; i<line.length(); i++)
            {
                if (!isdigit(line[i]))
                {
                    tree->setDuration(picturesObj.getDuration());
                }
                else
                    tree->setDuration(stoi(line));
            }
            }
            
            getline(infile, line, ',');
            if (line.length() == 0)
            {
                tree->setGenre1(picturesObj.getGenre1());
            }
            else
                tree->setGenre1(line);

            getline(infile, line, ',');
            if (line.length() == 0)
            {
                tree->setGenre2(picturesObj.getGenre2());
            }
            else
                tree->setGenre2(line);

            getline(infile, line, ',');
            if (line.length() == 0)
            {
                tree->setRelease(picturesObj.getRelease());
            }
            else
                tree->setRelease(line);

            getline(infile, line, ',');
            if (line.length() == 0)
            {
                tree->setMetacritic(picturesObj.getMetacritic());
            }
            else
            {
            for(int i=0; i< line.length(); i++)
            {
                if (!isdigit(line[i]))
                {
                    tree->setMetacritic(picturesObj.getMetacritic());
                }
                else
                    tree->setMetacritic(stoi(line));
            }
            }
            
            getline(infile, line, '\n');
            if (line.length() == 0)
            {
                tree->setSynopsis(picturesObj.getSynopsis());
            }
            else
               tree->setSynopsis(line);

                BSTreeP->addNode(*tree);
        }

         delete tree;
        
        cout <<" -- Records have been successfully read in.\n\n";
}
    else
        cout <<"Could not open file.\n";

    infile.close();
}

/*
 input: a pointer that points to an object of ActorActressBSTree class
 output: none
 This function allows users to add a new record to actor-actress by inputing data into a node and adding it to a BST
 */
void addRecord (ActorActressBSTree* BSTreeA)
{
    NodeActorActress* newNode = new NodeActorActress;
    
        int year;
        string award;
        int winner;
        string name;
        string film;
    
        cout <<endl;
        cout << "Enter year of record: ";
        cin >> year;
        cin.ignore(INT32_MAX, '\n');
        cout << "Enter award of record: ";
        getline(cin, award);
        cout << "If winner enter 1, else enter 0: ";
        cin >> winner;
        cin.ignore(INT32_MAX, '\n');
        cout << "Enter name of actor-actresses: ";
       getline(cin,name);
        cout << "Enter film name of record: ";
       getline (cin, film);
    
        newNode->setYear(year);
        newNode->setAward(award);
        newNode-> setWinner(winner);
        newNode->setName(name);
        newNode->setFilm(film);
        BSTreeA->addNode(*newNode);  // tree of all records is created
        cout<<endl;
        cout << "Record has been added.\n";
    
    
    delete newNode;

}

/*
 input: a pointer that points to an object of PicturesBSTree class
 output: none
 This function allows users to add a new record to pictures by inputing data into a node and adding it to a BST
 */
void addRecord (PicturesBSTree* BSTreeP)
{
    string databaseChoice;
    NodePictures* newNode = new NodePictures;
    

    string name;
    int year;
    int nominations;
    float rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;
    
    cout <<endl;
    cout << "Enter name of film: ";
    getline(cin, name);
    cout << "Enter year of film: ";
    cin >> year;
    cout << "Enter nominations: ";
    cin >> nominations;
    cout << "Enter rating of film: ";
    cin >> rating;
    cout << "Enter duration of film: ";
    cin >> duration;
    cin.ignore(INT32_MAX, '\n');
    cout << "Enter genre1 of film: ";
    getline(cin, genre1);
    cout << "Enter genre2 of film: ";
    getline(cin, genre2);
    cout << "Enter the month the film was released: ";
    getline(cin, release);
    cout << "Enter metacritic of film: ";
    cin >> metacritic;
    cin.ignore(INT32_MAX, '\n');
    cout << "Enter synopsis of film: ";
    getline(cin, synopsis);
    
    newNode->setName(name);
    newNode->setYear(year);
    newNode->setNominations(nominations);
    newNode->setRating(rating);
    newNode->setDuration(duration);
    newNode->setGenre1(genre1);
    newNode->setGenre2(genre2);
    newNode->setRelease(release);
    newNode->setMetacritic(metacritic);
    newNode->setSynopsis(synopsis);
    BSTreeP->addNode(*newNode);
    
    cout<<endl;
    cout << "Record has been added.\n";

    delete newNode;
}

/*
 input:  pointer pointing to an object of ActorActressBSTree class
 output: none
  This function allows users to modifiy records by calling findNode using the exact record name entered by user. It will out put the field of record user can modify of report if no such record exists. Contents of node found are are updated. If the name is changed, the old record is deleted and this record is added keeping BST structure.
 */
void modifyExistingRecord (ActorActressBSTree* BSTreeA)
{
    NodeActorActress* nodePtr = BSTreeA->Root(); // points at tree root and traverses through tree
    NodeActorActress* dataPtr = nullptr; // will point at record that user wishes to modify
    NodeActorActress* newNode = new NodeActorActress; // will copy data from the node dataPtr is pointing to
    vector<ActorActress> ActorActressVec;
    ActorActress object; // used to access vector functions
    bool repeat = true;  //terminates loop if false
    bool nameChange = false; // flag to check if field changed is name
    
    
        string name;
        int option;
        cout << "Enter name of record you wish to modify: \n";
        getline(cin, name);
    
        dataPtr = BSTreeA->findNode(name, nodePtr); // pointer to record that matches user input
        
    if (dataPtr == nullptr)
    {
            cout << "The entered name does not match any records.\n";
    }
        
    else
    {
        // makes a copy of the node to be modified to keep fields intact if name is changed
        newNode->setYear(dataPtr->getYear());
        newNode->setAward(dataPtr->getAward());
        newNode->setWinner(dataPtr->getWinner());
        newNode->setName(dataPtr->getName());
        newNode->setFilm(dataPtr->getFilm());
        
        do
        {
            cout<<endl;
            cout<< "--************************************************--\n";
            cout<<endl;
            cout << "These are the contents of the record you wish to modify: \n";
            cout << "Year: "<<dataPtr -> getYear()<< endl;
            cout << "Award: "<<dataPtr -> getAward()<< endl;
            cout << "Winner status: "<<dataPtr -> getWinner()<< endl;
            cout << "Name: "<<dataPtr -> getName()<< endl;
            cout << "Film: "<<dataPtr -> getFilm()<< endl;
            
            cout<<endl;

            cout << "Enter the number of the field that you would like to modify" << endl;
            cout << " 1. modify year" << endl;
            cout << " 2. modify award" << endl;
            cout << " 3. modify winner" << endl;
            cout << " 4. modify name" << endl;
            cout << " 5. modify film" << endl;
            cout << " 6. Cancel" << endl;
            cout <<endl;
            
            cin >> option;
            cin.ignore(INT32_MAX, '\n');
            
            if (option == 1)
            {
                int year;
                cout << "Enter new year: ";
                cin >> year;
                
                dataPtr->setYear(year);
                repeat = false;
            }
            else if (option == 2)
            {
                string award;
                cout << "Enter new award: ";
                getline(cin, award);
                
                dataPtr->setAward(award);
                repeat = false;
            }
            else if (option == 3)
            {
                int winner;
                cout << "1 indicates winner, 0 indicates loser.\n";
                cout << "Enter new winner status: ";
                cin >> winner;
                
                dataPtr->setWinner(winner);
                repeat = false;
            }
            else if (option == 4)
            {
                string name;
                cout << "Enter new name: ";
                getline(cin, name);
                
                newNode->setName(name);
                nameChange = true;
                repeat = false;
            }
            else if (option == 5)
            {
                string film;
                cout << "Enter new film: ";
                getline(cin, film);
                
                dataPtr->setFilm(film);
                repeat = false;
            }
            else if (option == 6)
            {
                cout << "Record modification has been cancelled by user.\n";
                repeat = false;
            }
            else
            {
                cout << "Invalid entry";
            }
                
        }while(repeat);
        
        if (nameChange == true)
        {
            dataPtr = BSTreeA->deleteNode(nodePtr, name); // unmodified copy is deleted from tree (name) and a pointer points to the new root (dataPtr)
            
            
            // if the user modifies name, adding this node will maintain the tree sorted by name
            BSTreeA->addNode(*newNode);
            
            delete newNode;// newNode is deleted freeing memory after being added to BST
            
        }
        
       // delete newNode;// newNode is deleted freeing memory if not used
    }
    
}


/*
 input: a pointer that points to an object of PicturesBSTree class
 output: none
 This function allows users to modifiy records by calling findNode using the exact record name entered by user. It will out put the field of record user can modify of report if no such record exists. Contents of node found are updated  and user is asked to enter new file name, if no file name is entered the actor actress file is overwritten.
 */
void modifyExistingRecord(PicturesBSTree* BSTreeP)
{
    
    NodePictures* nodePTr = BSTreeP->Root(); // points at tree root and traverses through tree
    NodePictures* dataPtr = nullptr; // will point at record that user wishes to modify
    NodePictures* newNode = new NodePictures; // will copy data from the node dataPtr is pointing to
    bool repeat = true;
    bool changeName = false;

    string name;
    int option;
    cout << "Enter name of record you wish to modify: \n";
    getline(cin, name);
    
    dataPtr = BSTreeP->findNode(name, nodePTr); // pointer to record that matches user input
    
    if (dataPtr == nullptr)
    {
        cout << "The entered name does not match any records.\n";
    }
    
    else
    {
        newNode->setName(dataPtr->getName());
        newNode->setYear(dataPtr->getYear());
        newNode->setNominations(dataPtr->getNominations());
        newNode->setRating(dataPtr->getRating());
        newNode->setDuration(dataPtr->getDuration());
        newNode->setGenre1(dataPtr->getGenre1());
        newNode->setGenre2(dataPtr->getGenre2());
        newNode->setRelease(dataPtr->getRelease());
        newNode->setMetacritic(dataPtr->getMetacritic());
        newNode->setSynopsis(dataPtr->getSynopsis());
        
        do
        {
            cout<<endl;
            cout<< "--************************************************--\n";
            cout<<endl;
            cout << "These are the contents of the record you wish to modify: \n";
            cout << "Name: "<<dataPtr -> getName()<< endl;
            cout << "Year: "<<dataPtr -> getYear()<< endl;
            cout << "Nominations: "<<dataPtr -> getNominations()<< endl;
            cout << "Rating: "<<dataPtr -> getRating()<< endl;
            cout << "Duration: "<<dataPtr -> getDuration()<< endl;
            cout << "Genre1: "<<dataPtr -> getGenre1()<< endl;
            cout << "Genre2: "<<dataPtr -> getGenre2()<< endl;
            cout << "Release: "<<dataPtr -> getRelease()<< endl;
            cout << "Metacritic: "<<dataPtr -> getMetacritic()<< endl;
            cout << "Synopsis: "<<dataPtr -> getSynopsis()<< endl;
        
            cout<<endl;
 
            cout << "Enter the number of the field that you would like to modify" << endl;
            cout << " 1. modify name" << endl;
            cout << " 2. modify year" << endl;
            cout << " 3. modify nominations" << endl;
            cout << " 4. modify rating" << endl;
            cout << " 5. modify duration" << endl;
            cout << " 6. modify genre1" << endl;
            cout << " 7. modify genre2" << endl;
            cout << " 8. modify release" << endl;
            cout << " 9. modify metacritic" << endl;
            cout << " 10. modify synopsis" << endl;
            cout << " 11. Cancel" << endl;
            cout<<endl;
            
            cin >> option;
            cin.ignore(INT32_MAX, '\n');
        
            if (option == 1)
            {
                string name;
                cout << "Enter new name: ";
                getline(cin, name);
                
                newNode->setName(name);
                changeName = true;
                repeat = false;
            }
            else if (option == 2)
            {
                int year;
                cout << "Enter new year: ";
                cin >> year;
            
                dataPtr->setYear(year);
                repeat = false;
            }
            else if (option == 3)
            {
                int nominations;
                cout << "Enter new nominations: ";
                cin >> nominations;
            
                dataPtr->setNominations(nominations);
                repeat = false;
            }
            else if (option == 4)
            {
                float rating;
                cout << "Enter new rating: ";
                cin >> rating;
            
                dataPtr->setRating(rating);
                repeat = false;
            }
            else if (option == 5)
            {
                int duration;
                cout << "Enter new duration: ";
                cin >> duration;
            
                dataPtr->setDuration(duration);
                repeat = false;
            }
            else if (option == 6)
            {
                string genre1;
                cout << "Enter new genre1: ";
                getline(cin, genre1);
            
                dataPtr->setGenre1(genre1);
                repeat = false;
            }
            else if (option == 7)
            {
                string genre2;
                cout << "Enter new genre2: ";
                getline(cin, genre2);
                
                dataPtr->setGenre2(genre2);
                repeat = false;
            }
            else if (option == 8)
            {
                string release;
                cout << "Enter new release: ";
                getline(cin, release);
                
                dataPtr->setRelease(release);
                repeat = false;
            }
            else if (option == 9)
            {
                int metacritic;
                cout << "Enter new metacritic: ";
                cin >> metacritic;
                
                dataPtr->setMetacritic(metacritic);
                repeat = false;
            }
            else if (option == 10)
            {
                string synopsis;
                cout << "Enter new synopsis: ";
                getline(cin, synopsis);
                
                dataPtr->setSynopsis(synopsis);
                repeat = false;
            }
            else if (option == 11)
            {
                cout << "Record modification has been cancelled by user.\n";
                repeat = false;
            }
            else
            {
                cout << "Invalid entry";
            }
        
        }while(repeat);
        
        if (changeName == true)
        {
            dataPtr = BSTreeP->deleteNode(nodePTr, name); // unmodified copy is deleted from tree (name) and a pointer points to the new root (dataPtr)
            
            
            // if the user modifies name, adding this node will maintain the tree sorted by name
            BSTreeP->addNode(*newNode);
            
            delete newNode;// newNode is deleted freeing memory after being added to BST
            
        }
        
        //delete newNode;// newNode is deleted freeing memory if not used
    }

}

/*
 input: pointer to an object of ActorActressBSTree class
 output: none
 This function allows users to delete a record by inputing the exact name  and informs user if record does not exist
 */
void deleteRecord(ActorActressBSTree* BSTreeA)
{
    NodeActorActress* nodePTr = nullptr;
    NodeActorActress* dataPtr = BSTreeA -> Root();

        string name;
        cout << "Enter the name of record to be deleted: ";
        getline(cin, name);
    
        nodePTr = BSTreeA->deleteNode(dataPtr, name);
    
    if(nodePTr != nullptr)
    {
        
        cout << "Record has been deleted.\n";
    }
    else
        cout<< "Record does not exist.\n";

}

/*
 input: pointer to an object of PicturesBSTree class
 output: none
 This function allows users to delete a record by inputing the exact name and informs user if record does not exist
 */
void deleteRecord(PicturesBSTree* BSTreeP)
{
    NodePictures* nodePTr = nullptr;
    NodePictures* dataPtr = BSTreeP -> Root();
    
    string name;
    cout << "Enter the name of record to be deleted: ";
    getline(cin, name);
    
    nodePTr = BSTreeP->deleteNode(dataPtr, name);
    
    if(nodePTr != nullptr)
    {
    
        cout << "Record has been deleted.\n";
    }
    else
        cout<< "Record does not exist.\n";
}


/*
 input: pointer to an object of ActorActressBSTree class
 output: none
 This function outputs menu of sortable fields, allows user to pick a field to sort by, then pick multiple fields to print to report. Function will call sort function of Vectors.h to sort all fields and returns the sorted vector that is then written to report. A second sort can be done on this returned vector. Menu is controlled by do while and while loops

 */
void sortRecords(ActorActressBSTree * BSTreeA)
{
    NodeActorActress* nodePTr = BSTreeA->Root();
    vector<ActorActress> ActorActressVec;
    ActorActress ActorActressObj;
    vector<ActorActress> actorActressVecAfterSort;
    vector<int> printFieldVec;
    bool repeat = true;
    bool repeat2 = true;
    int numFields = 0;
    int printField;
    string fileName;
    string field, input;
    string line;

    ActorActressVec = (BSTreeA->inorderTraversal(nodePTr, ActorActressVec));  // tree is transvered and copied into vector
    
    do
    {
        int option;
        string searchMode, search;
        cout<<endl;
        cout<< "--************************************************--\n";
        cout<<endl;
        cout << "Records can be sorted by the following fields: " << endl;
        cout << "1. year" << endl;
        cout << "2. award" << endl;
        cout << "3. name" << endl;
        cout << "4. film" << endl;
        cout << "5. Cancel" << endl;
        cout<<endl;
        cout << "Enter the number of the field to sort by or enter 5 to return to main menu.\n"
        << "Enter number: ";
        
        cin >> option;
        cin.ignore(INT32_MAX, '\n');
        if (option == 5)
        {
            cout << "record sort cancelled by user.\n";
            repeat2 = false; // stops second sort option
            break; // exit the first do while loop
            
        }
  
        cout<< "Out of the 4 sortable fields, enter the amount of fields you want printed to report: ";
        cin >> numFields;
        cin.ignore(INT32_MAX, '\n');

        cout << "Enter the number of the field/s to be written to report with a space between each number: \n";
        

        for (int i =0; i<numFields; i++)  // takes in fields to print
        {
            cin >> printField;
            printFieldVec.push_back(printField);
        }
        cin.ignore(INT32_MAX, '\n');

        if (option == 3) // tree is already sorted by name so print filled vector to file
        {
            
            cout << "Enter the file name that reports will be saved to: \n";
            getline(cin, fileName);
            ActorActressObj.writeToFile(fileName, printFieldVec, ActorActressVec);
            cout << "Report has been saved to "<<fileName<<".\n";
            repeat = false;
            
        }
        else if (option == 1 || option == 2 || option == 4) // sort vector by user input then print to file
        {
            actorActressVecAfterSort= (ActorActressObj.sort(ActorActressVec, option));
            if (actorActressVecAfterSort.empty())
            {
                repeat = false;
            }
            else
            {
                cout << "Enter the file name that reports will be saved to: \n";
                getline(cin, fileName);
                ActorActressObj.writeToFile(fileName,printFieldVec, actorActressVecAfterSort);
                cout << "Report has been saved to "<<fileName<<".\n";
                repeat = false;
            }
        }
        else
        {
            cout <<"Invalid entry.\n";
        }
        
        
    }while(repeat);
    

while (repeat2)
{
        cout << "Would you like to do a secondary sort?\n";
        getline(cin, input);
        
        if (input == "yes")
        {
            vector<ActorActress> actorActressVecAfterSecondSort;
            vector<int> printFieldVec2;
            string field;
        do
        {
            int option;
            string searchMode, search;
            cout<<endl;
            cout<< "--************************************************--\n";
            cout<<endl;
            cout << "Records can be sorted by the following fields: " << endl;
            cout << "1. year" << endl;
            cout << "2. award" << endl;
            cout << "3. name" << endl;
            cout << "4. film" << endl;
            cout << "5. Cancel" << endl;
            cout<<endl;
            cout << "Enter the number of the field to sort by or enter 5 to return to main menu.\n"
            << "Enter number: ";
            
            cin >> option;
            cin.ignore(INT32_MAX, '\n');
            if (option == 5)
            {
                cout << "record sort cancelled by user.\n";
                repeat2 = false;
                break;
            }

            cout<< "Out of the 4 sortable fields, enter the amount of fields you want printed to report: ";
            cin >> numFields;
            cin.ignore(INT32_MAX, '\n');

            cout << "Enter the number of the field/s to be written to report with a space between each number: \n";

            
            for (int i =0; i<numFields; i++)  // takes in fields to print
            {
                cin >> printField;
                printFieldVec.push_back(printField);
            }
            cin.ignore(INT32_MAX, '\n');
            
            if (option == 3)
            {
                cout << "Enter the file name that reports will be saved to: \n";
                getline(cin, fileName);
                ActorActressObj.writeToFile(fileName, printFieldVec, ActorActressVec);
                cout << "Report has been saved to "<<fileName<<".\n";
                repeat = false; // exist do while
                repeat2 = false; // exit while loop, return to main menu
                
            }
            else if (option == 1 || option == 2 || option == 4)
            {
                actorActressVecAfterSecondSort =(ActorActressObj.sort(actorActressVecAfterSort, option));
                
                if (actorActressVecAfterSort.empty())
                {
                    repeat = false;
                }
                else
                {
                    cout << "Enter the file name that reports will be saved to: \n";
                    getline(cin, fileName);
                    ActorActressObj.writeToFile(fileName,printFieldVec, actorActressVecAfterSecondSort);
                    cout << "Report has been saved to "<<fileName<<".\n";
                    repeat = false; //exist do while
                    repeat2 = false; // exist while  loop, return to main menu
                }
            }
            else
            {
                cout <<"Invalid entry.\n";
            }
        }while(repeat);
        }
    
        else
            repeat2 = false;
            
} //end of while loop
}

/*
input: pointer to an object of PicturesBSTree class
 output: none
 This function outputs menu of sortable fields, allows user to pick a field to sort by then pick multiple fields to print to report. Function will call sort function of Vectors.h to sort all fields and returns the sorted vector that is then written to report. A second sort can be done on this returned vector. Menu is controlled by do while and while loops
 */
void sortRecords(PicturesBSTree* BSTreeP)
{
    NodePictures* nodePTr = BSTreeP->Root();
    vector<Pictures> picturesVec;
    Pictures picturesObject;
     vector<int> printFieldVec;
    vector<Pictures> picturesVecAfterSort;
    bool repeat = true;
    bool repeat2 = true;
    int numFields = 0;
    int printField;
    string field, input, fileName;
    
    picturesVec= (BSTreeP->inorderTraversal(nodePTr, picturesVec));  // tree is transvered and copied into vector
    
    do
    {
        int option;
        cout<<endl;
        cout<< "--************************************************--\n";
        cout<<endl;
        cout << "Record can be sort by the following fields: " << endl;
        cout << "1. name" << endl;
        cout << "2. year" << endl;
        cout << "3. nominations" << endl;
        cout << "4. rating" << endl;
        cout << "5. duration" << endl;
        cout << "6. genre1" << endl;
        cout << "7. genre2" << endl;
        cout << "8. release" << endl;
        cout << "9. metacritic" << endl;
        cout << "10. synopsis" << endl;
        cout << "11. Cancel" << endl;
        cout<<endl;
        cout << "Enter the number of the field to sort by or enter 11 to return to main menu.\n"
        << "Enter number: ";
        
        cin >> option;
        cin.ignore(INT32_MAX, '\n');
        if (option == 11)
        {
            cout << "record sort cancelled by user.\n";
            repeat2 = false; //return to main menu
            break;
        }
        
        cout<< "Out of the 10 sortable fields, enter the amount of fields you want printed to report: ";
        cin >> numFields;
        cin.ignore(INT32_MAX, '\n');
            
        cout << "Enter the number of the field/s to be written to report: \n";
        
        for (int i =0; i<numFields; i++)  // takes in fields to print
        {
            cin >> printField;
            printFieldVec.push_back(printField);
        }
        cin.ignore(INT32_MAX, '\n');
        
        
        if (option == 1)
        {
            
            cout << "Enter the file name that reports will be saved to: \n";
            getline(cin, fileName);
            picturesObject.writeToFile(fileName, printFieldVec, picturesVec);
            cout << "Report has been saved to "<<fileName<<".\n";
            repeat = false; // exit do while loop
            
        }
        else if (option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 7 || option == 8 || option == 9 || option == 10)
        {
            picturesVecAfterSort = (picturesObject.sort(picturesVec, option));
           
            if (picturesVecAfterSort.empty())
            {
                repeat = false;
            }
            else
            {
                cout << "Enter the file name that reports will be saved to: \n";
                getline(cin, fileName);
                picturesObject.writeToFile(fileName,printFieldVec,picturesVecAfterSort);
                cout << "Report has been saved to "<<fileName<<".\n";
                repeat = false; // exit do while loop
            }
        }
        else
        {
            cout <<"Invalid entry.\n";
        }
        
        
    }while(repeat);
    
    
    while (repeat2)
    {
        cout << "Would you like to do a secondary sort?\n";
        getline(cin, input);
        
        if (input == "yes")
        {
            vector<Pictures> picturesVecAfterSecondSort;
            vector<int> printFieldVec2;
            string field;
            
            do
            {
                int option;
                cout<<endl;
                cout<< "--************************************************--\n";
                cout<<endl;
                cout << "Record can be sort by the following fields: " << endl;
                cout << "1. name" << endl;
                cout << "2. year" << endl;
                cout << "3. nominations" << endl;
                cout << "4. rating" << endl;
                cout << "5. duration" << endl;
                cout << "6. genre1" << endl;
                cout << "7. genre2" << endl;
                cout << "8. release" << endl;
                cout << "9. metacritic" << endl;
                cout << "10. synopsis" << endl;
                cout << "11. Cancel" << endl;
                cout<<endl;
                cout << "Enter the number of the field to sort by or enter 11 to return to main menu.\n"
                << "Enter number: ";
                
                cin >> option;
                cin.ignore(INT32_MAX, '\n');
                if (option == 11)
                {
                    cout << "record sort cancelled by user.\n";
                    repeat2 = false;
                    break;
                }
                
                cout<< "Out of the 10 sortable fields, enter the amount of fields you want printed to report: ";
                cin >> numFields;
                cin.ignore(INT32_MAX, '\n');
                    
                
                cout << "Enter the number of the field/s to be written to report: \n";
                
                for (int i =0; i<numFields; i++)  // takes in fields to print
                {
                    cin >> printField;
                    printFieldVec.push_back(printField);
                }
                cin.ignore(INT32_MAX, '\n');
                
                if (option == 1)
                {
                    
                    cout << "Enter the file name that reports will be saved to: \n";
                    getline(cin, fileName);
                    picturesObject.writeToFile(fileName, printFieldVec, picturesVec);
                    cout << "Report has been saved to "<<fileName<<".\n";
                    repeat = false;
                    repeat2 = false;
                    
                }
                else if (option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 7 || option == 8 || option == 9 || option == 10)
                {
                    picturesVecAfterSort = (picturesObject.sort(picturesVec, option));
                    
                    if (picturesVecAfterSort.empty())
                    {
                        repeat = false;
                    }
                    else
                    {
                        cout << "Enter the file name that reports will be saved to: \n";
                        getline(cin, fileName);
                        picturesObject.writeToFile(fileName,printFieldVec,picturesVecAfterSort);
                        cout << "Report has been saved to "<<fileName<<".\n";
                        repeat = false;
                        repeat2 = false;
                    }
                }
                else
                {
                    cout <<"Invalid entry.\n";
                }
                
                
            }while(repeat);
        }
            else
                repeat2 = false;
        
    }//end of while loop
}

/*
Function outputs searchable fields and whether user wants search to be done exact or contains.
If user chooses the name field, the corresponding binary search tree object is searched and result is written to file by calling writeToFile. This result is also copied into ActorActress or Pictures objects that are added into a vector.
if user does not choose the name field, the vector and field are used a parameters to exactSearch and containsSearch functions from Vector.h The returned vector is used in writeTofile Function
*/

void searchRecords(ActorActressBSTree * BSTreeA)
{
    NodeActorActress* dataPtr = nullptr;
    vector<ActorActress> ActorActressVec;
    ActorActress ActorActressObj;
    vector<ActorActress> resultVectorSecondSearch;
    vector<ActorActress> resultVectorCopy;
    vector<int> printFieldVec;
    vector<int> printFieldVec2;
    NodeActorActress* nodePTr = BSTreeA->Root();
    bool repeat = true;
    bool repeat2 = true;
    bool doSecondSearch = true;
    int printField;
    string fileName;
    
    ActorActressVec = BSTreeA->inorderTraversal(nodePTr, ActorActressVec);
    
   do
   {
        int option;
        string searchMode, search;
       cout<<endl;
       cout<< "--************************************************--\n";
       cout<<endl;
        cout << "Record can be searched by the following fields: " << endl;
        cout << "1. year" << endl;
        cout << "2. award" << endl;
        cout << "3. name" << endl;
        cout << "4. film" << endl;
        cout << "5. Cancel" << endl;
       cout <<endl;
        cout << "Enter the number of the field to search by or enter 5 to return to main menu.\n"
            << "Enter number: ";
        
        cin>>option;
        cin.ignore(INT32_MAX, '\n');
       
       if (option == 5)
       {
           cout << "record search cancelled by user.\n";
           doSecondSearch =false;
           break;
       }
       
       cout << "Enter the number of the field/s to be written to report: \n";
       cin >> printField;
       cin.ignore(INT32_MAX, '\n');
       
       printFieldVec.push_back(printField);
       
        cout << "exact or contains search?\n";
        getline (cin, searchMode);
       
        if (searchMode == "exact")
        {

            if (option == 3)
            {
                string name;
                cout << "Enter name: ";
                getline (cin, name);
               
                
                dataPtr = BSTreeA->findNode(name, nodePTr);
                
                if(dataPtr == nullptr)
                {
                    cout <<"Record with the name "<<name<<" was not found.\n";
                    repeat=false;
                    doSecondSearch = false;
                }
                else
                {
                    BSTreeA->writeToFile("search results.txt", dataPtr);
                
                    ActorActressObj.setYear(dataPtr->getYear());
                    ActorActressObj.setAward(dataPtr->getAward());
                    ActorActressObj.setWinner(dataPtr->getWinner());
                    ActorActressObj.setName(dataPtr->getName());
                    ActorActressObj.setFilm(dataPtr->getFilm());
                    resultVectorCopy.push_back(ActorActressObj);

     
                    cout << "Enter the file name that reports will be saved to: \n";
                    getline(cin, fileName);
                    
                    ActorActressObj.writeToFile(fileName, printFieldVec, resultVectorCopy);
                    
                    cout << "Report has been saved to "<<fileName<<".\n";
                    repeat = false;
                }
                
            }
            else if (option == 1 || option == 2 || option == 4 )
            {
                resultVectorCopy = (ActorActressObj.exactSearch(option, ActorActressVec));
                
                if(resultVectorCopy.empty())
                {
                    cout << "No matching records were found.\n";
                    repeat = false;
                }
                else
                {
            
                    cout << "Enter the file name that reports will be saved to: \n";
                    getline(cin, fileName);
                    
                    ActorActressObj.writeToFile(fileName, printFieldVec , resultVectorCopy);
                    
                    cout << "Report has been saved to "<<fileName<<".\n";
                    repeat = false;
                }
            }
            else
            {
                cout <<"Invalid entry.\n";
            }
        }

       if (searchMode == "contains")
       {
           if (option == 3)
           {
               string name;
               cout << "Enter name: ";
               getline (cin, name);
               
               
               dataPtr = BSTreeA->findNode(name, nodePTr);
               
               if(dataPtr == nullptr)
               {
                   cout <<"Record with the name "<<name<<" was not found.\n";
                   repeat = false;
               }
               else
               {
                   BSTreeA->writeToFile("search results.txt", dataPtr);
                   
                   ActorActressObj.setYear(dataPtr->getYear());
                   ActorActressObj.setAward(dataPtr->getAward());
                   ActorActressObj.setWinner(dataPtr->getWinner());
                   ActorActressObj.setName(dataPtr->getName());
                   ActorActressObj.setFilm(dataPtr->getFilm());
                   resultVectorCopy.push_back(ActorActressObj);

                   cout << "Enter the file name that reports will be saved to: \n";
                   getline(cin, fileName);
                   
                   ActorActressObj.writeToFile(fileName, printFieldVec , resultVectorCopy);
                   
                   cout << "Report has been saved to "<<fileName<<".\n";
                   repeat = false;
                 
               }
           }
           else if (option == 1 || option == 2 || option == 4 )
           {
               resultVectorCopy = (ActorActressObj.containsSearch(option, ActorActressVec));
               
               if(resultVectorCopy.empty())
               {
                   cout << "No matching records were found.\n";
                   repeat = false;
                   doSecondSearch = false;
               }
               else
               {
                   cout << "Enter the file name that reports will be saved to: \n";
                   getline(cin, fileName);
                   
                   ActorActressObj.writeToFile(fileName, printFieldVec , resultVectorCopy);
                   
                   cout << "Report has been saved to "<<fileName<<".\n";
                   repeat = false;
               }
           }
           else
           {
               cout <<"Invalid entry.\n";
           }
           
       }
       else if (searchMode != "exact" || searchMode != "contains")
       {
           cout <<"Invalid entry.\n";
       }
       
    }while (repeat);
    
    while (doSecondSearch)
    {
            string input;
            cout << "Would you like to do a secondary search?\n";
            cin >> input;
            
        if (input == "yes")
            {
  
            do
            {  int option;
                string searchMode, search;
                cout<<endl;
                cout<< "--************************************************--\n";
                cout<<endl;
                cout << "Record can be searched by the following fields: " << endl;
                cout << "1. year" << endl;
                cout << "2. award" << endl;
                cout << "3. name" << endl;
                cout << "4. film" << endl;
                cout << "5. Cancel" << endl;
                cout<<endl;
                cout << "Enter the number of the field to search by or enter 5 to return to main menu.\n";
                
                cin>>option;
                cin.ignore(INT32_MAX, '\n');
                
                if (option == 5)
                {
                    cout << "record search cancelled by user.\n";
                    doSecondSearch=false;
                    break;
                }
                
                cout << "Enter the number of the field/s to be written to report: \n";
                cin >> printField;
                cin.ignore(INT32_MAX, '\n');
                
                printFieldVec2.push_back(printField);
    
                
                cout << "exact or contains search?\n";
                getline(cin, searchMode);
                
                if (searchMode == "exact")
                {
                    
                    if (option == 1 || option == 2 || option == 3 || option == 4)
                    {
                        resultVectorSecondSearch = (ActorActressObj.exactSearch(option, resultVectorCopy));
                        
                        if (resultVectorSecondSearch.empty())
                        {
                            cout << "No matching records were found.\n";
                            repeat2 = false;
                        }
                        
                        else
                        {

                            cout << "Enter the file name that reports will be saved to: \n";
                            getline(cin, fileName);
                            
                            ActorActressObj.writeToFile(fileName, printFieldVec2 , resultVectorSecondSearch);
                            
                            cout << "Report has been saved to "<<fileName<<".\n";
                            repeat2 = false;
                            doSecondSearch = false;
                        }
                    }
                    

                    else
                    {
                        cout <<"Invalid entry.\n";
                    }
                }
                
                if (searchMode == "contains")
                {
                        if (option == 1 || option == 2 || option == 3 || option == 4 )
                    {
                        
                        resultVectorSecondSearch = (ActorActressObj.containsSearch(option, resultVectorCopy));
                        
                        if (resultVectorSecondSearch.empty())
                        {
                            
                            repeat2 = false;
                        }
                        
                        else
                        {
                            cout << "Enter the file name that reports will be saved to: \n";
                            getline(cin, fileName);
                            
                            ActorActressObj.writeToFile(fileName, printFieldVec2 , resultVectorSecondSearch);
                            
                            cout << "Report has been saved to "<<fileName<<".\n";
                            repeat2 = false;
                            doSecondSearch = false;
                        }
                    }
                    else
                    {
                        cout <<"Invalid entry.\n";
                    }
                
                }
                else if (searchMode != "exact" || searchMode != "contains")
                {
                    cout <<"Invalid entry.\n";
                }
                
            }while(repeat2);
            }
        else
            doSecondSearch= false;
    }
}

// functions works the same as function above

void searchRecords(PicturesBSTree* BSTreeP)
{
    
    NodePictures* dataPtr = nullptr;
    vector<Pictures> picturesVec;
    Pictures picturesObj;
    vector<Pictures> picturesVecAfterSearch;
    vector<Pictures> picturesVecAfterSecondSearch;
    vector<int> printFieldVec;
    vector<int> printFieldVec2;
    NodePictures* nodePTr = BSTreeP->Root();
    bool repeat = true;
    bool repeat2 = true;
    bool doSecondSearch = true;
    int printField;
    string fileName;
    
    picturesVec= BSTreeP->inorderTraversal(nodePTr, picturesVec);
    
    do
    {
        int option;
        string searchMode, search;
        cout<<endl;
        cout<< "--************************************************--\n";
        cout<<endl;
        cout << "Record can be searched by the following fields: " << endl;
        cout << "1. name" << endl;
        cout << "2. year" << endl;
        cout << "3. genre1" << endl;
        cout << "4. genre2" << endl;
        cout << "5. release" << endl;
        cout << "6. synopsis" << endl;
        cout << "7. Cancel" << endl;
        cout<<endl;
        cout << "Enter the number of the field to sort by or enter 7 to return to main menu.\n"
        << "Enter number: ";
        
        cin>>option;
        cin.ignore(INT32_MAX, '\n');
        
        
        if (option == 7)
        {
            cout << "record search cancelled by user.\n";
            doSecondSearch =false;
            break;
        }
        
        cout << "Enter the number of the field/s to be written to report: \n";
        cin >> printField;
        cin.ignore(INT32_MAX, '\n');
        
        printFieldVec.push_back(printField);
    
        
        cout << "exact or contains search?\n";
        getline (cin, searchMode);
        
        if (searchMode == "exact")
        {
            if (option == 1)
            {
                string name;
                cout << "Enter name: ";
                getline (cin, name);
                
                dataPtr = BSTreeP->findNode(name, nodePTr);
                
                if (dataPtr == nullptr)
                {
                    cout <<"Record with the name "<<name<<" was not found.\n";
                    repeat=false;
                    doSecondSearch = false;
                }
                else
                {
                    BSTreeP->writeToFile(fileName, dataPtr);
                    
                picturesObj.setName(dataPtr->getName());
                picturesObj.setYear(dataPtr->getYear());
                picturesObj.setNominations(dataPtr->getNominations());
                picturesObj.setRating(dataPtr->getRating());
                picturesObj.setDuration(dataPtr->getDuration());
                picturesObj.setGenre1(dataPtr->getGenre1());
                picturesObj.setGenre2(dataPtr->getGenre2());
                picturesObj.setRelease(dataPtr->getRelease());
                picturesObj.setMetacritic(dataPtr->getMetacritic());
                picturesObj.setSynopsis(dataPtr->getSynopsis());
                picturesVecAfterSearch.push_back(picturesObj);
                repeat = false;
                
                    cout << "Enter the file name that reports will be saved to: \n";
                    getline(cin, fileName);
                    
                    picturesObj.writeToFile(fileName, printFieldVec, picturesVecAfterSearch);
                    
                    cout << "Report has been saved to "<<fileName<<".\n";
                    repeat = false;
                }
                
            }
            else if (option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
            {
                picturesVecAfterSearch = (picturesObj.exactSearch(option, picturesVec));
                
                if(picturesVecAfterSearch.empty())
                {
                   
                    repeat = false;
                }
                else
                {
                    
                    cout << "Enter the file name that reports will be saved to: \n";
                    getline(cin, fileName);
                    
                    picturesObj.writeToFile(fileName, printFieldVec , picturesVecAfterSearch);
                    
                    cout << "Report has been saved to "<<fileName<<".\n";
                    repeat = false;
                }
            }
            else
            {
                cout <<"Invalid entry.\n";
            }
        }
        
        if (searchMode == "contains")
        {
            if (option == 1)
            {
                string name;
                cout << "Enter name: ";
                getline (cin, name);
                
                dataPtr = BSTreeP->findNode(name, nodePTr);
                
                if (dataPtr == nullptr)
                {
                    cout <<"Record with the name "<<name<<" was not found.\n";
                    repeat=false;
                    doSecondSearch = false;
                }
                else
                {
                    BSTreeP->writeToFile(fileName, dataPtr);
                    
                    picturesObj.setName(dataPtr->getName());
                    picturesObj.setYear(dataPtr->getYear());
                    picturesObj.setNominations(dataPtr->getNominations());
                    picturesObj.setRating(dataPtr->getRating());
                    picturesObj.setDuration(dataPtr->getDuration());
                    picturesObj.setGenre1(dataPtr->getGenre1());
                    picturesObj.setGenre2(dataPtr->getGenre2());
                    picturesObj.setRelease(dataPtr->getRelease());
                    picturesObj.setMetacritic(dataPtr->getMetacritic());
                    picturesObj.setSynopsis(dataPtr->getSynopsis());
                    picturesVecAfterSearch.push_back(picturesObj);
                    repeat = false;
                    
                    cout << "Enter the file name that reports will be saved to: \n";
                    getline(cin, fileName);
                    
                    picturesObj.writeToFile(fileName, printFieldVec, picturesVecAfterSearch);
                    
                    cout << "Report has been saved to "<<fileName<<".\n";
                    repeat = false;
                }
                
            }
            else if (option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
            {
                picturesVecAfterSearch = (picturesObj.containsSearch(option, picturesVec));
                
                if(picturesVecAfterSearch.empty())
                {
                    cout << "No matching records were found.\n";
                    repeat = false;
                }
                else
                {
                    
                    cout << "Enter the file name that reports will be saved to: \n";
                    getline(cin, fileName);
                    
                    picturesObj.writeToFile(fileName, printFieldVec , picturesVecAfterSearch);
                    
                    cout << "Report has been saved to "<<fileName<<".\n";
                    repeat = false;
                }
            }
            else
            {
                cout <<"Invalid entry.\n";
            }
        }
        else if (searchMode != "exact" || searchMode != "contains")
        {
            cout <<"Invalid entry.\n";
        }
        
    }while (repeat);
    
    while (doSecondSearch)
    {
        string input;
        cout << "Would you like to do a secondary search?\n";
        cin >> input;
        
        if (input == "yes")
        {
            do
            {
                int option;
                string searchMode, search;
                cout<<endl;
                cout<< "--************************************************--\n";
                cout<<endl;
                cout << "Record can be searched by the following fields: " << endl;
                cout << "1. name" << endl;
                cout << "2. year" << endl;
                cout << "3. genre1" << endl;
                cout << "4. genre2" << endl;
                cout << "5. release" << endl;
                cout << "6. synopsis" << endl;
                cout << "7. Cancel" << endl;
                cout<<endl;
                cout << "Enter the number of the field to sort by or enter 7 to return to main menu.\n"
                << "Enter number: ";
                
                cin>>option;
                cin.ignore(INT32_MAX, '\n');
                
                if (option == 7)
                {
                    cout << "record search cancelled by user.\n";
                    doSecondSearch =false;
                    break;
                }
                
                cout << "Enter the number of the field/s to be written to report: \n";
                cin >> printField;
                cin.ignore(INT32_MAX, '\n');
                
                printFieldVec2.push_back(printField);
                
                
                cout << "exact or contains search?\n";
                getline (cin, searchMode);
                
                if (searchMode == "exact")
                {
                    if (option == 1)
                    {
                        string name;
                        cout << "Enter name: ";
                        getline (cin, name);
                        
                        dataPtr = BSTreeP->findNode(name, nodePTr);
                        
                        if (dataPtr == nullptr)
                        {
                            cout <<"Record with the name "<<name<<" was not found.\n";
                            repeat2=false;
                            doSecondSearch = false;
                        }
                        else
                        {
                            BSTreeP->writeToFile(fileName, dataPtr);
                            
                            picturesObj.setName(dataPtr->getName());
                            picturesObj.setYear(dataPtr->getYear());
                            picturesObj.setNominations(dataPtr->getNominations());
                            picturesObj.setRating(dataPtr->getRating());
                            picturesObj.setDuration(dataPtr->getDuration());
                            picturesObj.setGenre1(dataPtr->getGenre1());
                            picturesObj.setGenre2(dataPtr->getGenre2());
                            picturesObj.setRelease(dataPtr->getRelease());
                            picturesObj.setMetacritic(dataPtr->getMetacritic());
                            picturesObj.setSynopsis(dataPtr->getSynopsis());
                            picturesVecAfterSecondSearch.push_back(picturesObj);
                            repeat2 = false;
                            
                            cout << "Enter the file name that reports will be saved to: \n";
                            getline(cin, fileName);
                            
                            picturesObj.writeToFile(fileName, printFieldVec, picturesVecAfterSecondSearch);
                            
                            cout << "Report has been saved to "<<fileName<<".\n";
                            repeat2 = false;
                            doSecondSearch = false;
                        }
                        
                    }
                    else if (option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
                    {
                        picturesVecAfterSecondSearch = (picturesObj.exactSearch(option, picturesVecAfterSearch));
                        
                        if(picturesVecAfterSearch.empty())
                        {
                            cout << "No matching records were found.\n";
                            repeat2 = false;
                        }
                        else
                        {
                            
                            cout << "Enter the file name that reports will be saved to: \n";
                            getline(cin, fileName);
                            
                            picturesObj.writeToFile(fileName, printFieldVec , picturesVecAfterSecondSearch);
                            
                            cout << "Report has been saved to "<<fileName<<".\n";
                            repeat2 = false;
                            doSecondSearch = false;
                        }
                    }
                    else
                    {
                        cout <<"Invalid entry.\n";
                    }
                }
                
                if (searchMode == "contains")
                {
                    if (option == 1)
                    {
                        string name;
                        cout << "Enter name: ";
                        getline (cin, name);
                        
                        dataPtr = BSTreeP->findNode(name, nodePTr);
                        
                        if (dataPtr == nullptr)
                        {
                            cout <<"Record with the name "<<name<<" was not found.\n";
                            repeat2=false;
                            doSecondSearch = false;
                        }
                        else
                        {
                            BSTreeP->writeToFile(fileName, dataPtr);
                            
                            picturesObj.setName(dataPtr->getName());
                            picturesObj.setYear(dataPtr->getYear());
                            picturesObj.setNominations(dataPtr->getNominations());
                            picturesObj.setRating(dataPtr->getRating());
                            picturesObj.setDuration(dataPtr->getDuration());
                            picturesObj.setGenre1(dataPtr->getGenre1());
                            picturesObj.setGenre2(dataPtr->getGenre2());
                            picturesObj.setRelease(dataPtr->getRelease());
                            picturesObj.setMetacritic(dataPtr->getMetacritic());
                            picturesObj.setSynopsis(dataPtr->getSynopsis());
                            picturesVecAfterSecondSearch.push_back(picturesObj);
                            repeat2 = false;
                            
                            cout << "Enter the file name that reports will be saved to: \n";
                            getline(cin, fileName);
                            
                            picturesObj.writeToFile(fileName, printFieldVec, picturesVecAfterSecondSearch);
                            
                            cout << "Report has been saved to "<<fileName<<".\n";
                            repeat2 = false;
                            doSecondSearch = false;
                        }
                        
                    }
                    else if (option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
                    {
                        picturesVecAfterSecondSearch = (picturesObj.containsSearch(option, picturesVecAfterSearch));
                        
                        if(picturesVecAfterSearch.empty())
                        {
                            cout << "No matching records were found.\n";
                            repeat2 = false;
                        }
                        else
                        {
                            
                            cout << "Enter the file name that reports will be saved to: \n";
                            getline(cin, fileName);
                            
                            picturesObj.writeToFile(fileName, printFieldVec , picturesVecAfterSecondSearch);
                            
                            cout << "Report has been saved to "<<fileName<<".\n";
                            repeat2 = false;
                            doSecondSearch = false;
                        }
                    }
                    else
                    {
                        cout <<"Invalid entry.\n";
                    }
                }
                else if (searchMode != "exact" || searchMode != "contains")
                {
                    cout <<"Invalid entry.\n";
                }
                
            }while(repeat);

        }
        else
            doSecondSearch= false;
}
}

// function creates a CSV file of the modififed recoreds when case 8 of main menu function is chosen
void writeModifiedRecordsToFile (PicturesBSTree* BSTreeP)
{
    NodePictures* nodePtr = BSTreeP -> Root();
    vector<Pictures> PicturesVec ;
    PicturesVec = (BSTreeP->inorderTraversal(nodePtr, PicturesVec));
    Pictures object;
    
    string fileName = "pictures-modified.csv";
    string saveToNewFile;
    cout <<"Save modified record to new file? \n"
    << "Enter yes or no. ";
    getline(cin, saveToNewFile);
    
    if(saveToNewFile == "yes")
    {
        cout << "Enter new file name that records will be saved to: \n";
        getline(cin, saveToNewFile);
        object.writeCSV(saveToNewFile, PicturesVec);
    }
    else
    {
        cout <<"Modified records have been saved to "<<fileName<<endl;
        object.writeCSV(fileName, PicturesVec);
    }

}

// functions works the same as function above
void writeModifiedRecordsToFile (ActorActressBSTree* BSTreeA)
{
    
    NodeActorActress* nodePtr = BSTreeA -> Root();
    vector<ActorActress> ActorActressVec ;
    ActorActressVec = (BSTreeA->inorderTraversal(nodePtr, ActorActressVec));
    ActorActress object;
    
    string fileName = "actor-actress-modified.csv";
    string saveToNewFile;
    cout <<"Save modified record to new file? \n"
        << "Enter yes or no. ";
    getline(cin, saveToNewFile);
    
    if(saveToNewFile == "yes")
    {
        cout << "Enter new file name that records will be saved to: \n";
        getline(cin, saveToNewFile);
        object.writeCSV(saveToNewFile, ActorActressVec);
    }
    else
    {
        cout <<"Modified records have been saved to "<<fileName<<endl;
        object.writeCSV(fileName, ActorActressVec);
    }
    
}

// Nancy Moreno Huizar

#ifndef Vectors_h
#define Vectors_h
#include <vector>
#include <string>
using namespace  std;

class ActorActress
{
private:
    int year;
    string award;
    int winner;
    string name;
    string film;
public:
    ActorActress() { year=-1; award = "no data"; winner = -1; name = "no data"; film = "no data";};
    void setYear(int aYear) { year = aYear;};
    int getYear (){return year;}
    void setAward(string anAward) {award = anAward;};
    string getAward (){return award;};
    void setWinner(int aWinner){winner = aWinner;};
    int getWinner (){return winner;}
    void setName(string aName){name = aName;};
    string getName(){return name;};
    void setFilm(string aFilm){film = aFilm;};
    string getFilm(){return film;};
    vector<ActorActress> exactSearch(int field, vector<ActorActress>& vectorToBeSearched);
    vector<ActorActress> containsSearch(int, vector<ActorActress>& inputVector);
    vector< ActorActress> sort (vector<ActorActress>&, int);
    void writeToFile (string fileName, vector<int>& printVector, vector<ActorActress>&);
    void writeCSV (string fileName, vector<ActorActress>&);
    };

class Pictures
{
private:
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
public:
    Pictures() {name = "no data"; year=-1; nominations = -1; rating = -1.0; duration = -1; genre1 = "no data"; genre2 = "no data"; release = "no data"; metacritic=-1; synopsis = "no data";};
    void setYear(int aYear) { year = aYear; };
    int getYear() { return year; };
    void setDuration(int aDuration) { duration = aDuration; };
    int getDuration() { return duration; };
    void setGenre1(string aGenre1) {genre1 = aGenre1;};
    string getGenre1 (){return genre1;};
    void setNominations(int aNominations){nominations = aNominations;};
    int getNominations(){return nominations ;};
    void setName(string aName){name = aName;};
    string getName(){return name;};
    void setGenre2(string aGenre2){genre2 = aGenre2; };
    string getGenre2(){return genre2;};
    void setRelease(string aRelease){release = aRelease; };
    string getRelease(){return release;};
    void setMetacritic(int aMetacritic) { metacritic = aMetacritic; };
     int getMetacritic() { return metacritic; };
    void setSynopsis(string aSynopsis){synopsis = aSynopsis; };
    string getSynopsis(){return synopsis;};
    void setRating(int aRating){rating = aRating;};
    float getRating(){return rating;};
    vector<Pictures> exactSearch(int, vector<Pictures>& vector);
    vector<Pictures> containsSearch(int, vector<Pictures>& inputVector);
    vector<Pictures> sort (vector<Pictures>&, int);
    void writeToFile (string fileName, vector<int>& printVector, vector<Pictures>& inputVector);
    void writeCSV (string fileName, vector<Pictures>& inputVector);
};

#endif /* Vectors_h */

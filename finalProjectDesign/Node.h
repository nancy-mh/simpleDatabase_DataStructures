//Nancy Moreno Huizar

#ifndef NODE_
#define NODE_
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// A generic tree node class
class NodeActorActress {
    int year;
    string award;
    int winner;
    string name;
    string film;
    NodeActorActress* left;
    NodeActorActress* right;
    NodeActorActress* parent;
    string noData = "no data";
public:
    NodeActorActress() { year=-1; award = noData; winner = -1; name = noData; film = noData; left=nullptr; right=nullptr; parent = nullptr;};
    void setYear(int aYear) { year = aYear;};
    int getYear(){return year;}
    void setAward(string anAward) {award = anAward;};
    string getAward (){return award;};
    void setWinner(int aWinner){winner = aWinner;};
    int getWinner (){return winner;}
    void setName(string aName){name = aName;};
    string getName(){return name;};
    void setFilm(string aFilm){film = aFilm;};
    string getFilm(){return film;};
    void setLeft(NodeActorActress* aLeft) { left = aLeft; };
    void setRight(NodeActorActress* aRight) { right = aRight; };
    void setParent(NodeActorActress* aParent) { parent = aParent; };
    NodeActorActress* Left() { return left; };
    NodeActorActress* Right() { return right; };
    NodeActorActress* Parent() { return parent; };
};

class NodePictures {
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
    NodePictures* left;
    NodePictures* right;
    NodePictures* parent;

public:
    NodePictures() {name = "no data"; year=-1; nominations = -1; rating = -1.0; duration = -1; genre1 = "no data"; genre2 = "no data"; release = "no data"; metacritic= -1; synopsis = "no data"; left=nullptr; right=nullptr; parent = nullptr;};
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
    void setRating(float aRating){rating = aRating;};
    float getRating(){return rating;};
    void setLeft(NodePictures* aLeft) { left = aLeft; };
    void setRight(NodePictures* aRight) { right = aRight; };
    void setParent(NodePictures* aParent) { parent = aParent; };
    NodePictures* Left() { return left; };
    NodePictures* Right() { return right; };
    NodePictures* Parent() { return parent; };
};

#endif

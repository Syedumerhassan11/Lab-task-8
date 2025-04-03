#include <iostream>
#include <vector>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string uID, string pub) 
        : title(t), publicationDate(pDate), uniqueID(uID), publisher(pub) {}

    virtual void displayInfo() = 0;
    void checkOut() { cout << title << " checked out." << endl; }
    void returnItem() { cout << title << " returned." << endl; }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string uID, string pub, string auth, string isbn, int pages)
        : Media(t, pDate, uID, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override { cout << title << " by " << author << ", ISBN: " << ISBN << ", " << numberOfPages << " pages." << endl; }
};

class DVD : public Media {
    string director;
    double duration, rating;
public:
    DVD(string t, string pDate, string uID, string pub, string dir, double dur, double rate)
        : Media(t, pDate, uID, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override { cout << title << " directed by " << director << ", " << duration << " min, Rating: " << rating << endl; }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pDate, string uID, string pub, string art, int tracks, string gen)
        : Media(t, pDate, uID, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override { cout << title << " by " << artist << ", " << numberOfTracks << " tracks, Genre: " << genre << endl; }
};

class Library {
    vector<Media*> collection;
public:
    void addMedia(Media* m) { collection.push_back(m); }

    void searchMedia(string title) {
        for (auto m : collection) {
            if (m->title == title) { m->displayInfo(); return; }
        }
        cout << "Media not found." << endl;
    }
};

int main() {
    Library lib;
    Book b("C++ Primer", "2012", "B001", "Pearson", "Lippman", "978-0321714114", 976);
    DVD d("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD c("Thriller", "1982", "C001", "Epic", "Michael Jackson", 9, "Pop");

    lib.addMedia(&b);
    lib.addMedia(&d);
    lib.addMedia(&c);

    b.displayInfo();
    d.displayInfo();
    c.displayInfo();

    lib.searchMedia("Inception");

    return 0;
}


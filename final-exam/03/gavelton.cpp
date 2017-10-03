#include <string>
#include <vector>
#include <iostream>
using namespace std;
class MediaItem {
  public:
    string title;
      MediaItem(const string &title) : title(title) {}
    ~MediaItem() {}
    bool searchTitle(const string& phrase) const {
      return title.find(phrase) != string::npos;
    }
    virtual bool searchOther(const string& phrase) const = 0;
};

class Book : public MediaItem {
  public:
    string *author;
      Book(const string &title, const string &author) :
        MediaItem(title), author(new string(author)) {}
    bool searchOther(const string& phrase) const {
      return author->find(phrase) != string::npos;
    }
    ~Book() { delete author; }
};

class Film : public MediaItem {
  public:
    string *director;
      Film(const string &title, const string &director) :
        MediaItem(title), director(new string(director)) {}
    bool searchOther(const string& phrase) const {
      return director->find(phrase) != string::npos;
    }
    ~Film() { delete director; }
};

class Catalog {
  vector<MediaItem *> items;
  public:
    void addItem(MediaItem *item) { items.push_back(item); }
    vector<MediaItem*> search(const string &phrase) {
      vector<MediaItem*> results;
        for (int i = 0; i < items.size(); i++) {
          if (items[i]->searchOther(phrase) ||
              items[i]->searchTitle(phrase)) {
            results.push_back(items[i]);
          }
        }
      return results;
    }
    ~Catalog() {
      for (int i = 0; i < items.size(); i++) {
        delete items[i];
      }
    }
};

int main() {
  Catalog c;
    c.addItem(new Book("Snow Crash", "Neal Stephenson"));
    c.addItem(new Film("Snow Piercer", "Joon Ho Bong"));
    vector<MediaItem *> results = c.search("Snow");
    for (int i = 0; i < results.size(); i++) {
      cout << results[i]->title << "\n";
    }
  return 0;
}

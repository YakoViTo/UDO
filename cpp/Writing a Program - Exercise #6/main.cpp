//Write a program that checks if a sentence is correct according to the "English" grammar. Assume that every
//sentence is terminated by a full stop (.) surrounded by whitespace.
//Added "the" to the "English" grammar
//Not using stringstream...

/*
        "ENGLISH" GRAMMAR

        SENTENCE:
            ARTICLE NOUN VERB
            NOUN VERB
            SENTENCE CONJUNCTION SENTENCE

        CONJUNCTION:
            "and"
            "or"
            "but"

        NOUN:
            "birds"
            "fish"
            "C++"

        VERB:
            "rules"
            "fly"
            "swim"

        ARTICLE:
            "the"
            "that"
            "a"
            "an"
*/

#include <iostream>
#include <string>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

class Name_value {
public:
    string str;
    char value;
    Name_value(): value('0') { }
    Name_value(string& s, const char v): str(s), value(v) { }
};

class Name_stream {
    bool full;
    Name_value buffer;
public:
    Name_stream();
    Name_value get();
    void putback(Name_value);
};

Name_stream::Name_stream():full(false), buffer(0) {}

void putback

Name_value Name_stream::get() {

    string left;
    cin >> left;

    if (left == "the" || left == "The"
        || left == "that" || left == "That"
        || left == "a" || left == "A"
        || left == "an" || left == "An")
        return Name_value{left, 'a'};

    if (left == "birds" || left == "fish" || left == "C++")
        return Name_value{left, 'n'};

    if (left == "rules" || left == "fly" || left == "swim")
        return Name_value{left, 'v'};

    if (left == "and" || left == "or" || left == "but")
        return Name_value{left, 'c'};

    throw std::runtime_error("Not a valid word");

}

Name_value article() {
    Name_value l = get();
    if (l.value == 'c')
        return l;
    return Name_value();
}

string verb() {
    string left = get();


}

string noun() {
    Name_value nm = article();
    Name_value left = get();
}

string conjunction() {

}

string sentence() {
    Name_value nm = get();
    string s = "";

    switch(nm.value) {
    case 'a':
        s = s.append(nm.str);
    }
}

int main() {

    return 0;
}

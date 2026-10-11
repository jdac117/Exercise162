#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

void display(const pair<string, int>& word_pair);

bool over_1(const pair<string, int>& word_pair);

int main() {
    cout << "The Word Counter \n\n";
    
    string text = "it was the best of times it was the worst of times it "
                  "was the age of wisdom it was the age of foolishness it was the "
                  "epoch of belief it was the epoch of incredulity it was the "
                  "season of light it was the season of darkness it was the "
                  "spring of hope it was the winter of despair";

    stringstream stream(text);
    string word;
    map<string, int> word_counts;
    int total_words = 0;

    while (stream >> word) {
        word_counts[word]++;
        total_words++;
    }

    cout << total_words << " WORDS: " << text << "\n\n";

    cout << word_counts.size() << " UNIQUE WORDS: ";
    for (auto const& [w, count] : word_counts) {
        cout << w << " ";
    }
    cout << "\n\n";

    cout << "COUNT PER WORD: ";
    for_each(word_counts.begin(), word_counts.end(), display);
    cout << "\n\n";

    long duplicate_count = count_if(word_counts.begin(), word_counts.end(), over_1);
    cout << duplicate_count << " DUPLICATE WORDS\n";

    return 0;
}

void display(const pair<string, int>& word_pair) {
    cout << word_pair.first << "=" << word_pair.second << " ";
}

bool over_1(const pair<string, int>& word_pair) {
    return word_pair.second > 1;
}

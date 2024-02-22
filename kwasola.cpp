#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {

std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

    std::string lyrics;
    std::getline(std::cin, lyrics, '^');


    std::transform(lyrics.begin(), lyrics.end(), lyrics.begin(), ::tolower);


    int letterCount[26] = {0};


    for (char c : lyrics) {
        if (std::isalpha(c)) {
            int index = c - 'a';
            letterCount[index]++;
        }
    }


    int mostFrequent = 0;
    int leastFrequent = 2000001;
    char mostFrequentLetter = 'z';
    char leastFrequentLetter = 'z';

    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > mostFrequent || (letterCount[i] == mostFrequent && 'a' + i < mostFrequentLetter)) {
            mostFrequent = letterCount[i];
            mostFrequentLetter = 'a' + i;
        }
        if (letterCount[i] < leastFrequent && letterCount[i] > 0) {
            leastFrequent = letterCount[i];
            leastFrequentLetter = 'a' + i;
        }
    }


    std::cout << mostFrequentLetter << " " << leastFrequentLetter << std::endl;

    return 0;
}

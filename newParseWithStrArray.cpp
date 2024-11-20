#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

std::vector<std::string> split(const std::string &input, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

std::vector<std::vector<std::string>> splitIntoWordGroups(const std::string &input) {
    // Split the input by commas to get groups
    std::vector<std::string> groups = split(input, ',');

    std::vector<std::vector<std::string>> wordGroups;

    // For each group, split it into words and store it in the vector of vectors
    for (const auto &group : groups) {
        wordGroups.push_back(split(group, ' '));
    }

    return wordGroups;
}

int main() {
    string sampleInput = "4 year old female hyena, born in spring, tan color, 70 pounds, from Friguia Park, Tunisia";
    string mySpecies = "";
    string arrayOfWords[5];

    vector<std::vector<string>> result = splitIntoWordGroups(sampleInput);

    // Output the groups and their words
    int j = 0;
    int k = 0;
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "Group " << (i + 1) << ": ";
        for (const auto &word : result[i]) {
            if (i==0) {
                // We are in the first group
                if (j==4) {
                    mySpecies = word;
                }
                arrayOfWords[j] = word;
                cout << "\n in the first group and word " << j << " is: " << word;
                j++;
            }
            else {
                cout << word << " ";
            }

            for (string aWord : arrayOfWords) {
                cout << "\n the array of words is " << aWord;
            }
        }
        cout << endl;
    }

    // Output species.
    cout << "\n mySpecies is..." << mySpecies << endl;

    return 0;
}
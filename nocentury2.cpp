#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

class Score {
private:
  std::string country;
  int score;
public:
  Score(std::string c, int s) {
        country = c;
        score = s;
        std::cout << c << "," << s << std::endl;
    }

  std::string getCountry() const { return country; }  // ADDED const
  void unsetCountry() { country = ""; }
  int getScore() const { return score; }  // ADDED const
};

/**
 * Read `country: score` pairs from infile and return a list of pairs
 * Stop when `infile` reaches EOF
 */
void readScores(std::istream &infile, std::vector<Score> &scores) {
  while(infile) {
    std::string country;
    infile >> std::ws;
    std::getline(infile, country, ':');
    int runs;
    infile >> runs;
    if (country != "") {
      Score score(country, runs);
      scores.push_back(score);
    }
  }
}

int noCenturyCountryCount(std::vector<Score> &scores) {
  int noCenturyCount = 0;
  std::map<std::string, bool> countryHasCentury;  // Keeps track of whether a country has a century

  for(const Score& s : scores) {
    if (s.getScore() >= 100) {
      countryHasCentury[s.getCountry()] = true;
    } else if (countryHasCentury.find(s.getCountry()) == countryHasCentury.end()) {
      countryHasCentury[s.getCountry()] = false;
    }
  }

  for (const auto &entry : countryHasCentury) {
    if (!entry.second) {
      noCenturyCount++;
    }
  }

  return noCenturyCount;
}

int main() {
  std::vector<Score> scores;
  readScores(std::cin, scores);
  int noCenturyCount = noCenturyCountryCount(scores);
  std::cout << noCenturyCount << std::endl;
}

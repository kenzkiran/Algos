#pragma once

#include <iostream>
#include <list>
#include <map>
#include <optional>
#include <vector>

using namespace std;
/* Common Utilities */

template <typename T>
void DumpVector(const std::vector<T> &in,
                std::optional<std::string> delimiter = std::nullopt) {
  std::string delim = (delimiter) ? *delimiter : " ";
  for (size_t i = 0; i < in.size(); ++i) {
    cout << in[i] << delim;
  }
  cout << endl;
}

template <typename T>
void DumpList(const std::list<T> &in,
              std::optional<std::string> delimiter = std::nullopt) {
  std::string delim = (delimiter) ? *delimiter : " ";
  for (auto iter = in.begin(); iter != in.end(); ++iter) {
    cout << *iter << delim;
  }
  cout << endl;
}

template <typename K, typename T> void DumpMap(const std::map<K, T> &in) {
  for (const auto &entry : in) {
    cout << entry.first << " : " << entry.second << endl;
  }
}
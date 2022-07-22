#include <algorithm>
#include <iostream>
#include <iterator>
#include <optional>
#include <utility>
#include <vector>

using OptionalSet = std::vector<std::optional<std::string>>;

class Parse {
private:
  std::vector<std::string> m_vec;

public:
  Parse() { m_vec.push_back("NULL"); }
  Parse(std::vector<std::string> input_vec) : m_vec(input_vec) {}

  Parse(OptionalSet input_vec) {
    for (auto i : input_vec) {
      if (i.has_value()) {
        m_vec.push_back(std::move(i->data()));
      } else if (!i.has_value()) {
        m_vec.push_back(std::move("NULL"));
      }
    }
  }

  void classed_print_vector_strings() {
    for (std::string i : m_vec) {
      std::cout << i << std::endl;
    }
  }
};

class ParseSet {
private:
  std::vector<Parse> m_set;
  
public:
  ParseSet(std::vector<Parse> input_set): m_set(input_set){}
};
bool specialEqual(const std::vector<OptionalSet> &vecs) {

  auto last_intersection = vecs[0];
  OptionalSet curr_intersection;

  auto cmp = [](auto lhs, auto rhs) {
    if (std::is_same<decltype(rhs.value()), std::nullopt_t>::value) {
      std::cout << "nullopt_t" << std::endl;
      rhs.value() = 2;
    }
    if (std::is_same<decltype(lhs.value()), std::nullopt_t>::value) {
      std::cout << "nullopt_t" << std::endl;
      lhs.value() = 2;
    }
    return lhs < rhs;
  };

  for (std::size_t i = 1; i < vecs.size(); ++i) {
    std::set_intersection(last_intersection.begin(), last_intersection.end(),
                          vecs[i].begin(), vecs[i].end(),
                          std::back_inserter(curr_intersection));
    std::swap(last_intersection, curr_intersection);
    curr_intersection.clear();
    for (int i = 0; i < last_intersection.size(); i++) {
      if (last_intersection[i].has_value()) {
        std::cout << "Last intersection" << last_intersection[i].value() << ' ';
      }
    }
  }
  if (last_intersection.empty()) {
    return 0;
  } else {
    return 1;
  }
}


int main(int argc, char *argv[]) {
  OptionalSet setA = {"A"};
  OptionalSet setB = {"C", "B", std::nullopt};
  OptionalSet setC = {"A", std::nullopt};
  std::vector<OptionalSet> input = {setA, setB, setC};

  Parse parser1(setA);
  Parse parser2(setB);
  Parse parser3(setC);
  parser3.classed_print_vector_strings();
  
  ParseSet set1({parser1,parser2,parser3});
  bool result = specialEqual(input);
  if (result == 1) {
    std::cout << "TRUE" << std::endl;
  } else {
    std::cout << "FALSE" << std::endl;
  }
  return 1;
};

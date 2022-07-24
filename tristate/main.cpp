#include <algorithm>
#include <iostream>
#include <iterator>
#include <optional>
#include <utility>
#include <vector>

using OptionalSet = std::vector<std::optional<std::string>>;

enum class Result { TRUE, FALSE, UNDETERMINED };

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
  void swap(Parse &lhs, std::vector<std::string> &rhs) {
    std::vector<std::string> temp = std::move(rhs);
    rhs = (std::move(lhs.m_vec));
    lhs.m_vec = std::move(temp);
  }

  const std::vector<std::string> &getVec() const { return m_vec; }
  void setVec(std::vector<std::string> newVec) { m_vec = std::move(newVec); }
};

class ParseSet : public Parse {
private:
  std::vector<Parse> m_set;

public:
  ParseSet(std::vector<Parse> input_set) : m_set(std::move(input_set)) {}
};

Result specialEqual(const std::vector<Parse> &set) {

  Parse last_intersection = set[0];
  std::vector<std::string> curr_intersection;

  auto cmp = [](auto lhs, auto rhs) { return lhs < rhs; };

  for (std::size_t i = 1; i < set.size(); ++i) {
    std::set_intersection(last_intersection.getVec().begin(),
                          last_intersection.getVec().end(),
                          set[i].getVec().begin(), set[i].getVec().end(),
                          std::back_inserter(curr_intersection));
    last_intersection.swap(last_intersection, curr_intersection);
    curr_intersection.clear();
  }
  std::cout << "results" << std::endl;
  for (int i = 0; i < last_intersection.getVec().size(); i++) {
    std::cout << last_intersection.getVec()[i] << std::endl;
  }
  if (last_intersection.getVec().empty()) {
    for (int j = 0; j < set.size(); j++) {
      if (std::find(set[j].getVec().begin(), set[j].getVec().end(),
                    std::string{"NULL"}) != set[j].getVec().end()) {
        return Result::UNDETERMINED;
      }
    }
    return Result::FALSE;
  } else {
    return Result::TRUE;
  }
}

int main(int argc, char *argv[]) {
  OptionalSet setA = {"A", "B", std::nullopt}; 
  OptionalSet setB = {"A"};
  OptionalSet setC = {"A","C"};
  Parse parser1(setA);
  Parse parser2(setB);
  Parse parser3(setC);

  std::vector<Parse> set1({parser1, parser2, parser3});
  Result result = specialEqual(set1);
  switch (result) {
  case (Result::TRUE):
    std::cout << "TRUE" << std::endl;
    break;
  case (Result::FALSE):
    std::cout << "FALSE" << std::endl;
    break;
  case (Result::UNDETERMINED):
    std::cout << "UNDETERMINED" << std::endl;
  }
  return 1;
};

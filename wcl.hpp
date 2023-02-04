#ifndef WCL_HPP
#define WCL_HPP

#include <string>
#include <vector>
#include <algorithm>

namespace wcl {

namespace wString {

/* Remove specific chars in front of std::string
 * */
std::string rm_front_chars(std::string str, std::string char_set) {
  unsigned int idx = 0;
  for (; idx < str.length(); idx++) {
    if (char_set.find(str[idx]) == std::string::npos) {
      break;
    }
  }
  return std::string(str.begin() + idx, str.end());
}

/* Remove specific chars in back of std::string
 * */
std::string rm_back_chars(std::string str, std::string char_set) {
  std::reverse(str.begin(), str.end());
  std::string result = rm_front_chars(str, char_set);
  std::reverse(result.begin(), result.end());
  return result;
}

/* Remove specific chars in back and front of std::string
 * */
std::string strip(std::string str, std::string strip_char_set) {
  str = rm_back_chars(str, strip_char_set);
  str = rm_front_chars(str, strip_char_set);
  return str;
}

/*
 * Remove back spaces.
 */
std::string rm_back_spaces(std::string str) {
  return rm_back_chars(str, std::string(" "));
}

/* Remove spaces in back and front of std::string
 * */
std::string strip(std::string str) {
  str = rm_back_chars(str, std::string(" "));
  str = rm_front_chars(str, std::string(" "));
  return str;
}

/*
 * Split a string into strings contained by a vector.
 */
std::vector<std::string> split(std::string str, std::string delimiters) {
  std::vector<std::string> result;
  std::string tempString;
  for (char &c:str) {
    if (delimiters.find(c) != std::string::npos) {
      result.push_back(tempString);
      tempString.clear();
    } else {
      tempString += c;
    }
  }
  if (!tempString.empty()) {
    result.push_back(tempString);
  }
  return result;
}

/*
 * Split by space.
 * Split a string into strings contained by vector.
 */
std::vector<std::string> split(std::string str) {
  return split(str, std::string(" "));
}



///* 將 string 全部依空格切開，每個新字串頭尾不會有空格 */
//std::vector<std::string> string_split_by_space(std::string str) {
//  std::vector<std::string> rt;
//  std::string temp;
//  for (int i = 0; (unsigned) i < str.length(); i++) {
//    if (str[i] == ' ') {
//      if ((unsigned) temp.length() > 0) {
//        rt.emplace_back(temp);
//        temp.clear();
//      }
//      continue;
//    }
//    temp += str[i];
//  }
//  if ((unsigned) temp.length() > 0)
//    rt.emplace_back(temp);
//  return rt;
//}
///* 將 c_string 全部依空格切開，每個新字串頭尾不會有空格 */
//std::vector<std::string> cstring_split_by_space(char cstr[]) {
//  std::string str(cstr);
//  return string_split_by_space(str);
//}

// TODO(wcl): rm vector empty string entries


} // namespace string

namespace wVector {

template<typename V>
void printVector(V v) {
  std::cout << "=== printVector(every item is captured by a pair of braces. ===" << std::endl;
  for (unsigned int i = 0; i < v.size(); i++) {
    std::cout << "v[" << i << "] : {" << v[i] << "}" << std::endl;
  }
  return;
}

void rm_empty_elements(std::vector<std::string> v) {
  std::vector<std::string> result;
  for (auto &item: v) {
    if (!item.empty()) {
      result.push_back(item);
    }
  }
  return;
}

}

} // namespace wcl




#endif  // WCL_HPP
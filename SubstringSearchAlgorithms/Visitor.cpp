#include "Visitor.h"
#include <cmath>
#include "MemoryUsage.h"

/*!Implementation Naive algorithm!*/


std::string ComplexityOfTheAlgorithm::visit(Naive *algorithm, const std::string& Text, const std::string& Pattern)
{
    size_t start_ = algorithm->Search(Text,Pattern);
    if (start_ == 0) {

        std::string result = "O(m)";
        return   result;
    }
    else if (start_ == Text.size() - Pattern.size()) {
        std::string result = "O(m(n-m+1))";
        return   result;
    }
    else {
        int count_of_conversions = 0;
        int count_of_comparisons = 0;
        for (size_t i = 0; i <= Text.size() - Pattern.size(); i++) {
            size_t j;
            int pos = 0;
            count_of_conversions++;
            bool isFound = true;
            // For each character with text check the pattern
            for (j = 0; j < Pattern.size(); j++) {
                if (Text[i + j] == Pattern[0] && isFound) {
                    isFound = false;
                    pos = i + j;
                }

                if (Text[i + j] != Pattern[j]) {
                    isFound= true;
                    break;
                }
            }
            count_of_comparisons =count_of_comparisons  + Pattern.size();
            // Line_2 found
            if (j == Pattern.size()) {
                std::string result = "O(nm)";
                return   result;
            }
        }
    }
}


/*!Implementation Rabin Karp algorithm!*/

std::string  ComplexityOfTheAlgorithm::visit(Rabina_Karpa *algorithm, const std::string& Text, const std::string& Pattern)
{
  int h = algorithm->power(algorithm->d, (Pattern.size() - 1)) % algorithm->q, t = 0, t0 = 0;
  int count_of_matches = 0;
  int count_of_comparisons = 0;
    for (size_t i = 0; i < Pattern.size(); i++) {
        t = (algorithm->d * t + Pattern[i]) % algorithm->q;
        t0 = (algorithm->d * t0 + Text[i]) % algorithm->q;
    }
    for (size_t j = 0; j < Text.size() - Pattern.size() + 1; j++) {
        if (t == t0) {
            count_of_matches++;
            bool isFound = true;
            for (size_t k = 0; k < Pattern.size(); k++) {
                if (Pattern[k] != Text[j + k]) { isFound = false; break; }
                else if(Pattern[k] == Text[j + k]){
                    count_of_comparisons++;
                }
            }
            if (isFound) {
                int s = count_of_matches + count_of_comparisons;
                if (s == pow((Text.size() - Pattern.size() + 1), Pattern.size())) {
                    std::string result = "O(nm)";
                    return   result ;
                }
                else  {
                   std::string result = "O(n)";
                   return   result;
                }
            }
        }
        t0 = (algorithm->d * (t0 - Text[j] * h) + Text[j + Pattern.size()]) % algorithm->q;
        if (t0 < 0) t0 += algorithm->q;
    }
}



/*!Implementation KMP algorithm!*/


std::string  ComplexityOfTheAlgorithm::visit(KMP *algorithm, const std::string& Text, const std::string& Pattern)
{
    std::string result = "O(n+m) ";
    return   result;
}

/*!Implementation Horspool algorithm!*/


std::string  ComplexityOfTheAlgorithm::visit(Horspool *algorithm, const std::string& Text, const std::string& Pattern)
{
    size_t start_ = algorithm->Search(Text, Pattern);
    if (start_ == 0) {
        std::string result = "O(m) ";
        return   result;
       
    }
    else if (start_ == Text.size() - Pattern.size()) {
        std::string result = "O(m(n-m+1))";
        return   result;
       
    }
    else {
        int count_of_comparisons = 0;
        std::vector<int> t = algorithm->shift_table(Pattern);
        size_t i = Pattern.size() - 1;
        while (i < Text.size()) {
            bool isFound = true;
            for (size_t k = 0; k < Pattern.size(); k++) {
                if (Pattern[Pattern.size() - 1 - k] != Text[i - k]) {
                    isFound = false;
                    break; 
                }
            }
            count_of_comparisons = count_of_comparisons + Pattern.size();
            if (isFound) {
                std::string result = "O(n+m)";
                return   result;
            }
            i = i + t[Text[i]];
        }
      
    }
}



/*!Implementation Boyer Moor algorithm!*/


std::string  ComplexityOfTheAlgorithm::visit(Boyer_Moor *algorithm, const std::string& Text, const std::string& Pattern)
{
     std::string result;
    if(algorithm->Search(Text,Pattern)== 0){
         result = "O(m) ";

    }
    else{
        result = "O(n+m) ";
    }
    return   result;
}

/*!Implementation Naive algorithm!*/

std::string AmountOfMemoryOfTheAlgorithm::visit(Naive* algorithm, const std::string& Text, const std::string& Pattern) {
    int* a = new int[4];
    algorithm->Search(Text, Pattern);
    return PrintUsage();
}



/*!Implementation Rabin Karp algorithm!*/


std::string AmountOfMemoryOfTheAlgorithm::visit(Rabina_Karpa* algorithm, const std::string& Text, const std::string& Pattern) {
    int* a = new int[8];
    algorithm->Search(Text, Pattern);
    return PrintUsage();
}



/*!Implementation KMP algorithm!*/


std::string AmountOfMemoryOfTheAlgorithm::visit(KMP* algorithm, const std::string& Text, const std::string& Pattern) {
    int* a = new int[7];
    algorithm->Search(Text, Pattern);
    return PrintUsage();
   
}


/*!Implementation Horspool algorithm!*/

std::string AmountOfMemoryOfTheAlgorithm::visit(Horspool* algorithm, const std::string& Text, const std::string& Pattern) {
    int* a = new int[5];
    algorithm->shift_table(Pattern);
    algorithm->Search(Text, Pattern);
    return PrintUsage();
}



/*!Implementation Boyer Moor algorithm!*/

std::string AmountOfMemoryOfTheAlgorithm::visit(Boyer_Moor* algorithm, const std::string& Text, const std::string& Pattern) {

    algorithm->Search(Text, Pattern);
    return PrintUsage();
}


#include "Visitor.h"

/*virtual*/std::string ComplexityOfTheAlgorithm::visit(Naive *p, const std::string& Line_1, const std::string& Line_2)
{
	int start_ = p->Search(Line_1,Line_2);
    if (start_ == 0) {
        std::string c = std::to_string(Line_2.size());
        std::string result = "O(nm) - O(" + c + ")";
        return   result;
    }
    else if (start_ == Line_1.size() - Line_2.size()) {
        std::string result = "O(m(n-m+1))";
        return   result;
    }
    else {
        int n = 0;
        int m = 0;
        for (size_t i = 0; i <= Line_1.size() - Line_2.size(); i++) {
            size_t j;
            int pos = 0;
            n++;
            bool q = true;
            // For each character with text check the pattern
            for (j = 0; j < Line_2.size(); j++) {
                if (Line_1[i + j] == Line_2[0] && q == true) {
                    q = false;
                    pos = i + j;
                }

                if (Line_1[i + j] != Line_2[j]) {
                    q = true;
                    break;
                }
            }
            m = m + Line_2.size();
            // Line_2 found
            if (j == Line_2.size()) {
                std::string c1 = std::to_string(m);
                std::string result = "O(nm) - O(" + c1 + ")";
                return   result;
            }
        }
    }
}


/*virtual*/std::string  ComplexityOfTheAlgorithm::visit(Rabina_Karpa *p, const std::string& Line_1, const std::string& Line_2)
{
    int start_ = p->Search(Line_1, Line_2);
  
        size_t j = 0;
        int pos = 0;
        int pattern_hash = 0;
        int text_hash = 0;
        int h = 1;
        int d = 10;
        bool q = true;
        int m = 0;
        int n = 0;
        for (size_t i = 0; i < Line_2.size() - 1; i++) {
            h = (h * d) % (d + 3);
        }
        // Calculate the hash value for the pattern and text
        for (size_t i = 0; i < Line_2.size(); i++) {
            pattern_hash = (d * pattern_hash + Line_2[i]) % (d + 3);
            text_hash = (d * text_hash + Line_1[i]) % (d + 3);
        }
        // Find a match

        for (size_t i = 0; i <= Line_1.size() - Line_2.size(); i++) {
          
            if (pattern_hash == text_hash) {
                m++;
                for (j = 0; j < Line_2.size(); j++) {
                    if (Line_1[i + j] == Line_2[0] && q == true) {
                        q = false;
                        pos = i + j;
                    }
                    else if (Line_1[i + j] == Line_2[j] ) {
                        n++;
                    }
                    else {
                        q = true;
                        break;
                    }
                }
                if (j == Line_2.size()) {
                    int s = n + m;
                    if (s == pow((Line_1.size() - Line_2.size() + 1), 3)) {
                        std::string s1 = std::to_string(Line_1.size() * Line_2.size());
                        std::string result = "O(nm) O(" + s1 + ")";
                        return   result ;
                    }
                    else  {
                        std::string s = std::to_string(Line_1.size());
                        std::string result = "O(n) O(" + s + ")";
                        return   result;
                    }
                }
            }
        if (i < Line_1.size() - Line_2.size()) {
             text_hash = (d * (text_hash - Line_1[i] * h) + Line_1[i + Line_2.size()]) % (d + 3);
             if (text_hash < 0) {
                   text_hash = (text_hash + (d + 3));
             }
               
        }
    }
}


/*virtual*/std::string  ComplexityOfTheAlgorithm::visit(KMP *p, const std::string& Line_1, const std::string& Line_2)
{
    std::string result = "O(n+m) ";
    return   result;
}


/*virtual*/std::string  ComplexityOfTheAlgorithm::visit(Horspool *p, const std::string& Line_1, const std::string& Line_2)
{
    int start_ = p->Search(Line_1, Line_2);
    if (start_ == 0) {
        std::string result = "O(m) ";
        return   result;
       
    }
    else if (start_ == Line_1.size() - Line_2.size()) {
        std::string result = "O(m(n-m+1))";
        return   result;
       
    }
    else {
        int m = 0;
        std::vector<int> t = p->shift_table(Line_2);
        int i = Line_2.size() - 1;
        while (i < Line_1.size()) {
            bool q = true;
            for (int k = 0; k < Line_2.size(); k++) {
                if (Line_2[Line_2.size() - 1 - k] != Line_1[i - k]) {
                    q = false; 
                    break; 
                }
            }
            m = m + Line_2.size();
            if (q) {
                std::string c1 = std::to_string(m);
                std::string result = "O(n+m) - O(" + c1 + ")";
                return   result;
            }
            i = i + t[Line_1[i]];
        }
      
    }
}
/*virtual*/std::string  ComplexityOfTheAlgorithm::visit(Boyer_Moor *p, const std::string& Line_1, const std::string& Line_2)
{
    std::string result = "O(n+m) - O( )";
    return   result;
}
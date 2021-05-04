#include "Visitor.h"
#include <cmath>
#include "MemoryUsage.h"

/*!Implementation Naive algorithm!*/
/*!
\code


std::string ComplexityOfTheAlgorithm::visit(Naive *p, const std::string& Line_1, const std::string& Line_2)
{
    int start_ = p->Search(Line_1,Line_2);
    if (start_ == 0) {
        std::string c = std::to_string(Line_2.size());
        std::string result = "O(m) - O(" + c + ")";
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
\endcode
*/


std::string ComplexityOfTheAlgorithm::visit(Naive *p, const std::string& Line_1, const std::string& Line_2)
{
	int start_ = p->Search(Line_1,Line_2);
    if (start_ == 0) {

        std::string result = "O(m)";
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
                std::string result = "O(nm)";
                return   result;
            }
        }
    }
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation Rabin Karp algorithm!*/
/*!
\code


std::string  ComplexityOfTheAlgorithm::visit(Rabina_Karpa *p, const std::string& Line_1, const std::string& Line_2)
{
  int h = p->power(p->d, (Line_2.size() - 1)) % p->q, t = 0, t0 = 0;
    int m = 0;
    int n = 0;
    for (int i = 0; i < Line_2.size(); i++) {
        t = (p->d * t + Line_2[i]) % p->q;
        t0 = (p->d * t0 + Line_1[i]) % p->q;
    }
    for (int j = 0; j < Line_1.size() - Line_2.size() + 1; j++) {
        if (t == t0) {
            m++;
            bool w = true;
            for (int k = 0; k < Line_2.size(); k++) {
                if (Line_2[k] != Line_1[j + k]) { w = false; break; }
                else if(Line_2[k] == Line_1[j + k]){
                    n++;
                }
            }
            if (w) {
                int s = n + m;
                if (s == pow((Line_1.size() - Line_2.size() + 1), Line_2.size())) {
                    std::string s1 = std::to_string(Line_1.size() * Line_2.size());
                    std::string result = "O(nm) O(" + s1 + ")";
                    return   result ;
                }
                else  {
                   std::string s = std::to_string(Line_1.size());
                   std::string result = "O(n) O(" + s + ")";
                   return   result;
                }
            };
        }
        t0 = (p->d * (t0 - Line_1[j] * h) + Line_1[j + Line_2.size()]) % p->q;
        if (t0 < 0) t0 += p->q;
    }
}

\endcode
*/

std::string  ComplexityOfTheAlgorithm::visit(Rabina_Karpa *p, const std::string& Line_1, const std::string& Line_2)
{
  int h = p->power(p->d, (Line_2.size() - 1)) % p->q, t = 0, t0 = 0;
    int m = 0;
    int n = 0;
    for (int i = 0; i < Line_2.size(); i++) {
        t = (p->d * t + Line_2[i]) % p->q;
        t0 = (p->d * t0 + Line_1[i]) % p->q;
    }
    for (int j = 0; j < Line_1.size() - Line_2.size() + 1; j++) {
        if (t == t0) {
            m++;
            bool w = true;
            for (int k = 0; k < Line_2.size(); k++) {
                if (Line_2[k] != Line_1[j + k]) { w = false; break; }
                else if(Line_2[k] == Line_1[j + k]){
                    n++;
                }
            }
            if (w) {
                int s = n + m;
                if (s == pow((Line_1.size() - Line_2.size() + 1), Line_2.size())) {
                    std::string s1 = std::to_string(Line_1.size() * Line_2.size());
                    std::string result = "O(nm)";
                    return   result ;
                }
                else  {
                   std::string s = std::to_string(Line_1.size());
                   std::string result = "O(n)";
                   return   result;
                }
            };
        }
        t0 = (p->d * (t0 - Line_1[j] * h) + Line_1[j + Line_2.size()]) % p->q;
        if (t0 < 0) t0 += p->q;
    }
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation KMP algorithm!*/
/*!
\code


std::string  ComplexityOfTheAlgorithm::visit(KMP *p, const std::string& Line_1, const std::string& Line_2)
{
    std::string result = "O(n+m) ";
    return   result;
}


\endcode
*/

std::string  ComplexityOfTheAlgorithm::visit(KMP *p, const std::string& Line_1, const std::string& Line_2)
{
    std::string result = "O(n+m) ";
    return   result;
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation Horspool algorithm!*/
/*!
\code


std::string  ComplexityOfTheAlgorithm::visit(Horspool *p, const std::string& Line_1, const std::string& Line_2)
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

\endcode
*/

std::string  ComplexityOfTheAlgorithm::visit(Horspool *p, const std::string& Line_1, const std::string& Line_2)
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
                std::string result = "O(n+m)";
                return   result;
            }
            i = i + t[Line_1[i]];
        }
      
    }
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation Boyer Moor algorithm!*/
/*!
\code


std::string  ComplexityOfTheAlgorithm::visit(Boyer_Moor *p, const std::string& Line_1, const std::string& Line_2)
{
     std::string result;
    if(p->Search(Line_1,Line_2)== 0){
         result = "O(m) ";

    }
    else{
        result = "O(n+m) ";
    }
    return   result;
}

\endcode
*/

std::string  ComplexityOfTheAlgorithm::visit(Boyer_Moor *p, const std::string& Line_1, const std::string& Line_2)
{
     std::string result;
    if(p->Search(Line_1,Line_2)== 0){
         result = "O(m) ";

    }
    else{
        result = "O(n+m) ";
    }
    return   result;
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation Naive algorithm!*/
/*!
\code


std::string AmountOfMemoryOfTheAlgorithm::visit(Naive* p, const std::string& Line_1, const std::string& Line_2) {
    int* a = new int[4];
    p->Search(Line_1, Line_2);
    return PrintUsage();
}

\endcode
*/
std::string AmountOfMemoryOfTheAlgorithm::visit(Naive* p, const std::string& Line_1, const std::string& Line_2) {
    int* a = new int[4];
    p->Search(Line_1, Line_2);
    return PrintUsage();
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation Rabin Karp algorithm!*/
/*!
\code


std::string AmountOfMemoryOfTheAlgorithm::visit(Rabina_Karpa* p, const std::string& Line_1, const std::string& Line_2) {
    int* a = new int[8];
    p->Search(Line_1, Line_2);
    return PrintUsage();
}

\endcode
*/

std::string AmountOfMemoryOfTheAlgorithm::visit(Rabina_Karpa* p, const std::string& Line_1, const std::string& Line_2) {
    int* a = new int[8];
    p->Search(Line_1, Line_2);
    return PrintUsage();
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation KMP algorithm!*/
/*!
\code


std::string AmountOfMemoryOfTheAlgorithm::visit(KMP* p, const std::string& Line_1, const std::string& Line_2) {
    int* a = new int[7];
    p->Search(Line_1, Line_2);
    return PrintUsage();

}

\endcode
*/
std::string AmountOfMemoryOfTheAlgorithm::visit(KMP* p, const std::string& Line_1, const std::string& Line_2) {
    int* a = new int[7];
    p->Search(Line_1, Line_2);
    return PrintUsage();
   
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation Horspool algorithm!*/
/*!
\code


std::string AmountOfMemoryOfTheAlgorithm::visit(KMP* p, const std::string& Line_1, const std::string& Line_2) {
    int* a = new int[7];
    p->Search(Line_1, Line_2);
    return PrintUsage();

}

\endcode
*/
std::string AmountOfMemoryOfTheAlgorithm::visit(Horspool* p, const std::string& Line_1, const std::string& Line_2) {
    int* a = new int[5];
    p->shift_table(Line_2);
    p->Search(Line_1, Line_2);
    return PrintUsage();
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation Boyer Moor algorithm!*/
/*!
\code


std::string AmountOfMemoryOfTheAlgorithm::visit(Boyer_Moor* p, const std::string& Line_1, const std::string& Line_2) {

    p->Search(Line_1, Line_2);
    return PrintUsage();
}


\endcode
*/
std::string AmountOfMemoryOfTheAlgorithm::visit(Boyer_Moor* p, const std::string& Line_1, const std::string& Line_2) {

    p->Search(Line_1, Line_2);
    return PrintUsage();
}

/*!
\param[in] p input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

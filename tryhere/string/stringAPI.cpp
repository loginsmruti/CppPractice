#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    //constructor
        //9 types
        //empty
        //fill
        //range
        //copy
        //move
        //list_initialization
        //from (const char*)
        //from (const char*, num of item)
        //from substring (const string& str, size_t pos, size_t len = npos)
        //(num of item, char)

    //destructor

    //Iterator
        //begin
        //cbegin
        //rbegin
        //crbegin
        //end
        //cend
        //rend
        //crend

    //Element Access
        //at
        //operator
        //front
        //back
        //data

    //capacity
        //empty
        //size
        //length
        //max_size
        //resize
        //capacity
        //reserve
        //shrink_to_fit

    //Modifiers
        //create
        //insert
            /**
             * string (1)	string& insert (size_t pos, const string& str);
             *  substring (2)	string& insert (size_t pos, const string& str, size_t subpos, size_t sublen = npos);
             *  c-string (3)	string& insert (size_t pos, const char* s);
             *  buffer (4)	string& insert (size_t pos, const char* s, size_t n);
             *  fill (5)	string& insert (size_t pos,   size_t n, char c);iterator insert (const_iterator p, size_t n, char c);
             *  single character (6)	iterator insert (const_iterator p, char c);
             *  range (7)	template <class InputIterator>iterator insert (iterator p, InputIterator first, InputIterator last);
             *  initializer list (8)	string& insert (const_iterator p, initializer_list<char> il);
             * 
             */
        //swap
        //erase
        //push_back
        //pop_back
        //apend     -> same as constructor except empty/move api
            /**
             * string (1)	string& append (const string& str);
             * substring (2)	string& append (const string& str, size_t subpos, size_t sublen = npos);
             * c-string (3)	string& append (const char* s);
             * buffer (4)	string& append (const char* s, size_t n);
             * fill (5)	string& append (size_t n, char c);
             * range (6)	template <class InputIterator>   string& append (InputIterator first, InputIterator last);
             * initializer list(7)	string& append (initializer_list<char> il);
             * 
             */
        //assign    -> same as constructor except empty api
            /**
             *   string (1)	string& assign (const string& str);
             *   substring (2)	string& assign (const string& str, size_t subpos, size_t sublen = npos);
             *   c-string (3)	string& assign (const char* s);
             *   buffer (4)	string& assign (const char* s, size_t n);
             *   fill (5)	string& assign (size_t n, char c);
             *   range (6)	template <class InputIterator>   string& assign (InputIterator first, InputIterator last);
             *   initializer list(7)	string& assign (initializer_list<char> il);
             *   move (8)	string& assign (string&& str) noexcept;
             * 
             */

    //operation
        //compare {pos ofcurrent str, len of curr str, other string}
        //replace {pos ofcurrent str, len of curr str, other string}
        //substr
            //string substr (size_t pos = 0, size_t len = npos) const;

    //Lookup
        //string::find // 
        //string::rfind
        //string::find_first_not_of
        //string::find_first_of
        //string::find_last_not_of
        //string::find_last_of

    //Observers

    //allocator

    return 0;
}

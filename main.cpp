#include <algorithm> // sort
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility> // pair, make_pair

typedef std::map<std::string, int>::const_iterator map_iter;


bool compare (std::pair<std::string, int> x, std::pair<std::string, int> y){
    return x.second < y.second;
}

int main()
{
    std::string s;
    std::map<std::string, int> counters; // store each word and an associated counter

    // read the input, keeping track of each word and how often we see it
    while (std::cin >> s)
        ++counters[s];

    std::vector< std::pair<std::string, int> > pairs;

    // dump map into a vector<pair<string, int>>
    for (map_iter it = counters.begin(); it != counters.end(); ++it){
        pairs.push_back( std::make_pair(it->first, it->second) );
    }

    // sort the vector by the second element using a predicate function
    std::sort(pairs.begin(), pairs.end(), compare);

    // write the words and associated count, by increasing number of counts
    for (std::vector< std::pair<std::string, int> >::const_iterator it = pairs.begin();
         it != pairs.end(); ++it){
        std::cout << it->first << "\t" << it->second << std::endl;
    }

    return 0;
}

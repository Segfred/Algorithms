//
//  main.cpp
//  buildmap
//
//  Created by Asmita on 2017/01/17.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "topological_sort.hpp"
//typedef std::string artifact; ///< A target, dependency, or both
template<typename artifact>
class dependency_graph
{
public:
    typedef std::unordered_map<artifact, std::unordered_set<artifact>> graph_type;
    void store_dependency(artifact const& target, artifact const& dependency)
    {
        graph_[target].insert(dependency);
        graph_[dependency]; // ensures that target is in the graph
    }
    graph_type const& graph() const { return graph_; }
    void buildmap();
    template<class OutIter>
    void sort(OutIter sorted)
    const
    {
        topological_sort(graph_, sorted);
    }
private:
    graph_type graph_;
};

template<typename artifact>
void dependency_graph<artifact>::buildmap()
{
    std::string line;
    while (std::getline(std::cin, line))
        
    {
        std::string target, dependency;
        //Input target first and then dependency
        std::istringstream stream(line);
        if (stream >> target >> dependency)
            store_dependency(target, dependency);
        else if (not target.empty())
            // Input line has a target with no dependency,
            // so report an error.
            std::cerr << "malformed input: target, " << target <<
            ", must be followed by a dependency name\n";
        // else ignore blank lines
    }

}
int main() {
    dependency_graph<std::string> graph;
    graph.buildmap();
        try {
        // Get the artifacts and print them out
        std::vector<std::string> sorted;
        graph.sort(std::back_inserter(sorted));
        std::copy(sorted.begin(), sorted.end(),
                  std::ostream_iterator<std::string>(std::cout, "\n"));
    } catch (std::runtime_error const& ex) {
        std::cerr << ex.what() << '\n';
        return EXIT_FAILURE;
    }
}

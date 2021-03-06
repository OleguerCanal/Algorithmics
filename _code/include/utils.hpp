#pragma once

#include <array>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdlib.h>
#include <string>
#include <vector>

#include "graph.hpp"
#include "single_link_list.hpp"

namespace utils
{

  // HELPERS ---------------------------------------------------

  template<typename T>
  std::vector<T> get_random_vector(size_t size, int seed, int max=100)
  {
    srandom(seed);
    std::vector<T> vect(size);
    if (typeid(T) == typeid(int))  // Case we wanna generate ints
      for (size_t i = 0; i < size; i++)
        vect[i] = static_cast<int>(rand())%max;

    if (typeid(T) == typeid(float))  // Case we wanna generate floats
      for (size_t i = 0; i < size; i++)
        vect[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return vect;
  }

  // TIMING ----------------------------------------------------
  // Start timer
  time_t tic()
  {
    return clock();
  }

  // Stop counting time and print timer
  void toc(time_t t, std::string print)
  {
    t = clock() - t;
    std::cout << "-->[TIME]: " << print << ": " << ((float)t) / CLOCKS_PER_SEC << '\n';
  }

  // PRINTING -------------------------------------------------
  // Prints object
  template <typename T = int>
  void print(std::vector<T> vec, std::string msg = "")
  {
    if (msg != "")
      std::cout << msg << ": ";
    for (size_t i = 0; i < vec.size(); i++)
      std::cout << vec[i] << " ";
    std::cout << std::endl;
  }

  void print(const custom_ds::Slist<int> &list)
  {
    custom_ds::s_list_node<int> *node = list.GetHead();
    while (node != nullptr)
    {
      std::cout << node->val << ", ";
      node = node->next;
    }
    std::cout << std::endl;
  }

  void print(custom_ds::s_list_node<int> *node)
  {
    while (node != nullptr)
    {
      std::cout << node->val << ", ";
      node = node->next;
    }
    std::cout << std::endl;
  }

  void print(graph::Graph graph)
  {
    std::queue<graph::Node *> nodes_to_visit; // Push nodes to list
    nodes_to_visit.push(graph.root);

    while (!nodes_to_visit.empty())
    {
      graph::Node *node = nodes_to_visit.front();
      nodes_to_visit.pop();
      std::cout << node->val << ", ";

      std::unordered_set<graph::Node *>::iterator it;
      for (it = node->childs.begin(); it != node->childs.end(); it++)
        nodes_to_visit.push(*it);
    }
    std::cout << std::endl;
  }
} // namespace utils

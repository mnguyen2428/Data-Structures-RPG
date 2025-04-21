#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    GameDecisionTree() : root(nullptr) {}

    // Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {
        std::ifstream file(filename);
        std::unordered_map<int, Node<T>*> map;

        if(file.is_open()) {
            std::string line;
            while(std::getline(file, line)) {
                std::stringstream ss(line);
                int eventNumber;
                int leftNum;
                int rightNum;
                std::string description;

                ss >> eventNumber >> delimiter;
                std::getline(ss, description, delimiter);
                ss >> leftNum >> delimiter >> rightNum;

                Story story(description, eventNumber, leftNum, rightNum);
                Node<T>* newNode = new Node<T>(story);
                if (eventNumber == 1) {
                    root = newNode;
                }
                map[eventNumber] = newNode;
            }

            for (const auto& pair : map) {
                Node<T>* node = pair.second;

                if (node->data.leftEventNumber != -1) {
                    node->left = map[node->data.leftEventNumber];
                }
                if (node->data.rightEventNumber != -1) {
                    node->right = map[node->data.rightEventNumber];
                }
            }
        }
        else {
            std::cout << "NOT OPEN" << endl;
        }
    }

    // Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* currentNode = root;

        while (currentNode) {
            std::cout << currentNode->data.description << std::endl;

            if (currentNode->data.leftEventNumber == -1 && currentNode->data.rightEventNumber == -1) {
                break;
            }

            int choice;
            Node<T>* leftNode = currentNode->left;
            Node<T>* rightNode = currentNode->right;

            std::cout<< "1:";
            std::cout << leftNode->data.description << std::endl;

            if(currentNode->data.rightEventNumber != -1) {
                std::cout<< "2:";
                std::cout << rightNode->data.description << std::endl;
            }

            std::cout << "Choice: ";
            std::cin >> choice;

            if (choice == 1) {
                currentNode = leftNode;
            } else if (choice == 2) {
                currentNode = rightNode;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H

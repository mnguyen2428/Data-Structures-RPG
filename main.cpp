#include <iostream>
#include <string>
#include "GameDecisionTree.h"

using namespace std;

int main() {
    GameDecisionTree<Story> myGame;

    string filename = "story.txt";
    char delimiter = '|';

    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);

    // Start the game
    myGame.playGame();

    return 0;
}
# Introduction

**This repository contains a programming assignment from a SDSU CS210 Data Structures class.**

## Overview
- This programming assignment uses a decision tree represented as a binary tree to drive the storyline.

## Class Descriptions
1. **Node Class Template**
  - This class has the pointers to its left child and right child
  - T is the story class
2. **Story Class**
  - This class contains:
    - `string description`: The text representing what happens at this point in the game.
    - `int eventNumber`: A unique identifier for each event.
    - `int leftEventNumber`: The event number of the next event if the player chooses the left path.
    - `int rightEventNumber`: The event number of the next event if the player chooses the right path.
3. **GameDecisionTree Class Template**
  - This class has methods for:
    - Loading the story data from a file and creating the tree.
    - Traversing the decision tree based on player input.
4. **Binary Tree Structure**
  - This class uses a binary decision tree structure to represent game events. Each node has two outcomes.
  - Implemented one exection where multiple events may lead to the same event.
5. **Text-Based RPG with External File Input**
  - The game story must be loaded from a text file. Each line contains the event description, event number, left and right child event number, separated by a delimiter.
6. **Main Function**
  - This class calls the load file function to load the story into the decision tree and the play game function.

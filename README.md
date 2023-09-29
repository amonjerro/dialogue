# Dialogue Tree System

This is a system that implements a very basic dialogue tree. It works as follows.

The tree is composed of several dialogue nodes. Nodes currently have two types: Information Nodes and Decision Nodes.
  - *Information Nodes*: Show information to the user and immediately advance to their next left child. Will ignore any right children unless in the current implementation.
  - *Decision Nodes*: Await a response from the user. If the response is Y or y, the dialogue proceeds down the left path. Otherwise, dialogue proceeds down the right path.
This means this tree is currently a binary tree. However, extending the number of children and the implementation of nodes can allow for more complex linking and interactions within the tree.

Nodes are created from an external `.tsv` file. The columns of that file are as follows:
  1. What type of node this entry is. 1 corresponds to Information Nodes and 2 to Decision Nodes
  2. The text for that node
  3. The path that must be followed to add this node to the tree. L means taking navigating down the left path and R means navigating down the right path.

So in a tree that looks like this

          A
        /   \
      B       C
     /       /
    D       E

A is the root so it gets no path in its 3rd column. B is a left child so it is L and C is the right child of the root, so it is R. D is the left child of the left child so it is LL, while E is the left child of the right child so it is RL.

# AVLTree
This program was a homework assignment for a data structures class. The following are the instructions given by the professor for the assignment.

Populate a tree via a text file (input.txt) Make sure that after every insert, the tree is balanced. At the end, display the tree in level format. Make sure to include the height and the balance factor of every node in your output. Redirect the display to  an output file (output.txt).

## Testing
The contents of the input file `input.txt` are random numbers: 
```
1 13 2 20 15 4 37 78 56
```

After runnning the program, the output file `output.txt` should mirror the following:
```
Item: 13, Height: 4, Balance: -1, Level :1
Item: 2, Height: 2, Balance: 0, Level :2
Item: 20, Height: 3, Balance: -1, Level :2
Item: 1, Height: 1, Balance: 0, Level :3
Item: 4, Height: 1, Balance: 0, Level :3
Item: 15, Height: 1, Balance: 0, Level :3
Item: 56, Height: 2, Balance: 0, Level :3
Item: 37, Height: 1, Balance: 0, Level :4
Item: 78, Height: 1, Balance: 0, Level :4
```
## Requirements

C++.

Tested with C++ 11 on Mac OS X 10.14.

Doesn't require any external packages, so it should be platform-agnostic.

# Hash Table

A hash table is a data structure that maps a key to a value in such a way that retriving a value from a key is an O(1) operation. 

This is achieved by (somehow) storing the values in an array and having a hash function that takes a key and returns the index where its respective value shall be stored.

## Hash function

A function that takes a key and returns an index of the array.


However, since `number of possible keys >> array positions` often times more than one key is mapped to a single position, this phenomenon is what's called a collision.

The best case scenario is having a hash function that evenly distributes keys across the possible array indexes in order to minimize collisions.


## Collision 
A collision between two keys happens when both keys are mapped to the same array index. There are several ways of handling collisions:

### 1. Closed adressing

The hash table is stored as an array of linked lists of key value pairs so that upon a collision, the key value pair being inserted is simply prepended to the list in the corresponding array index
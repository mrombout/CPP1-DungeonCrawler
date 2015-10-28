#ifndef DUNGEONCRAWLER_DISJOINTNODE_H
#define DUNGEONCRAWLER_DISJOINTNODE_H

template<class T>
struct DisjointNode {
public:
    DisjointNode(T value) :
        parent(this),
        rank(0),
        value(value) {

    }

    DisjointNode *find() {
        if(parent != this)
            parent = parent->find();
        return parent;
    }

    void unionMerge(DisjointNode *y) {
        DisjointNode *xRoot = find();
        DisjointNode *yRoot = y->find();
        if (xRoot == yRoot)
            return;

        if (xRoot->rank < yRoot->rank) {
            xRoot->parent = yRoot;
        } else if (xRoot->rank > yRoot->rank) {
            yRoot->parent = xRoot;
        } else {
            yRoot->parent = xRoot;
            xRoot->rank = xRoot->rank + 1;
        }
    }

    DisjointNode *parent;
    int rank;
    T value;
};

#endif //DUNGEONCRAWLER_DISJOINTNODE_H

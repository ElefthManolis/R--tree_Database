#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;

#include "Rectangle.cpp"

#ifndef NODE_CPP
#define NODE_CPP

class Node{
    public:
        int capacity;
        int parentId;
        int blockId;
        bool isLeaf;
        pair<int, Rectangle> rectangles[50];
        Rectangle boundingBox;
        Node(){
            capacity = 0;
        }
        Node(Rectangle bounding, bool isLeafNode, vector<pair<int, Rectangle>> rec, int aParentId, int aBlockId){
            isLeaf = isLeafNode;

            setRectangles(rec);

            boundingBox = bounding;
            parentId = aParentId;
            blockId = aBlockId;

            capacity = 0;
        }

        void setRectangles(vector<pair<int, Rectangle>> &rec) {
            for(int i = 0; i < rec.size(); i++) {
                rectangles[i] = rec[i];
            }
        }

        vector<pair<int, Rectangle>> getRectangles() {
            vector<pair<int, Rectangle>> out(50);

            for(int i = 0; i < 50; i++) {
                out[i] = rectangles[i];
            }

            return out;
        }

        void updateBounds(Rectangle aBoundingBox) {
            boundingBox = aBoundingBox;
        }

        void addChild(int blockID, Rectangle rec){
            cout<<"addChild"<<endl;
            cout<<capacity<<endl;
            rectangles[capacity] = { blockID, rec };
            capacity++;
            cout<<"addChild"<<endl;
            

        }

        void modifiedNode(){
            cout<<"Modified"<<endl;
            ofstream myfile;
            myfile.open ("indexfile.dat", ios::out | ios::binary);

            int blockStart = (blockId - 1) * sizeof(Node);
            myfile.seekp(blockStart, ios::beg);
            myfile.write((char *) this, sizeof(Node));
            myfile.close();
        }
        void updateBoundingBox(Rectangle rec){
            updateBounds(boundingBox);
            modifiedNode();
        }

};
#endif
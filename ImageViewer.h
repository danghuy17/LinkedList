#ifndef _IMAGEVIEWER_H_
#define _IMAGEVIEWER_H_

#define MAX_CHAR_NAME 32
#define MAX_CHAR_RESOLUTION 12
#define PLACE_PHOTO 52

// Struct use save date
struct Date {
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 11;
};

struct ImageViewer {
	char name[MAX_CHAR_NAME];
	char resolution[MAX_CHAR_RESOLUTION];
	char place[PLACE_PHOTO];
	struct Date date;
};

struct ImageViewerNode {
	struct ImageViewer iv;
	unsigned int view;
	struct ImageViewerNode* next;
	struct ImageViewerNode* pre;
};

// Double node 
struct doubleNode {
	struct ImageViewerNode* head;
	struct ImageViewerNode* tail;
};

typedef struct Date Date;
typedef struct ImageViewer ImageViewer;
typedef struct ImageViewerNode ImageViewerNode;
typedef struct doubleNode doubleNode;

// Create Date
Date createDate(unsigned int day, unsigned int month, unsigned int year);

// Create node
ImageViewer create(char* name, char* resolution, char* place, Date date);
ImageViewerNode* createNode(ImageViewer iv);

int rise(int view);

// Insert
doubleNode* insertNode(doubleNode* node, ImageViewerNode* new_node);

// Delete a node
ImageViewerNode* findDel(doubleNode* node, char* name, char* resolution, char* place);
doubleNode* delNode(doubleNode* node, ImageViewerNode* del_node);


// Review all node
void reviewNode(doubleNode* node);

// Search
ImageViewerNode* cpyNode(ImageViewerNode* u);
// Name
doubleNode* nameSearch(doubleNode* node, char* name);

// Resolution
doubleNode* resolutionSearch(doubleNode* node, char* resolution);

// Place
doubleNode* placeSearch(doubleNode* node, char* place);

// Time
doubleNode* yearSearch(doubleNode* node, unsigned int year);


// Show node
void printNode(ImageViewerNode* node);

// Find max view
ImageViewerNode* maxView(doubleNode* node);

// Delete all data
doubleNode* clear(doubleNode* node);

#endif
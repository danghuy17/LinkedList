#include "ImageViewer.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>


// Create Date
Date createDate(unsigned int day, unsigned int month, unsigned int year) {
	Date date;
	date.day = day;
	date.month = month;
	date.year = year;
	return date;
}

// Create Image Viewer
ImageViewer create(char* name, char* resolution, char* place, Date date) {
	ImageViewer new_iv;
	strcpy_s(new_iv.name, name);
	strcpy_s(new_iv.resolution, resolution);
	strcpy_s(new_iv.place, place);
	new_iv.date = date;
	return new_iv;
}

// Create a Image Viewer Node
ImageViewerNode* createNode(ImageViewer iv) {
	ImageViewerNode* new_node = (ImageViewerNode*)malloc(sizeof(ImageViewerNode));
	new_node->iv = iv;
	new_node->view = 0;
	new_node->next = new_node->pre = NULL;
	return new_node;
}

// Rise view
int rise(int view) {
	return view + 1;
}

// Insert node
doubleNode* insertNode(doubleNode* node, ImageViewerNode* new_node) {
	if (node == NULL) {
		node = (doubleNode*)malloc(sizeof(doubleNode));
		node->head = node->tail = new_node;
	}
	else {
		if (node->head == node->tail) {
			node->tail = new_node;
			node->head->next = node->tail;
			node->tail->pre = node->head;
		}
		else {
			node->tail->next = new_node;
			new_node->pre = node->tail;
			node->tail = new_node;
		}
	}
	return node;
}

// Delete node
ImageViewerNode* findDel(doubleNode* node, char* name, char* resolution, char* place) {
	ImageViewerNode* re = NULL;
	ImageViewerNode* u = node->head;
	while (u) {
		if (strcmp(name, u->iv.name) == 0) {
			if (strcmp(resolution, u->iv.resolution) == 0) {
				if (strcmp(place, u->iv.place) == 0) {
					re = u;
				}
			}
		}
		u = u->next;
	}
	return re;
}

doubleNode* delNode(doubleNode* node, ImageViewerNode* del_node) {
	if (node == NULL) {
		printf("\nDont delete. Linked List is NULL");
	}
	else {
		if (node->tail == node->head) {
			node->head = node->tail = NULL;
		}
		else if (del_node == node->head) {
			node->head = node->head->next;
			node->head->pre = NULL;
		}
		else if (del_node == node->tail) {
			node->tail = del_node->pre;
			node->tail->next = NULL;
		}
		else {
			del_node->next->pre = del_node->pre;
			del_node->pre->next = del_node->next;
		}
		free(del_node);
		printf("\nComplete delete node\n");
	}
	return node;
}

// Review all node
void reviewNode(doubleNode* node) {
	if (node == NULL) {
		printf("\nReview: Linked List is NULL");
	}
	else {
		ImageViewerNode* u = node->head;
		printf("\n|%32s|%12s|%52s|%12s|%10s|", "NAME", "RESOLUTION", "PLACE", "DATE", "VIEW");
		while (u) {
			printNode(u);
			u = u->next;
		}
	}
	printf("\n_________________THE END_________________");
}

// Search
ImageViewerNode* cpyNode(ImageViewerNode* u) {
	ImageViewerNode* new_u = (ImageViewerNode*)malloc(sizeof(ImageViewerNode));
	new_u->iv = u->iv;
	new_u->view = u->view;
	new_u->next = new_u->pre = NULL;
	return new_u;
}

// Name Search
doubleNode* nameSearch(doubleNode* node, char* name) {
	doubleNode* re = NULL;
	if (node == NULL) {
		printf("\nName Search: Linked List is NULL");
	}
	else {
		ImageViewerNode* u = node->head;
		while (u) {
			if (strcmp(name, u->iv.name) == 0) {
				ImageViewerNode* cpy_u = cpyNode(u);
				re = insertNode(re, cpy_u);
			}
			u = u->next;
		}
	}
	return re;
}

// Resolution
doubleNode* resolutionSearch(doubleNode* node, char* resolution) {
	doubleNode* re = NULL;
	if (node == NULL) {
		printf("\nResolution Search: Linked List is NULL");
	}
	else {
		ImageViewerNode* u = node->head;
		while (u) {
			if (strcmp(resolution, u->iv.resolution) == 0) {
				ImageViewerNode* cpy_u = cpyNode(u);
				re = insertNode(re, cpy_u);
			}
			u = u->next;
		}
	}
	return re;
}

// Place
doubleNode* placeSearch(doubleNode* node, char* place) {
	doubleNode* re = NULL;
	if (node == NULL) {
		printf("\nResolution Search: Linked List is NULL");
	}
	else {
		ImageViewerNode* u = node->head;
		while (u) {
			if (strcmp(place, u->iv.place) == 0) {
				ImageViewerNode* cpy_u = cpyNode(u);
				re = insertNode(re, cpy_u);
			}
			u = u->next;
		}
	}
	return re;
}

doubleNode* yearSearch(doubleNode* node, unsigned int year) {
	doubleNode* re = NULL;
	if (node == NULL) {
		printf("\nTime Search: Linked List is NULL");
	}
	else {
		ImageViewerNode* u = node->head;
		while (u) {
			if (year == u->iv.date.year) {
				ImageViewerNode* cpy_u = cpyNode(u);
				re = insertNode(re, cpy_u);
				u->view = cpy_u->view;
			}
			u = u->next;
		}
	}
	return re;
}

// Show node
void printNode(ImageViewerNode* node) {
	node->view = rise(node->view);
	ImageViewer iv = node->iv;
	Date date = iv.date;
	unsigned int year = date.year;
	char c_date[11];
	c_date[0] = date.day / 10 + '0';
	c_date[1] = date.day % 10 + '0';
	c_date[2] = '/';
	c_date[3] = date.month / 10 + '0';
	c_date[4] = date.month % 10 + '0';
	c_date[5] = '/';
	c_date[6] = year / 1000 + '0'; year %= 1000;
	c_date[7] = year / 100 + '0'; year %= 100;
	c_date[8] = year / 10 + '0'; year %= 10;
	c_date[9] = year + '0';
	c_date[10] = '\0';
	printf("\n|%32s|%12s|%52s|%12s|%10d|", iv.name, iv.resolution, iv.place, c_date, node->view);
}

ImageViewerNode* maxView(doubleNode* node) {
	ImageViewerNode* u = node->head;
	ImageViewerNode* max_node = NULL;
	unsigned int max = 0;
	while (u) {
		if (u->view > max) {
			max_node = u;
			max = u->view;
		}
		u = u->next;
	}
	return max_node;
}

doubleNode* clear(doubleNode* node) {
	if (node != NULL) {
		ImageViewerNode* u = node->head;
		while (u) {
			ImageViewerNode* tmp = u;
			u = u->next;
			free(tmp);
		}
	}
	return node;
}

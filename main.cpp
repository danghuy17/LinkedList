#include "header.h"


int main() {
	int choose = 1;
	doubleNode* node = NULL;
	while (choose != 0) {
		choose = menu();
		switch (choose) {
		case 1: {
			node = _1(node);
			break;
		}
		case 2: {
			node = _2(node);
			break;
		}
		case 31: {
			_31(node);
			break;
		}
		case 32: {
			_32(node);
			break;
		}
		case 4: {
			_4(node);
			break;
		}
		case 5: {
			_5(node);
			break;
		}
		case 6: {
			_6(node);
			break;
		}
		case 7: {
			_7(node);
			break;
		}
		case 0: {
			printf("\nDang thoat chuong trinh");
			break;
		}
		default: {
			printf("\nNhap sai gia tri");
		}
		}
	}
	clear(node);
	printf("\nKet thuc");
}

int menu() {
	char del_enter[2];
	int choose = 0;
	printf("\n_________________MENU_________________");
	printf("\n1. Chen Image Viewer Node");
	printf("\n2. Xoa Image Viewer Node");
	printf("\n3. Tim kiem");
	printf("\n4. Hien thi tat ca cac node");
	printf("\n5. Tim anh co view nhieu nhat");
	printf("\n6. Tim anh chup tai 1 noi");
	printf("\n7. Hien thi anh chup theo nam");
	printf("\n0. Thoat");
	printf("\nEnter: ");
	scanf_s("%d", &choose);
	if (choose == 3) {
		printf("\n3.1. Tim kiem theo ten");
		printf("\n3.2. Tim kiem theo do phan giai");
		printf("\n3.1. Quay lai");
		printf("\nEnter: ");
		scanf_s("%d", &choose);
		if (choose == 1) {
			choose = 31;
		}
		else if (choose == 2) {
			choose = 32;
		}
		else if (choose == 0) {
			choose = 30;
		}
	}
	fgets(del_enter, 2, stdin);
	return choose;
}

doubleNode* _1(doubleNode* node) {
	node = insertNode(node, createNode(_1_create()));
	return node;
}

char* delEnter(char* c) {
	int n = strlen(c);
	if (n != 0) {
		if (c[n - 1] == '\n') {
			c[n - 1] = '\0';
		}
	}
	return c;
}

ImageViewer _1_create() {
	ImageViewer new_iv;
	char name[MAX_CHAR_NAME];
	char resolution[MAX_CHAR_RESOLUTION];
	char place[PLACE_PHOTO];
	char del_enter[2];
	Date date;
	unsigned int day = 0, month = 0, year = 0;

	fflush(stdin);
	printf("Enter name: "); fgets(name, MAX_CHAR_NAME, stdin); delEnter(name);
	printf("Enter resolution: "); fgets(resolution, MAX_CHAR_RESOLUTION, stdin); delEnter(resolution);
	printf("Enter place: "); fgets(place, PLACE_PHOTO, stdin); delEnter(place);

	printf("Enter day: "); scanf_s("%d", &day);
	printf("Enter month: "); scanf_s("%d", &month);
	printf("Enter year: "); scanf_s("%d", &year);

	date = createDate(day, month, year);
	new_iv = create(name, resolution, place, date);
	return new_iv;
}

// 2
doubleNode* _2(doubleNode* node) {
	printf("\nDelete node");
	char name[MAX_CHAR_NAME];
	char resolution[MAX_CHAR_RESOLUTION];
	char place[PLACE_PHOTO];
	printf("Enter delete name: "); 
	fgets(name, MAX_CHAR_NAME, stdin); delEnter(name);
	printf("Enter delete resolution: ");
	fgets(resolution, MAX_CHAR_RESOLUTION, stdin); delEnter(resolution);
	printf("Enter delete place: "); 
	fgets(place, PLACE_PHOTO, stdin); delEnter(place);

	node = delNode(node, findDel(node, name, resolution, place));
	
	return node;
}

void _31(doubleNode* node) {
	char name[MAX_CHAR_NAME];
	fflush(stdin);
	printf("Enter name search: "); fgets(name, MAX_CHAR_NAME, stdin); delEnter(name);
	doubleNode* ns = nameSearch(node, name);
	reviewNode(ns);
	clear(ns);
}

void _32(doubleNode* node) {
	char resolution[MAX_CHAR_RESOLUTION];
	fflush(stdin);
	printf("Enter resolution search: "); fgets(resolution, MAX_CHAR_RESOLUTION, stdin); delEnter(resolution);
	doubleNode* rs = resolutionSearch(node, resolution);
	reviewNode(rs);
	clear(rs);
}

// 4
void _4(doubleNode* node) {
	reviewNode(node);
}

// 5
void _5(doubleNode* node) {
	printf("\nMAX VIEW");
	printf("\n|%32s|%12s|%52s|%12s|%10s|", "NAME", "RESOLUTION", "PLACE", "DATE", "VIEW");
	printNode(maxView(node));
}

// 6
void _6(doubleNode* node) {
	char place[PLACE_PHOTO];
	fflush(stdin);
	printf("Enter place search: "); fgets(place, MAX_CHAR_RESOLUTION, stdin); delEnter(place);
	doubleNode* rs = placeSearch(node, place);
	reviewNode(rs);
	clear(rs);
}

// 7
void _7(doubleNode* node) {
	unsigned int year = 0;
	fflush(stdin);
	printf("Enter year search: "); scanf_s("%d", &year);
	doubleNode* ys = yearSearch(node, year);
	reviewNode(ys);
	clear(ys);
}
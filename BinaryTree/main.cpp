#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct NODE{
	int data;
	NODE* pLeft;
	NODE* pRight;
};

NODE* CreateNode(int x){
	NODE* p = new NODE();
	p->data = x;
	p->pLeft = p->pRight = NULL;
	return p;
}

NODE* FindInsert(NODE* root, int x){
	if(root == NULL){
		return NULL;
	}
	
	NODE* p = root;
	NODE* f = p;
	
	while(p != NULL){
		f = p;
		
		if(p->data > x){
			p=p->pLeft;
		}else{
			p=p->pRight;
		}
	}
	
	return f;
}

void InsertNode(NODE* &root, int x){
	NODE* n = CreateNode(x);
	
	if(root == NULL){
		root = n;
		return;
	}else{
		NODE* f = FindInsert(root, x);
		
		if(f != NULL){
			if(f->data > x){
				f->pLeft = n;
			}else{
				f->pRight = n;
			}
			
		}
	}
}

void CreateTree(NODE* &root, int a[], int n){
	for(int i = 0; i < n; i++){
		InsertNode(root, a[i]);
	}
}

NODE* SearchNode_Re(NODE* root, int x){
	if(root == NULL){
		return NULL;
	}
	
	if(root->data == x){
		return root;
	}
	
	if(root->data > x){
		SearchNode_Re(root->pLeft, x);
	}else{
		SearchNode_Re(root->pRight, x);
	}
}

NODE* SearchNode(NODE* root, int x){
	if(root == NULL){
		return NULL;
	}
	
	NODE* p = root;
	
	while(p != NULL){
		if(p->data == x){
			return p;
		}
		else if(p->data > x){
			p = p->pLeft;
		}else{
			p = p->pRight;
		}
	}
}

void NLR(NODE* root){
	if(root != NULL){
		printf("%d \t", root->data);
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}

void LNR(NODE* root){
	if(root != NULL){
		LNR(root->pLeft);
		printf("%d \t", root->data);
		LNR(root->pRight);
	}
}

void LRN(NODE* root){
	if(root != NULL){
		LRN(root->pLeft);
		LRN(root->pRight);
		printf("%d \t", root->data);
	}
}

int main(int argc, char** argv) {
	printf("\nStart");
	NODE* root = NULL;
	int a[] = {40, 5, 35, 45, 15, 56, 48, 13, 16, 49, 47};
	int n = 11;
	CreateTree(root, a, n);
	//NLR(root);
	//LNR(root;
	LRN(root);
	
	printf("\nComplete");
	
	return 0;
}

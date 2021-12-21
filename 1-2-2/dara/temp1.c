#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode{
	int weight;
	char ch;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct{
	TreeNode* ptree;
	char ch;
	int key;
} element;

typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

//»ý¼º ÇÔ¼ö
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
 } 
 
 //ÃÊ±âÈ­
 void init(HeapType* h)
 {
 	h->heap_size=0;
  } 
  
  //heap sizeÀÇ È÷ÇÁ h ¿¡ ¾ÆÀÌÅÛ »ðÀÔ
 void insert_min_heap(HeapType* h, element item)
 {
 	int i;
 	i = ++(h->heap_size);
 	
 	//Æ®¸®¸¦ °Å½½·¯ ¿À¸£¸ç ºÎ¸ð ³ëµå¿Í ºñ±³
	 while((i!=1) && (item.key < h->heap[i/2].key))
	 {
	 	h->heap[i] = h->heap[i/2];
	 	i /= 2;
	  } 
	  h->heap[i] = item;
 }
 
 //»èÁ¦ ÇÔ¼ö
 element delete_min_heap(HeapType* h)
 {
 	int parent, child;
 	element item, temp;
 	
 	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent=1;
	child=2;
	while(child<=h->heap_size){
		//ÇöÀç ³ëµå¿Í ÀÚ½Ä³ëµåÁß ´õ ÀÛÀº ÀÚ½Ä³ëµå¸¦ Ã£´Â´Ù
		if((child <= h->heap_size) &&
		(h->heap[child].key) > h->heap[child+1].key)
		child++;
		if(temp.key < h->heap[child].key) break;
		//ÇÑ ´Ü°è ¾Æ·¡·Î ÀÌµ¿
		h->heap[parent] = h->heap[child];
		parent=child;
		child *= 2; 
	}
	h->heap[parent]=temp;
	return item;	
  } 
  
  //ÀÌÁø Æ®¸® »ý¼º ÇÔ¼ö
  TreeNode* make_tree(TreeNode* left, TreeNode* right)
  {
  	TreeNode* node =
  	(TreeNode*)malloc(sizeof(TreeNode));
  	node->left=left;
  	node->right=right;
  	return node;
   } 
   
   //ÀÌÁøÆ®¸® Á¦°Å ÇÔ¼ö
   void destroy_tree(TreeNode* root)
   {
   	if(root==NULL) return;
   	destroy_tree(root->left);
   	destroy_tree(root->right);
   	free(root);
	} 
	
	int is_leaf(TreeNode* root)
	{
		return !(root->left) && !(root->right);
	}
	void print_array(int codes[], int n)
	{
		for(int i=0; i< n; i++)
		printf("%d", codes[i]);
		printf("\n");
	}
	
	void print_codes(TreeNode* root, int codes[], int top)
	{
		// 1À» ÀúÀåÇÏ°í ¼øÈ¯È£ÃâÇÑ´Ù.
		if(root->left)
		{
			codes[top] =1;
			print_codes(root->left, codes, top+1);
		 } 
		// 0À» ÀúÀåÇÏ°í ¼øÈ¯È£ÃâÇÏ´Ù.
		if(root->right){
			codes[top] = 0;
			print_codes(root->right, codes, top+1);
		} 
		
		//´Ü¸»ÄÚµå¶ó¸é ÄÚµå Ãâ·Â
		if(is_leaf(root)){
			printf("%c: ", root->ch);
			print_array(codes, top);
		} 
	}
	
	//ÇãÇÁ¸¸ ÄÚµå »ý¼º ÇÔ¼ö
	void huffman_tree(int freq[], char ch_list[], int n)
	{
		int i;
		TreeNode *node, *x;
		HeapType* heap;
		element e, e1, e2;
		int codes[100];
		int top=0;
		
		heap = create();
		init(heap);
		for(i=0; i<n; i++){
			node = make_tree(NULL, NULL);
			e.ch = node->ch = ch_list[i];
			e.key = node->weight = freq[i];
			e.ptree = node;
			insert_min_heap(heap, e);
		}
		for(i=1; i<n; i++){
			//ÃÖ¼Ò°ªÀÇ µÎ°³ ³ëµå »èÁ¦
			e1 = delete_min_heap(heap);
			e2 = delete_min_heap(heap);
			//µÎ°³ÀÇ ³ëµå ÇÕÄ§
			x = make_tree(e1.ptree, e2.ptree);
			e.key = x->weight = e1.key + e2.key;
			e.ptree = x;
			printf("%d+%d->%d \n", e1.key, e2.key, e.key);
			insert_min_heap(heap, e); 
		}
		e = delete_min_heap(heap);
		print_codes(e.ptree, codes, top);
		destroy_tree(e.ptree);
		free(heap);
	 } 
	 
	 int main(void)
	 {
	 	char ch_list[] = {'s', 'i', 'n', 't', 'e'};
	 	int freq[] = {4, 6, 8, 12, 15};
	 	huffman_tree(freq, ch_list, 5);
	 	return 0;
	 }

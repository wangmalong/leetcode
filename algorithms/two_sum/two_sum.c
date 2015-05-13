#include <stdio.h>
#include <stdlib.h>

#define EMPTY 2147483647

typedef struct HashNode{
    int key;
    int value;
    struct HashNode* next; //相同hash取下一个节点
} HashNode;


typedef struct Hashtable{
    int size;
    int item_size;
    HashNode* head;
} Hashtable;


/*初始化*/
Hashtable* hashtable_init(int size);

/*添加一个*/
void hashtable_put(Hashtable *hashtable, int key, int value);

/*获取一个*/
int hashtable_get(Hashtable *hashtable, int key);

/*删除一个*/
void hashtable_remove(Hashtable *hashtable, int key);

/*销毁*/
void hashtable_destroy(Hashtable *hashtable);

/*打印*/
void hashtable_print(Hashtable *hashtable);

/*hash算法*/
int hash(int key, int size);

/*hash算法*/
int hash(int key, int size){
    return key>=0?key%size:-key%size;
}

/*初始化hashtable*/
Hashtable* hashtable_init(int size){
    Hashtable* hashtable = (Hashtable*)calloc(1, sizeof(Hashtable));
    hashtable->size = size;
    hashtable->item_size = 0;
    HashNode* head = (HashNode *)calloc(size, sizeof(HashNode));
	for(int i=0; i<size; i++)
	{
		head[i].key = EMPTY;
	}
    hashtable->head = head;
    return hashtable;
}

/*添加一个*/
void hashtable_put(Hashtable *hashtable, int key, int value){
    int index = hash(key, hashtable->size);

    HashNode *hashNode = hashtable->head + index;

    while (1)
    {
        if (hashNode->key == EMPTY || key == (hashNode->key))
        {
            if (hashNode->key == EMPTY)
            {
                hashtable->item_size = hashtable->item_size + 1;
            }
            hashNode->key = key;
            hashNode->value = value;
            return;
        }
        if (hashNode->next != NULL){
            hashNode = hashNode->next;
        }
        else{
            HashNode *newNode = (HashNode*)calloc(1, sizeof(HashNode));
            newNode->key = key;
            newNode->value = value;
            hashNode->next = newNode;
            hashtable->item_size = hashtable->item_size + 1;
            return;
        }
    }
}

/*获取一个*/
int hashtable_get(Hashtable *hashtable, int key){
    int index = hash(key, hashtable->size);
    HashNode *hashNode = hashtable->head + index;
    while (hashNode != NULL)
    {
        if (hashNode->key != EMPTY && key == (hashNode->key))
        {
            return hashNode->value;
        }
        hashNode = hashNode->next;
    }
    return EMPTY;
}

/*删除一个*/
void hashtable_remove(Hashtable *hashtable, int key){
    int index = hash(key, hashtable->size);
    HashNode *hashNode = hashtable->head + index;
    HashNode *temp = hashNode;
    while (hashNode != NULL)
    {
        if (key == (hashNode->key))
        {
            if ((hashtable->head + index) == hashNode)
            {
                hashNode->key = EMPTY;
                hashNode->value = 0;
            }
            else
            {
                temp->next = hashNode->next;
                free(hashNode);
            }
            hashtable->item_size = hashtable->item_size - 1;
            return;
        }
        temp = hashNode;
        hashNode = hashNode->next;
    }
    return;
}


/*销毁*/
void hashtable_destroy(Hashtable *hashtable){
    HashNode *head = hashtable->head;
    for (int index = 0; index < hashtable->size; index++)
    {
        HashNode *next = head->next;
        while (next != NULL)
        {
            HashNode *temp = next;
            next = next->next;
            free(temp);
        }
        head++;
    }
    free(hashtable->head);
    free(hashtable);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
	int i=0;
	Hashtable *h_table = hashtable_init(numsSize);
	int* ret = (int*)malloc(sizeof(int)*2);
	for(i=0; i<numsSize; i++)
	{
		if(hashtable_get(h_table,nums[i])==EMPTY)
		{
			hashtable_put(h_table, target-nums[i], i);
		}
		else
		{
			ret[0] = hashtable_get(h_table, nums[i])+1;
			ret[1] = i+1;
		}
	}
	hashtable_destroy(h_table);
    return ret;
}

int main()
{
	int s[]={1,3,6,34,21,42,4,56,7,234,54,6};
	int* ret = twoSum(s, 12, 60);
    printf("s[%d](%d) + s[%d](%d) = %d  ",ret[0]-1, s[ret[0]-1], ret[1]-1, s[ret[1]-1], s[ret[0]-1]+s[ret[1]-1]);
	return 0;
}

# WEEK1
本周学习主要分为以下部分
* vim 
* 链表
* git in Ubuntu & Windows
* 基于Python对OOP的了解

---

## vim的使用
* Basic movement
> |command|action|
> |:------------|:-----------:|
> |h| left|
> |j |down |
> |k| up|
> |l |right|
* Basic Edit
> |command|action|
> |--------------|:------------:|
> |i|insert in the current location|
> |o|open a New line **AFTER** the current line and go to  ** INSERT mode**|
> |O|open a New line **BEFORE** the current line and go to  ** INSERT mode**|
> |a|append, go the the end of the current **word** and go to **INSERT mode** |
> |A|append, go the the end of the current **LINE** and go to **INSERT mode** |
> |Esc|back to visual mode|
* Edit faster
> |command|action|
> |--------------|:------------:|
> |x|delete the letter right at the cursor|
> |dd|delete a line|
> |dw|delete a word|
> |w|go to next word|
> |W|go to next WORD|
> |e|go to the end of word|
> |E|go to the end of WORD|
> |b|back to the begin of word|
> |B|back to the begin of WORD|
> |G|go to the end of the file|
> |gg|go to the begin of the file|
> |(number)G|go to specified line of the file|
> |u|Undo|
> |CTRL-R|Redo|
> |$|go to the **end** of current line |
> |^|go the the **begin** of the line |
* Basic command
> |command|action|
> |--------------|:------------:|
> |:q|quit Vim|
> |:q!|quit vim without changes|
> |:w|write (save)|
> |:H / :help|help|
> |:set number|show lines number|
~~(一个不小心写成全英了orz)~~

## 链表(linked list)
### 分类
* single list
* double list
* circular list
### 操作
|operation|method|
|:---:|:--:|
|create|动态分配内存 生成单/双链表|
|destroy|利用一个辅助指针和free()函数摧毁链表|
|delete|主要思想为改指针指向然后free掉要删除的node，我的实现方法为将后一个node的值赋给要删除位置 然后再free掉后一个node（非最后一个节点），若是最后一个node，则找到前一个指针将其->next = NULL然后free掉最后一个node|
|insert|先查找index是否在链表中有意义，有意义则修改指针修改链表即可**caution**必须使用double pointer以便修改头指针地址并返回|
|edit & edit|主要注意index是否在链表中有意义|
|sort|bubble（拒绝）quicksort, mergesort|
(详见下面代码)
```C 
//根据数组生成一条链表，成功则返回头节点，失败返回 NULL 
ptr_Node create(int *arr, int n)
{
	if (arr == NULL)
		return NULL;
	ptr_Node resource, tmp;
	tmp = (ptr_Node)malloc(sizeof(Node));
	resource = tmp;
	resource->data = arr[0];
	resource->next = NULL;
	for (int i = 1; i < n; i++, tmp->next = NULL) {
		tmp -> next = (ptr_Node)malloc(sizeof(Node));
		tmp = tmp->next;
		tmp->data = arr[i];
	}
	return resource;
}
//销毁给定的链表 
void destroy(ptr_Node head)
{
	ptr_Node tmp = head;
	if (head == NULL)
		return;
	for (; tmp != NULL; head = tmp) {
		tmp = tmp->next;
		free(head);
    }
}

//在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
Status insert(ptr_Node *head, ptr_Node node, int index)
{
	int count;
	ptr_Node p = *head;

	if (index == 0) {
		node->next = p;
		*head = node;
		return SUCCESS;
	}

	//find if the index matches in the list
	for (count = 1; count != index && p != NULL; count++, p = p->next);
	if (count != index)
		return ERROR;
	
	node->next = p->next;
	p->next = node;
	return SUCCESS;
}

//删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
//删除成功返回 SUCCESS，其他情况返回 ERROR 
Status delete(ptr_Node *head, int index, int *data)
{
	int count;
	ptr_Node temp, p=*head;

	//find if the index matches in the list
	for (count =1 ; count != index && p != NULL; count++, p = p->next);
	if (count != index) 
		return ERROR;

	temp = p->next;
	*data = p->data;

	//将后一个node的值赋给要删除位置 然后再free掉后一个node
	if (temp != NULL) {
		p->next = temp->next;
		p->data = temp->data;
		free(temp);
	}
	else {
		for (temp = *head; temp->next != p; temp = temp->next);
		temp->next = NULL;
		free(p);
	}
	return SUCCESS;
}
int search(ptr_Node head, int data)
{
	ptr_Node tmp = head;
	for (int i = 1; tmp != NULL; tmp = tmp->next, i++) {
		if (tmp->data == data)
			return i;
	}
	return -1;
}


//将链表中 index 位点后面的结点的值修改为(*data)，将原值保存到(*data) 
//修改成功返回 SUCCESS，其他情况返回 ERROR 
Status edit(ptr_Node head, int index, int *data)
{
	int count;
	ptr_Node p = head; int tmp;

	//find if the index matches in the list
	for (count = 1; count != index && p != NULL; count++, p = p->next);
	if (count != index)
		return ERROR;

    tmp = *data;
	*data = p->data;
    p->data = tmp;
	return SUCCESS;

}

```
#### sort
有一点值得总结的是我在排序的时候运用了MergeSort（归并排序）
主要思想就是将链表从中间切开，利用递归对其进行排序

```c
Status sort(ptr_Node *head)
{
	void MS(ptr_Node* headRef);
	if (*head == NULL)
		return ERROR;
	MS(head);
	return SUCCESS;
}


void FrontBackSplit(ptr_Node source, ptr_Node* frontRef, ptr_Node* backRef)
{
	ptr_Node fast;
	ptr_Node slow;
	if (source == NULL || source->next == NULL)
	{
		/* length < 2 cases */
		*frontRef = source;
		*backRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;

		/*Advance 'fast' two nodes, and advance 'slow' one node.
		Thus the slow would point the middle of the linked list ultimately*/
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

void MS(ptr_Node* headRef) {
	void FrontBackSplit(ptr_Node source, ptr_Node* frontRef, ptr_Node* backRef);
	ptr_Node SortedMergeTurnover(ptr_Node a, ptr_Node b);
	ptr_Node head = *headRef;
	ptr_Node a;
	ptr_Node b;

	// Base case -- length 0 or 1 
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}

	// Split head into 'a' and 'b' sublists 
	FrontBackSplit(head, &a, &b);

	// Recursively sort the sublists 
	MS(&a);
	MS(&b);

	// answer = merge the two sorted lists together 
	*headRef = SortedMergeTurnover(a, b);
}


ptr_Node SortedMergeTurnover(ptr_Node a, ptr_Node b) {
	ptr_Node result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data)
	{
		result = a;
		result->next = SortedMergeTurnover(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMergeTurnover(a, b->next);
	}
	return(result);
}
```

###遇到的问题
在处理链表时犯下了一个非常非常粗心的错误
```Warning message in c
Program received signal SIGSEGV, Segmentation fault.
0x0000000000400c99 in main () at single.c:240
240		ptr->data = 6;
```
solution: ptr_Node new_node = (ptr_Node)malloc(sizeof(Node));
问题就是忘记给一个新建的指针分配空间了orz



## git在Ubuntu和Windows上的使用
### in Ubuntu

### in Windows
> Whereas similar to Ubuntu, lots of stuff need to be installed in the pre-step 

## 基于python对oop（oriented-object programming）的初步了解

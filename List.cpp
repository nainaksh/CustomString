#include<iostream>
#include<list>
#include<unordered_set>

using namespace std;

class MyList
{
public:

	int data;
	MyList* next;

	MyList(int mdata) :data(mdata)
	{
		next = nullptr;
	}

	~MyList()
	{

	}
};

	void Push(MyList** head, int data)
	{
		MyList* temp = new MyList(data);
		temp->next = (*head);
		(*head) = temp;
	}

	void Insert(MyList** prevNode, int data)
	{
		MyList* temp = new MyList(data);
		temp->next = (*prevNode)->next;
		(*prevNode)->next = temp;
	}

	void InsertAt(MyList** head, int data, int pos)
	{
		while (pos--)
		{
			if(pos == 0)
			{
				MyList* temp = new MyList(data);
				temp->next = (*head);
				(*head) = temp;
			}
			else
			{
				(head) = &(*head)->next;
			}
		}
	}

	void PopBegin(MyList **head)
	{
		MyList* temp = (*head);
		(*head) = (*head)->next;
		delete temp;
		temp = nullptr;
	}

	void PopEnd(MyList *head)
	{
		if (head->next == nullptr)
		{
			delete head;
		}

		while (head->next->next != nullptr)
		{
			head = head->next;
		
		}
		delete head->next;
		head->next = nullptr;
	}

	void ReverseList(MyList** head)
	{
		MyList* curr = (*head);
		MyList* next = nullptr;
		MyList* prev = nullptr;

		while (curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		(*head) = prev;
	}

	/*
	 4 5 3 2
	 curr = 4

	next = curr->next = 5
	curr->next = prev = 0
	prev = curr =  4
	curr = next = 5

	next = 3
	curr->next = 4
	prev = 5
	curr = 3

	next = 2
	curr->next = 5
	prev = 3
	curr = 2

	next = 0
	curr->next = 3
	prev = 2
	curr = 0

	*/

	MyList* ReverseListRecursive(MyList* head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		MyList * rest = ReverseListRecursive(head->next);
		head->next->next = head;
		head->next = nullptr;
		return rest;
	}

	void PrintReverseListRecursive(MyList* head)
	{
		if (head == nullptr )
		{
			return;
		}

		PrintReverseListRecursive(head->next);

		cout << head->data << "->";
	}

	/*
	2 3 5 4

	head = 2
	rest = 2

	head = 3
	rest = 3

	head = 5
	rest = 5

	head = 4 
	rest = 4
	next = 0

	4 5 3 2 
	*/

	void PrintList(MyList* head)
	{
		MyList* temp = head;
		do
		{
			cout << temp->data << "->";
			temp = temp->next;
			if(temp == nullptr)
			{
				break;
			}
		} while (temp != head);

		cout << endl;
	}

	bool DetectLoop(MyList* head)
	{
		MyList* fast = head;
		MyList* slow = head;

		while (fast && slow && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}

	bool CheckIntersect(MyList*p1, MyList* p2)
	{
		unordered_set<MyList*> s1;
		while (p1)
		{
			s1.insert(p1);
			p1 = p1->next;
		}

		while (p2)
		{
			if (s1.find(p2) != s1.end())
			{
				return true;
			}
			p2 = p2->next;
		}
		return false;
	}

	bool CheckIntersect2(MyList*p1, MyList*p2)
	{
		while (p1->next)
		{
			p1 = p1->next;
		}

		while (p2->next)
		{
			p2 = p2->next;
		}

		if (p1 == p2)
		{
			return true;
		}
		return false;
	}

	MyList* FindIntersect(MyList* p1, MyList* p2)
	{
		MyList* head1 = p1;
		MyList* head2 = p2;

		while (p1 && p2 && p1!=p2)
		{
			p1 = p1->next;
			p2 = p2->next;
			if (p1 == p2)
			{
				return p1;
			}
			if (p1 == nullptr)
			{
				p1 = head2;
			}
			if (p2 == nullptr)
			{
				p2 = head1;
			}
		}
		return p1;
	}

	void DeleteAt(MyList** head, int pos)
	{
		while (pos--)
		{
			if (pos == 0)
			{
				MyList* temp = (*head);
				(*head) = temp->next;
				delete temp;
				temp = nullptr;
			}
			else
				(head) = &(*head)->next;
		}
	}

	bool isPalindrome(MyList** left, MyList* right)
	{
		if (right == nullptr)
		{
			return true;
		}

		bool pal = isPalindrome(left, right->next);
		if (!pal)
		{
			return false;
		}

		bool pal1 = ((*left)->data == right->data);
		
		(*left) = (*left)->next;

		return pal1;
	}

int main1()
{
	MyList *m1 = nullptr;
	Push(&m1, 1);
	Push(&m1, 3);
	Insert(&m1, 2);
	Push(&m1, 4);
	Push(&m1, 5);

	PrintList(m1);

	m1->next->next->next->next->next = m1;

	PrintList(m1);

	if (DetectLoop(m1))
	{
		cout << "Loop found!!" << endl;
	}
	else
	{
		cout << "Loop not found!!" << endl;
	}

	//PopBegin(&m1);
	//PrintList(m1);

	//PopEnd(m1);
	//PrintList(m1);

	//InsertAt(&m1, 5, 2);
	//PrintList(m1);

	//ReverseList(&m1);
	//PrintList(m1);

	//MyList * r1 = ReverseListRecursive(m1);
	//PrintList(r1);

	/*PrintReverseListRecursive(m1);
	cout << endl;
	PrintList(m1);*/

	MyList* n1 = new MyList(1);
	n1->next = new MyList(2);
	n1->next->next = new MyList(3);
	n1->next->next->next = new MyList(4);
	n1->next->next->next->next = new MyList(5);
	n1->next->next->next->next->next = new MyList(6);
	n1->next->next->next->next->next->next = new MyList(7);
	// list 2
	MyList* n2 = new MyList(10);
	n2->next = new MyList(9);
	n2->next->next = new MyList(8);
	n2->next->next->next = n1->next->next->next;
	PrintList(n1);
	PrintList(n2);

	if (CheckIntersect2(n1, n2))
	{
		MyList* intersectNode = FindIntersect(n1, n2);
		cout << "Intersecting at :" << intersectNode->data;
	}
	else
	{
		cout << "Not Intersecting!!";
	}
	cout << endl;
	DeleteAt(&n1, 3);
	PrintList(n1);

	MyList* p1 = new MyList(1);
	p1->next = new MyList(2);
	p1->next->next = new MyList(3);
	p1->next->next->next = new MyList(4);
	p1->next->next->next->next = new MyList(1);

	PrintList(p1);
	if (isPalindrome(&p1, p1))
	{
		cout << "Palindrome!!!" << endl;
	}
	else
	{
		cout << "Not Palindrome!!!" << endl;
	}

	int n;
	cin >> n;
	std::cin.get();

	return 0;
}
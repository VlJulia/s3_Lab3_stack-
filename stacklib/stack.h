#include <iostream>
#include <cmath>

//define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
using namespace std;
template <class T>
class TStack
{
protected:
    int size;
    int top;
    T* mas;
public:
    TStack(int n = 1) {
        if (n <= 0) throw "negative size";
        this->size = n;
        this->mas = new T[n]();
        this->top = 0;
    }
    TStack(TStack<T>& stack) {
        if (stack.mas == nullptr) return;
        this->mas = new T[stack.size];
        this->size = stack.size;
        memcpy(this->mas,stack.mas,size*sizeof(T));
        if (this->size == 0) return;
        this->top = stack.top;
    }
    ~TStack() {
        delete[] mas;
        mas = nullptr;
    };

void Push(T a);
T Get();
T TopView();
int GetSize() { return size; };
int GetTop() { return top; };
bool IsFull() { return (this->top == this->size);};
bool IsEmpty() { return (this->top < 1); };
T Pop() { return Get(); };


//friend istream& operator>> (istream& istr, TStack<T> &obj);

TStack<T>& operator=(const TStack<T>& stack);

bool operator!=(const TStack<T>& stack) const {
    if (this->size != stack.size) return true;
    if (this->top != stack.top) return true;
    for (int i = 0; i < top; i++) {
        if (this->mas[i] != stack.mas[i]) return true;
    }
    return false;
};
bool operator==(const TStack<T>& stack) const  {
    if (this->size != stack.size) return false;
    if (this->top != stack.top) return false;
    for (int i = 0; i < top; i++) {
        if (this->mas[i] != stack.mas[i]) return false;
    }
    return true;
};

friend ostream& operator<< (ostream& ostr, TStack<T>& obj) {

    ostr << "size is ";
    ostr << obj.size << endl;
    ostr << "[" << endl;
    for (int i = 0; i < obj.size; i++) {
        ostr << obj.mas[i] << endl;
    }
    ostr << "]\n" << endl;
	if (!(obj.IsEmpty())) {
		T a = obj.TopView();
		ostr << "top is " << a;
	}
	else ostr << "is Empty";
    return ostr;

}
};

template <class T>
T TStack<T>::TopView() {
	if (IsEmpty()) throw "is Empty";
	return mas[top - 1];
}



//template <class T>
//istream& operator>> (istream& istr, TStack<T>& obj) {
//    int n;
//    istr >> n;
//    top = n;
//    for (int i = n-1; i>=0; i--) {
//        istr >> obj.mas[i];
//    }
//    return istr;
//}

template <class T>
void TStack<T>::Push(T a) {
    if (IsFull()) {
        throw "is full";
    }
    this->mas[top] = a;
    this->top++;
}

template <class T>
T TStack<T>::Get() {
    if (IsEmpty()) {
		std::cout << __FUNCTION__;
		throw ("is empty");
		return 1;
    }
	T a = this->mas[top-1];
	this->mas[top-1] = 0;
	this->top = top - 1;
	
    return a;
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& stack) {
    if (stack.mas == nullptr) return;
    if(this->size != stack.size) this->mas = new T[stack.size];
    this->size = stack.size;
    memcpy(this->mas, stack.mas, size * sizeof(T));
    if (this->size == 0) return;
    this->top = stack.top;
};


template <class T>
class TQueue {
protected:
    int size;
    int start;
    int end;
    int count;
    T* mas;

public:
    TQueue(int n = 0) {
        this->sise = n;
        this->start = 0;
        this->end = 0;
        this->count = 0;
        this->mas = new T[n];
    };
    TQueue(TQueue <T>& q) {
        this->sise = q.sise;
        this->start = q.start;
        this->end = q.end;
        this->count = q.count;
        this->mas = new T[q.size];
        memcpy(this->mas, stack.mas, size * sizeof(T));
    };
    ~TQueue() {
        delete[] this->mas;
        this->mas = nullptr;
    };

    void Push(T a);
    T Get();

    bool IsFull();
    bool IsEmpty();

    //операторы вводы и выводы

    friend ostream& operator<< (ostream& ostr, const TQueue& obj);
    friend istream& operator >> (istream& istr, TQueue& obj);
};

template<class T>
void TQueue<T>::Push(T a) {
    if (IsFull()) throw "if full";
    this->mas[end] = a;
    end=(end+1)%(size+1);
    count++;
};
template<class T>
T TQueue<T>::Get() {
    if (count == 0) throw "if empty";
    end--;
    if (end < 0) end += n;
    return this->mas[end];
}



template<class T>
bool TQueue<T>::IsFull() {
    return ((count > 0) && (end == begin)) ;
}
template<class T>
bool TQueue<T>::IsEmpty() {
    return (count == 0);
}

template<class T>
ostream& operator<< (ostream& ostr, const TQueue<T>& obj) {
    ostr << "size is " << obj.size << endl;
    ostr << "begin is " << obj.begin << endl;
    ostr << "end is " << obj.end << endl;
    ostr << "count " << obj.count << endl;
    for (int i = obj.begin; i < obj.count; i++) {
        ostr << obj.mas[i % (obj.size + 1)] << endl;
    }
    return ostr;

};
template<class T>
istream& operator >> (istream& istr, TQueue<T>& obj) {
    int n;
    istr >> n;
    obj.count = n - 1;
    for (int i = 0; i < obj.count; i++) {
        istr>> obj.mas[i % (obj.size + 1)] ;
    }
    return istr;
};



using namespace std;

class TCalculator
{
protected:
	string infix;
	string postfix;
	TStack<double> st;
	TStack<char> stc;
public:
	TCalculator() :st(20), stc(20)
	{
		infix = "";
		postfix = "";
	}
	string GetExpression() { return infix; }
	void SetExpression(string ex) { infix = ex; }
	string GetPostfix() { return postfix; }
	int Priority(char c);
	void ToPostfix();
	double CalcPostfix();
	double Calc();
};

int TCalculator::Priority(char c) {
	switch (c)
	{
	case ')':
	case '(': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
	default: throw "unknow elem " + c;
	}
}

void TCalculator::ToPostfix() {
	int i = 0;
	char c;
	bool flag = true;
	while (i < infix.size())
	{
		c = infix[i];
		std::cout << stc << endl << postfix << endl;

		if ((c == ' ')) { i++; continue; }
		if ((c >= '0') && (c <= '9')) 
		{
			size_t inx=0;
			double tmp = stod(&infix[i], &inx);
			//std::cout <<"\nSTOD inx "<< inx << endl;
			postfix += to_string(tmp)+" ";
			i += inx;
			continue;
		}

		if ((c == '+') || (c == '-') || (c == '/') || (c == '*')||(c=='(')) {
			flag = false;
			if (c == '(') {
				stc.Push(c); 
				i++;
				continue;
			}
			if (stc.IsEmpty()) { stc.Push(c); i++; continue; }
			char tmp = stc.TopView();
			if (Priority(tmp) < Priority(c)) { stc.Push(c);}
			else {
				while ((Priority(tmp) >= Priority(c))&&(!stc.IsEmpty())) {
					std::cout << stc << endl << postfix << endl;
					postfix += stc.Pop();
					//std::cout << "\n"<<postfix<<endl;
					postfix += " ";
					if (stc.IsEmpty()) { break; }
				}
				stc.Push(c);
			}
			i++;
			continue;
		}
		if (c == ')') {
			flag = false;
			char tmp = stc.Pop();
			while (tmp != '(')
			{
				postfix += tmp;
				tmp = stc.Pop();
			}
		}
		i++;
		if (flag) throw "unknow elem " + c;
	}
	

	while (!(stc.IsEmpty())) { postfix += stc.Pop(); }
	
};

double TCalculator::CalcPostfix() {
	int i = 0;
	char c;
	while (i < postfix.size())
	{
		c = postfix[i];
		if (c == ' ') { i++; continue; }

		if ((c >= '0') && (c <= '9')) {
			size_t inx;
			double tmp = stod(&postfix[i], &inx);
			st.Push(tmp);

			i += inx;
			continue;
		}

		double op2 = st.Pop();
		double op1 = st.Pop();
		switch (c)
		{
		case'+': { st.Push(op1 + op2);  break; }
		case'-': { st.Push(op1 - op2); break; }
		case'*': { st.Push(op1 * op2); break; }
		case'/': { st.Push(op1 / op2); break; }
		default: throw "unknow elem " + c;
		}
		i++;
	}
	return st.Pop();
}

double TCalculator::Calc() {
	ToPostfix();
	return CalcPostfix();
	/*int i = 0;
	char c;
	while (i < infix.size()) {
		c = infix[i];
		if ((c >= '0') && (c <= '9')) {
			size_t inx;
			double tmp = stod(&postfix[i], &inx);

			if ((stc.TopView() == '(') || (stc.IsEmpty()))	st.Push(tmp);
			else {
				char m = stc.Pop();
				switch (c)
				{
				case'+': { st.Push(st.Get() + tmp);  break; }
				case'-': { st.Push(st.Get() - tmp);  break; }
				case'*': { st.Push(st.Get() * tmp);  break; }
				case'/': { st.Push(st.Get() / tmp);  break; }
				}
			}
			i += inx;
			continue;
		}
		if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) { stc.Push(c); i++; continue; }

		if (c == ')') {
			char tmp = stc.Pop();
			while (tmp != '(') {
				double op2 = st.Pop();
				switch (tmp)
				{
				case'+': { st.Push(st.Get() + op2);  break; }
				case'-': { st.Push(st.Get() - op2);  break; }
				case'*': { st.Push(st.Get() * op2);  break; }
				case'/': { st.Push(st.Get() / op2);  break; }
				}

			}
		}


		i++;


	}
	while (!(stc.IsEmpty())) {
		char tmp = stc.Pop();
		while (tmp != '(') {
			double op2 = st.Pop();
			switch (tmp)
			{
			case'+': { st.Push(st.Get() + op2);  break; }
			case'-': { st.Push(st.Get() - op2);  break; }
			case'*': { st.Push(st.Get() * op2);  break; }
			case'/': { st.Push(st.Get() / op2);  break; }
			}

		}

	}
	return st.Pop();*/
}


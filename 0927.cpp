#include <iostream>
#include <string>
using namespace std;

// 동적 바인딩
class Bird {
public:
    // 가상 함수
    virtual void sound() {
        cout << "소리" << endl;
    }
};

class Sparrow : public Bird {
public:
    // 부모 클래스의 멤버 함수 재정의 -> 오버라이딩
    void sound() override{
        cout << "짹짹" << endl;
    }
};

class Crow : public Bird {
public:
    // 부모 클래스의 멤버 함수 재정의 -> 오버라이딩
    void sound() override {
        cout << "까악까악" << endl;
    }
};

int main() {
    // 객체 생성
    Bird bird;
    Sparrow sparrow;
    Crow crow;

    // 객체 타입에 맞게 멤버 함수 호출 -> 정적 바인딩
    bird.sound();
    sparrow.sound();
    crow.sound();

    // 참조를 통한 동적 바인딩
    // Bird 타입의 참조가 Sparrow 객체 참조
    Bird& refbird = sparrow;
    refbird.sound();    // 실행 시점에 실제 객체 타입을 확인하여 함수 호출

    // 포인터를 통한 동적 바인딩
    // Bird 타입의 포인터가 Crow 객체를 가리킴
    Bird* ptrbird = &crow;
    ptrbird->sound();   // 실행 시점에 실제 객체 타입을 확인하여 함수 호출
}


/* 정적 바인딩
class Bird{ 
public:
    // virtual이 아니기 때문에 정적 바인딩
    void sound() {
        cout << "소리" << endl;
    }
};

class Sparrow : public Bird {
public:
    void sound() {
        cout << "짹짹" << endl;
    }
};

class Crow : public Bird {
public:
    void sound() {
        cout << "까악까악" << endl;
    }
};

int main() {
    // 객체 생성
    Bird bird;
    Sparrow sparrow;
    Crow crow;

    // 객체 타입에 맞게 멤버 함수 호출
    bird.sound();       
    sparrow.sound();    
    crow.sound();      

    // 참조는 sparrow를 가리키지만 컴파일러는 선언된 타입에 맞게 함수를 호출함. 
    // 부모 클래스의 함수가 호출됨
    Bird& refbird = sparrow;   
    refbird.sound();

    // 포인터도 crow를 가리키지만 컴파일러는 선언된 타입에 맞게 함수를 호출함.
    // 부모 클래스의 함수가 호출됨
    Bird* ptrbird = &crow;
    ptrbird->sound();
}
*/


/*  다중 상속
// 부모 클래스1
class Character {
    string name;
    int level;
public:
    Character(string n, int l) : name(n), level(l) {

    }

    // name과 level 출력 함수
    void info() {
        cout << name << ", " << level << endl;
    }
};

// 부모 클래스2
class Weapon {
public:
    void print() {
        cout << "무기를 들었습니다." << endl;
    }
};

// 자식 클래스로 Character, Weapon 클래스를 다중 상속
class Player : public Character, public Weapon {
public:
    Player(string n, int l) : Character(n, l) {
        info();     // Character 클래스로부터 상속받은 info() 호출
        print();    // Weapon 클래스로부터 상속받은 print() 호출
    }
};

int main() {
    Player player("플레이어", 10);  // Player 객체 생성
    player.info();      // Character 클래스로부터 상속받은 info() 멤버 함수 호출
    player.print();      // Weapon 클래스로부터 상속받은 print() 멤버 함수 호출
}
*/


/* 상속 생성자, 소멸자
class Money {
    int total;

public:
    // 생성자, 자식 클래스 객체를 생성할 때 가장 먼저 호출됨(명시적 호출이 없을 경우)
    Money() {
        cout << "Money 생성자" << endl;
    }

    // 매개변수가 있는 생성자, 자식 생성자에서 명시적으로 호출될 때 실행됨
    Money(int n) : total(n) {
        cout << "Money 생성자2" << endl;
    }

    // 소멸자, 자식 클래스의 소멸자가 호출된 후 가장 마지막에 호출됨
    ~Money() {
        cout << "Money 소멸자" << endl;
    }
};

class Dollar : public Money{
public:
    // 생성자, 부모 클래스의 생성자가 호출된 후 생성자가 호출됨
    Dollar() { 
        cout << "Dollar 생성자" << endl;
    }
    
    // 매개변수가 있는 생성자, 초기화 리스트를 통해 부모 클래스의 매개변수가 있는 생성자를 명시적으로 호출
    Dollar(int n) : Money(n){
        cout << "Dollar 생성자2" << endl;
    }

    // 소멸자, 객체가 소멸되면 먼저 호출됨
    ~Dollar() {
        cout << "Dollar 소멸자" << endl;
    }
};

int main() {
    Dollar dollar;      // Dollar 객체 생성
    Dollar dollar2(10); // Dollar 객체2 생성
}
*/



/* 
상속 접근 지정자 변경
// 부모 클래스 (기반 클래스)
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void introduce() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

// 자식 클래스 (파생 클래스)
class Student : private Person {
private:
    string major;

public:
    Student(string n, int a, string m) : Person(n, a), major(m) {}

    void study() {
        cout << name << " 학생이 " << major << " 전공 공부 중입니다." << endl;
    }
};

int main() {
    Student s("홍길동", 21, "컴퓨터공학");
    s.introduce();   // 부모 클래스 함수 사용
    s.study();       // 자식 클래스 함수 사용
    return 0;
}
*/



/*
// 부모 클래스 (기반 클래스)
class Person {
protected:
    string name;
    int age;
    /*
    // 클래스 내부, 자식 클래스 내부에서만 접근 가능, 외부에서는 접근 불가능
    void introduce() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
    

public:
    Person(string n, int a) : name(n), age(a) {}

    // 클래스 내부이므로 private 멤버 함수인 introduce() 접근 가능
    void printIntroduce() {
        introduce();
    }

private:
    // 자식 클래스 및 외부 접근 불가능
    void introduce() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

// 자식 클래스 (파생 클래스)
class Student : public Person {
private:
    string major;

public:
    Student(string n, int a, string m) : Person(n, a), major(m) {}

    void study() {
        cout << name << " 학생이 " << major << " 전공 공부 중입니다." << endl;
    }
};

int main() {
    Student s("홍길동", 21, "컴퓨터공학");
    // s.introduce();   // 부모 클래스 함수 사용, 해당 함수는 접근 지정자가 protected/private이므로 외부에서 접근 불가능
    s.printIntroduce(); // public 함수인 printIntroduce()를 통해 private 함수 introduce()를 간접 접근
    s.study();       // 자식 클래스 함수 사용
    return 0;
}
*/



/* 부모, 자식 접근
class Book {
// 클래스 내부에서만 접근 가능, 자식 클래스에서도 접근 불가능
    string name;
    int page;

public:
    // 생성자, 초기화 리스트 사용하여 멤버 변수 초기화
    Book(string n, int p) : name(n), page(p) {}

    // name과 page 출력하는 함수
    void info() {
        cout << name << ", " << page << "페이지" << endl;
    }

    void bookSell() {
        info();         // 멤버 함수 호출
        //sell(20);     // 자식 클래스의 멤버 함수에는 접근 불가능
    }
};

// public 상속
class ComicBook : public Book {
    int count;
public:
    // 부모 생성자 호출, name과 page 초기화
    ComicBook(string n, int p) : Book(n, p) {}

    // count 출력 함수
    void sell(int c) {
        count = c;
        cout << count << "개 팔림" << endl;
    }
};

int main() {
    Book book("책", 300);                // Book 객체 생성
    ComicBook comic ("만화책", 200);     // ComicBook 객체 생성
        
    // 부모 클래스 자신의 멤버 함수 호출
    book.info();                         
    book.bookSell();
    // book.sell();     // 자식 클래스의 멤버 함수에 접근 불가능

    comic.info();       // 부모 클래스의 멤버 함수 호출
    comic.sell(10);     // 자식 클래스 자신의 멤버 함수 호출
}
*/



/* 상속
class Item {
    // private으로 클래스 내부에서만 접근 가능, 자식 클래스 직접 접근 불가능
    string name;
    int count;

    // 자식 클래스 및 외부에서 접근 가능
public:
    // 생성자, 초기화 리스트
    Item(string n, int c) : name(n), count(c) {}

    // 멤버 변수 출력하는 함수
    void info() {
        cout << name << ", " << count << "개" << endl;
    }

    // 자식 클래스에서 접근 가능하지만 외부에서는 접근 불가능
protected:
    // name 출력 함수
    void printName() {
        cout << name << endl;
    }
};

// Item 클래스를 public으로 상속, public -> public, protected -> protected
class Sword : public Item {
    int atk;
public:
    // 부모 클래스 생성자 호출 및 atk 초기화
    Sword(string n, int c, int a) : Item(n, c), atk(a) {}

    // 자식 클래스 내부에서는 부모 클래스의 protected인 멤버 함수 접근 가능
    void print() {
        printName();
    }
    // atk 출력 함수
    void printAtk() {
        cout << "공격력: " << atk << endl;
    }

};

// Item 클래스를 protected로 상속, public -> protected, protected -> protected
class Bow : protected Item {
    int atk;
public:
    // 부모 클래스 생성자 호출 및 atk 초기화
    Bow(string n, int c, int a) : Item(n, c), atk(a) {}

    // 자식 클래스 내부에서는 부모 클래스의 protected인 멤버 함수 접근 가능
    void print() {
        printName();
    }

    // atk 출력 함수
    void printAtk() {
        cout << "공격력: " << atk << endl;
    }
};

// Item 클래스를 private로 상속, public -> private, protected -> private
class Potion : private Item {
    int heal;
public:
    // 부모 클래스 생성자 호출 및 heal 초기화
    Potion(string n, int c, int h) : Item(n, c), heal(h) {}

    // 자식 클래스 내부에서는 부모 클래스의 protected인 멤버 함수 접근 가능
    void print() {
        printName();
    }

    // heal 출력 함수
    void printHeal() {
        cout << "회복량: " << heal << endl;
    }
};

int main() {
    Sword sword("LongSword", 5, 50);        // Sword 클래스 객체 생성
    Bow bow("LongBow", 2, 30);              // Bow 클래스 객체 생성
    Potion potion("HealPotion", 10, 500);   // Potion 클래스 객체 생성

    // public 상속
    sword.info();           // 부모 클래스의 public으로 된 멤버 함수에 접근 가능
    sword.printAtk();       // 자신 클래스의 멤버 함수 호출
    //sword.printName();    // protected 멤버 함수는 외부에서는 접근 불가능 -> 자식 클래스는 가능

    // protected 상속
    // bow.info();          // 부모 클래스의 public이 protected로 변경되어 외부에서 접근 불가능
    bow.printAtk();         // 자신 클래스의 멤버 함수 호출
    // bow.printName();     // protected 멤버 함수는 외부에서는 접근 불가능 -> 자식 클래스는 가능

    // private 상속
    //potion.info();        // 부모 클래스의 public이 private으로 변경되어 외부에서 접근 불가능
    potion.printHeal();     // 자신 클래스의 멤버 함수 호출
    // potion.printName();  // protected 멤버 함수는 외부에서는 접근 불가능 -> 자식 클래스는 가능
}

*/

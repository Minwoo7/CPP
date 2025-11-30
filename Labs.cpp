#include <iostream>
#include <vector>
using namespace std;

// 8번
void assignTest() {
    vector <int> v1, v2, v3, v4;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "the value of elements of v1 " << endl;
    for (auto& e : v1) cout << e << ",";
    cout << endl;
    cout << "the capacity of v1: " << v1.capacity() << endl;
    cout << "the value of elements of v2 after assign" << endl;
    v2.assign(v1.begin(), v1.end());

    cout << "the size of v2: " << v2.size() << endl;
    cout << "the capacity of v2: " << v2.capacity() << endl;

    for (auto& e : v1) cout << e << ",";
    cout << endl;

    v3.assign(10, 3);
    cout << "the result of v3.assign(7 , 3): " << endl;
    cout << "the size of v3: " << v3.size() << endl;
    cout << "the capacity of v3: " << v3.capacity() << endl;

    for (auto& e : v3) cout << e << ", ";
    cout << endl;

    v4.assign({ 5, 6, 7, 8 });
    cout << "the result of v4.assign({5, 6, 7}): " << endl;
    cout << "the size of v4: " << v4.size() << endl;
    cout << "the capacity of v4: " << v4.capacity() << endl;

    for (auto& e : v4) cout << e << ", ";
    cout << endl;

}

void itrTest() {
    vector <int> v1;
    vector <int>::iterator v1_itr;
    vector <int>::const_iterator v1_citer;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    v1_itr = v1.begin();
    cout << "Access the data through the iterator" << endl;
    for (; v1_itr != v1.end(); v1_itr++) cout << *v1_itr << ", ";
    cout << endl;

    v1_itr = v1.begin();
    cout << "Add 100 to every element in the vector through the iterator" << endl;
    for (; v1_itr != v1.end(); v1_itr++) *v1_itr += 100;

    cout << "Accee the element with range-for loop in the vector" << endl;
    for (auto& e : v1) cout << e << ", ";
    cout << endl;

    cout << "Accee the element with for loop in the vector" << endl;
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << ", ";
    cout << endl;
}

void sizeTest() {
    vector <int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    cout << "size of vector: " << v1.size() << endl;
}

void capacityTest() {
    vector <int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    cout << "capacity of vector: " << v1.capacity() << endl;
}

void atTest() {
    vector <int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    int& e = v1.at(1);

    cout << e << endl;
    e = 60;
    cout << v1[1] << endl;
}

void backTest()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    cout << v1.back() << endl;  // back()함수는 vector의 마지막 요소를 반환
    
    v1.back() = 100;    // vector의 마지막 요소 값 변경
    cout << v1.back() << endl;  // 변경된 값 출력
}

void beginTest()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int>::iterator it = v1.begin();  // begin() 함수는 vector의 첫 번째 요소를 가리키는 iterator 반환
    cout << *it << endl;    // iterator가 가리키는 첫 번째 요소 출력
}

void endTest()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int>::iterator it = v1.begin();  

    // end() 함수는 마지막 요소의 다음 위치를 가리키는 iterator 반환
    // 첫 번째 요소부터 마지막 요소까지 출력
    for (it; it != v1.end(); it++) {
        cout << *it << endl;
    }
}

void clearTest()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    // clear() 함수 호출 전 size와 capacity 출력
    cout << "size: " << v1.size() << endl;
    cout << "capacity: " << v1.capacity() << endl;

    // clear() 함수는 vector의 모든 요소를 제거
    v1.clear();
    
    // clear() 함수 호출 후 size와 capacity 출력, size는 0, capacity는 유지
    cout << "size: " << v1.size() << endl;
    cout << "capacity: " << v1.capacity() << endl;

}

int main(int argc, char const* argv[])
{
    //itrTest();
    backTest();
    beginTest();
    endTest();
    clearTest();

    return 0;
}


/* 7번
int main() {
    vector<int> vec1;
    vector<int> vec2;

    // vec1에 값 저장
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    // vec2에 값 저장
    vec2.push_back(100);
    vec2.push_back(200);
    vec2.push_back(300);

    // 두 vector를 앞에서부터 요소를 비교, 10 > 100이므로 vec2가 더 큼
    if (vec1 > vec2)
        cout << "vec1이 더 크다" << endl;
    else
        cout << "vec2가 더 크다" << endl;

    // front() 함수는 첫 번째 요소를 반환, 두 vector의 첫 번째 요소 값이 서로 다름
    if (vec1.front() != vec2.front())
        cout << "첫 번째 요소의 값이 다르다." << endl;
    else
        cout << "첫 번째 요소의 값이 같다." << endl;

    vec1.clear();   // clear() 함수는 vector의 모든 요소를 제거

    // 두 vector의 size를 비교, vec1은 0, vec2는 3이므로 다름
    if (vec1.size() == vec2.size())
        cout << "같다" << endl;
    else
        cout << "다르다" << endl;
}
*/

/* 6번
int main()
{
    vector<int> v1(5);  // 크기가 5인 vector 생성, size = 5, capacity = 5
    v1.push_back(3);    // 요소 1개 추가, size = 6

    cout << v1.capacity() << endl;  // capacity는 공간이 부족해지면서 늘어남, 약 1.5배로 증가하여 7 출력
    cout << v1.size() << endl;      // 저장된 요소 개수 6 출력

    *v1.begin() = 1;    // begin()은 첫 번째 요소를 가리키는 iterator 반환, 역참조 연산자 사용하여 값 1 저장
    cout << v1[0] << endl;  // 첫 번째 요소 값 출력
}
*/


/* 5번
int main()
{
    vector<int> v1(5);  // 크기가 5인 vector 생성, size = 5, capacity = 5
    v1.push_back(3);    // 요소 1개 추가, size = 6

    cout << v1.capacity() << endl;  // capacity는 공간이 부족해지면서 늘어남, 약 1.5배로 증가하여 7 출력
    cout << v1.size() << endl;      // 저장된 요소 개수 6 출력
    cout << v1[5] << endl;  // 추가된 3은 인덱스 5에 저장(6번째 위치)
}
*/


/* 4번
int main()
{
    vector<int> v1(5);  // 크기가 5인 vector 생성, size = 5, capacity = 5
    v1.push_back(3);    // 요소 1개 추가, size = 6

    cout << v1.capacity() << endl;  // capacity는 공간이 부족해지면서 늘어남, 약 1.5배로 증가하여 7 출력
    cout << v1.size() << endl;      // 저장된 요소 개수 6 출력
}
*/


/* 3번
class Rect {
private:
    int width, height;  // 사각형의 가로, 세로의 값을 저장하는 멤버 변수
public:
    // 생성자,전달받은 값으로 width와 height 초기화
    Rect(int w, int h) : width(w), height(h) { }

    // 사각형의 면적을 계산하여 반환하는 함수
    int area() {
        return width * height;
    }
};

int main() {
    vector<Rect> arr;   // Rect 객체를 저장하는 vector

    // Rect 객체를 vector에 추가
    arr.push_back(Rect(3, 5));
    arr.push_back(Rect(2, 7));
    arr.push_back(Rect(10, 5));

    // vector에 저장된 각 Rect 객체의 area() 함수를 호출하여 면적 출력
    for (int i = 0; i < arr.size(); i++) {
        cout << "면적: " << arr[i].area() << endl;
    }
}
*/


/* 2번
int main()
{
    vector<int> v1, v2, v3;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    // v1 출력 -> 10, 20, 30, 40, 50
    cout << "v1 = ";
    for (auto& v : v1) {
        cout << v << " ";
    }
    cout << endl;

    // v1의 모든 요소를 v2에 복사
    v2.assign(v1.begin(), v1.end());

    // v2 출력 -> 10, 20, 30, 40, 50
    cout << "v2 = ";
    for (auto& v : v2) {
        cout << v << " ";
    }
    cout << endl;

    // v3에 값 6을 3개 저장
    v3.assign(3, 6);

    // v3 출력 -> 6, 6, 6
    cout << "v3 = ";
    for (auto& v : v3) {
        cout << v << " ";
    }
    cout << endl;

    // v3에 5, 6, 7을 새로 저장 -> 기존 요소는 모두 삭제
    v3.assign({ 5, 6, 7 });

    // v3 출력 -> 5, 6, 7
    for (auto& v : v3) {
        cout << v << " ";
    }
    cout << endl;

    // at() 함수는 지정한 위치의 요소를 참조 반환 -> v1의 첫 번째 요소에 대한 참조 반환
    int& i = v1.at(0);

    cout << "v1 첫 번째 원소의 값:  " << i << endl;

    // 모든 요소와 size가 같으므로 v1과 v2는 같다.
    if (v1 == v2) cout << "v1과 v2는 같다." << endl;
    else cout << "v1과 v2는 다르다" << endl;

    i = 80; // v1 첫 번째 요소의 값 변경
    const int& j = v1.at(0);    // j는 v1[0]을 가리키므로 값은 80

    cout << "값을 변경 후 v1 첫 번째 원소의 값:  " << j << endl;

    // v1의 첫 번째 요소의 값이 80으로 변경되었으므로 v1과 v2는 다르다
    if (v1 == v2) cout << "v1과 v2는 같다." << endl;
    else cout << "v1과 v2는 다르다" << endl;
}
*/


/* 1번
int main()
{
    vector <int> v1;
    // v1.push_back(10);

    // 1부터 10까지 push_back() 사용하여 값 추가 후 size와 capacity 값 출력
    for (int i = 0; i < 10; i++) {
        v1.push_back(i + 1);

        cout << "size: " << v1.size() << ", capacity: " << v1.capacity() << endl;
    }

    // size는 vector에 저장된 요소의 개수, capacity는 저장할 수 있는 요소의 최대 개수
    // size는 10개의 값을 저장했기 때문에 10
    // capacity는 공간이 부족해지는 시점마다 기존 용량의 1.5배로 증가
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//replace
// vector의 모든 요소를 출력하는 함수
void printVec(const vector<int>& v) {
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ", ";
    }
}

int main()
{
    vector<int> vec = {2, 3, 8, 3}; // int형 값을 저장하는 vector 선언 및 초기화
  
    printVec(vec);      // vector 출력

    // replace()는 범위 내의 특정 값을 다른 값으로 바꿔주는 함수
    replace(vec.begin(), vec.end(), 3, 10);

    cout << endl;
    printVec(vec);      // 변경된 vector 출력
}


/* equal
int main()
{
    // int형 값을 저장하는 vector 선언 및 초기화
    vector<int> vec1 = { 3, 5, 7, 9 };
    vector<int> vec2 = { 3, 5, 7, 9 };
    vector<int> vec3 = { 3, 5, 7, 10 };

    // equal()은 두 범위의 요소가 모두 같으면 true, 하나라도 다르면 false를 반환하는 함수
    cout << equal(vec1.begin(), vec1.end(), vec2.begin()) << endl; // vec1과 vec2는 동일하므로 1 출력 -> true
    cout << equal(vec1.begin(), vec1.end(), vec3.begin()) << endl; // vec1과 vec3는 마지막 요소가 다르므로 0 출력 -> false
}
*/


/* fill
// vector의 모든 요소를 출력하는 함수
void printVec(const vector<int>& v) {
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ", ";
    }
}

int main()
{
    vector<int> vec = {2, 3, 8, 10};    // int형 값을 저장하는 vector 선언 및 초기화

    printVec(vec);      // vector 출력

    // fill()은 범위의 요소를 모두 지정한 값으로 채우는 함수
    fill(vec.begin(), vec.end(), 5);    // 전체 요소를 5로 채움

    cout << endl;
    printVec(vec);      // 값이 모두 5로 변경된 vector 출력
}
*/


/* reverse
// vector의 모든 요소를 출력하는 함수
void printVec(const vector<int>& v) {
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ", ";
    }
}

int main()
{
    vector<int> vec = {4, 6, 9, 12};    // int형 값을 저장하는 vector 선언 및 초기화

    printVec(vec);      // vector 출력

    // reverse()는 범위의 요소 순서를 역순으로 변경해주는 함수
    reverse(vec.begin(), vec.end());   
    
    cout << endl;
    printVec(vec);      // vector 역순으로 출력
}
*/


/* count
int main()
{
    vector<int> vec = {1, 5, 10, 5, 5};    // int형 값을 저장하는 vector 선언 및 초기화

    // count()는 범위 안에 특정 값이 몇 개 들어 있는지 세어주는 함수
    cout << count(vec.begin(), vec.end(), 5) << endl; // 5가 3개 있으므로 3 출력
    cout << count(vec.begin(), vec.end(), 2) << endl; // 값이 없으므로 0 출력
}
*/


/* find
int main() 
{
    vector<int> vec = {3, 5, 10, 2};    // int형 값을 저장하는 vector 선언 및 초기화

    // find()는 값이 있으면 iterator 반환하고 값이 없으면 end() 반환
    if (find(vec.begin(), vec.end(), 5) != vec.end()) {
        cout << "값 있음" << endl;     // 5가 있으면 출력
    }
    else {
        cout << "값 없음" << endl;     // 5가 없으면 출력
    }
}
*/


/* sort
// vector의 모든 요소를 출력하는 함수
void printVec(const vector<int>& v) {
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ", ";
    }
}

int main()
{
    vector<int> vec = {5, 10, 1, 3, 20};   // int형 값을 저장하는 vector 선언 및 초기화

    sort(vec.begin(), vec.end());   // 오름차순 정렬 (기본은 오름차순 정렬)

    printVec(vec);  // vector 출력
    cout << endl;

    sort(vec.begin(), vec.end(), greater<int>());   // 내림차순 정렬, greater<int>()를 사용하여 내림차순 정렬

    printVec(vec);  // vector 출력
}
*/

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>
using namespace std;

const int hash_size = 32;

// 初始化节点的结构体
template <typename T, typename U>
struct hash_node {
    T key;
    U value;
};

// 拉链法的hash_table
template <typename T, typename U>
class hash_table {
public:
    // 指定哈希表的大小 lambda表达式
    hash_table() : vec(hash_size) {}
    ~hash_table() {}
    bool insert_data(const T& key, const U& value);
    int hash(const T& key);
    bool hash_find(const T& key);
private:
    vector<list<hash_node<T, U>>> vec;

    template<typename T, typename U>
    int hash_table<T, U>::hash(const T& key) {
        return key % hash_size;
    }

    template<typename T, typename U>
    int hash_table<T, U>::hash_find(const T& key) {
        // 找到key对应的散列地址
        int index = hash(key);
        for (auto it = vec[index].begin(); it != vec[index].end(); it++) {
            if (it->key == key) {
                return true;
            }
        }
        return false;
    }

    template<typename T, typename U>
    bool hash_table<T, U>::insert_data(const T& key, const U& value) {
        // 如果原本的key对应的散列地址已经存在，则返回false
        if (hash_find(key)) {
            return false;
        }
        int index = hash(key);
        hash_node<T, U> node;
        node.key = key;
        node.value = value;
        vec[index].push_back(node);
        return true;
    }

    template<typename T, typename U>
    bool hash_table<T, U>::hash_delete(const T& key) {
        // 如果原本的key对应的散列地址已经存在，则返回false
        if (!hash_find(key)) {
            return false;
        }
        int index = hash(key);
        for (auto it = vec[index].begin(); it != vec[index].end(); it++) {
            if (it->key == key) {
                vec[index].erase(it);
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    hash_table<int, int> hash;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        // 随机插入数据
        int key = rand() % 100;
        int value = rand() % 100;
        hash.insert_data(key, value);
    }
    return 0;
}

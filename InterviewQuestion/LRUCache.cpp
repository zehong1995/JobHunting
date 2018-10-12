#include <bits/stdc++.h>
using namespace std;

// 双向链表的节点结构
struct LRUCacheNode {
    int key;
    int value;
    LRUCacheNode* prev;
    LRUCacheNode* next;
    LRUCacheNode():key(0),value(0),prev(NULL),next(NULL){}
};

class LRUCache {
private:
    unordered_map<int, LRUCacheNode*> mp;     // 代替hash_map
    LRUCacheNode* head;                      // 指向双链表的头结点
    LRUCacheNode* tail;                      // 指向双链表的尾结点
    int capacity;                            // Cache的容量
    int count;                               // 计数
    void removeLRUNode();                    // 删除尾结点（最久未使用）
    void detachNode(LRUCacheNode* node);     // 分离当前结点
    void insertToFront(LRUCacheNode* node);  // 节点插入到头部

public:
    LRUCache(int capacity);                  // 构造函数
    ~LRUCache();                             // 析构函数
    int get(int key);                        // 查询数据项
    void set(int key, int value);            // 未满时插入,已满时替换
};
LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
    this->count = 0;
    mp.clear();
    head = new LRUCacheNode;
    tail = new LRUCacheNode;
    head->next = tail;
    tail->prev = head;
}
LRUCache::~LRUCache() {
    while(head) {
        LRUCacheNode* nxt = head->next;
        delete head;
        head = nullptr;
        head = nxt;
    }
}
int LRUCache::get(int key) {
    if (mp.find(key) == mp.end()) {
        return -1;
    } else {
        LRUCacheNode* node = mp[key];
        detachNode(node);
        insertToFront(node);
    }

}
void LRUCache::set(int key, int value) {
    if (mp.find(key) == mp.end()) {
        LRUCacheNode* node = new LRUCacheNode;
        node->value = value;
        node->key = key;
        mp[key] = node;
        if (count == capacity) {
            removeLRUNode();
        }
        insertToFront(node);
        ++count;
    } else {
        LRUCacheNode* node = mp[key];
        node->value = value;
        detachNode(node);
        insertToFront(node);
    }
}
void LRUCache::removeLRUNode() {
    LRUCacheNode* node = tail->prev;
    detachNode(node);
    mp.erase(node->key);
    --count;
    delete node;
    node = nullptr;
}
void LRUCache::detachNode(LRUCacheNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
void LRUCache::insertToFront(LRUCacheNode* node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
}
int main() {
    return 0;
}

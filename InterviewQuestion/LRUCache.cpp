#include <bits/stdc++.h>
using namespace std;

// ˫������Ľڵ�ṹ
struct LRUCacheNode {
    int key;
    int value;
    LRUCacheNode* prev;
    LRUCacheNode* next;
    LRUCacheNode():key(0),value(0),prev(NULL),next(NULL){}
};

class LRUCache {
private:
    unordered_map<int, LRUCacheNode*> mp;     // ����hash_map
    LRUCacheNode* head;                      // ָ��˫�����ͷ���
    LRUCacheNode* tail;                      // ָ��˫�����β���
    int capacity;                            // Cache������
    int count;                               // ����
    void removeLRUNode();                    // ɾ��β��㣨���δʹ�ã�
    void detachNode(LRUCacheNode* node);     // ���뵱ǰ���
    void insertToFront(LRUCacheNode* node);  // �ڵ���뵽ͷ��

public:
    LRUCache(int capacity);                  // ���캯��
    ~LRUCache();                             // ��������
    int get(int key);                        // ��ѯ������
    void set(int key, int value);            // δ��ʱ����,����ʱ�滻
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

#include <stdlib.h>
#include <stdio.h>

#define NONTAKEN -1

typedef struct _MapEntry {
  int key;
  int value;
  struct _MapEntry* next;
} MapEntry;

typedef struct {
  MapEntry* buckets;
  int entriesInUse;
  int maxEntries;
} MyHashMap;

/** Initialize your data structure here. */
void myHashMapInit(MyHashMap* obj){
  for(int i = 0; i < obj->maxEntries; i++)
    obj->buckets[i].key = NONTAKEN;
}

MyHashMap* myHashMapCreate() {
  MyHashMap* instance = calloc(1, sizeof(MyHashMap));
  static const int startCapacity = 16;
  instance->buckets = calloc(startCapacity, sizeof(MapEntry));
  instance->maxEntries = startCapacity;
  instance->entriesInUse = 0;
  myHashMapInit(instance);
  return instance;
}

MapEntry* getEntry(MyHashMap* obj, int key){
  int hash = abs(key) % obj->maxEntries;
  return &obj->buckets[hash];
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
  MapEntry* entry = getEntry(obj, key);
  MapEntry* prev = entry;
  if () ...

  while (entry){
    if (entry->key == key){ // update existing
      entry->value = value;
      return;
    }
    prev = entry;
    entry = entry->next;
  }
  prev->next = calloc(1, sizeof(MapEntry));

  entry->key = key;
  obj->entriesInUse += 1;
}

// Returns the value to which the specified key is mapped,
// or -1 if this map contains no mapping for the key
int myHashMapGet(MyHashMap* obj, int key) {
  return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {

}

void myHashMapFree(MyHashMap* obj) {
  for(int i = 0; i < obj->entriesInUse; i++){
    MapEntry* entry = &obj->buckets[i];
    while(entry->next){ // linked lists are dynamically allocated
      MapEntry* nextNext = entry->next->next;
      free(entry->next);
      entry->next = nextNext;
    }
  }
  free(obj->buckets);
  free(obj);
}

void printHashMap(MyHashMap* obj){
  printf("entries: %d\n", obj->entriesInUse);
  for(int i = 0; i < obj->maxEntries; i++){
    MapEntry* entry = &obj->buckets[i];
    while(entry){
      if(entry->key != NONTAKEN)
        printf("%d=>%d\n", entry->key, entry->value);
      entry = entry->next;
    }
  }
}

// clang hashmap.c && ./a.out
int main(int argc, char const *argv[]){
  MyHashMap* map = myHashMapCreate();

  myHashMapPut(map, 2, 22);
  myHashMapPut(map, 13, 130);
  myHashMapPut(map, 22, 220);
  printHashMap(map);

  myHashMapFree(map);

  return 0;
}

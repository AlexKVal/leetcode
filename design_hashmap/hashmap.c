#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define initialCapacity 8
#define NONTAKEN -1

typedef struct {
  int key;
  int value;
} MapEntry;

typedef struct {
  MapEntry* entries;
  int entriesInUse;
  int maxEntries;
} MyHashMap;

/** Initialize your data structure here. */
void myHashMapInit(MyHashMap* obj){
  for(int i = 0; i < obj->maxEntries; i++)
    obj->entries[i].key = NONTAKEN;
}

MyHashMap* newHashMap(int capacity) {
  MyHashMap* instance = calloc(1, sizeof(MyHashMap));
  instance->entries = calloc(capacity, sizeof(MapEntry));
  instance->maxEntries = capacity;
  instance->entriesInUse = 0;
  myHashMapInit(instance);
  return instance;
}

MyHashMap* myHashMapCreate() {
  return newHashMap(initialCapacity);
}

int hash(int key, int size){
  return abs(key) % size;
}

// true - success, false - not set
bool setValue(MyHashMap* obj, int key, int value){
  int entryIndex = hash(key, obj->maxEntries);
  int shouldBeIndex = entryIndex;

  // open addressing
  while (entryIndex < obj->maxEntries){
    MapEntry* entry = &obj->entries[entryIndex];

    if (entry->key == NONTAKEN){
      entry->key = key;
      entry->value = value;
      obj->entriesInUse += 1;
      if (shouldBeIndex != entryIndex)
        printf(" setting %d shifted +%d\n", key, entryIndex - shouldBeIndex);
      return true;
    }

    if (entry->key == key){
      entry->value = value;
      return true;
    }

    entryIndex++;
  }
  return false;
}

// true - success
bool migrate(MyHashMap* oldHM, MyHashMap* newHM){
  for(int i = 0; i < oldHM->maxEntries; i++){
    MapEntry* entry = &oldHM->entries[i];
    if (entry->key == NONTAKEN) continue;
    bool success = setValue(newHM, entry->key, entry->value);
    if (!success) return false;
  }
  return true;
}

void rehash(MyHashMap* obj){
  MyHashMap* newMap;

  int prevCapacity = obj->maxEntries;
  while(true){
    int newCapacity = prevCapacity * 2;
    newMap = newHashMap(newCapacity);

    printf(" rehash %d->%d\n", prevCapacity, newCapacity);
    bool success = migrate(obj, newMap);
    if (success) break;

    puts(" collision in rehash");
    free(newMap);
    prevCapacity = newCapacity;
  }

  // swap
  free(obj->entries);
  obj->entries = newMap->entries;
  obj->maxEntries = newMap->maxEntries;
  puts(" rehash successful");
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
  printf("try putting %d=>%d\n", key, value);
  // rehash at >50% capacity
  if (obj->entriesInUse > obj->maxEntries/2) rehash(obj);

  while(!setValue(obj, key, value)){
    puts("need rehash");
    rehash(obj);
  }
  puts("put success");
}

// Returns the value to which the specified key is mapped,
// or -1 if this map contains no mapping for the key
int myHashMapGet(MyHashMap* obj, int key) {
  int entryIndex = hash(key, obj->maxEntries);
  int shouldBeIndex = entryIndex;

  // open addressing
  while (entryIndex < obj->maxEntries){
    MapEntry* entry = &obj->entries[entryIndex];

    if (entry->key == NONTAKEN) return NONTAKEN;
    if (entry->key == key){
      if (shouldBeIndex != entryIndex)
        printf(" getting %d probed +%d\n", key, entryIndex - shouldBeIndex);
      return entry->value;
    }

    entryIndex++;
  }

  return NONTAKEN;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
  int entryIndex = hash(key, obj->maxEntries);
  int shouldBeIndex = entryIndex;

  printf("freeing %d\n", key);
  while (entryIndex < obj->maxEntries){
    MapEntry* entry = &obj->entries[entryIndex];

    if (entry->key == NONTAKEN) return; // noop

    if (entry->key == key){ // free it
      entry->key = NONTAKEN;
      if (shouldBeIndex != entryIndex)
        printf(" found at +%d\n", entryIndex - shouldBeIndex);
      break;
    }

    entryIndex++;
  }

  // check for the next keys if they were shifted and unshift them
  entryIndex++;
  while (entryIndex < obj->maxEntries){
    MapEntry* entry = &obj->entries[entryIndex];

    if (entry->key == NONTAKEN) break;

    int shouldBeIndex = hash(entry->key, obj->maxEntries);
    if (entryIndex != shouldBeIndex){
      printf(" unshifting %d %d<<%d\n", entry->key, entryIndex - 1, entryIndex);
      MapEntry* prevEntry = &obj->entries[entryIndex - 1];
      prevEntry->key = entry->key;
      prevEntry->value = entry->value;
      entry->key = NONTAKEN;
    }

    entryIndex++;
  }
}

void myHashMapFree(MyHashMap* obj) {
  free(obj->entries);
  free(obj);
}

void printHashMap(MyHashMap* obj){
  puts("== state ==");
  printf("entries: %d\n", obj->entriesInUse);
  for(int i = 0; i < obj->maxEntries; i++){
    MapEntry* entry = &obj->entries[i];
    if(entry->key != NONTAKEN)
      printf(" %d %d=>%d\n", i, entry->key, entry->value);
  }
}

// clang hashmap.c && ./a.out
int main(int argc, char const *argv[]){
  MyHashMap* map = myHashMapCreate();

  puts("== writing ==");
  myHashMapPut(map, 1, 11);
  myHashMapPut(map, 2, 22);
  myHashMapPut(map, 2, 222); // update
  myHashMapPut(map, 17, 17);
  myHashMapPut(map, 18, 18);
  myHashMapPut(map, 19, 19);
  // puts("== reading ==");
  // printf("1: %d\n", myHashMapGet(map, 1));
  // printf("2: %d\n", myHashMapGet(map, 2));
  // printf("17: %d\n", myHashMapGet(map, 17));
  // printf("18: %d\n", myHashMapGet(map, 18));
  // printf("19: %d\n", myHashMapGet(map, 19));
  printHashMap(map);
  puts("== deleting ==");
  myHashMapRemove(map, 17);
  myHashMapRemove(map, 18);
  myHashMapRemove(map, 19);
  printHashMap(map);

  // myHashMapPut(map, 3, 33);
  // myHashMapPut(map, 4, 44);
  // myHashMapPut(map, 8, 88);

  // test need rehash
  // myHashMapPut(map, 2, 22);
  // myHashMapPut(map, 3, 33);
  // myHashMapPut(map, 7, 77);
  // printHashMap(map);

  // collision in rehash - hard to get
  // myHashMapPut(map, 22, 22);
  // myHashMapPut(map, 14, 14);
  // myHashMapPut(map, 15, 15);
  // printHashMap(map);

  myHashMapFree(map);

  return 0;
}

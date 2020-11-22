#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    static int const min_quality = 0;
    static int const max_quality = 50;

    void updateQuality();   
};

int FindDailyQualityUpdate(const Item& item);
int GetQuality(const Item item);
void UpdateDueDate(Item& item);
bool isMaturing(const Item& item);
bool isDecaying(const Item& item);
bool isAgedBrie(const Item& item);
bool isConcertPass(const Item& item);
void IncrementQuality(int & daily_quality_update);
void DecrementQuality(int & daily_quality_update);
bool ItemPastDueDate(const Item& item);
void UpdateItemQuality(Item& item, const int daily_quality_update);
int ClampItemQuality(int total_quality);
bool isLegendary(const Item& item);
bool IsConjured(const Item& item);
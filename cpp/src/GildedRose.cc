#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (Item & item : items)
    {
        int daily_quality_update = FindDailyQualityUpdate(item);
        UpdateDueDate(item);

        if (PastDueDate(item))
        {
            if (isAgedBrie(item))
            {
                IncrementQuality(daily_quality_update);
            }
            else if (isConcertPass(item))
            {
                daily_quality_update = -item.quality;
            }
            else if (isDecaying(item))
            {
                DecrementQuality(daily_quality_update);
            }
            else
            {

            } 
        }
        UpdateItemQuality(item, daily_quality_update);
    }
}

int FindDailyQualityUpdate(const Item& item)
{
    int daily_quality_update = 0;
    if (isMaturing(item))
    {
        IncrementQuality(daily_quality_update);

        if (isConcertPass(item))
        {
            if (item.sellIn < 11)
            {
                IncrementQuality(daily_quality_update);
            }

            if (item.sellIn < 6)
            {
                IncrementQuality(daily_quality_update);
            }
        }
    }
    else if (isDecaying(item))
    {
        DecrementQuality(daily_quality_update);
    }

    return daily_quality_update;
}

void UpdateDueDate(Item& item)
{
    if (!isLegendary(item))
    {
        item.sellIn = item.sellIn - 1;
    }
}

bool isMaturing(const Item& item)
{
    return isAgedBrie(item) || isConcertPass(item);
}

bool isDecaying(const Item& item)
{
    return !isLegendary(item) && !isAgedBrie(item) && !isConcertPass(item);
}

bool isAgedBrie(const Item& item)
{
    return "Aged Brie" == item.name;
}

bool isConcertPass(const Item& item)
{
    return "Backstage passes to a TAFKAL80ETC concert" == item.name;
}

void IncrementQuality(int & daily_quality_update)
{
    daily_quality_update = daily_quality_update+ 1;
}

void DecrementQuality(int & daily_quality_update)
{
    daily_quality_update = daily_quality_update - 1;
}

bool PastDueDate(const Item& item)
{
    return item.sellIn < 0;
}

void UpdateItemQuality(Item& item, const int daily_quality_update)
{
    if (!isLegendary(item))
    {
        int clamped_quality = ClampItemQuality(item.quality + daily_quality_update);
        item.quality = clamped_quality;
    }
}

int ClampItemQuality(const int total_quality)
{
    int clamped_quality = std::min(std::max(GildedRose::min_quality, total_quality), GildedRose::max_quality);
    return clamped_quality;  
}

bool isLegendary(const Item& item)
{
    return "Sulfuras, Hand of Ragnaros" == item.name;
}

bool IsConjured(const Item& item)
{
    return item.name.find("Conjured") != std::string::npos;
}
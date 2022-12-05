
// COS30008, Tutorial 5, 2022

#pragma once

#include <string>
#include <functional>

struct DataMap
{
    size_t fIndex;
    size_t fDatum;
    
    const char getAsChar() const;
};

// forward declaration to resolve mutual dependency between Callable and DataWrapper
class DataWrapper;

using Callable = std::function<const char(const DataWrapper&, size_t)>;

class DataWrapper
{
private:
    size_t fSize;
    DataMap* fData;

public:
        
    DataWrapper();
    ~DataWrapper();
        
    bool load( const std::string& aFileName );

    size_t size() const;
    
    const DataMap& operator[]( size_t aIndex ) const;
    
    const char get( size_t aIndex, Callable aSelector ) const;
};
